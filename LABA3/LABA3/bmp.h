#pragma once

#include<stdio.h>
#include<stdlib.h>

#define FILE_ERROR -3
#define PIXEL_OFFSET 54

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

typedef struct PIXEL {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
} PIXEL;

BMPFILE* get_bmp_file(char* file_name);

void printf_bmp(BMPFILE* bmp);

void bmp_file_info(BMPFILE** bmp_file, char* file_name);

PIXEL* push_pixels_to_struct(BMPFILE* bmp_file, char* file_name);

void printfbmppixels(BMPFILE* bmp_file, PIXEL* pixel);

void bw_conversion(BMPFILE* bmp_file, PIXEL* pixels, char* file_name);

void negative_conversion(BMPFILE* bmp_file, PIXEL* pixels, char* file_name);