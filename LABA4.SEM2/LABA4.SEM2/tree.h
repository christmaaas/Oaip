#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"functions.h"

#define GUESS 1
#define NOT_GUESS 2

typedef struct node {
	char* question;
	node* yes;
	node* no;
} node;

node* get_new_node(char* question);