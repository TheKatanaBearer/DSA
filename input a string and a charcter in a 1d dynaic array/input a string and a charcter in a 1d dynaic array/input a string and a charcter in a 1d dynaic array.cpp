// input a string and a charcter in a 1d dynaic array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
int main()
{

	//dynamically allocate memory for a character

	char* hamza = new char;

	cout << "input a character";
	cin >> *hamza;

	//dynamically allocate memory for a string

	string* abdullah = new string;

	cout << "input a string";

	cin.ignore();
	
	getline(cin, *abdullah);

	//freing the allocated material

	delete hamza;
	delete abdullah;

}

