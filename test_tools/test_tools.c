/*
	i2ctest.c

	Copyright 2008-2011 Michel Pollet <buserror@gmail.com>

 	This file is part of simavr.

	simavr is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	simavr is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with simavr.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "test_tools.h"

//for data structures
#include "sglib.h"
#define my_str_cmp(x, y) (strcmp((((avr_symbol_t*)x)->symbol), (((avr_symbol_t*)y)->symbol)))
#define search_cmp(x, y) (strcmp(((x)->symbol), (y)))

avr_t * avr = NULL;
avr_vcd_t vcd_file;

static uint8_t * _py_get_data(py_avr_wrapper * py){
	return py->avr->data;
}

py_avr_wrapper * py_sim_init(const char* fname, char* mmcu_name, bool do_startup){
	elf_firmware_t f = {{0}};
	elf_read_firmware(fname, &f);
	char *mmcu = (mmcu_name != NULL) ? mmcu_name : f.mmcu;
	
	avr_t *avr = avr_make_mcu_by_name(mmcu);
	if (!avr) {
		fprintf(stderr, "%s: could not find mmcu '%s'\n", fname, mmcu);
		return NULL;
	}
	
	avr_init(avr);
	avr_load_firmware(avr, &f);
	//put stuff into py_avr_wrapper
	py_avr_wrapper * res = malloc(sizeof(py_avr_wrapper));
	res->avr = avr;
	res->symbolcount = f.symbolcount;
	res->symbol_addr_sorted = f.symbol;
	//sorting stuff
	res->symbol_name_sorted = malloc(sizeof(avr_symbol_t *) * f.symbolcount);
	memcpy(res->symbol_name_sorted, res->symbol_addr_sorted, sizeof(avr_symbol_t *) * f.symbolcount);
	SGLIB_ARRAY_SINGLE_QUICK_SORT(avr_symbol_t*, res->symbol_name_sorted, f.symbolcount, my_str_cmp);
	
	for (int i = 0; i < f.symbolcount; i++){
		avr_symbol_t *s = res->symbol_name_sorted[i];
		//printf("in 0x%08x, %d, \"%s\"\n", s->addr, s->size, s->symbol);
		if (strcmp(s->symbol, "_exit") == 0) {
			//printf("_exit found at %08x\n", s->addr);
			res->stop_addr = s->addr;
		}
	}
	
	if (do_startup){
		uint32_t main_addr = get_symbol(res, "main")->addr;
		while(avr->pc != main_addr){
			avr_run(avr);
		}
	}
	res->get_data = _py_get_data;
	return res;
}

void py_sim_reset(py_avr_wrapper * py, bool do_startup){
	avr_reset(py->avr);
	if (do_startup){
		uint32_t main_addr = get_symbol(py, "main")->addr;
		while(avr->pc != main_addr){
			avr_run(avr);
		}
	}
}
void py_sim_terminate(py_avr_wrapper * py){
	avr_terminate(py->avr);
	free(py->symbol_name_sorted);
	free(py);
}



void print_symbols(py_avr_wrapper * py){
	puts("Sorted by address\t\t\tsorted by name");
	for (int i = 0; i < py->symbolcount; i++){
		avr_symbol_t *ad = py->symbol_addr_sorted[i], *lb = py->symbol_name_sorted[i];
		char buf[80];
		sprintf(buf, "0x%08x (%d): %s", ad->addr, ad->size, ad->symbol);
		printf("%-35.35s   ", buf);
		sprintf(buf, "0x%08x (%d): %s", lb->addr, lb->size, lb->symbol);
		printf("%-35.35s\n", buf);
	}
}

uint8_t args[2] = {4, 5};

int woah_validate(py_avr_wrapper * py){
	puts("validating...");
	//uint16_t * res = (uint16_t*)get_data_at_label(py, "a", NULL);
	uint8_t res = py->avr->data[24];
	printf("expected %hhu, got %hhu\n", args[0] + args[1], res);
	return 0;
}

int prologue_validate(py_avr_wrapper * py){
	puts("prologue"); return 0;
}
int running_validate(py_avr_wrapper * py){
	puts("running"); return 0;
}
int epilogue_validate(py_avr_wrapper * py){
	puts("epilogue"); return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 2){
		fprintf(stderr, "usage: <exe> <avr exe path>\n");
		return 1;
	}

	py_avr_wrapper * py = py_sim_init(argv[1], "atmega328p", true);
	
	avr_t *avr = py->avr;
	uint32_t stop_addr = py->stop_addr;
	

	avr->gdb_port = 1234;
	if (0) {
		avr->state = cpu_Stopped;
		avr_gdb_init(avr);
	}
	
	//printf("%x, %x, %x\n", avr->ramend, avr->flashend, avr->e2end);
	print_symbols(py);
	uint8_t * e2e = get_data_at_label(py, "E2E_SWITCH", NULL);
	e2e[0] = 1; //turn on running
	//mprintf("%hhx, %hhx\n", py->avr->data[32 + 0x3d], py->avr->data[32 + 0x3e]);
	/*
	for (int i = 0; i < 10; i++){
		printf("running function woah (%d out of %d):\n", i, 10);
		args[0] = rand(), args[1] = rand();
		printf("with arguments %hhu, %hhu\n", args[0], args[1]); 
		int res = supervise_func_all(
			py,
			"woah",
			"AVRBIND_woah_BEGIN",
			"AVRBIND_woah_END",
			args,
			2,
			20,
			prologue_validate,
			running_validate,
			woah_validate,
			epilogue_validate
		);
		if (res == 1){
			puts("symbol cannot be found");
		} else if (res == 2){
			puts("the function did not return or took too long");
		} else { //validate a
			puts("things went smoothly");
		}
	}
	*/
	
	int state = cpu_Running;
	while ((state != cpu_Done) && (state != cpu_Crashed)){
		state = avr_run(avr);
		if (avr->pc == stop_addr){
			puts("finished");
			avr->state = cpu_Done;
			state = cpu_Done;
		} else {}
	}
	
	puts("done");
	
}
