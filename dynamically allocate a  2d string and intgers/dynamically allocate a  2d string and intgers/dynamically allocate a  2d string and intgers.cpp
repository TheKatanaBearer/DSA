// dynamically allocate a  2d string and intgers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{

	// dynamically allocate a 2 dimensional array of floating values
	int rows = 5;
	int cols = 5;
	float** hamza = new float* [rows];
	for (int i = 0; i < rows; i++) {
		hamza[i] = new float[cols];
	}

	//initialize the elements of the float array
	float value = 1.2;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			hamza[i][j] = value;
			value += 1.0;
		}

		//dynamically allocate a string
		string** abdullah = new string * [rows];
		for (int i = 0; i < rows; i++) {
			abdullah[i] = new string[cols];
		}

		//initilaze the elements of the string array
		string element = "h";
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				abdullah[i][j] = element;
				element[0] += 1;
			}
		}
		//freeing the allocated memory
		for (int i = 0; i < rows; i++) {
			delete[]hamza[i];
			delete[]abdullah[i];
		}
		delete[]hamza;
		delete[]abdullah;


	}

}
