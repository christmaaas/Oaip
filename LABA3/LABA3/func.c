#include"Func.h"

char* input_file_name() {
	char* string = (char*)calloc(256, sizeof(char));
	printf("Input BMP file name (like \"Sea.bmp\"): ");
	gets_s(string, 255);
	int size = strlen(string);
	string = (char*)realloc(string, size + 1);
	return string;
}