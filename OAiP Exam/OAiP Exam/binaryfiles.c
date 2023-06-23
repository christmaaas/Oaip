#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bin_bubble_sort(FILE* file, int size) {
	int first = 0, second = 0;

	fseek(file, 0, SEEK_SET);

	for (int i = 0; i < size; i++) {

		fseek(file, 0, SEEK_SET);
		fread(&first, sizeof(int), 1, file);

		for (int j = 0; j < size - i - 1; j++) {

			fread(&second, sizeof(int), 1, file);

			if (first > second) {
				fseek(file, j * sizeof(int), SEEK_SET);

				fwrite(&second, sizeof(int), 1, file);
				fwrite(&first, sizeof(int), 1, file);
			}
			else {
				first = second;
			}
		}
	}
}

void bin_selection_sort(FILE* file, int size) {
	int first = 0, second = 0;
	
	for (int i = 0; i < size - 1; i++) {
		int minindex = i;

		for (int j = i + 1; j < size; j++) {
			fseek(file, minindex * sizeof(int), SEEK_SET);
			fread(&first, sizeof(int), 1, file);
			fseek(file, j * sizeof(int), SEEK_SET);
			fread(&second, sizeof(int), 1, file);
			
			if (second < first) {
				minindex = j;
			}
		}
		if (minindex != i) {
			fseek(file, i * sizeof(int), SEEK_SET);
			fread(&first, sizeof(int), 1, file);

			fseek(file, minindex * sizeof(int), SEEK_SET);
			fread(&second, sizeof(int), 1, file);

			fseek(file, i * sizeof(int), SEEK_SET);
			fwrite(&second, sizeof(int), 1, file);

			fseek(file, minindex * sizeof(int), SEEK_SET);
			fwrite(&first, sizeof(int), 1, file);
		}
	}
}

void bin_insertion_sort(FILE* file, int size) {
	int first = 0, second = 0;

	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0; j--) {
			fseek(file, ((j - 1) * sizeof(int)), SEEK_SET);
			fread(&first, sizeof(int), 1, file);
			fseek(file, j * sizeof(int), SEEK_SET);
			fread(&second, sizeof(int), 1, file);

			if (first > second) {
				fseek(file, ((j - 1) * sizeof(int)), SEEK_SET);
				fwrite(&second, sizeof(int), 1, file);
				fseek(file, j * sizeof(int), SEEK_SET);
				fwrite(&first, sizeof(int), 1, file);
			}
		}
	}
}

int size_of_bin_file(FILE* file) {
	int size = 0;

	fseek(file, 0, SEEK_END);
	size = ftell(file);

	return size / 4;
}

int find_pivot_elem(FILE* file, int last) {
	int pivot_index = (0 + last) / 2;
	int pivot_elem = 0;

	fseek(file, pivot_index * sizeof(int), SEEK_SET);
	fread(&pivot_elem, sizeof(int), 1, file);

	return pivot_elem;
}

void bin_quick_sort(FILE* file, int size, int first, int last) {
	if (first < last) {
		int left = first;
		int right = last;
		int pivot = find_pivot_elem(file, last);
		int current_left = 0;
		int current_right = 0;
		int position_left = 0;
		int position_right = last * sizeof(int);

		fseek(file, 0, SEEK_SET);
		fread(&current_left, sizeof(int), 1, file);

		fseek(file, position_right, SEEK_SET);
		fread(&current_right, sizeof(int), 1, file);

		do {
			while (current_left < pivot) {
				position_left += sizeof(int);
				left++;

				fseek(file, position_left, SEEK_SET);
				fread(&current_left, sizeof(int), 1, file);
			}
			while (current_right > pivot) {
				position_right -= sizeof(int);
				right--;

				fseek(file, position_right, SEEK_SET);
				fread(&current_right, sizeof(int), 1, file);
			}
			if (current_left > current_right) {
				fseek(file, position_left, SEEK_SET);
				fwrite(&current_right, sizeof(int), 1, file);

				fseek(file, position_right, SEEK_SET);
				fwrite(&current_left, sizeof(int), 1, file);

				position_left += sizeof(int);
				position_right -= sizeof(int);
				left++;
				right--;
			}
		} while (left < right);
		bin_quick_sort(file, size, first, right);
		bin_quick_sort(file, size, left, last);
	}
}

void bin_shell_sort(FILE* file, int size) {
	int step = size / 2;
	int first = 0, second = 0;
	for (int i = step; i > 0; i /= 2) {
		for (int k = i; k < size; k++) {
			for (int j = k - i; j >= 0; j -= i) {
				fseek(file, j * sizeof(int), SEEK_SET);
				fread(&first, sizeof(int), 1, file);
				fseek(file, (j + i) * sizeof(int), SEEK_SET);
				fread(&second, sizeof(int), 1, file);

				if (first > second) {
					fseek(file, j * sizeof(int), SEEK_SET);
					fwrite(&second, sizeof(int), 1, file);
					fseek(file, (j + i) * sizeof(int), SEEK_SET);
					fwrite(&first, sizeof(int), 1, file);
				}
			}
		}
	}
}

int main() {
	FILE* file = NULL;
	int a = 0;

	fopen_s(&file, "testt.bin", "wb");

	for (int i = 0; i < 8; i++) {
		printf("\nEnter %d num: ", i + 1);
		scanf_s("%d", &a);
		fwrite(&a, sizeof(int), 1, file);
	}

	fclose(file);

	fopen_s(&file, "testt.bin", "rb+");

	fread(&a, sizeof(int), 1, file);
	while (!feof(file)) {
		printf("%d\n", a);
		fread(&a, sizeof(int), 1, file);
	}

	int size = size_of_bin_file(file);

	int last = size - 1;

	bin_quick_sort(file, size, 0, last);

	fclose(file);

}

