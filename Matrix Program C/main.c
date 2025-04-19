#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

int main(void)
{

    // Arrays that store the values needed for the matrices
    int initialA[] = {6,4,8,3};
    int initialB[] = {1,2,3,4,5,6};
    int initialC[] = {2,4,6,1,3,5};

    // Creates the matrices by passing the value arrays and the size of the matrix
    Matrix* A = create_initialized_matrix(initialA,4,2,2);
    Matrix* B = create_initialized_matrix(initialB,6,2,3);
    Matrix* C = create_initialized_matrix(initialC,6,2,3);

    // Prints the matrices to show they hold the correct values
    printf("\nA:\n");
    print_matrix(A);
    printf("\nB:\n");
    print_matrix(B);
    printf("\nC:\n");
    print_matrix(C);

    // Preforms the test problem, and saves each step to prevent memory leaks
    Matrix* B_scaled3 = scalar_matrix_multiplication(B,3);
    Matrix* C_transposed = matrix_transpose(C);
    Matrix* C_times_B = matrix_multiplication(B_scaled3,C_transposed);
    Matrix* Result = matrix_addition(A,C_times_B);

    // Prints the result of the test problem
    printf("\nProblem: A + (3*B) * C transpose\nResult:\n");

    print_matrix(Result);

    // Deallocates all the matrices created
    destroy_matrix(A);
    destroy_matrix(B);
    destroy_matrix(C);
    destroy_matrix(B_scaled3);
    destroy_matrix(C_transposed);
    destroy_matrix(C_times_B);
    destroy_matrix(Result);

    return 0;
}
