#include<stdio.h>
int main() {
	int a, n;
	printf("Enter a numder a:\n");
	if ((scanf_s("%d", &a) == 0) || a == 0 || a < 0) {
		printf("\nYou need to write a numbers or the correct numbers\n");
		return 0;
    }
	for (int i = 1; i <= a; i++)
    n = i + 1;
    printf("\nThe smallest n > a is: %d\n", n);
    return 0;
}