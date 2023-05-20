#include "morse.h"
#include "resources.h"

void string_letters_to_lower(char** string) {
	int letter_position = FIRST_ELEMENT;
	while ((*string)[letter_position] != NULL_CHARACTER)	{
		if ((*string)[letter_position] >= 'A' && (*string)[letter_position] <= 'Z') {
			(*string)[letter_position] += HIGH_TO_LOWER;
		}
		letter_position++;
	}
}

void letter_to_lower(char* letter) {
	if ((*letter) >= 'A' && (*letter) <= 'Z') {
		(*letter) += HIGH_TO_LOWER;
	}
}

char* string_encryptation(const char* string) {
	char* encrypted_text = (char*)malloc(MAX_SIZE_OF_STRING);
	
	encrypted_text[FIRST_ELEMENT] = NULL_CHARACTER;
	
	string_letters_to_lower(&string);

	for (int i = 0; i < strlen(string); i++) {
		for (int j = 0; j < SIZE_OF_ALPHABET; j++) {
			if (string[i] == alphabet[j].symbol) {

				if (string[i] == SPACE) {
					strcat_s(encrypted_text, MAX_SIZE_OF_STRING, alphabet[j].code);
					break;
				}

				strcat_s(encrypted_text, MAX_SIZE_OF_STRING, alphabet[j].code);
				strcat_s(encrypted_text, MAX_SIZE_OF_STRING, " ");
				break;
			}
		}
	}

	return encrypted_text;
}

void morse_encrypt_string() {
	printf("\nText: ");

	char* text_to_encrypt = input_string();
	char* encrypted_text = string_encryptation(text_to_encrypt);
	
	printf("\nEncrypted text:\n");
	printf("%s", encrypted_text);

	printf("\n");

	free(text_to_encrypt);
	free(encrypted_text);
}

char* string_decryptation(const char* string) {
	char* encrypted_text = (char*)malloc(MAX_SIZE_OF_ENCRYPTED_STRING);
	char* decrypted_text = (char*)malloc(MAX_SIZE_OF_STRING);
	char* encrypted_letter = (char*)malloc(SIZE_OF_LETTER_AND_NULL_CHARACTER);

	int i = 0;

	decrypted_text[FIRST_ELEMENT] = NULL_CHARACTER;

	while (string[i] != NULL_CHARACTER) {
		int j = FIRST_ELEMENT;

		while ((string[i] != SPACE) && (string[i] != NULL_CHARACTER)) {
			encrypted_text[j] = string[i];
			i++;
			j++;
		}

		encrypted_text[j] = NULL_CHARACTER;

		for (int k = 0; k < SIZE_OF_ALPHABET; k++) {
			if (!strcmp(encrypted_text, alphabet[k].code)) {
				sprintf_s(encrypted_letter, SIZE_OF_LETTER_AND_NULL_CHARACTER, "%c", alphabet[k].symbol);
				strcat_s(decrypted_text, MAX_SIZE_OF_STRING, encrypted_letter);

				encrypted_text[FIRST_ELEMENT] = NULL_CHARACTER;

				break;
			}
		}

		if (string[i + 1] == SPACE) {
			strcat_s(decrypted_text, MAX_SIZE_OF_STRING, alphabet[SPACE_INDEX].code);
			i++;
		}
		else if (string[i] != NULL_CHARACTER) {
			i++;
		}
	}

	free(encrypted_text);
	free(encrypted_letter);

	return decrypted_text;
}

void morse_decrypt_string() {
	printf("\nText: ");
	
	char* text_to_decrypt = input_string();
	char* decrypted_text = string_decryptation(text_to_decrypt);

	printf("\nDecrypted text: \n");
	printf("%s", decrypted_text);

	printf("\n");

	free(text_to_decrypt);
	free(decrypted_text);
}

void print_file(const char* file_name) {
	FILE* file = file_open(file_name, "r");

	char letter = fgetc(file);
	while (!feof(file)) {
		printf("%c", letter);
		letter = fgetc(file);
	}

	fclose(file);

	printf("\n");
}

void file_encryption(const char* source_file_name, const char* destination_file_name) {
	FILE* file_to_encrypt = file_open(source_file_name, "r");
	FILE* encrypted_file = file_open(destination_file_name, "w");

	char letter = fgetc(file_to_encrypt);
	
	letter_to_lower(&letter);
	
	while (!feof(file_to_encrypt)) {
		for (int i = 0; i < SIZE_OF_ALPHABET; i++) {
			if (letter == alphabet[i].symbol) {
				if (letter == SPACE) {
					fprintf(encrypted_file, "%c", SPACE);
					break;
				}
				else if (letter == NEWLINE) {
					fprintf(encrypted_file, "%c", NEWLINE);
					break;
				}
				fprintf(encrypted_file, "%s ", alphabet[i].code);
				break;
			}
		}
		letter = fgetc(file_to_encrypt);
		
		letter_to_lower(&letter);
	}

	fclose(file_to_encrypt);
	fclose(encrypted_file);
}

void morse_encrypt_file() {
	printf("\nText:\n");
	
	print_file("morse.txt");

	printf("\nInput a name of new file(.txt): ");
	char* new_file_name = input_string();

	file_encryption("morse.txt", new_file_name);

	printf("\nEncrypted text:\n");

	print_file(new_file_name);

	free(new_file_name);
}

void space_or_newline_check(FILE* active_file, FILE* destination_file, char space_or_newline) {
	fpos_t pos = ftell(active_file);

	if (space_or_newline == NEWLINE) {
		fprintf(destination_file, "%c", NEWLINE);
	}
	else if ((space_or_newline = fgetc(active_file)) == SPACE) {
		fprintf(destination_file, "%c", SPACE);
	}

	fsetpos(active_file, &pos);
}

void file_decryption(const char* source_file_name, const char* destination_file_name) {
	char* encrypted_text = (char*)malloc(MAX_SIZE_OF_ENCRYPTED_STRING);
	char space_or_newline;

	FILE* encrypted_file = file_open(source_file_name, "r");
	FILE* decrypted_file = file_open(destination_file_name, "w");

	while (true) {
		int i = FIRST_ELEMENT;

		encrypted_text[i] = fgetc(encrypted_file);
		while (!feof(encrypted_file) && encrypted_text[i] != SPACE && encrypted_text[i] != NEWLINE) {
			i++;
			encrypted_text[i] = fgetc(encrypted_file);
		}

		space_or_newline = encrypted_text[i];
		encrypted_text[i] = NULL_CHARACTER;

		for (int k = 0; k < SIZE_OF_ALPHABET; k++) {
			if (!strcmp(encrypted_text, alphabet[k].code)) {
				fprintf(decrypted_file, "%c", alphabet[k].symbol);

				encrypted_text[FIRST_ELEMENT] = NULL_CHARACTER;

				break;
			}
		}

		if (feof(encrypted_file)) {
			break;
		}

		space_or_newline_check(encrypted_file, decrypted_file, space_or_newline);
	}

	fclose(encrypted_file);
	fclose(decrypted_file);

	free(encrypted_text);
}

void morse_decrypt_file() {
	printf("\nText:\n");

	print_file("morse.txt");

	printf("\nInput a name of new file(.txt): ");
	char* new_file_name = input_string();

	file_decryption("morse.txt", new_file_name);

	printf("\nDecrypted text:\n");

	print_file(new_file_name);

	free(new_file_name);
}

