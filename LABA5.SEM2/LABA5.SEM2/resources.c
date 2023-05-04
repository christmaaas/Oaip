
#include "resources.h"

char* input_str() {
	char* string = (char*)calloc(MAX_SIZE_OF_STRING, sizeof(char));

	gets_s(string, MAX_SIZE_OF_STRING);

	int size = strlen(string);

	string = (char*)realloc(string, size + 1);

	return string;
}

int valid_ip_check(char* str) {
	if (str == NULL) {
		return WRONG_INPUT;
	}

	int arr[MAX_IP_COMPONENTS];
	int counter = sscanf_s(str, "%d.%d.%d.%d", &arr[0], &arr[1], &arr[2], &arr[3]);
	
	if (counter != MAX_IP_COMPONENTS) {
		return WRONG_INPUT;
	}
	
	for (int i = 0; i < MAX_IP_COMPONENTS; i++) {
		if (arr[i] < 0 || arr[i] > MAX_IP_VALUE) {
			return WRONG_INPUT;
		}
	}
	
	return RIGHT_IP_ADRESS;
}

int choice_menu() {
	int choice = 0;

	while (scanf_s("%d", &choice) == 0 || choice < 1 || choice > 3 || getchar() != '\n') {
		printf("\nWRONG INPUT: You need to pick 1 - 3: ");
		rewind(stdin);
	}

	return choice;
}

int choice_domen_type() {
	int choice = 0;
	
	while (scanf_s("%d", &choice) == 0 || choice < 1 || choice > 3 || getchar() != '\n') {
		printf("\nYou need to pick 1 or 3: ");
		rewind(stdin);
	}
	
	return choice;
}

int find_pattern(char* string, char* pattren) {
	int i = 0; 
	int j = 0;
	int searched_index = 0;
	
	for (i = 0; string[i] != NULL_TERMINATOR; i++) {
		
		j = 0;
		searched_index = i; 
		
		while (pattren[j] != NULL_TERMINATOR && string[searched_index] == pattren[j]) {
			searched_index++;
			j++;
		}
		
		if (pattren[j] == NULL_TERMINATOR) {
			return searched_index;
		}
	}
	
	return NOT_FOUNDED;
}

FILE* file_open(const char* file_name, const char* mode) {
	FILE* file = NULL;
	errno_t error;

	error = fopen_s(&file, file_name, mode);

	if (error != 0) {
		exit(FILE_ERROR);
	}

	return file;
}

void menu_info() {
	printf("\n----- MENU -----\n");
	printf("1 - Search IP by domain\n");
	printf("2 - Search domain by IP\n");
	printf("3 - Exit\n");
	printf("----------------\n");
	printf("Your choice: ");
}
