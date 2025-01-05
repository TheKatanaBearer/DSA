// sum of 2,if 2 are equal then triple the sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int test(int num1, int num2) {
	return num1 == num2 ? (num1 + num2) * 3 : num1 + num2;
}
int main()
{

	int num1 = 5;
	int num2 = 5;

	cout << test(num1, num2);
}

