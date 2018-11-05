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
#include <stdlib.h>

int pythagoreanTriplets(int limit) {
	int a = 0;
	int b = 0;
	int c = 0;
	int m = 2;
	while (c < limit) {
		for (int n = 1; n < m; n++) {
			a = (m * m) - (n * n);
			b = (2 * m * n);
			c = (m * m) + (n * n);
			int sumE = ((a + b + c) == limit) ? 1 : 0;
			int value = (sumE == 1) ? (a * b * c) : 0;
			if (value != 0) {
				return value;
			}
		}
		m++;
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", pythagoreanTriplets(n));
	}
	return 0;
}