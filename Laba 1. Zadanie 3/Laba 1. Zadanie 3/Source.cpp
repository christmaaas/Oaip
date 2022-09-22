#include<stdio.h>
int main() {
	int R, a;
	const float root = 1.41421356;
	printf("Enter the radius of the circle and the side of the square:\n");
	if (scanf_s("%d", &R) == 0 || scanf_s("%d", &a) == 0 || a <= 0 || R <= 0 || a <= 0 && R <= 0) {
		printf("\nYou need to write only a numbers or a correct numbers\n");
		return 0;
	}
	int D = 2 * R, d = a * root;
	if (a >= D)
		printf("\nThe circle will fit in a square\n");
	else
		printf("\nThe circle will not fit in a square\n");
	if (d <= D)
		printf("\nThe square will fit into the circle\n");
	else
		printf("\nThe square will not fit into the circle\n");
	return 0;
}
