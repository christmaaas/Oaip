#include "menu.h"
#include "morse.h"
#include "resources.h"

int choice_menu() {
	int choice = 0;

	while (scanf_s("%d", &choice) == 0 || choice < 1 || choice > 5 || getchar() != '\n') {
		printf("\nWRONG INPUT: You need to pick 1 - 5: ");
		
		rewind(stdin);
	}

	return choice;
}

void menu_info() {
	printf("\n----- MENU -----\n");
	printf("1 - Encrypt string\n");
	printf("2 - Decrypt string\n");
	printf("3 - Encrypt file\n");
	printf("4 - Decrypt file\n");
	printf("5 - Exit\n");
	printf("----------------\n");
	printf("Your choice: ");
}

void menu() {
	int choice = 0;

	do {
		menu_info();

		choice = choice_menu();

		switch (choice) {
			case ENCRYPT_STRING:
				morse_encrypt_string();
				break;
			case DECRYPT_STRING:
				morse_decrypt_string();
				break;
			case ENCRYPT_FILE:
				morse_encrypt_file();
				break;
			case DECRYPT_FILE:
				morse_decrypt_file();
				break;
			case EXIT:
				return;
			default:
				exit(PROGRAMM_ERROR);
		}
	} while (choice != EXIT);
}