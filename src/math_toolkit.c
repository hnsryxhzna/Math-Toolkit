#include <stdio.h>
#include <string.h>

#include "module/GCD_calculator.h"
#include "module/prime_factorization.h"

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "usage: %s\n \t[-g] for GCD calculation\n \t[-f] for prime factorization\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-g") == 0) {
        GCD_calculator(argc - 2, &argv[2]);
    } else if (strcmp(argv[1], "-f") == 0) {
        prime_factorization(argc - 2, &argv[2]);
    } else {
        fprintf(stderr, "unkonwn option %s\nusage: %s\n \t[-g] for GCD calculation\n \t[-f] for prime factorization\n", argv[1], argv[0]);
    }

    return 0;
}
