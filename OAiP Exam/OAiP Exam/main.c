#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int data;
	struct list* next;
} list;

typedef struct ring {
	int data;
	struct ring* next;
} ring;

typedef struct twolist {
	int data;
	struct twolist* next;
	struct twolist* prev;
} twolist;

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

twolist* twolist_get_new_node(int data) {
	twolist* node = (twolist*)malloc(sizeof(twolist));

	node->data = data;
	node->next = NULL;
	node->prev = NULL;

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

void twolist_prosmotr(twolist* head) {
	twolist* tmp = head;
	
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

void add_to_twolist(twolist** head, int data) {
	twolist* new_node = twolist_get_new_node(data);

	if ((*head) == NULL) {
		(*head) = new_node;
	}

	else {
		twolist* current = (*head);
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
		new_node->prev = current;
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

void list_insertion_sort(list** head, int size) {
	list* previous = NULL;
	list* first = NULL;
	list* second = NULL;

	for (int i = 1; i < size; i++) {

		for (int j = i; j > 0; j--) {
			
			list* first = (*head);
			list* second = (*head);

			for (int t = 0; t < j; t++) {
				second = second->next;
			}

			for (int p = 0; p < (j - 1); p++) {
				first = first->next;
			}

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
		}
	}
}

void ring_push(ring** head, int data) {
	ring* temp;
	temp = (ring*)malloc(sizeof(ring));
	temp->next = NULL;
	temp->data = data;
	if ((*head) == NULL)
	{
		temp->next = temp;
		(*head) = temp;

	}
	else
	{
		temp->next = (*head)->next;
		(*head)->next = temp;
	}
}

void two_ring_push(twolist** head, int data) {
	twolist* temp = NULL;
	temp = (twolist*)malloc(sizeof(twolist));
	
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;

	if ((*head) == NULL) {
		temp->next = temp;
		temp->prev = temp;
		(*head) = temp;
	}
	else {
		temp->next = (*head)->next;
		(*head)->next->prev = temp;
		(*head)->next = temp;
		temp->prev = (*head);
		//(*head) = temp;
	}
}

void ring_prosmotr(ring* head) {
	ring* temp = head;

	do {
		printf("\nRing: %d", temp->data);
		temp = temp->next;
	} while (temp != head);
}

void two_ring_prosmotr(twolist* head) {
	twolist* temp = head;

	do {
		printf("\nRing: %d", temp->data);
		temp = temp->next;
	} while (temp != head);
}

void ring_bubble_sort(ring** head, int size) {
	ring* previous = NULL;

	for (int i = 0; i < size; i++) {

		ring* first = (*head);
		ring* second = (*head)->next;

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
				ring* tmp = first;
				first = second;
				second = tmp;
			}
			first = first->next;
			second = second->next;
		}
	}
}

void ring_selection_sort(ring** head, int size) {
	ring* previous_fisrt = NULL;
	ring* previous_second = NULL;
	ring* first = NULL;
	ring* second = NULL;

	for (int i = 0; i < size - 1; i++) {
		int minindex = i;

		for (int j = i + 1; j < size; j++) {
			ring* first = (*head);
			ring* second = (*head);

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
				ring* tmp = second->next;
				second->next = first->next;
				first->next = tmp;
				previous_second->next = first;
			}
			else {
				first->next = second->next;
				second->next = first;
				(*head) = second;
			}
			ring* tmp = first;
			first = second;
			second = tmp;
		}
	}
}

void ring_insertion_sort(ring** head, int size) {
	ring* previous = NULL;
	ring* first = NULL;
	ring* second = NULL;

	for (int i = 1; i < size; i++) {

		for (int j = i; j > 0; j--) {

			ring* first = (*head);
			ring* second = (*head);

			for (int t = 0; t < j; t++) {
				second = second->next;
			}

			for (int p = 0; p < (j - 1); p++) {
				first = first->next;
			}

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

				ring* tmp = first;
				first = second;
				second = tmp;
			}
		}
	}
}

void twolist_bubble_sort(twolist** head, int size) {
	for (int i = 0; i < size; i++) {
		
		twolist* first = (*head);
		twolist* second = (*head)->next;

		for (int j = 0; j < size - i - 1; j++) {
			if (first->data > second->data) {
				if (first != (*head)) {
					first->prev->next = second;
					second->prev = first->prev;
					second->next->prev = first;
					first->next = second->next;
					second->next = first;
					first->prev = second;
				}
				else {
					first->next = second->next;
					first->prev = second;
					second->next->prev = first;
					second->next = first;
					(*head) = second;
				}
				twolist* tmp = first;
				first = second;
				second = tmp;
			}
			first = first->next;
			second = second->next;
		}
	}
}

