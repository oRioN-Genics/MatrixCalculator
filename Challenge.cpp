#include <iostream>
#include "cMatrix3x3.h"

using namespace std;

int main() {
// Select operation
    char operation;
    cout << endl;
    cout << endl << "__3x3 Matrix Calculator__" << endl;
    cout << "Addition       ->    +" << endl;
    cout << "Subtraction    ->    -" << endl;
    cout << "Multiplication ->    x" << endl;
    cout << "Inverse        ->    i" << endl;
    cout << "Transpose      ->    '" << endl;

    cout << "Enter operation: "; cin >> operation;

    string matrix1, matrix2;

// If operation is '+' or '-' or 'x', take 2 matrix inputs
    if (operation == '+' || operation == '-' || operation == 'x') {
        cout << "Matrix Label: "; cin >> matrix1;
        cout << "Please enter the matrix values" << endl;
        cMatrix3x3 m1;
        m1.setLabel(matrix1);
        m1.setMatrix();

        cout << endl;

        cout << "Matrix Label: "; cin >> matrix2;
        cout << "Please enter the matrix values" << endl;
        cMatrix3x3 m2;
        m2.setLabel(matrix2);
        m2.setMatrix();

        switch (operation) {
        case '+' :
            cout << "Result of the Addition: " << endl;
            (m1+m2).printMatrix();
            break;
        case '-' :
            cout << "Result of the Subtraction: " << endl;
            (m1-m2).printMatrix();
            break;
        case 'x' :
            cout << "Result of the Multiplication: " << endl;
            (m1*m2).printMatrix();
            break;
            }
        } 
// if operation is 'i' or '\'', take 1 matrix input
        else if (operation == 'i' || operation == '\'') {
            cout << "Matrix Label: "; cin >> matrix1;
            cout << "Please enter the matrix values" << endl;
            cMatrix3x3 m1;
            m1.setLabel(matrix1);
            m1.setMatrix();

            cout << endl;
            
        switch (operation) {
        case 'i' :
            cout << "Result of the Inverse: " << endl;
            (m1.inverse()).printMatrix();
            break;
        case '\'' :
            cout << "Result of the Transpose: " << endl;
            (m1.transpose()).printMatrix();
            break;
        }
    } else {
        cout << "Invalid Operation!";
    }
    cout << "\nPress any key to exit...";
    cin.get(); 
    cin.get(); 

    return 0;
}