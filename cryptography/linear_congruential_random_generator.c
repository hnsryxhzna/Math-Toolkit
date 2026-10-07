#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(NULL));

    uint64_t a = pow(13, 13);
    uint64_t b = 0;
    uint64_t m = pow(2, 59);
    uint64_t seed = rand();
    int iteration = m % seed;

    for (int i = 0; i < iteration; i++) {
        seed = (a * seed + b) % m;
    }

    printf("%llu\n", seed);

    return seed;
}