void twolist_selection_sort(twolist** head, int size) {
	twolist* first = NULL;
	twolist* second = NULL;

	for (int i = 0; i < size - 1; i++) {
		
		int minindex = i;

		for (int j = i + 1; j < size; j++) {

			first = (*head);
			second = (*head);

			for (int k = 0; k < minindex; k++) {
				first = first->next;
			}

			for (int p = 0; p < j; p++) {
				second = second->next;
			}

			if (first->data > second->data) {
				minindex = j;
			}
		}
		if (minindex != i) {
			first = (*head);
			second = (*head);

			for (int t = 0; t < i; t++) {
				first = first->next;
			}

			for (int n = 0; n < minindex; n++) {
				second = second->next;
			}

			if (first != (*head)) {
				second->prev->next = first;
				first->prev->next = second;
				
				first->next->prev = second;
				second->next->prev = first;
				
				twolist* tmp1 = first->next;
				first->next = second->next;
				second->next = tmp1;
				
				twolist* tmp2 = first->prev;
				first->prev = second->prev;
				second->prev = tmp2;
			}
			else {
				second->next->prev = first;
				first->next = second->next;
				second->next = first;
				first->prev = second;
				(*head) = second;
			}
			list* tmp = first;
			first = second;
			second = tmp;
		}
	}
}

void list_reverse(list** head, int size) {
	
	int pivot = size / 2;
	int first_count = 0;
	int second_count = size - 1;

	for (int i = 0; i < pivot; i++) {
		
		list* first = (*head);
		list* second = (*head);

		list* prev_first = (*head);
		list* prev_second = (*head);

		for (int t = 0; t < first_count; t++) {
			first = first->next;
		}
	
		for (int p = 0; p < second_count; p++) {
			second = second->next;
		}
		
		if (first->next == second) {
			while (prev_first->next != first) {
				prev_first = prev_first->next;
			}
			prev_first->next = second;
			first->next = second->next;
			second->next = first;

			continue;
		}

		if (first != (*head)) {
			
			while (prev_first->next != first) {
				prev_first = prev_first->next;
			}
		
			while (prev_second->next != second) {
				prev_second = prev_second->next;
			}
			
			prev_first->next = second;
			list* tmp = second->next;
			second->next = first->next;
			first->next = tmp;
			prev_second->next = first;

		}
		else {
			
			while (prev_second->next != second) {
				prev_second = prev_second->next;
			}
			
			second->next = first->next;
			first->next = NULL;
			prev_second->next = first;
			(*head) = second;
		}
	
		list* tmp = first;
		first = second;
		second = tmp;

		first_count++;
		second_count--;
	
	}
}

void twolist_insertion_sort(twolist** head, int size) {
	
	twolist* first = NULL;
	twolist* second = NULL;
	
	for (int i = 1; i < size; i++) {
		
		for (int j = i; j > 0; j--) {
			
			first = (*head);
			second = (*head);

			for (int t = 0; t < j; t++) {
				second = second->next;
			}

			for (int p = 0; p < (j - 1); p++) {
				first = first->next;
			}

			if (first->data > second->data) {
				if (first != (*head)) {
					first->prev->next = second;
					second->prev = first->prev;
					second->next->prev = first;
					first->next = second->next;
					second->next = first;
					first->prev = second;
				}
				else {
					first->next = second->next;
					first->prev = second;
					second->next->prev = first;
					second->next = first;
					(*head) = second;
				}
				twolist* tmp = first;
				first = second;
				second = tmp;
			}
		}
	}
}

void delete(twolist** head) {
	twolist* tmp = (*head);
	
	for (int i = 0; i < 3; i++) {
		tmp = tmp->next;
	}

	twolist* todelete = tmp->next;

	tmp->next = tmp->next->next;
	tmp->next->prev = tmp;

	free(todelete);
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

	list_insertion_sort(&list_head, SIZE);

	printf("\nSorted:\n");
	prosmotr(list_head);
	twolist* head = NULL;

	int num = 0;

	for (int i = 0; i < SIZE; i++) {
		printf("\nInput num %d: ", i + 1);
		scanf_s("%d", &num);
		add_to_twolist(&head, num);
	}

	twolist_prosmotr(head);

	delete(&head);

	printf("\deleted: \n");

	twolist_prosmotr(head);






}