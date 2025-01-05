//
//
//
//Write a program that takes two matrices from user and performs following
//operations :
//-Matrix Addition
//- Transpose of a matrix
//- Checks if a matrix is symmetric or not
//- Interchange rows of a matrix
//You are supposed to implement following functions :
//1. Int * *InputMatrix(ifstream & fin, int& rows, int& cols)
//Description : This function will take size of matrix from file, create a
//matrix dynamically, take matrix elements from file and return the
//matrix created.Subscript operator and Integer iterators are not
//allowed to traverse the matrix.
//2. Void OutputMatrix(int** matrix, cont int& ROWS, const int&
//	COLS)
//	Description : Displays the matrix in proper format.Subscript operator
//	and Integer iterators are not allowed to traverse the matrix.
//	3. Int * *AddMatrix(int** matrixA, int** matrixB, const int& ROWS,
//		const int& COLS)
//	Description : This function takes two matrices as parameters, adds
//	them and saves the result in a newly created matrix R and returns the
//	result.Subscript operator and Integer iterators are not allowed to
//	traverse the matrix.
//	4. int** TransposeMatrix(int** matrix, const int& ROWS, const
//		int& COLS)
//	Decription : This function takes a matrix A, takes transpose of matrix
//	A, saves the result in a newly created matrix and returns the result.
//	Subscript operator is not allowed.Integer Iterators and offset notation
//	ARE ALLOWED.
//	5. Bool IsSymmetric(int** matrix, const int& ROWS, const int&
//		COLS)
//	Description : This function takes a matrix as parameter with its size
//	information and returns true if the matrix is symmetric and false
//	otherwise.Subscript operator is not allowed.Integer Iterators and
//	offset notation IS ALLOWED.
//
//	6. Void InterchangeRows(int** matrix, const int& ROWS, const
//		int& COLS)
//	Description : This function takes two row numbers and calls following
//	function to actually interchange the rows.
//	7. Void InterchangeRows(int*& row1, int*& row2)
//	Description : This function interchanges two rows.You are NOT
//	ALLOWED to iterate through rows and swap their values.Think of
//	simple solution.
//	Important Notes :
//-You cannot change the prototypes of the functions.
//- You can use subscript operator to allocate and deallocate the memory.
//- Your program should follow the exact sequence of Sample Run given
//below.
//- Goto instruction is not allowed in your program.
//- Violation of any of the above instructions may result in ZERO credit or
//marks deduction.
//
//







#include<iostream>
#include<fstream>
using namespace std;

int** matrix(ifstream& f,int& rows,int& cols)
{
	f >> rows >> cols;
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];

	}
	for (int i = 0; i < rows * cols; i++) {
		*(*(matrix + i / cols) + i % cols) = 0;
		f >> *(*(matrix + i / cols) + i % cols);
	}

	return matrix;

}


void output_matrix(int** matrix, int& cols, int& rows) {
	for (int i = 0; i < rows * cols; i++) {
		cout << *(*(matrix + i / cols) + i % cols) << " ";

		if ((i + 1) % cols == 0) {
			cout << "endl";
		}
	}
}


int** add_matrix(int** A, int** B, int& rows, int& cols) {
	int** result = new int*[rows];
	for (int i = 0; i < rows; i++) {
		result[i] = new int[cols];

	}

	for (int i = 0; i < rows * cols; i++) {
		*(*(result + i / cols) + i % cols) = (*(*(A + i / cols) + i % cols)) + (*(*B + i / cols) + i % cols);

	}

	return result;
}



int** transpose_matrix(int** matrix, const int& rows, const int& cols) {
	int** transpose = new int* [cols];
	for (int i = 0; i < cols; i++)
	{
		transpose[i] = new int[rows];
	}

	for (int i = 0; i < rows * cols; i++) {
		*(*(transpose + i % cols) + i / cols) = *(*matrix + i / cols) + i % cols;


	}

	return transpose;
}




int main() {

}