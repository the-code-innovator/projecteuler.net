// Special Pythagorean Triplet
// website: https://projecteuler.net/problem=9
// A Pythagorean triplet is a set of three natural numbers,
// 	a < b < c,
// 	for which,
// 		a^2 + b^2 = c^2
// For example,
// 	3^2 + 4^2 = 9 + 16 = 25 = 5^2.
// There exists exactly one Pythagorean triplet for which a + b + c = N.
// Find the product abc.
// If there is no such Pythagorean triplet print.
// N = 1000 -> projecteuler.net
// ANSWER: 31875000
// Contraints:
// 1 <= T <= 3000
// 1 <= N <= 3000

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct pythagorean_triplet {
	double adjacent;
	double opposite;
	double hypotentuse;
} triplet_t;

triplet_t __initialise__(double m, double n) {
	triplet_t found = {(pow(n, 2.0) - pow(m, 2.0)), (2.0 * m * n), (pow(m, 2.0) + pow(n, 2.0))};
	return found;
}

triplet_t get_triplet(double input) {
	return __initialise__(input, (input + 1.0));
}

triplet_t* __get_triplet_array__(int count) {
	triplet_t *triplet_array;
	triplet_array = calloc(count, sizeof(triplet_t));
	for (int i = 0; i < count; i++) {
		triplet_array[i] = get_triplet((double)(i + 1));
	}
	return triplet_array;
}

triplet_t* get_array(int count) {
	return __get_triplet_array__(count);
}

void __put_triplet__(triplet_t input) {
	printf("<%.0lF, %.0lF, %.0lF>\n", input.adjacent, input.opposite, input.hypotentuse);
}

void __put_triplet_array__(triplet_t* array) {
	for (int i = 0; i < (sizeof(array) / sizeof(triplet_t)); i++) {
		__put_triplet__(array[i]);
	}
}

void put_array(triplet_t* input_array) {
	__put_triplet_array__(input_array);
}

int main(int argc, char *argv[]) {
	triplet_t *array;
	array = get_array(5);
	put_array(array);
	return 0;
}
