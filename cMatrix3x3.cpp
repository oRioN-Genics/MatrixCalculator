#include <cmath>
#include "cMatrix3x3.h"
#include "eigen-3.4.0\eigen-3.4.0\Eigen\Dense"


cMatrix3x3::cMatrix3x3()
{
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            matrix[i][j] = 0;
        }
    }
}

cMatrix3x3::~cMatrix3x3()
{

}

void cMatrix3x3::setLabel(string argLabel) {
    label = argLabel;
}

void cMatrix3x3::setMatrix() {
    cout << "[0     0     0]" << endl;
    cout << "[0     0     0]" << endl;
    cout << "[0     0     0]" << endl;

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout << "Enter value for row " << i+1 << " column " << j+1 << ":"; cin >> matrix[i][j];
        }
    }

    printMatrix();
}

void cMatrix3x3::printMatrix() {
    int maxWidth = 0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            int width = to_string(matrix[i][j]).length();
            if (maxWidth < width) {
                maxWidth = width;
            }
        }
    }
    for (int i=0; i<3; i++) {
        cout << "[" ;
        for (int j=0; j<3; j++) {
            cout << setw(maxWidth) << matrix[i][j];
            if (j < 2) {
                cout << "       ";
            }
        }
        cout << "]" << endl;
    }
}

cMatrix3x3 cMatrix3x3::operator+(cMatrix3x3& other) {
    cMatrix3x3 result;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

cMatrix3x3 cMatrix3x3::operator-(cMatrix3x3& other) {
    cMatrix3x3 result;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return result;
}

cMatrix3x3 cMatrix3x3::operator*(cMatrix3x3& other) {
    cMatrix3x3 result;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                result.matrix[i][j] += (matrix[i][k] * other.matrix[k][j]);
            }
        }
    }
    return result;
}

// cMatrix3x3 cMatrix3x3::inverse() {
//   cMatrix3x3 result;
//   double det;
//   det = (matrix[0][0]*((matrix[1][1]*matrix[2][2])-(matrix[2][1]*matrix[1][2]))) -
//         (matrix[0][1]*((matrix[1][0]*matrix[2][2])-(matrix[2][0]*matrix[1][2]))) +
//         (matrix[0][2]*((matrix[1][1]*matrix[2][1])-(matrix[2][1]*matrix[1][1])));

//   double tolerance = 1e-20;

//   if (abs(det) < tolerance) {
//     cout << "Matrix is singular, Inverse doesn't exist!" << endl;
//     return result;
//   } else {
//     result.matrix[0][0] = (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) / det;
//     result.matrix[0][1] = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) / det;
//     result.matrix[0][2] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) / det;
//     result.matrix[1][0] = (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) / det;
//     result.matrix[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) / det;
//     result.matrix[1][2] = (matrix[1][0] * matrix[0][2] - matrix[0][0] * matrix[1][2]) / det;
//     result.matrix[2][0] = (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]) / det;
//     result.matrix[2][1] = (matrix[2][0] * matrix[0][1] - matrix[0][0] * matrix[2][1]) / det;
//     result.matrix[2][2] = (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]) / det;
//   }

//   return result;
// }

cMatrix3x3 cMatrix3x3::inverse() {
    cMatrix3x3 result;

    Eigen::Matrix3d mat;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat(i, j) = matrix[i][j];
        }
    }

    double det = mat.determinant();

    // Check if the matrix is singular
    if (std::abs(det) < std::numeric_limits<double>::epsilon()) {
        std::cerr << "Matrix is singular, inverse does not exist!." << std::endl;
        return result;
    }

    Eigen::Matrix3d invertedMat = mat.inverse();

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.matrix[i][j] = invertedMat(i, j);
        }
    }

    return result;
}

cMatrix3x3 cMatrix3x3::transpose() {
    cMatrix3x3 result;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            result.matrix[i][j] = matrix[j][i];
        }
    }
    return result;
}