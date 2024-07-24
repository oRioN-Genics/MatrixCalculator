#ifndef CMATRIX3X3_H
#define CMATRIX3X3_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#pragma once

class cMatrix3x3
{
public:
    cMatrix3x3();
    ~cMatrix3x3();
    void setLabel(string argLabel);
    void setMatrix();
    cMatrix3x3 operator+(cMatrix3x3& other);
    cMatrix3x3 operator-(cMatrix3x3& other);
    cMatrix3x3 operator*(cMatrix3x3& other);
    cMatrix3x3 inverse();
    cMatrix3x3 transpose();
    void printMatrix();


private:
    string label;
    double matrix[3][3];
};

#endif