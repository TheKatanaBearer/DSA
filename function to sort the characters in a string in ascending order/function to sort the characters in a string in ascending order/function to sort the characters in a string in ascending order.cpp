// function to sort the characters in a string in ascending order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;

string sort_characters(string hamza) {
	bool flag;
	char ch;
	//loop to perform bubble sort
	do {

		flag = false;
		for (int i = 0; i < hamza.length() - 1; i++) {
			if (hamza[i] > hamza[i + 1]) {
				ch = hamza[i];
				hamza[i] = hamza[i + 1];
				hamza[i + 1] = ch;

				flag = true;
				//demarcation that the swap has been fulfilled 
			}


		}

	} while (flag);

	//removing spaces form the sorting string
	string abdullah;
	for (int j = 0; j < hamza.length(); j++) {
		if (hamza[j] != ' ') {

			abdullah += hamza[j];

		}
	}
	return abdullah;
}
int main()
{

}

