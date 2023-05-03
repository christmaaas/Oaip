
#include "hashtable.h"
#include "cache.h"

int hash_function(char* key) {
	int accumulator = 0;
	
	for (int i = 0; i < strlen(key); i++)
		accumulator += key[i];
	
	return accumulator % SIZE_OF_CACHE;
}

hashtable_object* create_object(char* key, node* head) {
	hashtable_object* object = (hashtable_object*)malloc(sizeof(hashtable_object));
	
	object->head = head;
	object->key = key;

	return object;
}

hashtable* create_table(int size_of_table) {
	hashtable* table = (hashtable*)malloc(sizeof(hashtable));
	
	table->size = size_of_table;
	table->count = EMPTY_TABLE;
	table->objects = (hashtable**)malloc(size_of_table * sizeof(hashtable_object*));
	
	for (int i = 0; i < size_of_table; i++) 
		table->objects[i] = NULL;

	table->chains = create_chains(table);

	return table;
}

void free_object(hashtable_object* object) {
	free(object->head->value);
	free(object->key);
	free(object);
}

void free_hashtable(hashtable* table) {
	hashtable_object* object = NULL;
	
	for (int i = 0; i < table->size; i++) {
		object = table->objects[i];
		
		if (object != NULL)
			free_object(object);
	}
	
	free_chains(table);
	free(table);
}

void collision_prevention(hashtable* table, int index, hashtable_object* object) {
	list* head = table->chains[index];

	if (head == NULL) {
		head = create_list();
		head->object = object;
		head->next = NULL;
		table->chains[index] = head;
		
		return;
	}
	else {
		list* current = table->chains[index];

		while (current != NULL) {
			if (!strcmp(current->object->key, object->key)) {
				free(current->object->head->value);

				current->object->head->value = object->head->value;

				return;
			}
			current = current->next;
		}
		
		table->chains[index] = insert_list(head, object);

		return;
	}
}

void hashtable_insert(hashtable* table, char* key, node* head) {
	hashtable_object* object = create_object(key, head);

	int index = hash_function(key);

	hashtable_object* current_object = table->objects[index];

	if (current_object == NULL) {
		table->objects[index] = object;
		table->count++;
	}
	else {
		if (!strcmp(current_object->key, key)) {
			
			free(current_object->head->value);
			
			current_object->head->value = head->value;

			return;
		}
		else {
			collision_prevention(table, index, object);

			return;
		}
	}
}

char* hashtable_search(hashtable* table, char* key) {
	int index = hash_function(key);

	hashtable_object* current_object = table->objects[index];
	list* head = table->chains[index];

	while (current_object != NULL) {
		if (!strcmp(current_object->key, key)) 
			return current_object->head->value;
		if (head == NULL)
			return NULL;
		
		current_object = head->object;
		head = head->next;
	}
	
	return NULL;
}

list* create_list() {
	list* new_list = (list*)malloc(sizeof(list));
	
	return new_list;
}

list* insert_list(list* head, hashtable_object* object) {
	if (head == NULL) {
		list* new_list = create_list();
		
		new_list->object = object;
		new_list->next = NULL;
		head = new_list;
		
		return new_list;
	}
	else {
		list* temp = head;
		
		while (temp->next != NULL)
			temp = temp->next;

		list* node = create_list();
		
		node->object = object;
		node->next = NULL;
		temp->next = node;

		return head;
	}
}

void free_list(list* head) {
	list* temp = NULL;
	
	if (head == NULL)
		return;
	
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp->object->key);
		free(temp->object->head->value);
		free(temp->object);
		free(temp);
	}
}

list* create_chains(hashtable* table) {
	list** chains = (list**)malloc(table->size * sizeof(list*));
	
	for (int i = 0; i < table->size; i++) {
		chains[i] = NULL;
	}
	
	return chains;
}

void free_chains(hashtable* table) {
	list** chains = table->chains;

	for (int i = 0; i < table->size; i++) 
		free_list(chains[i]);
	
	free(chains);
}

void hashtable_delete(hashtable* table, char* key) {
	int index = hash_function(key);

	hashtable_object* object = table->objects[index];

	list* head = table->chains[index];

	if (object == NULL) {
		return;
	}
	else {
		if (!strcmp(object->key, key) && head == NULL) {
			
			table->objects[index] = NULL;
			
			table->count--;

			return;
		}
		else if (head != NULL) {
			if (!strcmp(object->key, key)) {
				
				list* node = head;
				head = head->next;
				node->next = NULL;
				
				table->objects[index] = create_object(node->object->key, node->object->head);
				
				table->chains[index] = head;

				return;
			}
			
			list* current = head;
			list* prev = NULL;
		
			while (current != NULL) {
				if (!strcmp(current->object->key, key)) {
					if (prev == NULL) {
						table->chains[index] = head->next;
						current->next = NULL;

						return;
					}
					else {
						prev->next = current->next;
						current->next = NULL;

						return;
					}
				}
				
				prev = current;
				current = current->next;
			}
		}
	}
}