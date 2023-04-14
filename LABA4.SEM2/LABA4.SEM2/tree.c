#include"tree.h"

node* get_new_node(char* question) {
    node* tree_node = (node*)malloc(sizeof(node));
    strcpy(tree_node->question, question);
    tree_node->yes = NULL;
    tree_node->no = NULL;
    return tree_node;
}

int tree_traversal(node* root) {
    int pick = 0;
    printf("%s\n", root->question);
    printf("|1 - YES | 2 - NO|\n");
    pick = pick_answer();
    if (pick == 1) {
        if (root->yes == NULL) {
            printf("\nI guessed right!\n");
            return GUESS;
        }
        else {
            return tree_traversal(root->yes);
        }
    }
    else {
        if (root->no == NULL) {
            printf("I didnt guessed :(");
            return NOT_GUESS;
        }
        else {
            return tree_traversal(root->no);
        }
    }
    return 0;
}

void new_footballer(node* root) {

}

