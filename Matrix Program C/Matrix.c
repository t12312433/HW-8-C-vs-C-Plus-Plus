#include "Matrix.h"
#include <stdlib.h>
#include <stdio.h>

// Create Matrix
// Creates a matrix of the specified size full of zeros
Matrix* create_matrix(int newRows, int newCols) {

    // Checks if the passed rows and columns are valid
    if(newRows > 0 && newCols > 0) {

        Matrix* newMatrix = malloc(sizeof(Matrix));

        // Updates the member rows and columns
        newMatrix->rows = newRows;
        newMatrix->cols = newCols;

        // Creates the rows of matrix
        newMatrix->matrix = malloc(sizeof(int*) * newRows);

        // Iterates through the rows, creating the columns and initializing the slots
        for(int i = 0; i < newMatrix->rows; i++) {

            // Creates the current column
            newMatrix->matrix[i] = malloc(sizeof(int) * newCols);

            // Iterates through the current column initializing to zero
            for(int j = 0; j < newMatrix->cols; j++) {

                // Initializes the current slot
                newMatrix->matrix[i][j] = 0;

            }// End of for loop

        }// End of for loop

        return newMatrix;

    // Handles invalid rows or columns
    }else {

        // Returns null
        return NULL;

    }// End of if statement

}// End of Create Matrix

// Create initialized Matrix
// Creates a matrix of the specified size with the passed initial values
Matrix* create_initialized_matrix(int * initialValues, int initialSize,int newRows, int newCols) {

    // Checks if the passed rows and columns are valid
    if(newRows > 0 && newCols > 0) {

        Matrix* newMatrix = malloc(sizeof(Matrix));

        // Updates the member rows and columns
        newMatrix->rows = newRows;
        newMatrix->cols = newCols;

        // Creates the rows of matrix
        newMatrix->matrix = malloc(sizeof(int*) * newRows);

        // Stores the current index in initial values
        int index = 0;

        // Iterates through the rows, creating the columns and initializing the slots
        for(int i = 0; i < newMatrix->rows; i++) {

            // Creates the current column
            newMatrix->matrix[i] = malloc(sizeof(int) * newCols);

            // Iterates through the current column initializing to zero
            for(int j = 0; j < newMatrix->cols; j++) {

                // Checks if initial values has more values
                if(index < initialSize ) {

                    // Sets the current slots value and increments index
                    newMatrix->matrix[i][j] = initialValues[index];
                    index++;

                    // Handles less initial values than the size of the matrix
                }else {

                    // Sets the current slot to zero
                    newMatrix->matrix[i][j] = 0;

                }// End of if statement

            }// End of for loop

        }// End of for loop

        return newMatrix;

        // Handles invalid rows or columns
    }else {

        // Returns null
        return NULL;

    }// End of if statement

}// End of Create initialized Matrix

// Destroy Matrix
// Deallocates the passed matrix
void destroy_matrix(Matrix* matrix) {

    // Checks if the matrix is empty
    if(matrix != NULL) {

        // Checks if the member matrix is empty
        if(matrix->matrix != NULL) {

            // Iterates through the rows deleting the slots
            for(int i = 0; i < matrix->rows; i++) {

                // Checks if the current slot is empty
                if(matrix->matrix[i] != NULL) {

                    free(matrix->matrix[i]);

                }// End of if statement

            }// End of for loop

            // Deallocates member matrix
            free(matrix->matrix);

        }// End of if statement

        // Deallocates the matrix
        free(matrix);

    }// End of if statement

}// End of Destroy Matrix

// Matrix Print Function
// Prints the matrix to the console in a readable format
void print_matrix(const Matrix* printMatrix) {

        // Checks if the matrix is not empty and has valid rows and columns
        if(printMatrix != NULL && printMatrix->rows > 0 && printMatrix->cols > 0) {

            // Iterates through the rows of the matrix
            for (int i = 0; i < printMatrix->rows; i++) {

                // Prints the opening brace for the current row
                 printf("{ ");

                // Iterates through the columns of the current row
                for (int j = 0; j < printMatrix->cols; j++) {

                    // Prints the current element in the matrix followed by a space
                    printf("%d ",printMatrix->matrix[i][j]);

                }// End of inner for loop

                // Prints the closing brace and moves to the next line
                printf("}\n");

            }// End of outer for loop

        }// End of if statement

}// End of Matrix Print Function

