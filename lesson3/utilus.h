#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// srand(time(NULL))
void t_fill_array(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        arr[i] = rand() % 100000000;
    }
}