
#include"Func.h"

void memory_allocate(int size, char*** string) {

	(*string) = (char**)calloc(size, sizeof(char*));
	for (int i = 0; i < size; i++) {

		(*string)[i] = (char*)calloc(1, 256);
	}
}

void memory_realloc(int size, char*** string) {

	(*string) = (char**)realloc((*string), size * sizeof(char*));
	for (int i = 0; i < size; i++) {

		(*string)[i] = (char*)realloc((*string)[i], (strlen((*string)[i]) + 1));
	}
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

int find_pattern(char* str_with_ptr, char ptr[]) {
	int i, j, k;
	for (i = 0; str_with_ptr[i] != '\0'; i++) {
		for (j = i, k = 0; ptr[k] != '\0' && str_with_ptr[j] == ptr[k]; j++, k++)
			;
		if (ptr[k] == '\0') {
			return j;
		}
	}
	return 0;
}

int len_of_ptr(char* str_with_ptr, int* index, int shift) {
	int fl = 0;
	while (str_with_ptr[(*index)] != '<') {
		(*index)++;
		fl++;
	}
	if (fl == shift) {
		return 1;
	}
	else return 0;
}

int find_pattern_for_fields(char* str_with_ptr, char ptr[], int shift_for_len, int shift_for_pos) {
	int i, j, k, pos;
	for (i = 0; str_with_ptr[i] != '\0'; i++) {
		for (j = i, k = 0; ptr[k] != '\0' && str_with_ptr[j] == ptr[k]; j++, k++)
			;
		if (ptr[k] == '\0') {
			if (len_of_ptr(str_with_ptr, &j, shift_for_len)) {
				pos = j + shift_for_pos;
				return pos;
			}
		}
	}
	return 0;
}

char* take_ptr(char* buf, int pos) {
	int i = 0;
	char* tmp = (char*)calloc(1, 1);
	while (buf[pos] != '<') {
		tmp[i] = buf[pos];
		pos++;
		i++;
		tmp = (char*)realloc(tmp, (i + 2));
	}
	tmp[i] = '\0';
	return tmp;
}

char* take_ptr_cost(char* buf, int pos) {
	int i = 0;
	char* tmp = (char*)calloc(1, 1);
	while (buf[pos] != '\"') {
		tmp[i] = buf[pos];
		pos++;
		i++;
		tmp = (char*)realloc(tmp, (i + 2));
	}
	tmp[i] = '\0';
	return tmp;
}

int* parse_ram(Laptop** array, FILE* file) {
	int pos = 0, i = 0;
	char* buf = (char*)calloc(5000, 1);
	char ptr[] = "<td class='result__attr_var  cr-result__attr_odd'>";
	int* arr = (int*)calloc(100, sizeof(int));

	fopen_s(&file, "Catalog.txt", "r");

	fgets(buf, 5000, file);
	while (!feof(file)) {
		if ((pos = find_pattern_for_fields(buf, ptr, 46, 55)) != 0) {
			arr[i] = atoi(take_ptr(buf, pos));
			i++;
		}
		fgets(buf, 5000, file);
	}
	arr = (int*)realloc(arr, (i + 1) * sizeof(int));

	fclose(file);
	free(buf);
	return arr;
}

char** parse_name(Laptop** array, FILE* file, int* size) {
	int pos = 0;
	char* buf = (char*)calloc(5000, 1);
	char** arr = NULL;
	char ptr[] = "<span class=\"result__name\">";
	memory_allocate(100, &arr);

	fopen_s(&file, "Catalog.txt", "r");

	fgets(buf, 5000, file);
	while (!feof(file)) {
		if ((pos = find_pattern(buf, ptr)) != 0) {
			arr[(*size)] = take_ptr(buf, pos + 15);
			(*size)++;
		}
		fgets(buf, 5000, file);
	}

	memory_realloc((*size), &arr);
	fclose(file);
	free(buf);
	return arr;
}

int* parse_ssd(Laptop** array, FILE* file) {
	int pos = 0, i = 0;
	char* buf = (char*)calloc(5000, 1);
	char ptr[] = "<td class='result__attr_var '>";
	int* arr = (int*)calloc(100, sizeof(int));

	fopen_s(&file, "Catalog.txt", "r");

	fgets(buf, 5000, file);
	while (!feof(file)) {
		if ((pos = find_pattern_for_fields(buf, ptr, 18, 35)) != 0) {
			arr[i] = atoi(take_ptr(buf, pos));
			i++;
		}
		fgets(buf, 5000, file);
	}
	arr = (int*)realloc(arr, (i + 1) * sizeof(int));

	fclose(file);
	free(buf);
	return arr;
}


int* parse_cost(Laptop** array, FILE* file) {
	int pos = 0, i = 0;
	char* buf = (char*)calloc(5000, 1);
	char ptr[] = "data-labels=\"\" content=\"";
	int* arr = (int*)calloc(100, sizeof(int));

	fopen_s(&file, "Catalog.txt", "r");

	fgets(buf, 5000, file);
	while (!feof(file)) {
		if ((pos = find_pattern(buf, ptr)) != 0) {
			arr[i] = atoi(take_ptr_cost(buf, pos));
			i++;
		}
		fgets(buf, 5000, file);
	}
	arr = (int*)realloc(arr, (i + 1) * sizeof(int));

	fclose(file);
	free(buf);
	return arr;
}

int calculate_size(Laptop** array) {
	FILE* file = NULL;
	int size_for_parse = 0;
	char* buf = (char*)calloc(5000, 1);
	char ptr[] = "<span class=\"result__name\">";

	fopen_s(&file, "Catalog.txt", "r");

	fgets(buf, 5000, file);
	while (!feof(file)) {
		if (find_pattern(buf, ptr) != 0) {
			size_for_parse++;
		}
		fgets(buf, 5000, file);
	}
	fclose(file);
	free(buf);
	return size_for_parse;
}

void memorystr(char** str) {
	(*str) = (char*)malloc(255);
}

void parse(Laptop** array, FILE* file, int* size) {
	char** name = parse_name(array, file, size);
	int* arr1 = parse_cost(array, file);
	int* arr2 = parse_ram(array, file);
	int* arr3 = parse_ssd(array, file);
	for (int i = 0; i < (*size); i++) {
		memorystr(&(*array)[i].name);
		(*array)[i].name = name[i];
		(*array)[i].cost = arr1[i];
		(*array)[i].ram_mem = arr2[i];
		(*array)[i].ssd_mem = arr3[i];
	}
	output(array, size);
}