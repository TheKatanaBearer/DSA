#include "Matrix.h"

void Matrix::allocateMemory() {
    elements = new int* [numRows];
    for (int i = 0; i < numRows; ++i) {
        elements[i] = new int[numCols]();
    }
}

void Matrix::deallocateMemory() {
    for (int i = 0; i < numRows; ++i) {
        delete[] elements[i];
    }
    delete[] elements;
}

// Constructors
Matrix::Matrix() : numRows(0), numCols(0), elements(nullptr) {}

Matrix::Matrix(int r, int c) : numRows(r), numCols(c) {
    allocateMemory();
}

Matrix::Matrix(int r, int c, int** data) : numRows(r), numCols(c) {
    allocateMemory();
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            elements[i][j] = data[i][j];
        }
    }
}

Matrix::Matrix(const Matrix& other) {
    numRows = other.numRows;
    numCols = other.numCols;
    allocateMemory();
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            elements[i][j] = other.elements[i][j];
        }
    }
}

// Destructor
Matrix::~Matrix() {
    if (elements != nullptr) {
        deallocateMemory();
    }
}

// Assignment operator
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        if (elements != nullptr) {
            deallocateMemory();
        }
        numRows = other.numRows;
        numCols = other.numCols;
        allocateMemory();
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                elements[i][j] = other.elements[i][j];
            }
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (numRows != other.numRows || numCols != other.numCols) {
        cerr << "Matrix dimensions must match for addition" << endl;
    }
    Matrix result(numRows, numCols);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            result.elements[i][j] = elements[i][j] + other.elements[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (numRows != other.numRows || numCols != other.numCols) {
        cerr << "Matrix dimensions must match for subtraction" << endl;
    }
    Matrix result(numRows, numCols);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            result.elements[i][j] = elements[i][j] - other.elements[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (numCols != other.numRows) {
        cerr << "Matrix dimensions must match for multiplication" << endl;
    }
    Matrix result(numRows, other.numCols);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < other.numCols; ++j) {
            result.elements[i][j] = 0;
            for (int k = 0; k < numCols; ++k) {
                result.elements[i][j] += elements[i][k] * other.elements[k][j];
            }
        }
    }
    return result;
}


Matrix& Matrix::operator+=(const Matrix& other) {
    if (numRows != other.numRows || numCols != other.numCols) {
        cerr << "Matrix dimensions must match for addition" << endl;
    }
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            elements[i][j] += other.elements[i][j];
        }
    }
    return *this;
}


Matrix& Matrix::operator-=(const Matrix& other) {
    if (numRows != other.numRows || numCols != other.numCols) {
        cerr << "Matrix dimensions must match for subtraction" << endl;
    }
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            elements[i][j] -= other.elements[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    if (numCols != other.numRows) {
        cerr << "Matrix dimensions must match for multiplication" << endl;
    }

    Matrix result(numRows, other.numCols);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < other.numCols; ++j) {
            result.elements[i][j] = 0;
            for (int k = 0; k < numCols; ++k) {
                result.elements[i][j] += elements[i][k] * other.elements[k][j];
            }
        }
    }

    *this = result;

    return *this;
}


bool Matrix::operator!=(const Matrix& other) const {
    if (numRows != other.numRows || numCols != other.numCols) {
        return true;
    }
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (elements[i][j] != other.elements[i][j]) {
                return true;
            }
        }
    }
    return false;
}


bool Matrix::operator==(const Matrix& other) const {
    if (numRows != other.numRows || numCols != other.numCols) {
        return false;
    }
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (elements[i][j] != other.elements[i][j]) {
                return false;
            }
        }
    }
    return true;
}


ostream& operator<<(ostream& out, const Matrix& matrix) {
    for (int i = 0; i < matrix.numRows; ++i) {
        for (int j = 0; j < matrix.numCols; ++j) {
            out << matrix.elements[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

istream& operator>>(istream& is, Matrix& matrix) {
    for (int i = 0; i < matrix.numRows; ++i) {
        for (int j = 0; j < matrix.numCols; ++j) {
            is >> matrix.elements[i][j];
        }
    }
    return is;
}


int* Matrix::operator[](int index) {
    return elements[index];
}

int& Matrix::operator()(int r, int c) {
    return elements[r][c];
}

