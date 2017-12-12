#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

void t_swap(int *a, int *b) {
   *a = *a ^ *b;
   *b = *b ^ *a;
   *a = *a ^ *b;
}

void t_print_array(int *arr, int len) {
    printf("[");
    for (int i = 0; i < len; ++i) {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}

void t_print_matrix (int x, int y, int matrix[x][y]) {
	for (int i = 0; i < x; i++) {
		printf("[");
    	for (int j = 0; j < y; ++j) printf("%d, ", matrix[i][j]);
    	printf("]\n");
	}
}

// srand(time(NULL))
void t_fill_array(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        arr[i] = rand() % 100000000;
    }
}