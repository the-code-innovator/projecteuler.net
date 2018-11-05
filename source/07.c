// 10001st prime
// website: https://projecteuler.net/problem=7
// By listing the first six prime numbers:
	// 2, 3, 5, 7, 11, and 13,
// we can see that the 6th prime is 13.
// What is the Nth prime number?
// N = 10001 -> projecteuler.net
// ANSWER: 104743
// Constraints:
// 1 <= T <= 10^3
// 1 <= N <= 10^4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int popCount(int n) {
	n -= (n >> 1) & 0x55555555;
	n = ((n >> 2) & 0x33333333) + (n & 0x33333333);
	n = ((n >> 4) & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
	return (n * 0x01010101) >> 24;
}

int primeN(int n) {
	if (n < 2) {
		return 2;
	}
	if (n == 2) {
		return 3;
	}
	if (n == 3) {
		return 5;
	}
	int limit, root, count = 2;
	limit = (int)(n * (log(n) + log(log(n)))) + 3;
	root = (int)sqrt(limit);
	switch(limit % 6) {
		case 0:
			limit = 2 * (limit / 6) - 1;
			break;
		case 5:
			limit = 2 * (limit / 6) + 1;
			break;
		default:
			limit = 2 * (limit / 6);
	}
	switch(root % 6) {
		case 0:
			root = 2 * (root / 6) - 1;
			break;
		case 5:
			root = 2 * (root / 6) + 1;
			break;
		default:
			root = 2 * (root / 6);
	}
	int dim = (limit + 31) >> 5;
	int *sieve;
	sieve = calloc(dim, sizeof(int));
	for (int i = 0; i < root; i++) {
		if ((sieve[i >> 5] & (1 << (i & 31))) == 0) {
			int start, s1, s2;
			if ((i & 1) == 1) {
				start = i * (3 * i + 8) + 4;
				s1 = 4 * i + 5;
				s2 = 2 * i + 3;
			}
			else {
				start = i * (3 * i + 10) + 7;
				s1 = 2 * i + 3;
				s2 = 4 * i + 7;
			}
			for (int j = start; j < limit; j += s2) {
				sieve[j >> 5] |= 1 << (j & 31);
				j += s1;
				if (j >= limit) {
					break;
				}
				sieve[j >> 5] |= 1 << (j & 31);
			}
		}
	}
	int i;
	for (i = 0; count < n; i++) {
		count += popCount(~sieve[i]);
	}
	--i;
	int mask = ~sieve[i];
	free(sieve);
	int p;
	for (p = 31; count >= n; --p) {
		count -= (mask >> p) & 1;
	}
	return 3 * (p + (i << 5)) + 7 + (p & 1);
}

int main(int argc, char *argv[]) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int nPrime = primeN(n);
		printf("%d\n", nPrime);
	}
	return 0;
}