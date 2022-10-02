#include <stdio.h>
int main() {
	int array[100], arraysize, sum1 = 0, sum2 = 0, firstnegative = 0, lastnegative = 0;
	printf("Enter the size of the array: ");
	if (scanf_s("%d", &arraysize) == 0 || arraysize < 1 || arraysize > 100) {
		printf("\nYou need to write a correct numbers\n");
		return 0;
	}
	for (int i = 0; i < arraysize; i++) {
		printf("Number %d: ", i + 1);
		scanf_s("%d", &array[i]);
		if (i % 2 != 0)
			sum1 += array[i];
	}
	for (firstnegative = 0; firstnegative < arraysize; firstnegative++) {
		if (array[firstnegative] < 0) break;
	}
	for (lastnegative = arraysize - 1; lastnegative > firstnegative; lastnegative--) {
		if (array[lastnegative] < 0) break;
	}
	for (int i = firstnegative + 1; i < lastnegative; i++) {
		sum2 += array[i];
	}
	printf("\nSum of odd elements: %d\n", sum1);
	printf("\nSum of elements between first negative and last negative: %d\n", sum2);
	return 0;
}