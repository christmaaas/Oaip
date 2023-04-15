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
	char* string = (char*)calloc(256, sizeof(char));
	gets_s(string, 255);
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