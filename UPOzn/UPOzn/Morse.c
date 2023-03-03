#include"Morse.h"
#include"Func.h"

#define arr_size(arr) (sizeof(arr)/sizeof(*arr))

morse_code Table[] = {
	{".-", 'A'},
	{"-...", 'B'},
	{"-.-.", 'C'},
	{"-..", 'D'},
	{".", 'E'},
	{"..-.", 'F'},
	{"--.", 'G'},
	{"....", 'H'},
	{"..", 'I'},
	{".---", 'J'},
	{"-.-", 'K'},
	{".-..", 'L'},
	{"--", 'M'},
	{"-.", 'N'},
	{"---", 'O'},
	{".--.", 'P'},
	{"--.-", 'Q'},
	{".-.", 'R'},
	{"...", 'S'},
	{"-", 'T'},
	{"..-", 'U'},
	{"...-", 'V'},
	{".--", 'W'},
	{"-..-", 'X'},
	{"-.--", 'Y'},
	{"--..", 'Z'},
	{".-", 'a'},
	{"-...", 'b'},
	{"-.-.", 'c'},
	{"-..", 'd'},
	{".", 'e'},
	{"..-.", 'f'},
	{"--.", 'g'},
	{"....", 'h'},
	{"..", 'i'},
	{".---", 'j'},
	{"-.-", 'k'},
	{".-..", 'l'},
	{"--", 'm'},
	{"-.", 'n'},
	{"---", 'o'},
	{".--.", 'p'},
	{"--.-", 'q'},
	{".-.", 'r'},
	{"...", 's'},
	{"-", 't'},
	{"..-", 'u'},
	{"...-", 'v'},
	{".--", 'w'},
	{"-..-", 'x'},
	{"-.--", 'y'},
	{"--..", 'z'},
	{" ", ' '},
	{".-.-.-", '.'},
	{"--..--", ','},
	{"-.-.--", '!'},
	{"..--..", '?'},
	{"  ", '\n'},
	{".----", '1'},
	{"..---", '2'},
	{"...--", '3'},
	{"....-", '4'},
	{".....", '5'},
	{"-....", '6'},
	{"--...", '7'},
	{"---..", '8'},
	{"----.", '9'},
	{"-----", '0'}
};

void morse_encrypt(morse_code* table) {
	int size = (sizeof(table) / sizeof(table[0]));
	printf("Text: ");
	char* str = input_str();
	printf("\nEncrypted text: ");
	for (int i = 0; i < strlen(str); i++) {
		for (int j = 0; j < 68; j++) {
			if (str[i] == table[j].symbol) {
				printf("%s ", table[j].code);
				break;
			}
		}
	}
	printf("\n");
	free(str);
}

void morse_decrypt(morse_code* table) {
	printf("Text: ");
	char* str = input_str();
	char* buf = (char*)calloc(6, 1);
	int i = 0, j = 0;
	printf("\nDecrypted text: ");
	while (str[i] != '\0') {
		j = 0;
		while ((str[i] != ' ') && (str[i] != '\0')) {
			buf[j] = str[i];
			buf[j + 1] = '\0';
			i++;
			j++;
		}
		for (int k = 0; k < 68; k++) {
			if (!strcmp(buf, table[k].code)) {
				printf("%c", table[k].symbol);
				break;
			}
		}
		if (str[i + 1] == ' ') {
			printf("%c", table[52].symbol);
			i++;
		}
		if (str[i] != '\0') {
			i++;
		}
	}
	printf("\n");
	free(str);
	free(buf);
}

void print_file(morse_code* table) {
	FILE* file = NULL;
	char symbol;

	fopen_s(&file, "Encrypt.txt", "r");

	printf("\nText: ");
	symbol = fgetc(file);
	while (!feof(file)) {
		printf("%c", symbol);
		symbol = fgetc(file);
	}
	printf("\n");

	fclose(file);
}

void morse_encrypt_file(morse_code* table) {
	FILE* file = NULL;
	char symbol;
	print_file(table);

	fopen_s(&file, "Encrypt.txt", "r");

	printf("Encrypted text: ");
	symbol = fgetc(file);
	while (!feof(file)) {
		for (int i = 0; i < 68; i++) {
			if (symbol == table[i].symbol) {
				printf("%s ", table[i].code);
			}
		}
		symbol = fgetc(file);
	}
	printf("\n");

	fclose(file);
}

void morse_decrypt_file(morse_code* table) {
	FILE* file = NULL;
	char* buf = (char*)calloc(6, 1);
	char* str = (char*)calloc(512, 1);
	int i = 0, j = 0, k = 0;
	char c = 0;
	print_file(table);

	fopen_s(&file, "Encrypt.txt", "r");

	c = fgetc(file);
	while (!feof(file)) {
		str[i] = c;
		i++;
		c = fgetc(file);
	}

	fclose(file);

	printf("Decrypted text: ");
	while (str[j] != '\0') {
		k = 0;
		while ((str[j] != ' ') && (str[j] != '\0')) {
			buf[k] = str[j];
			buf[k + 1] = '\0';
			k++;
			j++;
		}
		for (int t = 0; t < 68; t++) {
			if (!strcmp(buf, table[t].code)) {
				printf("%c", table[t].symbol);
				break;
			}
		}
		if (str[j + 1] == ' ') {
			printf("%c", table[52].symbol);
			j++;
		}
		if (str[j] != '\0') {
			j++;
		}
	}
	printf("\n");
	free(buf);
	free(str);
}

