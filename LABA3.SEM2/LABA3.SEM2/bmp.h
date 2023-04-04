#pragma once

#include<stdio.h>
#include<stdlib.h>

#include"error.h"
#include"functions.h"


#pragma pack(push, 1)

typedef struct BMPHEADER {
	unsigned short ID;
	unsigned int file_size;
	unsigned short unused1;
	unsigned short unused2;
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
} BMPFILE;

typedef struct PIXEL {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
} PIXEL;

#pragma pack(pop)

void print_bmp(char* file_name);

void push_bw_pixels_wide(BMPFILE bmp, FILE* bmp_file, FILE* new_bmp_file);

void push_bw_pixels_high(BMPFILE bmp, FILE* bmp_file, FILE* new_bmp_file);

void convert_to_bw(BMPFILE bmp, FILE* bmp_file, FILE* new_bmp_file);

void bw_conversion(char* file_name);

void push_negative_pixels_wide(BMPFILE bmp, FILE* bmp_file, FILE* new_bmp_file);

void push_negative_pixels_high(BMPFILE bmp, FILE* bmp_file, FILE* new_bmp_file);

void convert_to_negative(BMPFILE bmp, FILE* bmp_file, FILE* new_bmp_file);

void negative_conversion(char* file_name);

void push_gamma_correction(BMPFILE bmp, FILE* bmp_file, FILE* new_bmp_file, double gamma_degree);

void gamma_correction(char* file_name);

int compare(const void* first_pointer, const void* second_pointer);

void sort_color_channels(unsigned char* channel_blue, unsigned char* channel_green, unsigned char* channel_red, int size_filter);

void push_new_filter(BMPFILE bmp, FILE* bmp_file, FILE* new_bmp_file, int size_filter);

void median_filtration(char* file_name);


