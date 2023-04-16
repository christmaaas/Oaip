#include"tree.h"
#include"functions.h"
#include"error.h"

node* get_new_node(const char* question) {
    node* tree_node = (node*)malloc(sizeof(node));
    tree_node->question = (char*)malloc(strlen(question) + 1);
    strcpy(tree_node->question, question);
    tree_node->yes = NULL;
    tree_node->no = NULL;
    return tree_node;
}

void free_tree(node* root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->yes);
    free_tree(root->no);
    if (root->question != NULL) {
        free(root->question);
    }
    free(root);
}

void free_node(node* tree_node) {
    free(tree_node->question);
    free(tree_node->yes);
    free(tree_node->no);
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
    node* tree_leaf_buf = NULL;
    
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
    tree_leaf_buf = get_new_node(tree_leaf->question);
    
    if (pick == YES) {
        new_question_node->yes = new_footballer;
        new_question_node->no = tree_leaf_buf;
    }
    else {
        new_question_node->no = new_footballer;
        new_question_node->yes = tree_leaf_buf;
    }
    
    strcpy(tree_leaf->question, new_question_node->question);
    tree_leaf->yes = new_question_node->yes;
    tree_leaf->no = new_question_node->no;

    free(new_footballer_name);
    free(new_question);
}

void new_game() {
    FILE* file = NULL;
    node* temp = NULL;
    node* first_question = NULL;
    file = file_open("database.txt");
    if (file == NULL) {
        first_question = get_new_node("Cristiano Ronaldo");
    }
    else {
        first_question = load_database(file);
        fclose(file);
    }
    printf("Hello! I am football Akinator! Try to beat me, good luck!\n");
    
    while (INFINITE_CYCLE) {
        temp = footballer_tree_traversal(first_question);
        if (temp == NULL) {
            break;
        }
        add_new_footballer(temp);
    }
    printf("\nThanks for game! Come back and play again!\n");
    
    file = file_create("database.txt");
    push_database(file, first_question);
    fclose(file);

    free(first_question);
    free(temp);
}

void push_database(FILE* database, node* root) {
    if (root == NULL) {
        return;
    }
    if (root->yes == NULL && root->no == NULL) {
        fprintf(database, "%c", 'A');
        fprintf(database, "%s\n", root->question);
    }
    else {
        fprintf(database, "%c", 'Q');
        fprintf(database, "%s\n", root->question);
    }
    push_database(database, root->yes);
    push_database(database, root->no);
}

node* load_database(FILE* database) {
    node* root = NULL;
    char* root_node = (char*)malloc(STRING_SIZE);
   
    if (fgets(root_node, STRING_SIZE, database) == NULL) {
        return;
    }
    
    if (root_node[0] == 'Q') {
        delete_symbol(&root_node);
        root = get_new_node(root_node);
        root->yes = load_database(database);
        root->no = load_database(database);
    }
    else {
        delete_symbol(&root_node);
        return get_new_node(root_node);
    }
    
    free(root_node);
    
    return root;
}