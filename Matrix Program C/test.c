#include <stdio.h>
#include "Matrix.h"

int main() {
    // Test 1: Create initialized matrices
    int dataA[] = {1, 2, 3, 4};
    int dataB[] = {5, 6, 7, 8};
    Matrix* A = create_initialized_matrix(dataA, 4, 2, 2);
    Matrix* B = create_initialized_matrix(dataB, 4, 2, 2);

    printf("Matrix A:\n");
    print_matrix(A);
    printf("Matrix B:\n");
    print_matrix(B);

    // Test 2: Add matrices
    Matrix* C = matrix_addition(A, B);
    printf("A + B:\n");
    print_matrix(C);

    // Test 3: Scalar multiplication
    Matrix* D = scalar_matrix_multiplication(B, 3);
    printf("3 * B:\n");
    print_matrix(D);

    // Test 4: Matrix multiplication
    Matrix* E = matrix_multiplication(A, B);
    printf("A * B:\n");
    print_matrix(E);

    // Test 5: Transpose
    Matrix* F = matrix_transpose(B);
    printf("Transpose of B:\n");
    print_matrix(F);

    // Cleanup
    destroy_matrix(A);
    destroy_matrix(B);
    destroy_matrix(C);
    destroy_matrix(D);
    destroy_matrix(E);
    destroy_matrix(F);

    return 0;
}
