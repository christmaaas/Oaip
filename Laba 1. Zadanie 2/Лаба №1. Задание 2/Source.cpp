#include<stdio.h>
int main() {
	int a, b, c;
	printf("Enter a number a, b, c:\n");
	if (scanf_s("%d", &a) == 0 || scanf_s("%d", &b) == 0 || scanf_s("%d", &c) == 0) {
		printf("\nYou need to write a numbers\n");
		return 0;
	}
	if (a == -b || a == -c || c == -b)
		printf("\nYou got pair of opposite numbers\n");
	else
		printf("\nNo pair of opposite numbers\n");
	return 0;
}
