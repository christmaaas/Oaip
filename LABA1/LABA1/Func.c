#include"Func.h"

ram enum_push(int num) {
	if (num == 4) return LOW;
	if (num == 8) return MEDIUM;
	if (num == 16) return HIGH;
}

void push_laptop_in_array(Laptop lap, Laptop** array, int* size) {
	(*size)++;
	if ((*array) == NULL) {
		(*array) = (Laptop*)malloc((*size) * sizeof(lap));
	}
	else (*array) = (Laptop*)realloc((*array), (*size) * sizeof(lap));
	(*array)[(*size) - 1] = lap;
}

void input_str(char** string) {
	int N = 256;
	(*string) = (char*)malloc(N * sizeof(char));
	int i = 0;
	while (((*string)[i] = getchar()) != '\n' && (*string)[i] != EOF) {
		i++;
		if (i == N) {
			N *= 2;
			(*string)[i] = (char*)realloc((*string), N * sizeof(char));
		}
	}
	(*string) = (char*)realloc((*string), (i + 1) * sizeof(char));
	(*string)[i] = '\0';
}

int choice_menu(int choice) {
	while (scanf_s("%d", &choice) == 0 || choice <= 0 || choice > 6 || getchar() != '\n') {
		printf("\nYou need to pick 1 - 6: ");
		rewind(stdin);
	}
	return choice;
}

int choice_for_sort(int choice) {
	while (scanf_s("%d", &choice) == 0 || choice < 1 || choice > 5 || getchar() != '\n') {
		printf("\nYou need to pick 1 - 5: ");
		rewind(stdin);
	}
	return choice;
}

int choice_for_sort_menu(int choice) {
	while (scanf_s("%d", &choice) == 0 || choice < 1 || choice > 2 || getchar() != '\n') {
		printf("\nYou need to pick 1 - 2: ");
		rewind(stdin);
	}
	return choice;
}

int input_k_num(int num, int* size) {
	while (scanf_s("%d", &num) == 0 || num <= 0 || num > (*size) || getchar() != '\n') {
		printf("\nPick a correct cost\n");
		rewind(stdin);
	}
	return num;
}

int input_cost(int num) {
	while (scanf_s("%d", &num) == 0 || getchar() != '\n') {
		printf("\nPick a correct cost\n");
		rewind(stdin);
	}
	return num;
}

int input_ssd(int num) {
	while (scanf_s("%d", &num) == 0 || num < 128 || (num > 128 && num < 256) || (num > 256 && num < 512) || (num > 512 && num < 1024) || num > 1024 || getchar() != '\n') {
		printf("\nPick a correct SSD capacity\n");
		rewind(stdin);
	}
	return num;
}

int input_ram(int num) {
	while (scanf_s("%d", &num) == 0 || num < 4 || (num > 4 && num < 8) || (num > 8 && num < 16) || num > 16 || getchar() != '\n') {
		printf("\nPick a correct RAM capacity\n");
		rewind(stdin);
	}
	return num;
}

Laptop* mem_for_struct_array(int size) {
	Laptop* tmp = (Laptop*)malloc(size * sizeof(Laptop));
	return tmp;
}

void output(Laptop** array, int* size) {
	for (int i = 0; i < (*size); i++) {
		printf("\n------- LAPTOP -------\n");
		printf("%s\n", (*array)[i].name);
		printf("----- PARAMETERS -----\n");
		printf("Cost: %d$\n", (*array)[i].cost);
		printf("CPU: %s\n", (*array)[i].cpu);
		printf("RAM: %d GB\n", (*array)[i].ram_mem);
		printf("SSD: %d GB\n", (*array)[i].ssd_mem);
		printf("----------------------\n");
	}
}

int symbol_check(char* str) {
	int c = str[0];
	return c;
}

