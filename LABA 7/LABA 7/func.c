#include"Header.h"

int len_string(char** string) {
	int temp = 0;
	while ((*string)[temp] != '\0') {
		temp++;
	}
	return temp;
}

int max_len_word(char* string, int len_of_string, int* second_len_of_string) {
	int len_of_string_with_max_word = 0;
	int max_word = 0;
	while (len_of_string_with_max_word < len_of_string) {
		int len_of_max_word = 0;
		while (len_of_string_with_max_word < len_of_string && string[len_of_string_with_max_word] != ' ') {
			len_of_string_with_max_word++;
			len_of_max_word++;
		}
		len_of_string_with_max_word++;
		if (len_of_max_word > max_word) {
			max_word = len_of_max_word;
			*second_len_of_string = len_of_string_with_max_word;
		}
	}
	return max_word;
}

void output(char* string, int max_word_start, int second_len_of_string) {
	printf("\nMax word: ");
	for (int i = max_word_start - 1; i < second_len_of_string; i++) // -1
		printf("%c", string[i]);
}

void input(char** string) {
	/*int N = 256;
	(*string) = (char*)malloc(N * sizeof(char));
	int i = 0;
	while (((*string)[i] = getchar()) != '\n' && (*string)[i] != EOF) {
		i++;
		if (i == N) {
			N *= 2;
			(*string)[i] = (char*)realloc((*string), N * sizeof(char));
		}
	}
	(*string) = (char*)realloc((*string), (i + 1) * sizeof(char));
	(*string)[i] = '\0';*/
	int symbol;
	int i = 0;
	int N = 256;
	rewind(stdin);
	while ((symbol = getchar()) != EOF && symbol != '\n')
	{
		(*string)[i++] = symbol;
		if (i == N) {
			N *= 2;
			(*string)[i] = (char*)realloc((*string), N * sizeof(char));
		}
	}
	(*string)[i] = '\0';
}

int choice_fun(int choice) {
	printf("Task list: 1 - First task, 2 - Second task, 3 - Exit\n");
	printf("Your choice: ");
	while (scanf_s("%d", &choice) == 0 || choice > 3 || choice < 1 || getchar() != '\n') {
		printf("You need to write correct numbers\n");
		printf("Your choice: ");
		rewind(stdin);
	}
	return choice;
}

void change_to_space(char** string, int len_of_string) {
	int j = 0;
	while ((*string)[j] != '\0') {
		if ((*string)[j] == '.' || (*string)[j] == ',' || 
			(*string)[j] == '-' || (*string)[j] == '_' || 
			(*string)[j] == '=' || (*string)[j] == '?' || 
			(*string)[j] == '!' || (*string)[j] == '(' || 
			(*string)[j] == ')' || (*string)[j] == '[' || 
			(*string)[j] == ']' || (*string)[j] == '{' || 
			(*string)[j] == '}' || (*string)[j] == ';' || 
			(*string)[j] == ':');
		(*string)[j] = ' ';
		j++;
	}
}

int find_first_word(char** string, int len_of_string) {
	int iofS = 0; // iofS - index of start of first word
	int iofE = 0; // iofE - index of end of first word
	while ((*string)[iofS] == ' ' && (*string)[iofS] != '\0')
		iofS++;
	iofE = iofS;
	while ((*string)[iofE] >= 'a' && (*string)[iofE] <= 'z' || (*string)[iofE] >= 'A' && (*string)[iofE] <= 'Z' && (*string)[iofE] != ' ' && (*string)[iofE] != '\0') {
		iofE++;
	}
	int len = iofE - iofS;
	return len;
}

void back_to_menu() {
	printf("\nPress ENTER to back to menu\n");
	while (getchar() == '\n')
		main();
}

void delete_word(char** string1, char** string2, int len_of_string1, int len_of_string2) {
	int len_of_fw = find_first_word(string2, len_of_string2); // len_of_fw - length of first word
	for (int i = 0; i < len_of_string1; i++) {
		int j = 0;
		while ((*string1)[i] == (*string2)[j] && (*string1)[i] != '\0' && (*string2)[j] != ' ') {
			i++;
			j++;
		}
		if (j == len_of_fw) {
			int k = (i - len_of_fw);
			while ((*string1)[k + len_of_fw] != '\0')
			{
				(*string1)[k] = (*string1)[k + len_of_fw];
				k++;
			}
			(*string1) = (char*)realloc((*string1), (len_of_string1 - len_of_fw + 1) * sizeof(char));
			(*string1)[k] = '\0';
			break;
		}

	}
}

int task1() {
	char* string = (char*)malloc(256);
	int len_of_string = 0, max_word = 0, second_len_of_string = 0, max_word_start = 0;
	printf("\nTask: Find a max length word: \n");
	printf("Enter a string: ");
	input(&string);
	len_of_string = len_string(&string);
	max_word = max_len_word(string, len_of_string, &second_len_of_string);
	max_word_start = second_len_of_string - max_word;
	output(string, max_word_start, second_len_of_string);
	printf("\n");
	free(string);
	back_to_menu();
}

int task2() {
	char* string1 = (char*)malloc(256);
	char* string2 = (char*)malloc(256);
	int len_of_string1 = 0, len_of_string2 = 0;
	printf("\nTask: Delete first word from second string in first string\n");
	printf("Enter a first string: ");
	input(&string1);
	printf("Enter a second string: ");
	input(&string2);
	len_of_string1 = len_string(&string1);
	len_of_string2 = len_string(&string2);
	delete_word(&string1, &string2, len_of_string1, len_of_string2);
	printf("\nNew string: %s", string1);
	free(string1);
	free(string2);
	back_to_menu();
}
int end() {
	return 0;
}