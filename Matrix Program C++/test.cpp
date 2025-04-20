#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {

    // Test 1: Constructor and printing
    int data1[] = {1, 2, 3, 4};
    Matrix m1(data1, 4, 2, 2);
    cout << "Test 1: Constructor and output\n" << m1 << endl;

    // Test 2: Matrix Addition
    int data2[] = {4, 3, 2, 1};
    Matrix m2(data2, 4, 2, 2);
    Matrix sum = m1 + m2;
    cout << "Test 2: m1 + m2\n" << sum << endl;

    // Test 3: Scalar Multiplication
    Matrix scaled = 2 * m1;
    cout << "Test 3: 2 * m1\n" << scaled << endl;

    // Test 4: Transpose
    Matrix transposed = m1.transpose();
    cout << "Test 4: Transpose of m1\n" << transposed << endl;

    // Test 5: Matrix Multiplication
    int data3[] = {1, 0, 0, 1};
    Matrix identity(data3, 4, 2, 2);
    Matrix product = m1 * identity;
    cout << "Test 5: m1 * identity\n" << product << endl;

    // Test 6: Chain operations
    int dataB[] = {1, 2, 3, 4, 5, 6};
    int dataC[] = {2, 4, 6, 1, 3, 5};
    Matrix B(dataB, 6, 2, 3);
    Matrix C(dataC, 6, 2, 3);
    Matrix result = m1 + (3 * B) * C.transpose();
    cout << "Test 6: m1 + (3*B) * C^T\n" << result << endl;

    return 0;
}
