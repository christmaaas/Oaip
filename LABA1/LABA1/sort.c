#include "sort.h"
#include "struct.h"
#include "recources.h"

void sort_one_field(Laptop** array, const int* size) {
	int choice = 0;
	
	printf("\nChoice sort by: 1 - Name | 2 - Cost | 3 - SSD | 4 - RAM\n");
	printf("Your choice: ");
	
	choice = choice_for_sort();
	
	switch (choice) {
		case SORT_BY_NAME:
			for (int i = 0; i < (*size) - 1; i++) {
				for (int j = 0; j < (*size) - 1; j++) {
					str_swap(array, (*array)[j].name, (*array)[j + 1].name, j);
				}
			}
			break;
		case SORT_BY_COST:
			for (int i = 0; i < (*size) - 1; i++) {
				for (int j = 0; j < (*size) - 1; j++) {
					digit_swap(array, (*array)[j].cost, (*array)[j + 1].cost, j);
				}
			}
			break;
		case SORT_BY_SSD:
			for (int i = 0; i < (*size) - 1; i++) {
				for (int j = 0; j < (*size) - 1; j++) {
					digit_swap(array, (*array)[j].ssd_mem, (*array)[j + 1].ssd_mem, j);
				}
			}
			break;
		case SORT_BY_RAM:
			for (int i = 0; i < (*size) - 1; i++) {
				for (int j = 0; j < (*size) - 1; j++) {
					digit_swap(array, (*array)[j].ram_mem, (*array)[j + 1].ram_mem, j);
				}
			}
			break;
		default:
			exit(PROGRAM_ERROR);
	}
}

void sort_two_fields(Laptop** array, const int* size) {
	Laptop buf;
	
	for (int i = 0; i < (*size) - 1; i++) {
		for (int j = 0; j < (*size) - 1; j++) {
			if (((*array)[j].cost > (*array)[j + 1].cost) || ((*array)[j].cost == (*array)[j + 1].cost) && ((*array)[j].ram_mem > (*array)[j + 1].ram_mem)) {
				buf = (*array)[j];
				(*array)[j] = (*array)[j + 1];
				(*array)[j + 1] = buf;
			}
		}
	}
}

void sort(Laptop** array, const int* size) {
	int choice = 0;
	
	output_sort_menu();

	choice = choice_for_sort_menu();
	
	switch (choice) {
		case SORT_BY_ONE_FIELD:
			sort_one_field(array, size);
			output(array, size);
			break;
		case SORT_BY_TWO_FIELDS:
			sort_two_fields(array, size);
			output(array, size);
			break;
		default:
			exit(PROGRAM_ERROR);
	}
}

int symbol_check(const char* str) {
	int c = str[0];
	return c;
}

void str_swap(Laptop** array, const char* str1, const char* str2, int index) {
	Laptop buf;
	if (symbol_check(str1) > symbol_check(str2)) {
		buf = (*array)[index];
		(*array)[index] = (*array)[index + 1];
		(*array)[index + 1] = buf;
	}
}

void digit_swap(Laptop** array, const int num1, const int num2, int index) {
	Laptop buf;
	if (num1 > num2) {
		buf = (*array)[index];
		(*array)[index] = (*array)[index + 1];
		(*array)[index + 1] = buf;
	}
}