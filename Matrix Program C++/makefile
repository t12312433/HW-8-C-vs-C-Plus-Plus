# Makefile for C++ matrix project

CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

TARGET = matrix_cpp
TEST_TARGET = test_matrix

SRC = main.cpp Matrix.cpp
OBJ = $(SRC:.cpp=.o)

TEST_SRC = test.cpp Matrix.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

.PHONY: all run run-val clean test test-run test-val

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

run-val: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# --- Test Section ---

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

test-run: test
	./$(TEST_TARGET)

test-val: test
	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_TARGET)

# --- Clean up ---

clean:
	rm -f $(OBJ) $(TARGET) $(TEST_OBJ) $(TEST_TARGET)
