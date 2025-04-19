#include "Matrix.h"


using namespace std;

    // Matrix (default constructor)
    // Makes an empty matrix
    Matrix::Matrix() {

        // Initializes members to empty values
        matrix = nullptr;
        rows = 0;
        cols = 0;

    }// End of Matrix (default constructor)

    // Matrix (Parameterized Constructor)
    // Given an array of initial values it's size and the rows and cols in the matrix
    // Creates a matrix with the initial values and zeros if the size of the matrix
    // is greater than the initial values
    Matrix::Matrix(const int* initialValues, int initialSize, int newRows, int newCols) {

        // Checks if the construction was passed valid initial values and valid rows and cols
        if (initialValues != nullptr && initialSize > 0 && newRows > 0 && newCols > 0) {

            // Updates members to the number of rows and cols
            rows = newRows;
            cols = newCols;

            // Creates the first part of the 2d array matrix
            matrix = new int*[rows];

            // Iterates through the whole row creating the columns
            for (int i = 0; i < rows; i++) {

                // Creates the current column
                matrix[i] = new int[cols];

            }// End of for loop

            // Stores the current index in initial values
            int index = 0;

            // Iterates through all the rows and columns initializing the values
            for (int i = 0; i < rows; i++) {

                // Iterates through all the columns in the current row initializing the values
                for (int j = 0; j < cols; j++) {

                    // Checks if initial values has more values
                    if(index < initialSize ) {

                        // Sets the current slots value and increments index
                        matrix[i][j] = initialValues[index];
                        index++;

                    // Handles less initial values than the size of the matrix
                    }else {

                        // Sets the current slot to zero
                        matrix[i][j] = 0;

                    }// End of if statement

                }// End of for loop

            }// End of for loop

        }else {

            // Creates a empty matrix
            matrix = nullptr;
            rows = 0;
            cols = 0;

        }// End of if statement

    }// End of Matrix (Parameterized Constructor)

    // Matrix (Parameterized Constructor)
    // Given the rows and columns in the matrix
    // Creates a matrix of that size full of zeros
    Matrix::Matrix(int newRows, int newCols) {

        // Checks if the passed rows and columns are valid
        if(newRows > 0 && newCols > 0) {

            // Updates the member rows and columns
            rows = newRows;
            cols = newCols;

            // Creates the rows of matrix
            matrix = new int*[rows];

            // Iterates through the rows, creating the columns and initializing the slots
            for(int i = 0; i < rows; i++) {

                // Creates the current column
                matrix[i] = new int[cols];

                // Iterates through the current column initializing to zero
                for(int j = 0; j < cols; j++) {

                    // Initializes the current slot
                    matrix[i][j] = 0;

                }// End of for loop

            }// End of for loop

        // Handles invalid rows or columns
        }else {

            // Creates an empty matrix
            matrix = nullptr;
            rows = 0;
            cols = 0;

        }// End of if statement

    }// End of Matrix (Parameterized Constructor)

    // Matrix Assignment Operator
    // Assigns the matrix to a deep copy of the passed matrix
    Matrix& Matrix::operator=(const Matrix& rhs) {

        // Checks that this not a self assignment
        if (this != &rhs) {

            // Checks if the matrix is not empty
            if (rhs.matrix != nullptr) {

                // Iterates through the rows deallocating the columns
                for(int i = 0; i < rows; i++) {

                    // Checks if the memory is allocated
                    if(matrix[i] != nullptr) {

                        // Deallocates the current column
                        delete[] matrix[i];

                    }// End of if statement

                }// End of for loop

                // Deletes the rows
                delete[] matrix;

                // Assigns to nullptr
                matrix = nullptr;

            }// End of if statement

            // Updates row and cols
            rows = rhs.rows;
            cols = rhs.cols;

            // Checks if the rows and cols are valid
            if(rows > 0 && cols > 0) {

                // Creates the rows of matrix
                matrix = new int*[rows];

                // Iterates through the rows creating and initializing the columns
                for(int i = 0; i < rows; i++) {

                    // Creates the current column
                    matrix[i] = new int[cols];

                    // Iterates through the column initializing it
                    for(int j = 0; j < cols; j++) {

                        // Sets the current slot to the passed matrix corresponding slot
                        matrix[i][j] = rhs.matrix[i][j];

                    }// End of for loop

                }// End of for loop

            // Handles empty matrix
            }else {

                // sets the matrix to nullptr
                matrix = nullptr;

            }// End of if statement

        }// End of if statement

        // Returns the matrix
        return *this;

    }// End of Matrix Assignment Operator

    // Matrix Copy Constructor
    // Creates a deep copy of the passed matrix
    Matrix::Matrix(const Matrix& rhs) {

        // Updates row and cols
        rows = rhs.rows;
        cols = rhs.cols;

        // Checks if the rows and cols are valid
        if(rows > 0 && cols > 0) {

            // Creates the rows of matrix
            matrix = new int*[rows];

            // Iterates through the rows creating and initializing the columns
            for(int i = 0; i < rows; i++) {

                // Creates the current column
                matrix[i] = new int[cols];

                // Iterates through the column initializing it
                for(int j = 0; j < cols; j++) {

                    // Sets the current slot to the passed matrix corresponding slot
                    matrix[i][j] = rhs.matrix[i][j];

                }// End of for loop

            }// End of for loop

        // Handles empty matrix
        }else {

            // sets the matrix to nullptr
            matrix = nullptr;

        }// End of if statement

    }// End of Matrix copy constructor

    // Matrix Destructor
    // Deallocates memory used by the matrix
    Matrix::~Matrix() {

        // Checks if the matrix is not empty and has valid dimensions
        if(matrix != nullptr && rows > 0 && cols > 0) {

            // Iterates through the rows to deallocate the columns
            for(int i = 0; i < rows; i++) {

                // Checks if the memory is allocated for the current row
                if(matrix[i] != nullptr) {

                    // Deallocates the current column
                    delete[] matrix[i];

                }// End of if statement

            }// End of for loop

            // Deallocates the array holding the rows
            delete[] matrix;

        }// End of if statement

    }// End of Matrix Destructor

    // Matrix Addition Operator
    // Adds the current matrix to another matrix and returns the result
    Matrix Matrix::operator+(const Matrix& matrix2) const {

        // Checks if the dimensions of the two matrices are the same and valid
        if(matrix2.rows == rows && matrix2.cols == cols && rows > 0 && cols > 0) {

            // Creates a result matrix with the same dimensions as the current matrix
            Matrix result(rows, cols);

            // Iterates through the rows of both matrices
            for (int i = 0; i < matrix2.rows; i++) {

                // Iterates through the columns of both matrices
                for (int j = 0; j < matrix2.cols; j++) {

                    // Adds corresponding elements from both matrices and stores in the result matrix
                    result.matrix[i][j] = matrix[i][j] + matrix2.matrix[i][j];

                }// End of inner for loop

            }// End of outer for loop

            // Returns the result matrix
            return result;

        // Handles empty matrix
        }else {

            // Creates and returns an empty matrix
            Matrix result = Matrix();
            return result;

        }// End of if statement

    }// End of Matrix Addition Operator

    // Scalar Matrix Multiplication Operator
    // Multiplies the current matrix by a scalar factor and returns the result
    Matrix Matrix::operator*(const int factor) const {

        // Checks if the matrix has valid rows and columns
        if(rows > 0 && cols > 0) {

            // Creates a result matrix with the same dimensions as the current matrix
            Matrix result(rows, cols);

            // Iterates through the rows of the matrix
            for (int i = 0; i < rows; i++) {

                // Iterates through the columns of the matrix
                for (int j = 0; j < cols; j++) {

                    // Multiplies the current element by the factor and stores in the result matrix
                    result.matrix[i][j] = matrix[i][j] * factor;

                }// End of inner for loop

            }// End of outer for loop

            // Returns the result matrix
            return result;

        // Handles empty matrix
        }else {

            // Creates and returns an empty matrix
            Matrix result = Matrix();
            return result;

        }// End of if statement

    }// End of Matrix Scalar Multiplication Operator


    // Scalar Matrix Multiplication Operator
    // Multiplies a scalar factor by the matrix and returns the result
    Matrix operator*(const int factor, const Matrix& matrix2 ) {

        // Checks if the matrix has valid rows and columns
        if(matrix2.rows > 0 && matrix2.cols > 0) {

            // Creates a result matrix with the same dimensions as the input matrix
            Matrix result(matrix2.rows, matrix2.cols);

            // Iterates through the rows of the matrix
            for (int i = 0; i < matrix2.rows; i++) {

                // Iterates through the columns of the matrix
                for (int j = 0; j < matrix2.cols; j++) {

                    // Multiplies the current element by the factor and stores in the result matrix
                    result.matrix[i][j] = matrix2.matrix[i][j] * factor;

                }// End of inner for loop

            }// End of outer for loop

            // Returns the result matrix
            return result;

        // Handles empty matrix
        }else {

            // Creates and returns an empty matrix
            Matrix result = Matrix();
            return result;

        }// End of if statement

    }// End of Scalar Matrix Multiplication Operator


    // Matrix Multiplication Operator
    // Multiplies the current matrix with another matrix and returns the result
    Matrix Matrix::operator*(const Matrix& matrix2) const {

        // Checks if the number of columns in the matrices match,
        // and checks that both matrices have valid dimensions
        if(cols == matrix2.rows && cols > 0 && rows > 0 && matrix2.cols > 0) {

            // Creates the result matrix
            Matrix result(rows, matrix2.cols);

            // Iterates through each row until the whole array has been multiplied
            for (int i = 0; i < rows; i++) {

                // Iterates through each column of the second matrix
                for (int j = 0; j < matrix2.cols; j++) {

                    // Initializes the total for the current slot in the matrix
                    int total = 0;

                    // Iterates through getting the dot product
                    for (int k = 0; k < cols; k++) {

                        // Adds the product of the corresponding elements
                        total += matrix[i][k] * matrix2.matrix[k][j];

                    }// End of for loop

                    // Sets the total in the current slot
                    result.matrix[i][j] = total;

                }// End of for loop

            }// End of for loop

            // Returns the result matrix
            return result;

        // Handles empty matrix
        } else {

            // Creates and returns an empty result matrix
            Matrix result = Matrix();
            return result;

        }// End of if statement

    }// End of Matrix Multiplication Operator (*)


    // Transpose
    // Returns a new matrix that is the transpose of the current matrix
    Matrix Matrix::transpose() const {

        // Checks if the matrix has valid dimensions
        if(rows > 0 && cols > 0) {

            // Creates the transposed matrix
            Matrix result(cols, rows);

            // Iterates through the rows of the current matrix
            for (int i = 0; i < rows; i++) {

                // Iterates through the columns of the current matrix
                for (int j = 0; j < cols; j++) {

                    // Sets swapped value
                    result.matrix[j][i] = matrix[i][j];

                }// End of for loop

            }// End of for loop

            // Returns the transposed result matrix
            return result;

        // Handles empty matrix
        } else {

            // Creates and returns the empty matrix
            Matrix result = Matrix();
            return result;

        }// End of if statement

    }// End of Matrix Transpose

    // Overloaded <<
    // Given a matrix adds its contents into the ostream
     ostream& operator<<(ostream& os, const Matrix& printMatrix) {

        // Checks if the matrix has valid rows and columns
        if(printMatrix.rows > 0 && printMatrix.cols > 0) {

            // Iterates through the rows of the matrix
            for (int i = 0; i < printMatrix.rows; i++) {

                // Prints the opening brace for the current row
                os << "{ ";

                // Iterates through the columns of the current row
                for (int j = 0; j < printMatrix.cols; j++) {

                    // Prints the current element in the matrix followed by a space
                    os << printMatrix.matrix[i][j] << " ";

                }// End of inner for loop

                // Prints the closing brace and moves to the next line
                os << "}\n";

            }// End of outer for loop

        }// End of if statement

        // Returns the ostream
        return os;

    }// End of Overloaded <<
