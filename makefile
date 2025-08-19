CFLAGS  := -Wall -Wextra -O2
CC      := gcc

#########################################################

# SRC_DIR := src
# SRCS    := $(wildcard $(SRC_DIR)/*.c)
# TARGETS := $(patsubst $(SRC_DIR)/%.c,%,$(SRCS))

.PHONY: all
all: math_toolkit

math_toolkit:
	$(CC) $(CFLAGS) ./src/module/GCD_calculator.c ./src/module/prime_factorization.c ./src/math_toolkit.c -o math_toolkit

# %: $(SRC_DIR)/%.c
# 	$(CC) $(CFLAGS) $< -o $@

# clean:
# 	rm -f $(TARGETS)


.PHONY: clean
clean:
	rm -f math_toolkit
