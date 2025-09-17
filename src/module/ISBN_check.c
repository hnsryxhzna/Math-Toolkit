#include <stdio.h>
#include <stdlib.h>

#include "ISBN_check.h"

int isbn_check(int argc, char *argv[]) {
    if (argc != 1) {
        fprintf(stderr, "an integer should be entered\n");
        return 1;
    }

    char *isbn = argv[0];
    int sum = 0;

    for (int i = 0; i < 10; i++) {
        int number = isbn[0] - '0';
        sum += number * (i + 1);
    }

    while (sum > 0) {
        sum -= 11;
        if (sum == 0) {
            printf("Valid ISBN\n");
        } else if (sum < 0) {
            printf("Invalid ISBN\n");
        }
    }

    return 0;
}
