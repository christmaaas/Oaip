#include<math.h>

#include"bmp.h"

void print_bmp(char* file_name) {
	BMPFILE bmp;
	FILE* bmp_file = file_open(file_name);
	fread(&bmp, sizeof(BMPFILE), 1, bmp_file);
	printf("\n----- BMP-INFO -----\n");
	printf("Size of BMP file: %d"
		"\nPixel offset: %d"
		"\nSize of BMP-Header: %d"
		"\nWidth of BMP: %d"
		"\nHeight of BMP: %d"
		"\nBits per pixel: %hd"
		"\nCompression: %d"
		"\nSize of data: %d\n",
		bmp.bmphdr.file_size,
		bmp.bmphdr.pixel_offset,
		bmp.bmpinf.header_size,
		bmp.bmpinf.width,
		bmp.bmpinf.height,
		bmp.bmpinf.bits_per_pixel,
		bmp.bmpinf.cmprsn,
		bmp.bmpinf.data_size);
	printf("--------------------\n");
	fclose(bmp_file);
}

void push_bw_pixels_wide(BMPFILE bmp, FILE* bmp_file, FILE* new_bmp_file) {
	PIXEL pixels, new_pixels;
	unsigned char bw_color;
	for (int i = 0; i < bmp.bmpinf.height; i++) {
		for (int j = 0; j < bmp.bmpinf.width; j++) {
			fread(&pixels, sizeof(PIXEL), 1, bmp_file);

			bw_color = (unsigned char)(0.3 * pixels.red + 0.59 * pixels.green + 0.11 * pixels.blue);
			new_pixels.blue = bw_color;
			new_pixels.green = bw_color;
			new_pixels.red = bw_color;

			fwrite(&new_pixels, sizeof(PIXEL), 1, new_bmp_file);
		}
	}
}

void push_bw_pixels_high(BMPFILE bmp, FILE* bmp_file, FILE* new_bmp_file) {
	PIXEL pixels, new_pixels;
	unsigned char bw_color;
	for (int i = 0; i < bmp.bmpinf.data_size; i += 3) {
		fread(&pixels, sizeof(PIXEL), 1, bmp_file);

		bw_color = (unsigned char)(0.3 * pixels.red + 0.59 * pixels.green + 0.11 * pixels.blue);
		new_pixels.blue = bw_color;
		new_pixels.green = bw_color;
		new_pixels.red = bw_color;

		fwrite(&new_pixels, sizeof(PIXEL), 1, new_bmp_file);
	}
}

void convert_to_bw(BMPFILE bmp, FILE* bmp_file, FILE* new_bmp_file) {
	fseek(bmp_file, bmp.bmphdr.pixel_offset, SEEK_SET);
	fseek(new_bmp_file, bmp.bmphdr.pixel_offset, SEEK_SET);
	if (bmp.bmpinf.width > bmp.bmpinf.height) {
		push_bw_pixels_wide(bmp, bmp_file, new_bmp_file);
	}
	else {
		push_bw_pixels_high(bmp, bmp_file, new_bmp_file);
	}
}

void bw_conversion(char* file_name) {
	BMPFILE bmp;
	FILE* file = file_open(file_name);
	FILE* new_file = new_file_open("BWCONVERTED.bmp");
	
	fread(&bmp, sizeof(BMPFILE), 1, file);
	fwrite(&bmp, sizeof(BMPFILE), 1, new_file);

	convert_to_bw(bmp, file, new_file);

	fclose(file);
	fclose(new_file);
	printf("\n%s was converted to black-white in \"BWCONVERTED.bmp\" file\n", file_name);
}

void push_negative_pixels_wide(BMPFILE bmp, FILE* bmp_file, FILE* new_bmp_file) {
	PIXEL pixels, new_pixels;
	for (int i = 0; i < bmp.bmpinf.height; i++) {
		for (int j = 0; j < bmp.bmpinf.width; j++) {
			fread(&pixels, sizeof(PIXEL), 1, bmp_file);
			
			new_pixels.blue = (unsigned char)(255 - pixels.blue);
			new_pixels.green = (unsigned char)(255 - pixels.green);
			new_pixels.red = (unsigned char)(255 - pixels.red);
		
			fwrite(&new_pixels, sizeof(PIXEL), 1, new_bmp_file);
		}
	}
}

void push_negative_pixels_high(BMPFILE bmp, FILE* bmp_file, FILE* new_bmp_file) {
	PIXEL pixels, new_pixels;
	for (int i = 0; i < bmp.bmpinf.data_size; i += 3) {
		fread(&pixels, sizeof(PIXEL), 1, bmp_file);

		new_pixels.blue = (unsigned char)(255 - pixels.blue);
		new_pixels.green = (unsigned char)(255 - pixels.green);
		new_pixels.red = (unsigned char)(255 - pixels.red);

		fwrite(&new_pixels, sizeof(PIXEL), 1, new_bmp_file);
	}
}

void convert_to_negative(BMPFILE bmp, FILE* bmp_file, FILE* new_bmp_file) {
	fseek(bmp_file, bmp.bmphdr.pixel_offset, SEEK_SET);
	fseek(new_bmp_file, bmp.bmphdr.pixel_offset, SEEK_SET);
	if (bmp.bmpinf.width > bmp.bmpinf.height) {
		push_negative_pixels_wide(bmp, bmp_file, new_bmp_file);
	}
	else {
		push_negative_pixels_high(bmp, bmp_file, new_bmp_file);
	}
}

void negative_conversion(char* file_name) {
	BMPFILE bmp;
	FILE* file = file_open(file_name);
	FILE* new_file = new_file_open("NEGATIVE.bmp");

	fread(&bmp, sizeof(BMPFILE), 1, file);
	fwrite(&bmp, sizeof(BMPFILE), 1, new_file);

	convert_to_negative(bmp, file, new_file);

	fclose(file);
	fclose(new_file);
	printf("\n%s was converted to negative in \"NEGATIVE.bmp\" file\n", file_name);
}

void push_gamma_correction(BMPFILE bmp, FILE* bmp_file, FILE* new_bmp_file, double gamma_degree) {
	PIXEL pixels;
	fseek(bmp_file, bmp.bmphdr.pixel_offset, SEEK_SET);
	fseek(new_bmp_file, bmp.bmphdr.pixel_offset, SEEK_SET);
	for (int i = 0; i < bmp.bmpinf.data_size; i += 3) {
		fread(&pixels, sizeof(PIXEL), 1, bmp_file);

		pixels.blue = (unsigned char)(pow((double)pixels.blue / 255.0, gamma_degree) * 255.0);
		pixels.green = (unsigned char)(pow((double)pixels.green / 255.0, gamma_degree) * 255.0);
		pixels.red = (unsigned char)(pow((double)pixels.red / 255.0, gamma_degree) * 255.0);

		fwrite(&pixels, sizeof(PIXEL), 1, new_bmp_file);
	}
}

void gamma_correction(char* file_name) {
	printf("\nInput a gamma-correction degree: ");
	double gamma_degree = gamma_degree_check();
	BMPFILE bmp;
	FILE* file = file_open(file_name);
	FILE* new_file = new_file_open("GAMMACOR.bmp");
	
	fread(&bmp, sizeof(BMPFILE), 1, file);
	fwrite(&bmp, sizeof(BMPFILE), 1, new_file);

	push_gamma_correction(bmp, file, new_file, gamma_degree);

	fclose(file);
	fclose(new_file);
	printf("\n%s was gamma-corrected in \"GAMMACOR.bmp\" file\n", file_name);
}



