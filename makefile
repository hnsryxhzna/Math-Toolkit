CFLAGS  := -Wall -Wextra -O2
CC      := gcc

#########################################################

SRC_DIR := src
SRCS    := $(wildcard $(SRC_DIR)/*.c)
TARGETS := $(patsubst $(SRC_DIR)/%.c,%,$(SRCS))

.PHONY: all clean

all: $(TARGETS)

%: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)