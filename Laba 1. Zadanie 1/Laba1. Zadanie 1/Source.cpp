#include<stdio.h>
	int function(int x, int y) {
		int e = 1;
		for (int i = 0; i < y; i++)
		{
			e = e * x;
		}
		return e;
        }
	int main() {
		int b, q, n, sum;
		printf("Enter a number b, q, n:\n");
		if (scanf_s("%d", &b) == 0 || scanf_s("%d", &q) == 0 || scanf_s("%d", &n) == 0 || b == 0 && q == 0 && n == 0) {
			printf("\nYou need to write a numbers or a correct numbers\n");
			return 0;
		}
		sum = (b * (function(q, n) - 1) / (q - 1));
		printf("\nThe sum of the terms of the geometric progression: %d\n", sum);
        return 0;
	}

	

















	


    
	


