// prorgam to dynamically allocate a character array and an integer array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
int main()
{
	int size;
	cout << "enter the size of an array";
	cin >> size;
	int* hamza = new int[size];
	
	//initializing the elements of the array

	for (int i = 0; i < size; i++) {
		hamza[i] = i + 1;

	}

	//dynamically allocate an integer of string

	string* fatima = new string[size];

	//initilaizing the elements of the stringt hat i just initilaized

	for (int i = 0; i < size; i++) {
		fatima[i] = "element-" + to_string(i + 1);
	}
}

