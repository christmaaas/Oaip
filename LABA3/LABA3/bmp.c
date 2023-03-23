#include"bmp.h"

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

void printf_bmp(BMPFILE* bmp) {
	printf("ID: %s"
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
		"\npwidth: $d"
		"\npheight: %d"
		"\ncolors_count: %d"
		"\nimp_colors_count: %d",
		bmp->bmphdr.ID,
		bmp->bmphdr.file_size,
		bmp->bmphdr.unused,
		bmp->bmphdr.pixel_offset,
		bmp->bmpinf.header_size,
		bmp->bmpinf.width,
		bmp->bmpinf.height,
		bmp->bmpinf.color_planes,
		bmp->bmpinf.bits_per_pixel,
		bmp->bmpinf.cmprsn,
		bmp->bmpinf.cmprsn,
		bmp->bmpinf.data_size,
		bmp->bmpinf.pwidth,
		bmp->bmpinf.pheight,
		bmp->bmpinf.colors_count,
		bmp->bmpinf.imp_colors_count);
}