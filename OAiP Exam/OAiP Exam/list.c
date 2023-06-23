#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int data;
	struct list* next;
} list;

typedef struct twolinked_list {
	int data;
	struct twolinked_list* next;
	struct twolinked_list* prev;
} twolinked_list;

list* list_get_new_node(int data) {
	list* node = (list*)malloc(sizeof(list));

	node->data = data;
	node->next = NULL;

	return node;
}

twolinked_list* twolinked_list_get_new_node(int data) {
	twolinked_list* node = (twolinked_list*)malloc(sizeof(twolinked_list));

	node->data = data;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

void push_stack(list** head, int data) {
	list* new_node = list_get_new_node(data);

	if ((*head) == NULL) {
		(*head) = new_node;
		return;
	}

	new_node->next = (*head);
	(*head) = new_node;
}

list* pop_stack(list* head) {
	if (head == NULL) {
		printf("\nStack is empty\n");
		return;
	}
	list* tmp = head;
	tmp->next = NULL;
	head = head->next;
	return tmp;
}

void prosmotr(list* head) {
	list* tmp = head;
	while (tmp != NULL) {
		printf("Num: %d\n", tmp->data);
		tmp = tmp->next;
	}
}

void push_queue(list** tail, list** head, int data) {
	list* new_node = list_get_new_node(data);

	if ((*tail) == NULL) {
		(*tail) = new_node;
		(*head) = new_node;
		return;
	}

	(*tail)->next = new_node;
	(*tail) = new_node;
}

list* pop_queue(list* head) {
	if (head == NULL) {
		printf("\nQueue is empty\n");
		return;
	}

	list* tmp = head;
	head = head->next;

	return tmp;
}

void push_twolinked_queue(twolinked_list** head, twolinked_list** tail, int data) {
	twolinked_list* tmp = twolinked_list_get_new_node(data);

	if ((*head) == NULL) {
		(*head) = tmp;
		(*tail) = tmp;
		return;
	}

	tmp->prev = (*tail);
	(*tail)->next = tmp;
	(*tail) = tmp;
}

twolinked_list* pop_twolinked_queue(twolinked_list** head) {
	if ((*head) == NULL) {
		printf("Queue is empty");
		return;
	}

	twolinked_list* tmp = (*head);
	(*head) = (*head)->next;

	return tmp;
}

void add_to_list(list** head, int data) {
	list* new_node = list_get_new_node(data);

	if (*head == NULL) {
		*head = new_node;
	}

	else {
		list* current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
	}
}

#define SIZE 8

void list_bubble_sort(list** head, int size) {
	list* previous = NULL;

	for (int i = 0; i < size; i++) {

		list* first = (*head);
		list* second = (*head)->next;

		for (int j = 0; j < size - i - 1; j++) {
			if (first->data > second->data) {
				previous = (*head);

				if (previous != first) {
					while (previous->next != first) {
						previous = previous->next;
					}
					previous->next = second;
					first->next = second->next;
					second->next = first;
				}
				else {
					first->next = second->next;
					second->next = first;
					(*head) = second;
				}
				list* tmp = first;
				first = second;
				second = tmp;
			}
			first = first->next;
			second = second->next;
		}
	}
}

void list_selection_sort(list** head, int size) {
	list* previous_fisrt = NULL;
	list* previous_second = NULL;
	list* first = NULL;
	list* second = NULL;

	for (int i = 0; i < size - 1; i++) {
		int minindex = i;

		for (int j = i + 1; j < size; j++) {
			list* first = (*head);
			list* second = (*head);

			for (int k = 0; k < minindex; k++) {
				first = first->next;
			}
			for (int p = 0; p < j; p++) {
				second = second->next;
			}
			if (second->data < first->data) {
				minindex = j;
			}
		}
		if (minindex != i) {
			previous_fisrt = (*head);
			previous_second = (*head);

			first = (*head);
			second = (*head);

			for (int t = 0; t < i; t++) {
				first = first->next;
			}
			for (int n = 0; n < minindex; n++) {
				second = second->next;
			}

			if (previous_fisrt != first) {
				while (previous_fisrt->next != first) {
					previous_fisrt = previous_fisrt->next;
				}
				while (previous_second->next != second) {
					previous_second = previous_second->next;
				}
				previous_fisrt->next = second;
				list* tmp = second->next;
				second->next = first->next;
				first->next = tmp;
				previous_second->next = first;
			}
			else {
				first->next = second->next;
				second->next = first;
				(*head) = second;
			}
			list* tmp = first;
			first = second;
			second = tmp;
		}
	}
}



int main() {
	list* list_head = NULL;

	int a = 0;
	int size = SIZE;

	for (int i = 0; i < SIZE; i++) {
		printf("\nInput num %d: ", i + 1);
		scanf_s("%d", &a);
		add_to_list(&list_head, a);
	}

	prosmotr(list_head);

	list_selection_sort(&list_head, SIZE);

	printf("\nSorted:\n");
	prosmotr(list_head);



}