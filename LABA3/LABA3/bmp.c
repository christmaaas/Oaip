#include"bmp.h"
#include"func.h"
#include"formulas.h"

int error_check(errno_t err) {
	if (err != 0) {
		printf("\nFile open error\n");
		exit(FILE_ERROR);
	}
	return 1;
}

BMPFILE* get_bmp_file(char* file_name) {
	FILE* file;
	errno_t err;

	err = fopen_s(&file, file_name, "rb");
	error_check(err);

	BMPFILE* bmp = (BMPFILE*)malloc(sizeof(BMPFILE));
	fread(&bmp->bmphdr, sizeof(BMPHEADER), 1, file);
	fread(&bmp->bmpinf, sizeof(BMPINFO), 1, file);
	bmp->data = (unsigned char*)malloc(bmp->bmpinf.data_size);
	fseek(file, bmp->bmphdr.pixel_offset, SEEK_SET);
	fread(bmp->data, bmp->bmpinf.data_size, 1, file);

	fclose(file);

	return bmp;

}

void printfbmppixels(BMPFILE* bmp_file, PIXEL* pixel) {
	for (int i = 0; i < bmp_file->bmpinf.height * bmp_file->bmpinf.width; i++) {
		if (i % 3 == 0) {
			printf("\n ");
		}
		printf("%02x %02x %02x | ", pixel[i].blue, pixel[i].green, pixel[i].red);
	}
}

void printf_bmp(BMPFILE* bmp) {
	printf("ID: %c%c"
		"\nfile_size: %d"
		"\nunused: %s"
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
		bmp->bmphdr.ID[0],
		bmp->bmphdr.ID[1],
		bmp->bmphdr.file_size,
		bmp->bmphdr.unused,
		bmp->bmphdr.pixel_offset,
		bmp->bmpinf.header_size,
		bmp->bmpinf.width,
		bmp->bmpinf.height,
		bmp->bmpinf.color_planes,
		bmp->bmpinf.bits_per_pixel,
		bmp->bmpinf.cmprsn,
		bmp->bmpinf.data_size,
		bmp->bmpinf.pwidth,
		bmp->bmpinf.pheight,
		bmp->bmpinf.colors_count,
		bmp->bmpinf.imp_colors_count);
}

void bmp_file_info(BMPFILE** bmp_file, char* file_name) {
	(*bmp_file) = get_bmp_file(file_name);
	printf_bmp((*bmp_file));
}

PIXEL* push_pixels_to_struct(BMPFILE* bmp_file, char* file_name) {
	int num_of_pixels = bmp_file->bmpinf.width * bmp_file->bmpinf.height;
	PIXEL* pixels = (PIXEL*)malloc(num_of_pixels * sizeof(PIXEL));
	FILE* file = NULL;
	errno_t err;

	err = fopen_s(&file, file_name, "rb");
	error_check(err);

	fseek(file, PIXEL_OFFSET, SEEK_SET);
	int pixel_index = 0;
	for (int i = 0; i < bmp_file->bmpinf.height; i++) {
		for (int j = 0; j < bmp_file->bmpinf.width; j++) {
			fread(&(pixels[pixel_index].blue), 1, 1, file);
			fread(&(pixels[pixel_index].green), 1, 1, file);
			fread(&(pixels[pixel_index].red), 1, 1, file);
			pixel_index++;
		}
	}

	fclose(file);

	return pixels;
}

void bw_conversion(BMPFILE* bmp_file, PIXEL* pixels, char* file_name) {
	FILE* new_file = NULL;
	errno_t new_err;
	int index = 0;
	char bw_color;

	new_err = fopen_s(&new_file, "BWCONVERTED.bmp", "wb");
	error_check(new_err);

	fwrite(bmp_file, sizeof(BMPFILE), 1, new_file);

	fseek(new_file, PIXEL_OFFSET, SEEK_SET);
	for (int i = 0; i < bmp_file->bmpinf.height; i++) {
		for (int j = 0; j < bmp_file->bmpinf.width; j++) {
			bw_color = set_bw_color(pixels[index].red, pixels[index].green, pixels[index].blue);
			fwrite(&bw_color, 1, 1, new_file);
			fwrite(&bw_color, 1, 1, new_file);
			fwrite(&bw_color, 1, 1, new_file);
			index++;
		}
	}

	fclose(new_file);
}

void negative_conversion(BMPFILE* bmp_file, PIXEL* pixels, char* file_name) {
	FILE* new_file = NULL;
	errno_t new_err;
	int index = 0;
	char red;
	char green;
	char blue;

	new_err = fopen_s(&new_file, "NEGATIVECONVERTED.bmp", "wb");
	error_check(new_err);

	fwrite(bmp_file, sizeof(BMPFILE), 1, new_file);

	fseek(new_file, PIXEL_OFFSET, SEEK_SET);
	for (int i = 0; i < bmp_file->bmpinf.height; i++) {
		for (int j = 0; j < bmp_file->bmpinf.width; j++) {
			red = (char)(255 - pixels[index].red);
			green = (char)(255 - pixels[index].green);
			blue = (char)(255 - pixels[index].blue);
			fwrite(&red, 1, 1, new_file);
			fwrite(&green, 1, 1, new_file);
			fwrite(&blue, 1, 1, new_file);
			index++;
		}
	}

	fclose(new_file);
}