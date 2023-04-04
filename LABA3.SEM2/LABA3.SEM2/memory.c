#include"memory.h"

PIXEL** memory_allocate(BMPFILE bmp) {
	PIXEL** pixels = (PIXEL**)malloc(bmp.bmpinf.height * sizeof(PIXEL*));
	for (int i = 0; i < bmp.bmpinf.height; i++) {
		pixels[i] = (PIXEL*)malloc(bmp.bmpinf.width * sizeof(PIXEL));
	}
	return pixels;
}

void free_memory(BMPFILE bmp, PIXEL** pixels) {
	for (int i = 0; i < bmp.bmpinf.height; i++) {
		free(pixels[i]);
	}
	free(pixels);
}