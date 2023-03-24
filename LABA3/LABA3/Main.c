#include<stdio.h>
#include<stdlib.h>

#include"bmp.h"
#include"func.h"
#include"formulas.h"

int main() {
	BMPFILE* bmp_file = NULL;
	PIXEL* pixels = NULL;
	char* file_name = input_file_name();
	bmp_file_info(&bmp_file, file_name);
	pixels = push_pixels_to_struct(bmp_file, file_name);
	negative_conversion(bmp_file, pixels, file_name);
	free(bmp_file);
	free(pixels);
	free(file_name);
	return 0;
}