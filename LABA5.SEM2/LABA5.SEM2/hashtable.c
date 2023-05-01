
#include "hashtable.h"

int hash_function(char* key) {
	int accumulator = 0;
	
	for (int i = 0; i < strlen(key); i++)
		accumulator += key[i];
	
	return accumulator % SIZE_OF_HASHTABLE;
}

hashtable_object* create_object(char* key, char* value) {
	hashtable_object* object = (hashtable_object*)malloc(sizeof(hashtable_object));
	
	object->key = (char*)malloc(strlen(key) + 1);
	object->value = (char*)malloc(strlen(value) + 1);

	strcpy_s(object->key, (strlen(key) + 1), key);
	strcpy_s(object->value, (strlen(value) + 1), value);

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
	free(object->key);
	free(object->value);
	free(object);
}

void free_hashtable(hashtable* table) {
	hashtable_object* object = NULL;
	
	for (int i = 0; i < table->size; i++) {
		object = table->objects[i];
		
		if (object != NULL) 
			free(object);
	}
	
	free_chains(table);
	free(table->objects);
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
				free_object(current->object);
				
				current->object = object;

				return;
			}
			current = current->next;
		}
		
		table->chains[index] = insert_list(head, object);

		return;
	}
}

void hashtable_insert(hashtable* table, char* key, char* value) {
	hashtable_object* object = create_object(key, value);

	int index = hash_function(key);

	hashtable_object* current_object = table->objects[index];

	if (current_object == NULL) {
		if (table->count == table->size) {
			printf("Insert error: hashtable is full.");
			free_object(object);
			
			return;
		}
		
		table->objects[index] = object;
		table->count++;
	}
	else {
		if (!strcmp(current_object->key, key)) {
			strcpy_s(table->objects[index]->value, strlen(table->objects[index]->value), value);
			free_object(object);

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
			return current_object->value;
		if (head == NULL)
			return NULL;
		
		current_object = head->object;
		head = head->next;
	}
	
	return NULL;
}

void print_search_resault(hashtable* table, char* key) {
	char* value = hashtable_search(table, key);

	if (value != NULL)
		printf("Key: %s, Value: %s\n", key, value);
	else {
		printf("Key: %s does not exist\n", key);
	}
}

void print_hashtable(hashtable* table) {
	printf("\n-------------------\n");
	
	for (int i = 0; i < table->size; i++) {
		if (table->objects[i] != NULL) {
			printf("Index: %d, Key: %s, Value: %s", i, table->objects[i]->key, table->objects[i]->value);
			
			if (table->chains[i] != NULL) {
				printf(" => Chains => ");
				
				list* head = table->chains[i];
				
				while (head != NULL) {
					printf("Key: %s, Value: %s", head->object->key, head->object->value);
					head = head->next;
				}
			}
			printf("\n");
		}
	
	}
	printf("\n-------------------\n");
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
	list* temp = NULL;;
	
	if (head == NULL)
		return;
	
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp->object->key);
		free(temp->object->value);
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
		free(chains[i]);
	
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
			
			free_object(object);
			
			table->count--;

			return;
		}
		else if (head != NULL) {
			if (!strcmp(object->key, key)) {
				free_object(object);
				
				list* node = head;
				head = head->next;
				node->next = NULL;
				
				table->objects[index] = create_object(node->object->key, node->object->value);
				
				free_list(node);
				
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
						
						free_list(current);

						return;
					}
					else {
						prev->next = current->next;
						current->next = NULL;
						
						free_list(current);

						return;
					}
				}
				
				prev = current;
				current = current->next;
			}
		}
	}
}