#include "stack.h"

#define MEMORY_ERROR -2

void push_node(stack** head, char* word, int size) {
    stack* tmp = malloc(sizeof(stack));
   
    if (tmp == NULL) {
        exit(MEMORY_ERROR);
    }
   
    (*tmp).next = (*head);
    (*tmp).word = word;
    (*tmp).size = size;
    (*head) = tmp;
}

stack* pop_node(stack** head) {
    if (!(*head)) {
        return NULL;
    }
    
    if ((*head)->word) {
        free((*head)->word);
    }
    
    stack* buf = (*head)->next;
    
    free((*head));
   
    return buf;
}

void free_stack(stack** head) {
    while (*head) {
        (*head) = pop_node(head);
    }
}

char* check_stack(stack* head, const char* word, int size_of_word) {
    stack* p = head;
    while (p) {
        if (!strcmp(word, p->word)) {
            p->size += size_of_word;
            return head;
        }
        p = p->next;
    }
    return NULL;
}