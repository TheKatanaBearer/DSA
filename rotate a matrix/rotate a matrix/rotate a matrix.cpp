// rotate a matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main(){

	int number;
	cout << "enter the number";
	cin >> number;

	int remainder = 0;
	int revnumber = 0;

	while (number > 0) {
		remainder = number % 10;
		number = number / 10;
		revnumber = (revnumber * 10) + remainder;
	}

	cout << "the reversed number is " << revnumber;


}