#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "prime_factorization.h"

int prime_factorization(int argc, char *argv[]) {
    if (argc != 1) {
        fprintf(stderr, "usage: %s <positive-integer>\n", argv[0]);
        return 1;
    }

    long long n = atoll(argv[0]);
    if (n < 2) {
        printf("%lld has no prime factorization (need n >= 2)\n", n);
        return 0;
    }

    long long q = n;
    int first = 1;

    printf("%lld = ", n);

    while (q % 2 == 0) {
        if (!first) {
            printf(" * ");
        }
        printf("2");
        first = 0;
        q /= 2;
    }

    for (long long t = 3; t <= q / t; t += 2) {
        while (q % t == 0) {
            if (!first) {
                printf(" * ");
            }
            printf("%lld", t);
            first = 0;
            q /= t;
        }
    }

    if (q > 1) {
        if (!first) {
            printf(" * ");
        }
        printf("%lld", q);
    }

    printf("\n");
    return 0;

    // long long Q = n;
    // long long t = 2;

    // printf("%lld = ", n);

    // // pull out factor 2s
    // while (Q % 2 == 0) {
    //     printf("2");
    //     Q /= 2;
    //     if (Q > 1) printf(" * ");
    // }

    // // odd factors
    // for (t = 3; t * t <= Q; t += 2) {
    //     while (Q % t == 0) {
    //         printf("%lld", t);
    //         Q /= t;
    //         if (Q > 1) printf(" * ");
    //     }
    // }

    // // leftover prime > 1
    // if (Q > 1) printf("%lld", Q);

    // printf("\n");
    // return 0;
}
