#include<stdio.h>
int main() {
	int number;
	printf("Enter a number that will be converted to a Roman number:\n");
	if (scanf_s("%d", &number) == 0 || number > 10 || number < 0) {
		printf("\nYou need to write a correct numbers\n");
		return 0;
	}
    switch (number) {
	case 0:
		printf("\nThe number 0 does not exist in the Roman numeral system\n");
		break;
	case 1:
		printf("\nRoman number: I\n");
		break;
	case 2:
		printf("\nRoman number: II\n");
		break;
	case 3:
		printf("\nRoman number: III\n");
		break;
	case 4:
		printf("\nRoman number: IV\n");
		break;
	case 5:
		printf("\nRoman number: V\n");
		break;
	case 6:
		printf("\nRoman number: VI\n");
		break;
	case 7:
		printf("\nRoman number: VII\n");
		break;
	case 8:
		printf("\nRoman number: VIII\n");
		break;
	case 9:
		printf("\nRoman number: IX\n");
		break;
	case 10:
		printf("\nRoman number: X\n");
		break;
	}
	return 0;
}