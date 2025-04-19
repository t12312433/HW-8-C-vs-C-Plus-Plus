#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>


class Matrix {

private:

    int rows;       // Number of rows in the matrix
    int cols;       // Number of columns in the matrix
    int** matrix;   // Dynamic 2D array storing the matrix


public:

    // Default Constructor
    // Creates an empty matrix (0 rows and 0 columns)
    Matrix();

    // Parameterized Constructor
    // Creates a matrix with initial values, size of the values, and specified rows and columns
    Matrix(const int* initialValues, int initialSize, int newRows, int newCols);

    // Parameterized Constructor
    // Creates a matrix with specified rows and columns, all elements initialized to zero
    Matrix(int newRows, int newCols);

    // Copy Constructor
    // Creates a deep copy of the passed matrix
    Matrix(const Matrix& rhs);

    // Assignment Operator
    // Assigns the current matrix to a deep copy of the passed matrix
    Matrix& operator=(const Matrix& rhs);

    // Destructor
    // Deallocates the memory used by the matrix
    ~Matrix();

    // Matrix Addition Operator
    // Returns a new matrix that is the sum of the current matrix and matrix2
    Matrix operator+(const Matrix& matrix2) const;

    // Scalar Multiplication Operator
    // Multiplies the current matrix by a scalar (factor) and returns the result
    Matrix operator*(const int factor) const;

    // Scalar Multiplication Operator
    // Multiplies a scalar (factor) by a matrix and returns the result
    friend Matrix operator*(const int factor, const Matrix& matrix2);

    // Matrix Multiplication Operator
    // Returns a new matrix by multiplying two matrices
    Matrix operator*(const Matrix& matrix2) const;

    // Matrix Transpose Function
    // Returns a new matrix that is the transpose of the current matrix
    Matrix transpose() const;

    // Overloaded <<
    // Given a matrix adds its contents into the ostream
    friend std::ostream& operator<<(std::ostream& os, const Matrix& printMatrix);

};



#endif //MATRIX_H
