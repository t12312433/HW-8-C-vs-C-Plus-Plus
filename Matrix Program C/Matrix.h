#ifndef MATRIX_H
#define MATRIX_H

typedef struct {

    int rows;
    int cols;
    int** matrix;

} Matrix;

// Creates a matrix of the specified size full of zeros
Matrix* create_matrix(int newRows, int newCols);

// Creates a matrix of the specified size with the passed initial values
Matrix* create_initialized_matrix(int * initialValues, int initialSize,int newRows, int newCols);

// Deallocate the passed matrix
void destroy_matrix(Matrix* matrix);

// Prints the passed matrix
void print_matrix(const Matrix* printMatrix);

// Returns the matrix addition result of the two passed matrices
Matrix* matrix_addition(const Matrix* matrix, const Matrix* matrix2);

// Returns the result of the scalar multiplication
Matrix* scalar_matrix_multiplication(const Matrix* matrix1, const int scalar);

// Returns the result of the matrix multiplication
Matrix* matrix_multiplication(const Matrix* matrix1, const Matrix* matrix2);

// Returns the result of the matrix multiplication
Matrix* matrix_transpose(const Matrix* matrix);



#endif // MATRIX_H
