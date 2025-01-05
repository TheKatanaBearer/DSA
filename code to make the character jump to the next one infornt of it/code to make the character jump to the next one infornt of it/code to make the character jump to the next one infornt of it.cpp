// code to make the character jump to the next one infornt of it.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;

string hop_ahead(string str) {

	for (int i = 0; i < str.length(); i++) {
		int ascii_holder = int(str[i]);

		if (ascii_holder == 122) {
			str[i] = char(97);

		}

		if (ascii_holder == 90) {
			str[i] = char(65);
		}

		if ((ascii_holder >= 65 && ascii_holder <= 90) || (ascii_holder >= 97 && ascii_holder <= 122)) {
			str[i] = char(ascii_holder + 1);
		}
	}

	return str;
}
int main()
{

	string hamza = "i am a good guy";

	cout << "enter the stringt that u are dying to enter\n";
	cout << hop_ahead(hamza);

}


