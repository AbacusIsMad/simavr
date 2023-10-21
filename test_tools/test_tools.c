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




avr_symbol_t * get_symbol(py_avr_wrapper * py, const char * label){
	int found = 0, res_idx = 0;
	SGLIB_ARRAY_BINARY_SEARCH(avr_symbol_t*, py->symbol_name_sorted, 0, py->symbolcount, label, search_cmp, found, res_idx);
	if (!found) {
		return NULL;
	}
	avr_symbol_t * symbol = py->symbol_name_sorted[res_idx];
	return symbol;
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

//TODO make program too
uint8_t * get_data_at_label(py_avr_wrapper * py, const char * label, uint32_t * size){
	
	avr_symbol_t * symbol = get_symbol(py, label);
	if (symbol == NULL) return NULL;
	
	*size = symbol->size;
	uint8_t * res = py->avr->data + (symbol->addr - AVR_SEGMENT_OFFSET_DATA);
	/*
	for (int i = 0; i < 0x800; i++){
		if (i % 16 == 0) printf("\n0x%04x: ", i);
		printf("%02x ", py->avr->data[i]);
	}
	putchar('\n');
	*/
	return res;
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
