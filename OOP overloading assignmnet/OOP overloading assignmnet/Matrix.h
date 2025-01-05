#pragma once
#include <iostream>
using namespace std;

class Matrix {
private:
    int numRows;
    int numCols;
    int** elements;

    void allocateMemory();
    void deallocateMemory();

public:
    // Constructors
    Matrix();
    Matrix(int r, int c);
    Matrix(int r, int c, int** data);
    Matrix(const Matrix& other);

    // Destructor
    ~Matrix();

    // Assignment operator
    Matrix& operator=(const Matrix& other);

    // Arithmetic operators
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    // Compound assignment operators
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);

    // Comparison operators
    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    // Stream insertion and extraction operators
    friend ostream& operator<<(std::ostream& out, const Matrix& matrix);
    friend istream& operator>>(std::istream& is, Matrix& matrix);

    // Subscript operator for row
    int* operator[](int index);

    // Function call operator for element access
    int& operator()(int r, int c);
};



