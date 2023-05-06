#include "array.h"
#include "struct.h"
#include "recources.h"

void delete(Laptop** array, int* size) {
	int k = 0;
	
	printf("\n--------------- DELETE ---------------\n");
	printf("Enter a number of a laptop to delete: ");
	
	k = input_k_num(size);
	
	free((*array)[k - 1].name);
	
	for (int i = (k - 1); i < (*size); i++) {
		(*array)[i] = (*array)[i + 1];
	}
	(*size)--;
	(*array) = (Laptop*)realloc((*array), (*size) * sizeof(Laptop));
	
	printf("\n--- LAPTOP NUMBER %d WAS DELETED ---\n", k);
	printf("--------------------------------------\n");
	output(array, size);
}

void init_laptop(Laptop** array, int* size) {
	Laptop tmp;
	
	printf("\n--------- INIT LAPTOP ---------\n");
	printf("Enter a name of laptop: ");
	tmp.name = input_str();
	
	printf("\nEnter a cost (in Rubles) of %s: ", tmp.name);
	tmp.cost = input_cost();
	
	printf("\nEnter a RAM (4GB/8GB/16GB) of %s: ", tmp.name);
	tmp.ram_mem = enum_push(input_ram());
	
	printf("\nEnter a SSD (128GB/256GB/512GB/1024GB) capacity of %s: ", tmp.name);
	tmp.ssd_mem = input_ssd();
	
	push_laptop_in_array(tmp, array, size);
	
	printf("---------------------------------\n");
	output(array, size);
}

void init_new_array(Laptop** array, int* size) {
	for (int i = (*size) - 1; i >= 0; i--) {
		
		free((*array)[i].name);
		
		(*size)--;
		(*array) = (Laptop*)realloc((*array), (*size) * sizeof(Laptop));
	}
	
	printf("\n-------------------------\n");
	printf("--- ARRAY WAS DELETED ---\n");
	printf("-------------------------\n");
	
	init_laptop(array, size);
}

void push_laptop_in_array(Laptop lap, Laptop** array, int* size) {
	(*size)++;
	if ((*array) == NULL) {
		(*array) = (Laptop*)malloc((*size) * sizeof(lap));
	}
	else {
		(*array) = (Laptop*)realloc((*array), (*size) * sizeof(lap));
	}
	(*array)[(*size) - 1] = lap;
}

Laptop* mem_for_struct_array(int size) {
	Laptop* tmp = (Laptop*)malloc(size * sizeof(Laptop));
	
	return tmp;
}