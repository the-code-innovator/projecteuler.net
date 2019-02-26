// Summation of primes
// website: https://projecteuler.net/problem=10
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below N.
// N = 2 * 10^6 -> projecteuler.net
// ANSWER: 142913828922
// Constraints:
// 1 <= T <= 10^4
// 1 <= N <= 10^6

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

long long int sumNPrime(int n) {
	bool *primes = calloc(n + 1, sizeof(bool));
	memset(primes, true, n + 1);
	for (int i = 2; i * i <= n; i++) {
		if (primes[i] == true) {
			for (int j = i * 2; j <= n; j += i) {
				primes[j] = false;
			}
		}
	}
	long long int sum = 0;
	for (int i = 2; i <= n; i++) {
		if (primes[i]) {
			sum += i;
		}
	}
	free(primes);
	return sum;
}

int main(int argc, char *argv[]) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", sumNPrime(n));
	}
	return 0;
}
