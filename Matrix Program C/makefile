# Makefile for C matrix project

CC = gcc
CFLAGS = -std=c99 -Wall -g

TARGET = matrix_c
TEST_TARGET = test_matrix_c

SRC = main.c Matrix.c
TEST_SRC = test.c Matrix.c

OBJ = $(SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

.PHONY: all run run-val clean test test-run test-val

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c Matrix.h
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

run-val: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# ===== TEST RULES =====

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

test-run: test
	./$(TEST_TARGET)

test-val: test
	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_TARGET)

# ===== CLEAN =====

clean:
	rm -f $(OBJ) $(TARGET) $(TEST_OBJ) $(TEST_TARGET)
