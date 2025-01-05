////
////
//////              Hamza Khan Tariq
////
//////              04072313050
////
////
////
////


//////								creating a matrix class



#include <iostream>

using namespace std;

class Matrix {
private:
    int numRows;
    int numCols;
    int** elements;

    void allocateMemory() {
        elements = new int* [numRows];
        for (int i = 0; i < numRows; ++i) {
            elements[i] = new int[numCols]();
        }
    }

    void deallocateMemory() {
        for (int i = 0; i < numRows; ++i) {
            delete[] elements[i];
        }
        delete[] elements;
    }

public:
    // Default constructor
    Matrix() : numRows(0), numCols(0), elements(nullptr) {}

    // Parameterized constructor
    Matrix(int r, int c) : numRows(r), numCols(c) {
        allocateMemory();
    }

    // Parameterized constructor with data
    Matrix(int r, int c, int** data) : numRows(r), numCols(c) {
        allocateMemory();
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                elements[i][j] = data[i][j];
            }
        }
    }

    // Copy constructor
    Matrix(const Matrix& other) {
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
    ~Matrix() {
        if (elements != nullptr) {
            deallocateMemory();
        }
    }

    // Assignment operator
    Matrix& operator=(const Matrix& other) {
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

    // Addition operator
    Matrix operator+(const Matrix& other) const {
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

    // Subtraction operator
    Matrix operator-(const Matrix& other) const {
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

    // Multiplication operator
    Matrix operator*(const Matrix& other) const {
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

    // Addition assignment operator
    Matrix& operator+=(const Matrix& other) {
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

    // Subtraction assignment operator
    Matrix& operator-=(const Matrix& other) {
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

    // Multiplication assignment operator
    Matrix& operator*=(const Matrix& other) {
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
    }

    //inequality operator
    bool operator!=(const Matrix& other) const {
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

    // Equality operator
    bool operator==(const Matrix& other) const {
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




    // Stream insertion operator
    friend ostream& operator<<(ostream& out, const Matrix& matrix) {
        for (int i = 0; i < matrix.numRows; ++i) {
            for (int j = 0; j < matrix.numCols; ++j) {
                out << matrix.elements[i][j] << ' ';
            }
            out << '\n';
        }
        return out;
    }

    // Stream extraction operator
    friend istream& operator>>(istream& is, Matrix& matrix) {
        for (int i = 0; i < matrix.numRows; ++i) {
            for (int j = 0; j < matrix.numCols; ++j) {
                is >> matrix.elements[i][j];
            }
        }
        return is;
    }

    // Subscript operator for row
    int* operator[](int index) {
        return elements[index];
    }

   

    // Function call operator for element access
    int& operator()(int r, int c) {
        return elements[r][c];
    }

    
};

int main() {
    Matrix mat1(3, 3);
    Matrix mat2(3, 3);

    cout << "Enter elements of first 2x2 matrix:\n";
    cin >> mat1;
    cout << "Enter elements of second 2x2 matrix:\n";
    cin >> mat2;

    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:\n" << sum;

    Matrix difference = mat1 - mat2;
    cout << "Difference of matrices:\n" << difference;

    Matrix product = mat1 * mat2;
    cout << "Product of matrices:\n" << product;

    return 0;
}










////						creating a string class



//
//#include<iostream>
//
//using namespace std;
//
//class mystring {
//private:
//	char* strdata;
//	int strlength;
//
//	//helper function to convert the integer to string
//
//
//	void inttostring(int n, char* buffer) {
//		int num = n;
//		int i = 0;
//	
//		
//		//checking each digit
//
//		do {
//			buffer[i++] = num % 10 + '0';
//			num = num / 10;
//		} while (num != 0);
//
//		//string reversal
//
//		int start = 0;
//		int end = strlen(buffer)-1;
//
//		while (start < end) {
//			//swapping characters
//
//			char temp = buffer[start];
//			buffer[start] = buffer[end];
//			buffer[end] = temp;
//
//			start++;
//			end--;
//		}
//
//
//
//	
//	}
//
//public:
//
//	//default constructor
//	mystring():strdata(NULL),strlength(0){}
//
//	//convert constructor with int paramter
//
//	mystring(int n) {
//		char temp[15];
//
//		inttostring(n, temp);
//
//		strlength = strlen(temp);
//		strdata = new char[strlength + 1];
//		strcpy(strdata, temp);
//	}
//
//
//	//convert constructor with const char* paramter
//
//	mystring(const char* str):strlength(strlen(str)){
//	
//		strdata = new char[strlength + 1];
//		strcpy(strdata, str);
//	}
//	
//	//copy constructor
//
//	mystring(const mystring& other) :strlength(other.strlength) {
//		strdata = new char[strlength + 1];
//		strcpy(strdata, other.strdata);
//	}
//
//	//destructor
//
//	~mystring() {
//		delete[]strdata;
//	}
//
//	//assignment operator
//
//	mystring& operator=(const mystring& other) {
//		if (this != &other) {
//			delete[]strdata;
//			strlength = other.strlength;
//			strdata = new char[strlength + 1];
//			strcpy(strdata, other.strdata);
//		}
//		return *this;
//	}
//
//		//operator for concatenation
//	mystring operator+(const mystring& other)const {
//		mystring result(strlength + other.strlength);
//		strcpy(result.strdata, strdata);
//		strcat(result.strdata, other.strdata);
//
//		return result;
//	}
//
//	//concatenation assignment operator
//
//	mystring& operator+=(const mystring& other) {
//		*this = *this + other;
//		return *this;
//	}
//	
//	//subscript operator
//
//	char& operator()(int index) {
//		return strdata[index];
//	}
//
//	//stream insertion operator
//
//	friend ostream& operator<<(ostream& out, const mystring& mystr) {
//		out << mystr.strdata;
//		return out;
//	}
//
//	//stream extraction operator
//
//	friend istream& operator>>(istream& is, mystring& mystr) {
//		char temp[256];
//		is >> temp;
//		mystr = mystring(temp);
//		return is;
//	}
//
//	//relational operator <
//
//	bool operator<(const mystring& other)const{
//	
//		int minlength = (strlength < other.strlength) ? strlength : other.strlength;
//
//		for (int i = 0; i < minlength; i++) {
//			if (strdata[i] < other.strdata[i]) {
//				return true;
//			}
//			else {
//				return false;
//			}
//		}
//
//	}
//
//
//	//relational operator <=
//	bool operator<=(const mystring& other) const {
//		int minLength = (strlength < other.strlength) ? strlength : other.strlength;
//		for (int i = 0; i < minLength; ++i) {
//			if (strdata[i] < other.strdata[i]) return true;
//			if (strdata[i] > other.strdata[i]) return false;
//		}
//		return strlength <= other.strlength;
//	}
//
//
//		// Greater than operator
//		bool operator>(const mystring & other) const {
//			int minLength = (strlength < other.strlength) ? strlength : other.strlength;
//			for (int i = 0; i < minLength; ++i) {
//				if (strdata[i] > other.strdata[i]) return true;
//				if (strdata[i] < other.strdata[i]) return false;
//			}
//			return strlength > other.strlength;
//		}
//
//		
//			// Greater than or equal to operator
//			bool operator>=(const mystring & other) const {
//				int minLength = (strlength < other.strlength) ? strlength : other.strlength;
//				for (int i = 0; i < minLength; ++i) {
//					if (strdata[i] < other.strdata[i]) return false;
//					if (strdata[i] > other.strdata[i]) return true;
//				}
//				return strlength >= other.strlength;
//			}
//
//			bool operator==(const mystring& other)const {
//				if (strlength != other.strlength) {
//					return false;
//				}
//				for (int i = 0; i < strlength; i++) {
//					if (strdata[i] != other.strdata[i]) {
//						return false;
//					}
//				}
//				return true;}
//
//			// for inequaliy operator
//
//			bool operator!=(const mystring& other)const {
//
//				if (strlength != other.strlength) return true;
//
//				for (int i = 0; i < strlength; ++i) {
//					if (strdata[i] != other.strdata[i]) {
//						return true;
//					}
//
//					return false;
//				}
//			}
//				
//
//};
//
//
//
//int main() {
//
//	mystring str1("hamza");
//	mystring str2("khan");
//
//	mystring str3 = str1 + str2;
//
//	cout << "after the concatenation of the string " << str3 << endl;
//
//	mystring str4;
//	cout << "inputting a string in this step " << endl;
//	cin >> str4;
//
//
//	cout << "you entered " << str4 << endl;
//
// 
//	//utilizing the convert constructor
//
//	mystring str5(12345);
//	cout << "Number as string: " << str5 << endl;
//
//
//}



