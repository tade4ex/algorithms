#include "utilus.h"

void t_buble_sort (int * arr, int len) {
	bool not_change;
	int op = 2;
	for (int i = 0; i < len; ++i) { op+=2;
		not_change = true; op+=2;
		for (int j = 0; j < len-1; ++j) { op+=3;
			if (arr[j] > arr[j + 1]) {
				t_swap(&arr[j], &arr[j + 1]);
				not_change = false;
				op+=2;
			}
		}
		if (not_change) break;
		op++;
	}
	// printf("len = %d, operaions=%d\n", len, op);
}

void t_shaker_sort (int * arr, int len) {
	int op = 2;
	for (int i = 0; i < len; ++i) { op+= 2;
		int j = i; op++;
		for (; j < (len - i - 1); ++j) {
			if (arr[j] > arr[j + 1]) {
				t_swap(&arr[j], &arr[j + 1]); op++;
			}
			 op+= 3;
		}
		for (; j > i; --j) {
			if (arr[j - 1] > arr[j]) {
				t_swap(&arr[j - 1], &arr[j]);
				op++;
			}
			op+= 3;
		}
	}
	// printf("len = %d, operaions=%d\n", len, op);
}

int t_bin_search (int f, int * arr, int len) {
	int l = 0, r = len - 1, m = r / 2;
	while (l <= r && arr[m] != f) {
		if (arr[m] < f) l = m + 1;
		else r = m - 1;
		m = l + (r - l) / 2;
		if (arr[m] == f) return m;
	}
	return -1;
}


int main () {
	int len_arr = 1000000, arr[len_arr];
	
	t_fill_array(arr, len_arr);

	// t_print_array(arr, len_arr);

	// t_buble_sort(arr, len_arr);
	t_shaker_sort(arr, len_arr);

	// t_print_array(arr, len_arr);

	// int f = 94;
	// int key = t_bin_search(f, arr, len_arr);
	// printf("%d => %d\n", f, key);

	return 0;
}

/*

|--------------|--------------------|--------------------|--------------------|
| len          | 10                 | 100                | 10000              |
|--------------|--------------------|--------------------|--------------------|
| bubble sort  | 339                | 31755              | 345186513          |
|--------------|--------------------|--------------------|--------------------|
| shaker sort  | 207                | 17740              | 174938413          |
|--------------|--------------------|--------------------|--------------------|

*/