#include"Func.h"

Laptop* mem_for_struct_array(int size) {
	Laptop* tmp = (Laptop*)malloc(size * sizeof(Laptop));
	return tmp;
}

int enum_push(int num) {
	if (num == 4) return LOW;
	if (num == 8) return MEDIUM;
	if (num == 16) return HIGH;
	return -1;
}

int symbol_check(char* str) {
	int c = str[0];
	return c;
}

void str_swap(Laptop** array, const char* str1, const char* str2, int index) {
	Laptop buf;
	if (symbol_check(str1) > symbol_check(str2)){
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

void push_laptop_in_array(Laptop lap, Laptop** array, int* size) {
	(*size)++;
	if ((*array) == NULL) {
		(*array) = (Laptop*)malloc((*size) * sizeof(lap));
	}
	else {
		(*array) = (Laptop*)realloc((*array), (*size) * sizeof(lap));
	}
	(*array)[(*size) - 1] = lap;
}

char* input_str() {
	char* string = (char*)calloc(256, sizeof(char));
	gets_s(string, 255);
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

int input_k_num(int* size) {
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

void output(Laptop** array, int* size) {
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

void sort_one_field(Laptop** array, int* size) {
	int choice = 0;
	printf("\nChoice sort by: 1 - Name | 2 - Cost | 3 - SSD | 4 - RAM\n");
	printf("Your choice: ");
	choice = choice_for_sort();
	switch (choice) {
	case 1:
		for (int i = 0; i < (*size) - 1; i++) {
			for (int j = 0; j < (*size) - 1; j++) {
				str_swap(array, (*array)[j].name, (*array)[j + 1].name, j);
			}
		}
		break;
	case 2:
		for (int i = 0; i < (*size) - 1; i++) {
			for (int j = 0; j < (*size) - 1; j++) {
				digit_swap(array, (*array)[j].cost, (*array)[j + 1].cost, j);
			}
		}
		break;
	case 3:
		for (int i = 0; i < (*size) - 1; i++) {
			for (int j = 0; j < (*size) - 1; j++) {
				digit_swap(array, (*array)[j].ssd_mem, (*array)[j + 1].ssd_mem, j);
			}
		}
		break;
	case 4: 
		for (int i = 0; i < (*size) - 1; i++) {
			for (int j = 0; j < (*size) - 1; j++) {
				digit_swap(array, (*array)[j].ram_mem, (*array)[j + 1].ram_mem, j);
			}
		}
		break;
	default:
		exit(0);
	}
}

void sort_two_fields(Laptop** array, int* size) {
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

void sort(Laptop** array, int* size) {
	int choice = 0;
	printf("\n----- SORT -----\n");
	printf("Pick a type of sort\n");
	printf("1 - Sort by one field\n");
	printf("2 - Sort by cost and RAM\n");
	printf("----------------\n");
	printf("Your choice: ");
	choice = choice_for_sort_menu();
	switch (choice) {
	case 1:
		sort_one_field(array, size);
		output(array, size);
		break;
	case 2:
		sort_two_fields(array, size);
		output(array, size);
		break;
	default:
		exit(0);
	}
}

void delete(Laptop** array, int* size) {
	int k = 0;
	printf("\n--------------- DELETE ---------------\n");
	printf("Enter a number of a laptop to delete: ");
	k = input_k_num(size);
	free((*array)[k - 1].name);
	for (int i = (k - 1); i < (*size); i++) {
		(*array)[i] = (*array)[i + 1];
	}
	(*size)--;
	(*array) = (Laptop*)realloc((*array), (*size) * sizeof(Laptop));
	printf("\n--- LAPTOP NUMBER %d WAS DELETED ---\n", k);
	printf("--------------------------------------\n");
	output(array, size);
}

void init_laptop(Laptop** array, int* size) {
	Laptop tmp;
	printf("\n--------- INIT LAPTOP ---------\n");
	printf("Enter a name of laptop: ");
	tmp.name = input_str();
	printf("\nEnter a cost (in Rubles) of %s: ", tmp.name);
	tmp.cost = input_cost();
	printf("\nEnter a RAM (4GB/8GB/16GB) of %s: ", tmp.name);
	tmp.ram_mem = enum_push(input_ram());
	printf("\nEnter a SSD (128GB/256GB/512GB/1024GB) capacity of %s: ", tmp.name);
	tmp.ssd_mem = input_ssd();
	push_laptop_in_array(tmp, array, size);
	printf("---------------------------------\n");
	output(array, size);
}

void init_new_array(Laptop** array, int* size) {
	for (int i = (*size) - 1; i >= 0; i--) {
		free((*array)[i].name);
		(*size)--;
		(*array) = (Laptop*)realloc((*array), (*size) * sizeof(Laptop));
	}
	printf("\n-------------------------\n");
	printf("--- ARRAY WAS DELETED ---\n");
	printf("-------------------------\n");
	init_laptop(array, size);
}

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
	menu_info();
	choice = choice_menu();
	switch (choice) {
	case 1:
		output(array, size);
		menu(array, size);
		break;
	case 2:
		init_laptop(array, size);
		menu(array, size);
		break;
	case 3:
		delete(array, size);
		menu(array, size);
		break;
	case 4:
		sort(array, size);
		menu(array, size);
		break;
	case 5:
		init_new_array(array, size);
		menu(array, size);
		break;
	case 6:
		exit(2);
		break;
	default:
		exit(0);
	}
}
