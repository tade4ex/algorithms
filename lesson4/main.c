#include "utilus.h"

void solution1 (int x, int y, int matrix[x][y]) {
	int matrix_out[x][y];
	for (int i = 0; i < x; i++) {
		if (matrix[i][0] == 1) matrix_out[i][0] = 1;
		else if (matrix[i][0] == 0) matrix_out[i][0] = 0;
		for (int j = 0; j < y; j++) {
			if (matrix[0][j] == 1) matrix_out[0][j] = 1;
			else if (matrix[0][j] == 0) matrix_out[0][j] = 0;
			if (i > 0 && j > 0) {
				if (matrix[i][j] == 0) matrix_out[i][j] = 0;
				else matrix_out[i][j] = matrix_out[i-1][j] + matrix_out[i][j-1];
			}
		}
	}
	t_print_matrix(x, y, matrix_out);
}

int solution2 (int a, int b) {
	assert(a > b);
	int matrix[a + 1][a + 1];
	for (int _a = 0; _a < a + 1; _a++) {
		matrix[_a][0] = 1;
		for (int _b = 0; _b < _a + 1; _b++) {
			if (_b == _a) matrix[_a][_b] = 1;
			else if (_a > 1 && _b > 0) matrix[_a][_b] = matrix[_a-1][_b-1] + matrix[_a-1][_b];
		}
	}
	/* Print matrix */
	for (int i = 0; i < a+1; i++) {
		t_print_array(matrix[i], i+1);
	}
	return matrix[a][b];
}

bool t_move (int i, int j, int n, int m) {
	if (i > 0 && j > 0 && i < n && j < m) return true;
	return false;
}

/* poka chto ne rabotajet */
void solution3 (int n, int m) {
	int matrix[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = 0;
	int matrix_move[8][2] = {
		{ -1, -3 },
		{ 1, 3 },
		{ -1, 3 },
		{ 1, 3 },
		{ -3, -1 },
		{ 3, -1 },
		{ -3, 1 },
		{ 3, 1 }
	};
	for (int i = 0; i > n; i++) {
		for (int j = 0; j < m; j++) {
			for (int m = 0; m < 9; m++) {
				if (t_move(i + matrix_move[m][0], j + matrix_move[m][1], n, m)) {
					if (matrix[matrix_move[m][0] + i][matrix_move[m][1] + j] == 0)
						matrix[matrix_move[m][0] + i][matrix_move[m][1] + j] = 1;
				}
			}
		}
	}
	t_print_matrix(n, m, matrix);
}


int main () {
	printf("SOLUTION1:\n");
	int matrix[3][5] = {
		{ 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 0 },
		{ 0, 1, 0, 1, 1 }
	};
	solution1(3, 5, matrix);
	printf("\n");

	printf("SOLUTION2:\n");
	printf("(4, 2) = %d\n", solution2(4, 2));
	printf("\n");
}