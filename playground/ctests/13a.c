#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	long double *array = calloc(100, sizeof(long double));
	long double sum = 0.0L;
	for (int i = 0; i < 100; i++) {
		scanf("%Lf", &array[i]);
		sum += array[i];
	}
	char *string = (char*)malloc(sizeof(char) * 100);
	sprintf(string, "%.0Lf", sum);
	string[10] = '\0';
	printf("%s\n", string);
	return 0;
}
