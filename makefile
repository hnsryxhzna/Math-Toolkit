CFLAGS  := -Wall -Wextra -O2
CC      := gcc

#########################################################

.PHONY: all
all: math_toolkit

math_toolkit:
	$(CC) $(CFLAGS) ./src/module/GCD_calculator.c ./src/module/prime_factorization.c ./src/module/vector_multiplication.c  ./src/math_toolkit.c -o math_toolkit

.PHONY: clean
clean:
	rm -f math_toolkit
