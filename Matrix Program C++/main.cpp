#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {

    // Arrays that store the values needed for the matrices
    int initialA[] = {6,4,8,3};
    int initialB[] = {1,2,3,4,5,6};
    int initialC[] = {2,4,6,1,3,5};

    // Creates the matrices by passing the value arrays and the size of the matrix
    Matrix A(initialA,4,2,2);
    Matrix B(initialB,6,2,3);
    Matrix C(initialC,6,2,3);

    // Prints the matrices to show they hold the correct values
    cout << "A:\n" << A << endl;
    cout << "B:\n" << B << endl;
    cout << "C:\n" << C << endl;

    // Preforms the test problem
    Matrix D = A + (3*B) * C.transpose();

    cout << "Problem: A + (3*B) * C transpose" << endl;
    // Prints the result of the test problem
    cout << "Result:\n" << D << endl;


    return 0;

}

