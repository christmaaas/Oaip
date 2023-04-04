#include<math.h>

#include"memory.h"

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
	PIXEL pixels;
	PIXEL new_pixels;
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
	PIXEL pixels;
	PIXEL new_pixels;
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
	PIXEL pixels;
	PIXEL new_pixels;
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
	PIXEL pixels;
	PIXEL new_pixels;
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
	BMPFILE bmp;
	printf("\nInput a gamma-correction degree: ");
	double gamma_degree = gamma_degree_check();
	FILE* file = file_open(file_name);
	FILE* new_file = new_file_open("GAMMACOR.bmp");
	
	fread(&bmp, sizeof(BMPFILE), 1, file);
	fwrite(&bmp, sizeof(BMPFILE), 1, new_file);

	push_gamma_correction(bmp, file, new_file, gamma_degree);

	fclose(file);
	fclose(new_file);
	printf("\n%s was gamma-corrected in \"GAMMACOR.bmp\" file\n", file_name);
}

int compare(const void* first_pointer, const void* second_pointer) {
	const unsigned char* current_byte = (const unsigned char*)first_pointer;
	const unsigned char* next_byte = (const unsigned char*)second_pointer;
	return ((*current_byte) - (*next_byte));
}

void sort_color_channels(unsigned char* channel_blue, unsigned char* channel_green, unsigned char* channel_red, int size_filter) {
	qsort(channel_blue, size_filter * size_filter, sizeof(unsigned char), compare);
	qsort(channel_green, size_filter * size_filter, sizeof(unsigned char), compare);
	qsort(channel_red, size_filter * size_filter, sizeof(unsigned char), compare);
}

void push_new_filter(BMPFILE bmp, FILE* bmp_file, FILE* new_bmp_file, int size_filter) {
	PIXEL** pixels = memory_allocate(bmp);
	unsigned char* channel_blue = (unsigned char*)malloc(size_filter * size_filter * sizeof(unsigned char));
	unsigned char* channel_green = (unsigned char*)malloc(size_filter * size_filter * sizeof(unsigned char));
	unsigned char* channel_red = (unsigned char*)malloc(size_filter * size_filter * sizeof(unsigned char));
	int size_filter_half = size_filter / 2;
	unsigned char padding = 0;
	
	fseek(bmp_file, bmp.bmphdr.pixel_offset, SEEK_SET);
	fseek(new_bmp_file, bmp.bmphdr.pixel_offset, SEEK_SET);
	
	for (int row = 0; row < bmp.bmpinf.height; row++) {
		for (int col = 0; col < bmp.bmpinf.width; col++) {
			fread(&pixels[row][col], sizeof(PIXEL), 1, bmp_file);
		}
		fseek(bmp_file, bmp.bmpinf.width % 4, SEEK_CUR);
	}
	
	for (int row = size_filter_half; row < bmp.bmpinf.height - size_filter_half; row++) {
		for (int col = size_filter_half; col < bmp.bmpinf.width - size_filter_half; col++) {
			int signature = 0;
			for (int near_row = 0; near_row < size_filter; near_row++) {
				for (int near_col = 0; near_col < size_filter; near_col++) {
					if (signature < size_filter * size_filter) {
						channel_blue[signature] = pixels[row + near_row - size_filter_half][col + near_col - size_filter_half].blue;
						channel_green[signature] = pixels[row + near_row - size_filter_half][col + near_col - size_filter_half].green;
						channel_red[signature] = pixels[row + near_row - size_filter_half][col + near_col - size_filter_half].red;
						signature++;
					}
				}
			}
			
			sort_color_channels(channel_blue, channel_green, channel_red, size_filter);
		
			pixels[row][col].blue = channel_blue[(size_filter * size_filter) / 2];
			pixels[row][col].green = channel_green[(size_filter * size_filter) / 2];
			pixels[row][col].red = channel_red[(size_filter * size_filter) / 2];
		}
	}
	
	for (int row = 0; row < bmp.bmpinf.height; row++) {
		for (int col = 0; col < bmp.bmpinf.width; col++) {
			fwrite(&pixels[row][col], sizeof(PIXEL), 1, new_bmp_file);
		}
		if (bmp.bmpinf.height > bmp.bmpinf.width) {
			fwrite(&padding, sizeof(unsigned char), bmp.bmpinf.width % 4, new_bmp_file);
		}
	}
	
	free(channel_blue);
	free(channel_green);
	free(channel_red);
	free_memory(bmp, pixels);
}

void median_filtration(char* file_name) {
	BMPFILE bmp;
	printf("\nInput a size of filter for median filtration: ");
	int size_filter = filter_check();
	FILE* file = file_open(file_name);
	FILE* new_file = new_file_open("MEDIANFILTER.bmp");

	fread(&bmp, sizeof(BMPFILE), 1, file);
	fwrite(&bmp, sizeof(BMPFILE), 1, new_file);

	push_new_filter(bmp, file, new_file, size_filter);

	fclose(file);
	fclose(new_file);
	printf("\n%s was median-filtered in \"MEDIANFILTER.bmp\" file\n", file_name);
}

