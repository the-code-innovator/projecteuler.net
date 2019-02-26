#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* stringReversed(char *inputString, int length) {
	char *reversed = (char*)malloc(sizeof(char) * length);
	for (int i = 0; i < length; i++) {
		reversed[i] = inputString[length - i - 1];
	}
	return reversed;
}

char** reversedStrings(char** array, int elementLength, int arrayLength) {
	char **reversed = calloc(arrayLength, sizeof(char) * elementLength);
	for (int i = 0; i < arrayLength; i++) {
		reversed[i] = (char*)malloc(sizeof(char) * elementLength);
		reversed[i] = stringReversed(array[i], elementLength);
	}
	return reversed;
}

char* firstNDigitOfSum(char** array, int elementLength, int arrayLength, int N) {
	char **transformed = reversedStrings(array, elementLength, arrayLength);
	char *sumString = (char*)malloc(sizeof(char) * 2 * elementLength);
	int carry = 0;
	for (int i = 0; i < elementLength; i++) {
		int sum = 0;
		for (int j = 0; j < arrayLength; j++) {
			char charAtIJ = transformed[j][i];
			char *string = (char*)malloc(sizeof(char) * 1);
			sprintf(string, "%c", charAtIJ);
			int elementIntAtI = atoi(string);
			sum += elementIntAtI;
		}
		int sumAtI = (sum + carry) % 10;
		char charSumAtI = sumAtI + '0';
		sumString[i] = charSumAtI;
		carry = (sum + carry) / 10;
	}
	char *carryString = (char*)malloc(sizeof(char) * (arrayLength / 2));
	sprintf(carryString, "%d", carry);
	// printf("%s->carrystring\n", carryString);
	carryString = stringReversed(carryString, strlen(carryString));
	// printf("%s->carrystring\n", carryString);
	sumString = stringReversed(sumString, strlen(sumString));
	// printf("%s->sumstring\n", sumString);
	sumString = strcat(carryString, sumString);
	printf("%s<-sumString\n", sumString);
	// return sumString;
	// char *reversedSumString = stringReversed(sumString, );
	// return sumString;
	char *ndigits = (char*)malloc(sizeof(char) * (N + 1));
	for (int i = 0; i < N; i++) {
		if (sumString[i] != '0') {
			// continue;
			ndigits[i] = sumString[i];
			// i++;
		}
		
	}
	ndigits[N] = '\0';
	return ndigits;
}

char** getStrings(int elementLength, int arrayLength) {
	char **array = calloc(arrayLength, sizeof(char) * elementLength);
	for (int i = 0; i < arrayLength; i++) {
		array[i] = (char*)malloc(sizeof(char) * elementLength);
		scanf("%s", array[i]);
	}
	return array;
}

int main(int argc, char *argv[]) {
	char **input = getStrings(4, 2);
	printf("%s\n", firstNDigitOfSum(input, 4, 2, 2));
	return 0;
}
