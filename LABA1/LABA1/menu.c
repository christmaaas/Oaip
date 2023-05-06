#include "menu.h"
#include "struct.h"
#include "recources.h"
#include "sort.h"
#include "array.h"

void menu_info() {
	printf("\n----- MENU -----\n");
	printf("1 - Output array\n");
	printf("2 - Add laptop in array\n");
	printf("3 - Delete laptop from array\n");
	printf("4 - Sort array\n");
	printf("5 - Initialized new array\n");
	printf("6 - Exit\n");
	printf("----------------\n");
	printf("Your choice: ");
}

void menu(Laptop** array, int* size) {
	int choice = 0;

	do {
		menu_info();

		choice = choice_menu();

		switch (choice) {
		case OUTPUT_ARRAY:
			output(array, size);
			break;
		case ADD_LAPTOP:
			init_laptop(array, size);
			break;
		case DELETE_LAPTOP:
			delete(array, size);
			break;
		case SORT_ARRAY:
			sort(array, size);
			break;
		case NEW_ARRAY:
			init_new_array(array, size);
			break;
		case EXIT:
			exit(EXIT_CODE);
		default:
			exit(PROGRAMM_ERROR);
		}
	} while (choice != EXIT);
}