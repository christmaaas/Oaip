#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INFINITE_CYCLE 1
#define PROGRAMM_ERROR -3
#define YES 1
#define NO 2

typedef struct node {
	char* question;
	struct node* yes;
	struct node* no;
} node;

node* get_new_node(char* question);

node* footballer_tree_traversal(node* root);

void add_new_footballer(node* tree_leaf);

void new_game();