
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
	int count = 0;

	FILE* file = file_open(file_name);

	char* string = (char*)calloc(SIZE_OF_STRING, sizeof(char));

	char symbol = fgetc(file);

	while (!feof(file)) {

		string[count] = symbol;
		count++;

		symbol = fgetc(file);
	}

	fclose(file);
	
	return string;
}

void print_file(char* file_name) {
	FILE* file = file_open(file_name);

	printf("\nText: ");

	char symbol = fgetc(file);

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
	char* encrypted_text = (char*)calloc(MAX_SIZE_OF_ENCRYPTED_STRING, 1);
	char* text_to_decrypt = (char*)calloc(SIZE_OF_STRING, 1);
	
	int i = 0, j = 0;

	print_file("Morse.txt");

	text_to_decrypt = read_file("Morse.txt");
	
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
				
				encrypted_text[0] = NULL_CHARACTER;

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
	
	free(encrypted_text);
	free(text_to_decrypt);
}