// Matrix Addition
// Returns the matrix addition result of the two passed matrices
Matrix* matrix_addition(const Matrix* matrix1, const Matrix* matrix2) {

    // Checks if the matricies are not null and the dimensions of the two matrices are the same and valid
    if(matrix1 != NULL && matrix2 != NULL && matrix2->rows == matrix1->rows
        && matrix2->cols == matrix1->cols&& matrix1->rows > 0 && matrix1->cols > 0) {

        // Creates a new matrix with the same dimensions as the current matrix
        Matrix* newMatrix = create_matrix(matrix2->rows, matrix2->cols);


        // Iterates through the rows of both matrices
        for (int i = 0; i < matrix2->rows; i++) {

            // Iterates through the columns of both matrices
            for (int j = 0; j < matrix2->cols; j++) {

                // Adds corresponding elements from both matrices and stores in the result matrix
                newMatrix->matrix[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];

            }// End of inner for loop

        }// End of outer for loop

        // Returns the result matrix
        return newMatrix;

        // Handles empty matrix
    }else {

        // Returns null
        return NULL;

    }// End of if statement

}

// Scalar Matrix Multiplication
// Returns the result of the scalar multiplication
Matrix* scalar_matrix_multiplication(const Matrix* matrix, const int scalar) {

    // Checks if the matrix is not null and has valid rows and columns
    if(matrix != NULL && matrix->rows > 0 && matrix->cols > 0) {

        // Creates a result matrix with the same dimensions as the current matrix
        Matrix* newMatrix = create_matrix(matrix->rows, matrix->cols);

        // Iterates through the rows of the matrix
        for (int i = 0; i < matrix->rows; i++) {

            // Iterates through the columns of the matrix
            for (int j = 0; j < matrix->cols; j++) {

                // Multiplies the current element by the factor and stores in the result matrix
                newMatrix->matrix[i][j] = matrix->matrix[i][j] * scalar;

            }// End of inner for loop

        }// End of outer for loop

        // Returns the result matrix
        return newMatrix;

        // Handles empty matrix
    }else {

        // Returns null
        return NULL;

    }// End of if statement

}// End of Scalar Matrix Multiplication

// Matrix Multiplication
// Returns the result of the matrix multiplication
Matrix* matrix_multiplication(const Matrix* matrix1, const Matrix* matrix2) {

    // Checks if the matrices are not null and the number of columns in the matrices match,
    // and checks that both matrices have valid dimensions
    if(matrix1 != NULL && matrix2 != NULL && matrix1->cols == matrix2->rows
        && matrix1->cols > 0 && matrix1->rows > 0 && matrix2->cols > 0) {

        // Creates the result matrix
        Matrix* newMatrix = create_matrix(matrix1->rows, matrix2->cols);

        // Iterates through each row until the whole array has been multiplied
        for (int i = 0; i < matrix1->rows; i++) {

            // Iterates through each column of the second matrix
            for (int j = 0; j <matrix2->cols; j++) {

                // Initializes the total for the current slot in the matrix
                int total = 0;

                // Iterates through getting the dot product
                for (int k = 0; k < matrix1->cols; k++) {

                    // Adds the product of the corresponding elements
                    total += matrix1->matrix[i][k] * matrix2->matrix[k][j];

                }// End of for loop

                // Sets the total in the current slot
                newMatrix->matrix[i][j] = total;

            }// End of for loop

        }// End of for loop

        // Returns the result matrix
        return newMatrix;

        // Handles empty matrix
    } else {

        // Returns null
        return NULL;

    }// End of if statement

}// End of Matrix Multiplication

// Matrix Transpose
// Returns the result of the matrix multiplication
Matrix* matrix_transpose(const Matrix* matrix) {

    // Checks if the matrix is not null and has valid dimensions
    if(matrix != NULL && matrix->rows > 0 && matrix->cols > 0) {

        // Creates the transposed matrix
        Matrix* newMatrix = create_matrix(matrix->cols, matrix->rows);

        // Iterates through the rows of the current matrix
        for (int i = 0; i < matrix->rows; i++) {

            // Iterates through the columns of the current matrix
            for (int j = 0; j < matrix->cols; j++) {

                // Sets swapped value
                newMatrix->matrix[j][i] = matrix->matrix[i][j];

            }// End of for loop

        }// End of for loop

        // Returns the transposed result matrix
        return newMatrix;

        // Handles empty matrix
    } else {

        // Returns null
        return NULL;

    }// End of if statement

}// End of Matrix Transpose