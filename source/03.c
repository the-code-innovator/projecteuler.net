// Largest prime factor
// website: https://projecteuler.net/problem=3
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number N ?
// N = 600851475143 -> projecteuler.net
// ANSWER: 6857
// Constraints:
// 1 <= T <= 10
// 10 <= N <= 10^12

#include <stdio.h>

int main(int argc, char *argv[]) {
	int t;
	scanf("%d", &t);
	while (t--) {
		long int n;
		scanf("%ld", &n);
		long int temp = n;
		long int largestFactor = 0;
		long int primeCounter = 2;
		while (primeCounter * primeCounter <= temp) {
			if (temp % primeCounter == 0) {
				temp = temp / primeCounter;
				largestFactor = primeCounter;
			}
			else {
				primeCounter = (primeCounter == 2) ? 3 : primeCounter + 2;
			}
		}
		if (temp > largestFactor) {
			largestFactor = temp;
		}
		printf("%ld\n", largestFactor);
	}
	return 0;
}