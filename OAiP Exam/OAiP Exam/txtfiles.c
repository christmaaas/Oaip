#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void square(FILE* file1, FILE* file2) {
    int num = 0;
    while (!feof(file1)) {
        fscanf_s(file1, "%d", &num);
        num *= num;
        fprintf(file2, "%d ", num);
    }
}


int main() {
    FILE* file1 = NULL;
    FILE* file2 = NULL;

    int num = 0;

    fopen_s(&file1, "square1.txt", "r");
    fopen_s(&file2, "square2.txt", "w");

    square(file1, file2);

    fclose(file1);
    fclose(file2);

    fopen_s(&file2, "square2.txt", "r");

    fscanf_s(file2, "%d", &num);
    while (!feof(file2)) {
        printf("%d ", num);
        fscanf_s(file2, "%d", &num);
    }

    fclose(file2);




    return 0;
}
