#include"functions.h"

int pick_answer() {
	int pick = 0;
	while (scanf_s("%d", &pick) == 0 || pick < 1 || pick > 2 || getchar() != '\n') {
		printf("\nYou need to pick 1 or 2: ");
		rewind(stdin);
	}
	return pick;
}