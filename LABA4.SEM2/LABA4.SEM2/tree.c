#include"tree.h"
#include"functions.h"

node* get_new_node(char* question) {
    node* tree_node = (node*)malloc(sizeof(node));
    tree_node->question = (char*)malloc(strlen(question) + 1);
    strcpy(tree_node->question, question);
    tree_node->yes = NULL;
    tree_node->no = NULL;
    return tree_node;
}

node* footballer_tree_traversal(node* root) {
    int pick = 0;
    
    if (root == NULL) {
        exit(PROGRAMM_ERROR);
    }
    
    printf("\n%s?\n", root->question);
    print_answer();
    pick = pick_answer();
    if (pick == YES) {
        if (root->yes == NULL) {
            printf("\nI guessed right!\n");
            return NULL;
        }
        else {
            return footballer_tree_traversal(root->yes);
        }
    }
    else {
        if (root->no == NULL) {
            printf("\nI didnt guessed :(\n");
            return root;
        }
        else {
            return footballer_tree_traversal(root->no);
        }
    }
    return NULL;
}

void add_new_footballer(node* tree_leaf) {
    int pick = 0;
    char* new_footballer_name = NULL;
    char* new_question = NULL;
    node* new_question_node = NULL;
    node* new_footballer = NULL;
    node* root_buf = NULL;
    
    if (tree_leaf == NULL) {
        exit(PROGRAMM_ERROR);
    }
    
    printf("\nWhat it was the footballer?: ");
    new_footballer_name = input_str();
    printf("What is distinguishes %s from %s?: ", new_footballer_name, tree_leaf->question);
    new_question = input_str();
    printf("What is answer for %s to \"%s\"?\n",new_footballer_name, new_question);
    print_answer();
    pick = pick_answer();
    new_question_node = get_new_node(new_question);
    new_footballer = get_new_node(new_footballer_name);
    root_buf = get_new_node(tree_leaf->question);
    
    if (pick == YES) {
        new_question_node->yes = new_footballer;
        new_question_node->no = root_buf;
    }
    else {
        new_question_node->no = new_footballer;
        new_question_node->yes = root_buf;
    }
    
    strcpy(tree_leaf->question, new_question_node->question);
    tree_leaf->yes = new_question_node->yes;
    tree_leaf->no = new_question_node->no;

    free(new_footballer_name);
    free(new_question);
}

void new_game() {
    node* temp = NULL;
    node* first_question = get_new_node("Cristiano Ronaldo");
    printf("Hello! I am football akinator! Try to beat me, good luck!\n");
    
    while (INFINITE_CYCLE) {
        if ((temp = footballer_tree_traversal(first_question)) == NULL) {
            break;
        }
        add_new_footballer(temp);
    }
    printf("\nThanks for game! Come back and play again!\n");
    
    free(first_question);
    free(temp);
}