void sort_one_field(Laptop** array, int* size) {
	int i, j, choice = 0;
	Laptop buf;
	printf("\nChoice sort by: 1 - Name | 2 - CPU | 3 - Cost | 4 - SSD | 5 - RAM\n");
	printf("Your choice: ");
	choice = choice_for_sort(choice);
	switch (choice) {
	case 1:
		for (i = 0; i < (*size) - 1; i++) {
			for (j = 0; j < (*size) - 1; j++) {
				if (symbol_check((*array)[j].name) > symbol_check((*array)[j + 1].name)) {
					buf = (*array)[j];
					(*array)[j] = (*array)[j + 1];
					(*array)[j + 1] = buf;
				}
			}
		}
		break;
	case 2:
		for (i = 0; i < (*size) - 1; i++) {
			for (j = 0; j < (*size) - 1; j++) {
				if (symbol_check((*array)[j].cpu) > symbol_check((*array)[j + 1].cpu)) {
					buf = (*array)[j];
					(*array)[j] = (*array)[j + 1];
					(*array)[j + 1] = buf;
				}
			}
		}
		break;
	case 3:
		for (i = 0; i < (*size) - 1; i++) {
			for (j = 0; j < (*size) - 1; j++) {
				if ((*array)[j].cost > (*array)[j + 1].cost) {
					buf = (*array)[j];
					(*array)[j] = (*array)[j + 1];
					(*array)[j + 1] = buf;
				}
			}
		}
		break;
	case 4:
		for (i = 0; i < (*size) - 1; i++) {
			for (j = 0; j < (*size) - 1; j++) {
				if ((*array)[j].ssd_mem > (*array)[j + 1].ssd_mem) {
					buf = (*array)[j];
					(*array)[j] = (*array)[j + 1];
					(*array)[j + 1] = buf;
				}
			}
		}
		break;
	case 5: 
		for (i = 0; i < (*size) - 1; i++) {
			for (j = 0; j < (*size) - 1; j++) {
				if ((*array)[j].ram_mem > (*array)[j + 1].ram_mem) {
					buf = (*array)[j];
					(*array)[j] = (*array)[j + 1];
					(*array)[j + 1] = buf;
				}
			}
		}
		break;
	}
}

void sort_two_fields(Laptop** array, int* size) {
	int i, j;
	Laptop buf;
	for (i = 0; i < (*size) - 1; i++) {
		for (j = 0; j < (*size) - 1; j++) {
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
	choice = choice_for_sort(choice);
	switch (choice) {
	case 1:
		sort_one_field(array, size);
		output(array, size);
		break;
	case 2:
		sort_two_fields(array, size);
		output(array, size);
		break;
	}
}

void delete(Laptop** array, int* size) {
	int i, k = 0;
	printf("\nEnter a number of a laptop to delete: ");
	k = input_k_num(k, size);
	free((*array)[k - 1].name);
	free((*array)[k - 1].cpu);
	for (i = (k - 1); i < (*size); i++) {
		(*array)[i] = (*array)[i + 1];
	}
	(*size)--;
	(*array) = (Laptop*)realloc((*array), (*size) * sizeof(Laptop));
	printf("\n--- LAPTOP NUMBER %d WAS DELETED ---\n", k);
	output(array, size);
}

void init_laptop(Laptop** array, int* size) {
	Laptop tmp;
	printf("\n--------- INIT LAPTOP ---------\n");
	printf("Enter a name of laptop: ");
	input_str(&tmp.name);
	printf("\nEnter a CPU of %s: ", tmp.name);
	input_str(&tmp.cpu);
	printf("\nEnter a cost (in $) of %s: ", tmp.name);
	tmp.cost = input_cost(tmp.cost);
	printf("\nEnter a SSD (128GB/256GB/512GB/1024GB) capacity of %s: ", tmp.name);
	tmp.ssd_mem = input_ssd(tmp.ssd_mem);
	printf("\nEnter a RAM (4GB/8GB/16GB) of %s: ", tmp.name);
	tmp.ram_mem = enum_push(input_ram(tmp.ram_mem));
	push_laptop_in_array(tmp, array, size);
	printf("---------------------------------\n");
	output(array, size);
}

void init_new_array(Laptop** array, int* size) {
	for (int i = (*size) - 1; i >= 0; i--) {
		free((*array)[i].name);
		free((*array)[i].cpu);
		(*size)--;
		(*array) = (Laptop*)realloc((*array), (*size) * sizeof(Laptop));
	}
	printf("\n--- ARRAY WAS DELETED ---\n");
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
	choice = choice_menu(choice);
	switch (choice) {
	case 1:
		output(array, size);
		menu(array, size);
	case 2:
		init_laptop(array, size);
		menu(array, size);
	case 3:
		delete(array, size);
		menu(array, size);
	case 4:
		sort(array, size);
		menu(array, size);
	case 5:
		init_new_array(array, size);
		menu(array, size);
	case 6:
		exit(2);
	}
}
