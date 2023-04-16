#include"functions.h"

int pick_answer() {
	int pick = 0;
	while (scanf_s("%d", &pick) == 0 || pick < 1 || pick > 2 || getchar() != '\n') {
		printf("\nYou need to pick 1 or 2: ");
		rewind(stdin);
	}
	return pick;
}

char* input_str() {
	char* string = (char*)calloc(STRING_SIZE, sizeof(char));
	gets_s(string, STRING_SIZE);
	int size = strlen(string);
	string = (char*)realloc(string, size + 1);
	return string;
}

void print_answer() {
	printf("----------------\n");
	printf("1 - Yes | 2 - No\n");
	printf("----------------\n");
	printf("Your answer: ");
}

void delete_symbol(char** string) {
	for (int i = 0; i < strlen((*string)); i++) {
		(*string)[i] = (*string)[i + 1];
	}
	(*string)[strcspn((*string), "\n")] = 0;
}