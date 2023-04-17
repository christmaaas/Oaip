#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"error.h"

void push_log(FILE* log_file, char* log_info, char* log_variety);

void push_game_log(FILE* log_file, char* log_info, char* log_variety, char* game_variety);