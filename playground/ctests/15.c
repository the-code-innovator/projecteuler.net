#include <stdio.h>
#include <stdlib.h>

long double getMinLatticePaths(long double **array, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		printf("\n");
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				array[i][j] = 1;
			}
			if (i == j) {
				array[i][j] = 2 * array[i][j - 1];
			}
			if ((j < i) && (j > 0)) {
				array[i][j] = array[i][j - 1] + array[i - 1][j];
			}
			printf("%.0Lf, ", array[i][j]);
		}
	}
	long double minLatticePaths = array[rows - 1][columns - 1];
	free(array);
	return minLatticePaths;
}

int main(int argc, char *argv[]) {
	int rows, columns;
	scanf("%d", &rows);
	scanf("%d", &columns);
	long double **array = calloc(rows, sizeof(long double) * columns);
	for (int i = 0; i < rows; i++) {
		array[i] = calloc(columns, sizeof(long double));
	}
	long double minLatticePaths = getMinLatticePaths(array, rows, columns);
	printf("%.0Lf\n", minLatticePaths);
	return 0;
}
