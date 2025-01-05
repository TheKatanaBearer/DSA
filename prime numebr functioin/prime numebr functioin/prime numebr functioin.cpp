// prime numebr functioin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int num, counter = 0;
	cout << "enter  a number";
	cin >> num;
	for (int i = 0; i <= num; i++)
	{
		if (num % i == 0) {
			counter++;
		}
	}
	if (counter == 2) {
		cout << "the numebr that u entered is a prime number";

	}
	else {
		cout << "the number that u have entred is not prime";
	}

}

