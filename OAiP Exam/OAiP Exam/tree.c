#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} node;

node* get_new_node(int data) {
	node* new_node = (node*)malloc(sizeof(node));

	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

