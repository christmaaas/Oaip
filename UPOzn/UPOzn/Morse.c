
#include "morse.h"
#include "menu.h"
#include "resources.h"

morse_code alphabet[] = {
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
	{".----.", '\''},
	{"-..-.", '/'},
	{"-.--.", '('},
	{"-.--.-", ')'},
	{".-...", '&'},
	{"---...", ':'},
	{"-.-.-.", ';'},
	{"-...-", '='},
	{".-.-.", '+'},
	{"-....-", '-'},
	{"..--.-", '_'},
	{".-..-.", '"'},
	{"...-..-", '$'},
	{".--.-.", '@'},
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

char* input_string() {
	char* string = (char*)calloc(SIZE_OF_STRING, sizeof(char));

	gets_s(string, SIZE_OF_STRING);

	int size = strlen(string);

	string = (char*)realloc(string, size + 1);

	return string;
}

void morse_encrypt(morse_code* alphabet) {
	printf("\nText: ");

	char* text_to_encrypt = input_string();

	printf("\nEncrypted text: ");

	for (int i = 0; i < strlen(text_to_encrypt); i++) {
		for (int j = 0; j < SIZE_OF_ALPHABET; j++) {
			if (text_to_encrypt[i] == alphabet[j].symbol) {

				if (text_to_encrypt[i] == SPACE) {
					printf("%s", alphabet[j].code);
					break;
				}

				printf("%s ", alphabet[j].code);

				break;
			}
		}
	}

	printf("\n");

	free(text_to_encrypt);
}

void morse_decrypt(morse_code* alphabet) {
	char* text_to_decrypt = input_string();

	char* encrypted_text = (char*)calloc(MAX_SIZE_OF_ENCRYPTED_STRING, sizeof(char));

	int i = 0, j = 0;

	printf("\nText: ");

	printf("\nDecrypted text: ");

	while (text_to_decrypt[i] != NULL_CHARACTER) {
		j = 0;

		while ((text_to_decrypt[i] != SPACE) && (text_to_decrypt[i] != NULL_CHARACTER)) {
			encrypted_text[j] = text_to_decrypt[i];
			encrypted_text[j + 1] = NULL_CHARACTER;
			i++;
			j++;
		}

		for (int k = 0; k < SIZE_OF_ALPHABET; k++) {
			if (!strcmp(encrypted_text, alphabet[k].code)) {
				printf("%c", alphabet[k].symbol);

				break;
			}
		}

		if (text_to_decrypt[i + 1] == SPACE) {
			printf("%c", SPACE);

			i++;
		}
		else if (text_to_decrypt[i] != NULL_CHARACTER) {
			i++;
		}
	}

	printf("\n");

	free(text_to_decrypt);
	free(encrypted_text);
}

char* read_file(char* file_name) {
	FILE* file = file_open(file_name);


}

void print_file(char* file_name) {
	char symbol;

	FILE* file = file_open(file_name);

	printf("\nText: ");

	symbol = fgetc(file);

	while (!feof(file)) {
		printf("%c", symbol);

		symbol = fgetc(file);
	}

	printf("\n");

	fclose(file);
}

void morse_encrypt_file(morse_code* alphabet) {
	print_file("Morse.txt");

	FILE* file = file_open("Morse.txt");

	printf("\nEncrypted text: ");

	char symbol = fgetc(file);

	while (!feof(file)) {

		for (int i = 0; i < SIZE_OF_ALPHABET; i++) {
			if (symbol == alphabet[i].symbol) {

				if (symbol == SPACE) {
					printf("%s", alphabet[i].code);
					break;
				}

				printf("%s ", alphabet[i].code);
			}
		}

		symbol = fgetc(file);
	}

	printf("\n");

	fclose(file);
}

void morse_decrypt_file(morse_code* alphabet) {
	char* encrypted_text = (char*)calloc(6, 1);
	char* text_to_decrypt = (char*)calloc(512, 1);
	
	int i = 0, j = 0, k = 0;

	print_file(alphabet);

	FILE* file = file_open("Morse.txt");

	char symbol = fgetc(file);
	
	while (!feof(file)) {
		
		text_to_decrypt[i] = symbol;
		i++;
		
		symbol = fgetc(file);
	}

	fclose(file);

	printf("Decrypted text: ");
	while (text_to_decrypt[j] != '\0') {
		k = 0;
		while ((text_to_decrypt[j] != ' ') && (text_to_decrypt[j] != '\0')) {
			encrypted_text[k] = text_to_decrypt[j];
			encrypted_text[k + 1] = '\0';
			k++;
			j++;
		}
		for (int t = 0; t < 68; t++) {
			if (!strcmp(encrypted_text, alphabet[t].code)) {
				printf("%c", alphabet[t].symbol);
				break;
			}
		}
		if (text_to_decrypt[j + 1] == ' ') {
			printf("%c", alphabet[52].symbol);
			j++;
		}
		else if (text_to_decrypt[j] != '\0') {
			j++;
		}
	}
	printf("\n");
	
	free(encrypted_text);
	free(text_to_decrypt);
}

