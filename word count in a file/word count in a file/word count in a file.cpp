// word count in a file.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cctype>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
int main()
{
	string fileName;
	cout << "enter the file name";
	cin >> fileName;

	ifstream hamza(fileName);

	if (!hamza) {

		cerr << "there was an error";
		return 1;
	}

	string line;
	int wordcount = 0;
	while (getline(hamza, line)) {
		stringstream ss(line);
		string word;
		while (ss >> word) {
			wordcount++;
		}
	}

	cout << "the word count is" << wordcount;

	hamza.close();
	return 0;


}
