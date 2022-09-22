#include<stdio.h>
float stepen(float x, float y) {
	int e = 1;
	for (int i = 0; i < y; i++)
	{
		e = e * x;
	}
	return e;
}
float factorial(float h) {
	int e = 1;
	for (int i = 1; i <= h; i++)
	{
		e = e * i;
	}
	return e;
}
int main() {
	float X, N, step = 0, res = 0, v2 = 0, v1, v3;
	int fl = 0;
	printf("Enter X and N\n");
	if (scanf_s("%f", &X) == 0 || scanf_s("%f", &N) == 0 || N < 1 || X < 1) {
		printf("\nYou need to write only a numbers or write a correct numbers\n");
		return 0;
	}
	for (float i = 1; i <= N; i = i + 2) {
		fl += 1;
		step = 0 + i;
		v1 = (stepen(X, step)) / (factorial(step));
		v2 = v2 - v1;
		v2 = v2 * (-1);
	}
	if (fl % 2 == 0) v2 = v2 * (-1);
	v3 = (stepen(-1, N) * stepen(X, 2 * N + 1) / factorial(2 * N + 1));
	res = v2 + v3;
    printf("\nResult: %6.1f\n", res);
	return 0;
}