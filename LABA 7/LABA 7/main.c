#include"Header.h"

void main() {
	int choice = 0;
	int (*task)(void) = NULL;
	choice = choice_fun(choice);
	switch (choice) {
	case 1:
		task = task1;
		task();
		break;
	case 2:
		task = task2;
		task();
		break;
	case 3:
		task = end();
		task();
		break;
	}
}