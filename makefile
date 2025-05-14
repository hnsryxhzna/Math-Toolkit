CFLAGS  := -Wall -Wextra -O2
CC      := gcc

#########################################################

SRC_DIR := src
SRCS    := $(wildcard $(SRC_DIR)/*.c)
TARGET  := calculator

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)
