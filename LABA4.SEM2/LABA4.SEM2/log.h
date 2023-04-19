#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUESTION 'Q'

#define ANSWER 'A'

#define OBJECT 'O'

void push_log(FILE* log_file, char* log_info, char* log_variety);

void push_game_log(FILE* log_file, char* log_info, char* log_variety, char* question_or_answer);