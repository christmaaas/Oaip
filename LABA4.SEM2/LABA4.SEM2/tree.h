#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITE_CYCLE 1

#define PROGRAMM_ERROR -3

#define STRING_SIZE 256

#define QUESTION 'Q'

#define ANSWER 'A'

#define YES 1

#define NO 2

typedef struct node {
	char* question;
	struct node* yes;
	struct node* no;
} node;

node* get_new_node(const char* question);

node* footballer_tree_traversal(FILE* log_file, node* root);

void free_tree(node* root);

void free_node(node* tree_node);

void add_new_footballer(FILE* log_file, node* node_to_change);

void push_database(FILE* database_file, node* root);

node* load_database(FILE* database_file);
