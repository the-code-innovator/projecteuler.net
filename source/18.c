#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

long max(long long element1, long long element2) {return (element1 > element2) ? element1 : element2;}
long long triangle_number(long long input) {return (input * (input + 1LL)) / 2LL;}
long long getIndex(long long i, long long j) {return (triangle_number(i) + j);}


int main(int argc, char *argv[]) {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long input;
        scanf("%lld", &input);
        long long *pyramid = calloc(triangle_number(input), sizeof(long long));
        for (long long i = 0LL; i < triangle_number(input); i++) {
            scanf("%lld", &pyramid[i]);
        }
        for (long long i = (input - 2LL); i >= 0LL; i--) {
            for (long long j = 0LL; j <= i; j++) {
                pyramid[getIndex(i, j)] += max(pyramid[getIndex((i + 1LL), j)], pyramid[getIndex((i + 1LL), (j + 1LL))]);
            }
        }
        printf("%lld\n", pyramid[0LL]);
    }
	return 0;
}

