// Smallest multiple
// website: https://projecteuler.net/problem=5
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to N?
// N = 20 -> projecteuler.net
// ANSWER: 232792560
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 40

// SET: Z+ = {i: i ∈ [1, ∞)}, P(n) = {j: j ∈ {2, 3, 5, 7, ...} and j < n}, L(P(n)) = {l ∈ Z+ : p^l < n}
// TIP: m | i, ∀ i ∈ [1, n] <=> m = (p ∈ P(n))∏{p^k}, where p^k | m and k = max(L(P(n)))
// FOR EXAMPLE: 2520 = 2^3 * 3^2 * 5 * 7.

#include <stdio.h>

int main(int argc, char *argv[]) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
		int maxPrimeIndex = 0;
		for (; maxPrimeIndex < (sizeof(primes) / sizeof(int)); maxPrimeIndex++) {
			if (primes[maxPrimeIndex] > n) {
				break;
			}
		}
		int minMultiple = 1;
		for (int i = 0; i < maxPrimeIndex; i++) {
			int basePrime = primes[i];
			while (basePrime <= n) {
				basePrime *= primes[i];
			}
			basePrime = basePrime / primes[i];
			minMultiple *= basePrime;
		}
		printf("%d\n", minMultiple);
	}
	return 0;
}