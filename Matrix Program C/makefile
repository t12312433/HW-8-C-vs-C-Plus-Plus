# Makefile for C matrix project

CC = gcc
CFLAGS = -std=c99 -Wall -g
TARGET = matrix_c
SRC = main.c Matrix.c
OBJ = $(SRC:.c=.o)

.PHONY: all run run-val clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c Matrix.h
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

run-val: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
