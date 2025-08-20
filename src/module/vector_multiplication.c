#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "vector_multiplication.h"

int get_mid(int argc) {
    return argc / 2;
}

int get_vector_size(int argc) {
    return argc / 2;
}

char** convert_into_vector(int vector_size, char *argv[], double *vector) {
    for (int i = 0; i < vector_size; i++) {
        char *endptr; 
        vector[i] = strtod(*argv, &endptr);

        if (!(*endptr == '\0' && endptr != *argv)) {
            fprintf(stderr, "input should be a valid number\n");
            return argv;
        }

        argv++;
    }

    return argv;
}

int parse_param(int argc, char* argv[], double *vector1, double *vector2) {
    int mid = get_mid(argc);
    int vector_size = get_vector_size(argc);

    if (strcmp(argv[mid], ",") != 0) {
        fprintf(stderr, "usage: [vector1] , [vector2]\n");
        return 1;
    } else if (argc % 2 != 1) {
        fprintf(stderr, "invalid input: two vectors should be in same size\n");
        return 1;
    }

    argv = convert_into_vector(vector_size, argv, vector1);
    argv++;
    argv = convert_into_vector(vector_size, argv, vector2);

    // TODO: if mid == 1
    return 0;
}

double vector_mul(double *vector1, double *vector2, int vector_size) {
    double result = 0;

    for (int i = 0; i < vector_size; i++) {
        result += vector1[i] * vector2[i];
    }

    return result;
}

int vector_multiplication(int argc, char* argv[]) {
    int vector_size = get_vector_size(argc);

    double *vec1 = malloc(vector_size * sizeof(double));
    double *vec2 = malloc(vector_size * sizeof(double));

    parse_param(argc, argv, vec1, vec2);
    printf("%f\n", vector_mul(vec1, vec2, vector_size));

    free(vec1);
    free(vec2);

    return 0;
}

