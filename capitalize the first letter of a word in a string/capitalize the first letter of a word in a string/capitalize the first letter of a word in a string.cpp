// capitalize the first letter of a word in a string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cctype>
using namespace std;
string capital(string str) {

	for (int i = 0; i < str.length(); i++) {
		if (i == 0 || str[i - 1] == ' ') {
			str[i] = toupper(str[i]);

		}
	}
	return str;
}

int main()
{
	string hamza = "hello there i am hamza";
	cout << "here is the function in use";
	cout << capital(hamza);

}

