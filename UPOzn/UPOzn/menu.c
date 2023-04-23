
#include "menu.h"
#include "morse.h"
#include "log.h"

int choice_menu() {
	int choice = 0;

	while (scanf_s("%d", &choice) == 0 || choice < 1 || choice > 5 || getchar() != '\n') {
		printf("\nWRONG INPUT: You need to pick 1 - 5: ");
		push_log(log_type[ERROR], "Programm error: wrong input", "a");
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

	push_log(log_type[APPLICATION], "Programm runs.", "w");

	do {
		menu_info();

		choice = choice_menu();

		switch (choice) {
		case ENCRYPT_STRING:
			morse_encrypt();
			break;
		case DECRYPT_STRING:
			morse_decrypt();
			break;
		case ENCRYPT_FILE:
			morse_encrypt_file();
			break;
		case DECRYPT_FILE:
			morse_decrypt_file();
			break;
		case EXIT:
			push_log(log_type[APPLICATION], "Programm ends.", "a");
			return;
		default:
			push_log(log_type[ERROR], "Programm error: code -2", "a");
			exit(PROGRAMM_ERROR);
		}
	} while (choice != EXIT);
}