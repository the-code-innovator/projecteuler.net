// Sum square difference
// website: https://projecteuler.net/problem=6
// The sum of the squares of the first ten natural numbers is,
// 1^2 + 2^2 + .. + 10^2 = 385
// The square of the sum of the first ten natural numbers is,
// (1 + 2 + .. + 10)^2 = 55^2 = 3025
// Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
// Find the difference between the sum of the squares of the first N natural numbers and the square of the sum.
// N = 100 -> projecteuler.net
// ANSWER: 251641501
// Constraints:
// 1 <= T <= 10^4
// 1 <= N <= 10^4

#include <stdio.h>

int main(int argc, char *argv[]) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		long int s1 = (n * (n + 1)) / 2;
        s1 = s1 * s1;
        long int s2 = n * (n + 1);
        int s3 = 2 * n + 1;
        s2 = s2 * s3;
        s2 = s2 / 6;
        long int difference = s1 - s2;
		printf("%ld\n", difference);
	}
	return 0;
}