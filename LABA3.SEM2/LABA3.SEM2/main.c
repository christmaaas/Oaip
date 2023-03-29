#include<stdio.h>
#include<stdlib.h>

#include"bmp.h"
#include"functions.h"
#include"error.h"


int main() {
	char* file_name = input_file_name();
	menu(&file_name);
	return 0;
}