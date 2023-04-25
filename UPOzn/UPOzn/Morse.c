
#include "morse.h"
#include "resources.h"
#include "log.h"

morse_code alphabet[] = {
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

void string_letters_to_lower(char* string) {
	int letter_position = FIRST_ELEMENT;
	while (string[letter_position] != NULL_CHARACTER)	{
		if (string[letter_position] >= 'A' && string[letter_position] <= 'Z') {
			string[letter_position] += HIGH_TO_LOWER;
		}
		letter_position++;
	}
}

void letter_to_lower(char* letter) {
	if ((*letter) >= 'A' && (*letter) <= 'Z') {
		(*letter) += HIGH_TO_LOWER;
	}
}

void morse_encrypt_user_string() {
	printf("\nText: ");

	char* text_to_encrypt = input_string();
	string_letters_to_lower(text_to_encrypt);

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
	
	char* encrypted_text = (char*)calloc(MAX_SIZE_OF_ENCRYPTED_STRING, sizeof(char));
	char* text_to_decrypt = input_string();

	int i = 0; 
	int j = 0;

	printf("\nDecrypted text: \n");

	while (text_to_decrypt[i] != NULL_CHARACTER) {
		j = FIRST_ELEMENT;
		
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

	char letter = fgetc(file);
	while (!feof(file)) {
		printf("%c", letter);
		letter = fgetc(file);
	}

	fclose(file);
	
	push_log(log_type[APPLICATION], "File \"Morse.txt\" was printed.", "a");

	printf("\n");
}

void morse_encrypt_file() {
	print_file("Morse.txt");

	FILE* file = file_open("Morse.txt", "r");

	printf("\nEncrypted text:\n");

	char letter = fgetc(file);
	letter_to_lower(&letter);
	while (!feof(file)) {
		for (int i = 0; i < SIZE_OF_ALPHABET; i++) {
			if (letter == alphabet[i].symbol) {
				if (letter == SPACE) {
					printf("%c", SPACE);
					break;
				}
				else if (letter == NEWLINE) {
					printf("%c", NEWLINE);
					break;
				}
				printf("%s ", alphabet[i].code);
				break;
			}
		}
		letter = fgetc(file);
		letter_to_lower(&letter);
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
	
	print_file("Morse.txt");

	FILE* file = file_open("Morse.txt", "r");

	printf("\nDecrypted text: \n");

	while (true) {
		i = FIRST_ELEMENT;
		
		encrypted_text[i] = fgetc(file);
		while (!feof(file) && encrypted_text[i] != SPACE && encrypted_text[i] != NEWLINE) {
			i++;
			encrypted_text[i] = fgetc(file);
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
		
		if (feof(file)) {
			break;
		}
		
		space_or_newline_check(file, space_or_newline);
	}

	fclose(file);

	push_log(log_type[APPLICATION], "File text was decrypted.", "a");

	printf("\n");
	
	free(encrypted_text);
}

