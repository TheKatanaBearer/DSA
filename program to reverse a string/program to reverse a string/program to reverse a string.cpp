// program to reverse a string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//program for the reversal of a string
#include <iostream>
#include<string>
using namespace std;

string revserse_string(string str) {
	string temp = str;
	int index_pos = 0;

	for (int x = temp.length() - 1; x >= 0; x--) {
		str[index_pos] = temp[x];
		index_pos++;
	}
	return str;
}
int main()
{
	string hamza = "my name is hamza";
	cout << revserse_string(hamza);




}

