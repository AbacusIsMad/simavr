#include "util.h"

#include "sglib.h"
#define search_cmp(x, y) (strcmp(((x)->symbol), (y)))

avr_symbol_t * get_symbol(py_avr_wrapper * py, const char * label){
	int found = 0, res_idx = 0;
	SGLIB_ARRAY_BINARY_SEARCH(avr_symbol_t*, py->symbol_name_sorted, 0, py->symbolcount, label, search_cmp, found, res_idx);
	if (!found) {
		return NULL;
	}
	avr_symbol_t * symbol = py->symbol_name_sorted[res_idx];
	return symbol;
}

//TODO make program too
uint8_t * get_data_at_label(py_avr_wrapper * py, const char * label, uint32_t * size){
	
	avr_symbol_t * symbol = get_symbol(py, label);
	if (symbol == NULL) return NULL;
	
	if (size != NULL) *size = symbol->size;
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

uint16_t get_sp(py_avr_wrapper * py){
	return py->avr->data[R_SPL] | (py->avr->data[R_SPH] << 8);
}

avr_flashaddr_t get_ret_addr(py_avr_wrapper * py){
	uint16_t sp = get_sp(py) + 1;
	avr_flashaddr_t res = 0;
	for (int i = 0; i < py->avr->address_size; i++, sp++) {
		res = (res << 8) | py->avr->data[sp];
	}
	res <<= 1;
	return res;
}
