#include"bmp.h"

void printf_bmp(BMPFILE bmp) {
	printf("ID: %d"
		"\nfile_size: %d"
		"\nunused1: %d"
		"\nunused2: %d"
		"\npixel_offset: %d"
		"\nheader_size: %d"
		"\nwidth: %d"
		"\nheight: %d"
		"\ncolor_planes: %hd"
		"\nbits_per_pixel: %hd"
		"\ncmprsn: %d"
		"\ndata_size: %d"
		"\npwidth: %d"
		"\npheight: %d"
		"\ncolors_count: %d"
		"\nimp_colors_count: %d",
		bmp.bmphdr.ID,
		bmp.bmphdr.file_size,
		bmp.bmphdr.unused1,
		bmp.bmphdr.unused2,
		bmp.bmphdr.pixel_offset,
		bmp.bmpinf.header_size,
		bmp.bmpinf.width,
		bmp.bmpinf.height,
		bmp.bmpinf.color_planes,
		bmp.bmpinf.bits_per_pixel,
		bmp.bmpinf.cmprsn,
		bmp.bmpinf.data_size,
		bmp.bmpinf.pwidth,
		bmp.bmpinf.pheight,
		bmp.bmpinf.colors_count,
		bmp.bmpinf.imp_colors_count);
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





