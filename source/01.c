// Multiples of 3 and 5
// website: https://projecteuler.net/problem=1
// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
// The sum of these multiples is 23. 
// Find the sum of all the multiples of 3 or 5 below N.
// N = 1000 -> projecteuler.net
// ANSWER: 233168
// Constraints:
// 1 <= T <= 10^5
// 1 <= N <= 10^9

#include <stdio.h>

int main(int argc, char *argv[]) {
	int t;
	scanf("%d", &t);
	while (t--) {
		long int sum = 0;
		long int n;
		scanf("%ld", &n);
		long int limit3 = (n - 1) / 3;
		long int limit5 = (n - 1) / 5;
		long int limit15 = (n - 1) / 15;
		long int sum3 = 3 * ((limit3 * (limit3 + 1)) / 2);
		long int sum5 = 5 * ((limit5 * (limit5 + 1)) / 2);
		long int sum15 = 15 * ((limit15 * (limit15 + 1)) / 2);
		sum = sum3 + sum5 - sum15;
		printf("%ld\n", sum);
	}
	return 0;
}