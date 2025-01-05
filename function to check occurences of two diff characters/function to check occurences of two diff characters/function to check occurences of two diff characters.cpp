// function to check occurences of two diff characters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;

string count_chars(string hamza, string ch1, string ch2) {
	

	int ctr1=0;
	int ctr2=0;

	for (int x = 0; x < hamza.length(); x++) {
		if (hamza[x] = ch1[0]) {
			ctr1++;

		}

		if (hamza[x] = ch2[0]) {

			ctr2++;
		}
	}

	if (ctr1 == ctr2) {
		return true;
	}

	else {
		return false;
	}
}

int main()
{
}

