#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "prime_factorization.h"

int prime_factorization(int argc, char *argv[]) {
    if (argc != 1) {
        fprintf(stderr, "an integer should be entered\n");
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[0]);
    int t = 2;
    int Q;

    Q = n;
    int nowQ = sqrt(Q);

    while (t < nowQ) {
        if (Q % t == 0) {
            printf("%d * ", t);
            Q = Q / t;
            nowQ = sqrt(Q);
        } else {
            t++;
        }
    }

    if (Q == n) {
        printf("n is prime\n");
    } else {
        printf("%d = %d\n", Q, n);
    }

    return 0;
}
