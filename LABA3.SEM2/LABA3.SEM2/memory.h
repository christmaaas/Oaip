#pragma once
#include<stdio.h>
#include<stdlib.h>

#include"bmp.h"

PIXEL** memory_allocate(BMPFILE bmp);

void free_memory(BMPFILE bmp, PIXEL** pixels);