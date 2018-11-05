// Largest palindrome product
// website: https://projecteuler.net/problem=4
// A palindromic number reads the same both ways.
// The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers which is less than N.
// N = 997799 -> projecteuler.net
// ANSWER: 906609
// Constraints:
// 1 <= T <= 100
// 101101 <= N < 997799

#include <stdio.h>
#include <stdlib.h>

int divisibleBy3Digit(int input) {
	for (int i = 999; i >= 100; i--) {
		if ((input % i == 0) && ((input / i) <= 999) && ((input / i) >= 100)) {
			return 1;
		}
	}
	return 0;
}

int palindrome(int input) {
	int number = input * 1000;
	int remaining = 0;
	while (input > 0) {
		int remainder = input % 10;
		remaining = (remaining * 10) + remainder;
		input /= 10;
	}
	return (number + remaining);
}

int main(int argc, char *argv[]) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int firstHalf = 999;
		int palindromic = 0;
		int isDivisible = 0;
		for (int  i = firstHalf; i >= 100; i--) {
			palindromic = palindrome(i);
			isDivisible = divisibleBy3Digit(palindromic);
			if ((palindromic <= n) && (isDivisible == 1)) {
				printf("%d\n", palindromic);
				break;
			}
		}
	}
	return 0;
}