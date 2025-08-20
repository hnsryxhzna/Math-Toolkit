#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"module/vector_multiplication.h"

int parse_param(int argc, char* argv[]) {
    if (argc % 2 != 1) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    for (int counter = 0; counter < argc; counter++) {
        char *endptr;
        int value = argv[counter];

        strtod(value, &endptr);

        if (!(*endptr == '\0' && endptr != value)) {
            fprintf(stderr, "invalid input\n");
        }

        if (argv[counter] == 44) {
        }
    }

    return 0;
}

int vector_multiplication(int argc, char* argv[]) {

    

    return 0;
}
