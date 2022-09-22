#include<stdio.h>
int main() {
	int S = 0, P = 1, n;
	printf("Enter a number n:\n");
	if ((scanf_s("%d", &n) == 0 || n < 3)) {
		printf("\nYou don't have numbers that are multiples of 3 or you entered negative numbers\n");
		return 0;
	}
    for (int i = 3; i <= n; i = i + 3) {
		S = S + i;
		P = P * i;
    }
	printf("\nSum: %d\nComposition: %d\n", S, P);
    return 0;
}
    