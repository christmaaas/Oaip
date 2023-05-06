#include "recources.h"
#include "struct.h"

char* input_str() {
	char* string = (char*)calloc(MAX_SIZE_OF_STRING, sizeof(char));
	gets_s(string, MAX_SIZE_OF_STRING);
	
	int size = strlen(string);

	string = (char*)realloc(string, size + 1);
	
	return string;
}

int choice_menu() {
	int choice = 0;
	
	while (scanf_s("%d", &choice) == 0 || choice <= 0 || choice > 6 || getchar() != '\n') {
		printf("\nYou need to pick 1 - 6: ");
		rewind(stdin);
	}
	
	return choice;
}

int choice_for_sort() {
	int choice = 0;
	
	while (scanf_s("%d", &choice) == 0 || choice < 1 || choice > 5 || getchar() != '\n') {
		printf("\nYou need to pick 1 - 5: ");
		rewind(stdin);
	}
	
	return choice;
}

int choice_for_sort_menu() {
	int choice = 0;
	
	while (scanf_s("%d", &choice) == 0 || choice < 1 || choice > 2 || getchar() != '\n') {
		printf("\nYou need to pick 1 - 2: ");
		rewind(stdin);
	}
	
	return choice;
}

int input_k_num(const int* size) {
	int k = 0;
	
	while (scanf_s("%d", &k) == 0 || k <= 0 || k > (*size) || getchar() != '\n') {
		printf("\nPick a correct laptop to delete\n");
		rewind(stdin);
	}
	
	return k;
}

int input_cost() {
	int cost = 0;
	
	while (scanf_s("%d", &cost) == 0 || getchar() != '\n') {
		printf("\nPick a correct cost\n");
		rewind(stdin);
	}
	
	return cost;
}

int input_ssd() {
	int ssd = 0;
	
	while (scanf_s("%d", &ssd) == 0 || ssd < 128 || (ssd > 128 && ssd < 256) || (ssd > 256 && ssd < 512) || (ssd > 512 && ssd < 1024) || ssd > 1024 || getchar() != '\n') {
		printf("\nPick a correct SSD capacity\n");
		rewind(stdin);
	}
	
	return ssd;
}

int input_ram() {
	int ram = 0;
	
	while (scanf_s("%d", &ram) == 0 || ram < 4 || (ram > 4 && ram < 8) || (ram > 8 && ram < 16) || ram > 16 || getchar() != '\n') {
		printf("\nPick a correct RAM capacity\n");
		rewind(stdin);
	}
	
	return ram;
}

int enum_push(int num) {
	if (num == 4) return LOW;
	if (num == 8) return MEDIUM;
	if (num == 16) return HIGH;
	return -1;
}

void output(Laptop** array, const int* size) {
	for (int i = 0; i < (*size); i++) {
		printf("\n------- LAPTOP -------\n");
		printf("%s\n", (*array)[i].name);
		
		printf("----- PARAMETERS -----\n");
		printf("Cost: %d$\n", (*array)[i].cost);
		printf("RAM: %d GB\n", (*array)[i].ram_mem);
		printf("SSD: %d GB\n", (*array)[i].ssd_mem);
		printf("----------------------\n");
	}
}

void output_sort_menu() {
	printf("\n----- SORT -----\n");
	printf("Pick a type of sort\n");
	printf("1 - Sort by one field\n");
	printf("2 - Sort by cost and RAM\n");
	printf("----------------\n");
	printf("Your choice: ");
}
