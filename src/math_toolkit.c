#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "module/GCD_calculator.h"
#include "module/prime_factorization.h"
#include "module/vector_multiplication.h"
#include "module/ISBN_check.h"

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "usage: %s\n \t[-g] for GCD calculation\n \t[-f] for prime factorization\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "-g") == 0) {
        GCD_calculator(argc - 2, &argv[2]);
    } else if (strcmp(argv[1], "-f") == 0) {
        prime_factorization(argc - 2, &argv[2]);
    } else if (strcmp(argv[1], "-v") == 0) {
        vector_multiplication(argc - 2, &argv[2]);
    } else if (strcmp(argv[1], "-i") == 0) {
        isbn_check(argc - 2, &argv[2]);
    } else {
        fprintf(stderr, "unkonwn option %s\nusage: %s\n \t[-g] for GCD calculation\n \t[-f] for prime factorization\n", argv[1], argv[0]);
    }

    return 0;
}

