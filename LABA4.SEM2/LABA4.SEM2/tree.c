#include "tree.h"
#include "resources.h"
#include "log.h"
#include "game.h"

node* get_new_node(const char* question) {
    node* tree_node = (node*)malloc(sizeof(node));
    
    tree_node->question = (char*)malloc(strlen(question) + 1);
   
    strcpy_s(tree_node->question, (strlen(question) + 1), question);
   
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

node* footballer_tree_traversal(FILE* log_file, node* root) {
    int pick = 0;
    
    if (root == NULL) {
        push_log(log_file, "Error: empty pointer. Exit from programm.", "error");
        
        exit(PROGRAMM_ERROR);
    }
    
    printf("\n%s?\n", root->question);
   
    push_game_log(log_file, root->question, "game", "Question");
    
    print_answer_menu();
    
    pick = pick_answer();
    
    if (pick == YES) {
        
        push_game_log(log_file, "Yes", "game", "Answer");
        
        if (root->yes == NULL) {
            
            printf("\nI guessed right!\n");
            
            push_log(log_file, "Programm guest the object.", "game");
            
            return NULL;
        }
        else {
            return footballer_tree_traversal(log_file, root->yes);
        }
    }
    else {
        push_game_log(log_file, "No", "game", "Answer");
       
        if (root->no == NULL) {
           
            printf("\nI didnt guessed :(\n");
           
            push_log(log_file, "Programm didnt guest the object.", "game");
           
            return root;
        }
        else {
            return footballer_tree_traversal(log_file, root->no);
        }
    }
    
    return NULL;
}

void add_new_footballer(FILE* log_file, node* node_to_change) {
    int pick = 0;

    char* new_footballer_name = NULL;
    char* new_question = NULL;
    char* temp_string = NULL;

    node* new_question_node = NULL;
    node* new_footballer = NULL;

    if (node_to_change == NULL) {
        push_log(log_file, "Error: empty pointer. Exit from programm.", "error");
        
        exit(PROGRAMM_ERROR);
    }

    printf("\nWhat it was the footballer?: ");

    new_footballer_name = input_str();

    push_game_log(log_file, new_footballer_name, "game", "Object");

    printf("What is distinguishes %s from %s?: ", new_footballer_name, node_to_change->question);

    new_question = input_str();

    printf("What is answer for %s to \"%s\"?\n", new_footballer_name, new_question);
    
    print_answer_menu();

    pick = pick_answer();

    new_footballer = get_new_node(new_footballer_name);
    new_question_node = get_new_node(new_question);

    if (pick == YES) {
        node_to_change->yes = new_footballer;
        node_to_change->no = new_question_node;
    }
    else {
        node_to_change->no = new_footballer;
        node_to_change->yes = new_question_node;
    }

    temp_string = node_to_change->question;
    node_to_change->question = new_question_node->question;
    new_question_node->question = temp_string;

    free(new_footballer_name);
    free(new_question);
}

void push_database(FILE* database_file, node* root) {
    if (root == NULL) {
        return;
    }
    
    if (root->yes == NULL && root->no == NULL) {
        fprintf(database_file, "%c", ANSWER);
        fprintf(database_file, "%s\n", root->question);
    }
    else {
        fprintf(database_file, "%c", QUESTION);
        fprintf(database_file, "%s\n", root->question);
    }
    
    push_database(database_file, root->yes);
    push_database(database_file, root->no);
}

void delete_first_symbol(char** string) {
    for (int i = 0; i < strlen((*string)); i++) {
        (*string)[i] = (*string)[i + 1];
    }
    (*string)[strcspn((*string), "\n")] = '\0';
}

node* load_database(FILE* database_file) {
    node* root = NULL;
    
    char* root_node = (char*)malloc(STRING_SIZE);
   
    if (fgets(root_node, STRING_SIZE, database_file) == NULL) {
       
        free(root_node);
        
        return NULL;
    }
    
    if (root_node[0] == QUESTION) {
        delete_first_symbol(&root_node);
        
        root = get_new_node(root_node);
        
        root->yes = load_database(database_file);
        root->no = load_database(database_file);
    }
    else {
        delete_first_symbol(&root_node);
        
        root = get_new_node(root_node);

        free(root_node);

        return root;
    }
    
    free(root_node);
    
    return root;
}