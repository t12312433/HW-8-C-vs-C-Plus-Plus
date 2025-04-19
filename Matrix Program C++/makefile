# Makefile for C++ matrix project

CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
TARGET = matrix_cpp
SRC = main.cpp Matrix.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all run run-val clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

run-val: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
