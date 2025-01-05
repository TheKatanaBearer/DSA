// factorial of a number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int factorial = 1;
	int i = 0;
	int num1;
	cout << "enter a number";
	cin >> num1;
	for (i = 1; i < num1; i++) {
		factorial = factorial * 1;
	}
	cout << "the factorial of the number" << num1 << "is" << factorial;
}


