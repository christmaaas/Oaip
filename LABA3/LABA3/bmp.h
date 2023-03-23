#pragma once

#include<stdio.h>
#include<stdlib.h>

#define FILE_ERROR -3

#pragma pack(push, 1)

typedef struct BMPHEADER {
	unsigned char ID[2];
	unsigned int file_size;
	unsigned char unused[4];
	unsigned int pixel_offset;
} BMPHEADER;

typedef struct BMPINFO {
	unsigned int header_size;
	unsigned int width;
	unsigned int height;
	unsigned short color_planes;
	unsigned short bits_per_pixel;
	unsigned int cmprsn;
	unsigned int data_size;
	unsigned int pwidth;
	unsigned int pheight;
	unsigned int colors_count;
	unsigned int imp_colors_count;
} BMPINFO;

typedef struct BMPFILE {
	BMPHEADER bmphdr;
	BMPINFO bmpinf;
	unsigned char* data;
} BMPFILE;

#pragma pack(pop)

BMPFILE* get_bmp_file(char* file_name);

void printf_bmp(BMPFILE* bmp);