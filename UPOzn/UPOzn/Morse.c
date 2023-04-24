
#include "morse.h"
#include "resources.h"
#include "log.h"

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
	{"\n", '\n'},
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

void morse_encrypt_user_string() {
	printf("\nText: ");

	char* text_to_encrypt = input_string();

	printf("\nEncrypted text: \n");

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

	push_log(log_type[APPLICATION], "User text was encrypted.", "a");

	free(text_to_encrypt);
}

void morse_decrypt_user_string() {
	printf("\nText: ");
	
	char* text_to_decrypt = input_string();
	char* encrypted_text = (char*)calloc(MAX_SIZE_OF_ENCRYPTED_STRING, sizeof(char));

	int i = 0; 
	int j = 0;

	printf("\nDecrypted text: \n");

	while (text_to_decrypt[i] != NULL_CHARACTER) {
		j = 0;
		while ((text_to_decrypt[i] != SPACE) && (text_to_decrypt[i] != NULL_CHARACTER)) {
			encrypted_text[j] = text_to_decrypt[i];
			i++;
			j++;
		}

		encrypted_text[j] = NULL_CHARACTER;

		for (int k = 0; k < SIZE_OF_ALPHABET; k++) {
			if (!strcmp(encrypted_text, alphabet[k].code)) {
				printf("%c", alphabet[k].symbol);

				encrypted_text[FIRST_ELEMENT] = NULL_CHARACTER;

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

	push_log(log_type[APPLICATION], "User text was decrypted.", "a");

	free(text_to_decrypt);
	free(encrypted_text);
}

void print_file(const char* file_name) {
	FILE* file = file_open(file_name, "r");

	printf("\nText:\n");

	char symbol = fgetc(file);
	while (!feof(file)) {
		printf("%c", symbol);
		symbol = fgetc(file);
	}

	fclose(file);
	
	push_log(log_type[APPLICATION], "File \"Morse.txt\" was printed.", "a");

	printf("\n");
}

void morse_encrypt_file() {
	print_file("Morse.txt");

	FILE* file = file_open("Morse.txt", "r");

	printf("\nEncrypted text:\n");

	char symbol = fgetc(file);
	while (!feof(file)) {
		for (int i = 0; i < SIZE_OF_ALPHABET; i++) {
			if (symbol == alphabet[i].symbol) {
				if (symbol == SPACE) {
					printf("%c", SPACE);
					break;
				}
				else if (symbol == NEWLINE) {
					printf("%c", NEWLINE);
					break;
				}
				printf("%s ", alphabet[i].code);
				break;
			}
		}

		symbol = fgetc(file);
	}

	fclose(file);

	push_log(log_type[APPLICATION], "File text was encrypted.", "a");

	printf("\n");
}

void space_or_newline_check(FILE* file, char space_or_newline) {
	fpos_t pos = ftell(file);

	if (space_or_newline == NEWLINE) {
		printf("%c", NEWLINE);
	}
	else if ((space_or_newline = fgetc(file)) == SPACE) {
		printf("%c", SPACE);
	}

	fsetpos(file, &pos);
}

void morse_decrypt_file() {
	char space_or_newline;
	char* encrypted_text = (char*)malloc(MAX_SIZE_OF_ENCRYPTED_STRING, sizeof(char));
	
	int i = 0; 
	int cycle = CONTINUE_CYCLE;
	
	print_file("Morse.txt");

	FILE* file = file_open("Morse.txt", "r");

	printf("\nEncrypted text: \n");

	while (cycle) {
		i = 0;
		encrypted_text[i] = fgetc(file);
		while (encrypted_text[i] != SPACE && encrypted_text[i] != NEWLINE && !feof(file)) {
			i++;
			encrypted_text[i] = fgetc(file);
			if (feof(file)) {
				cycle = BREAK_CYCLE;
				break;
			}
		}
		
		space_or_newline = encrypted_text[i];
		encrypted_text[i] = NULL_CHARACTER;
		
		for (int k = 0; k < SIZE_OF_ALPHABET; k++) {
			if (!strcmp(encrypted_text, alphabet[k].code)) {
				printf("%c", alphabet[k].symbol);
				
				encrypted_text[FIRST_ELEMENT] = NULL_CHARACTER;
				
				break;
			}
		}
		space_or_newline_check(file, space_or_newline);
	}

	fclose(file);

	push_log(log_type[APPLICATION], "File text was decrypted.", "a");

	printf("\n");
	
	free(encrypted_text);
}

