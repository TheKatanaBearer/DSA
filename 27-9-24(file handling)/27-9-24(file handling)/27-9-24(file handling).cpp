

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main() {
	
	ifstream f("random.txt");

	string name, course;

	float a = 0.0;

	float gpa;

	int i = 0;

	if (!f.is_open()) {
		cout << "the file didnt open " << endl;
	}

	
	while (f.good()) {
		getline(f, name, ',');

		getline(f, course, ',');

		f >> gpa;
		

		cout << name << endl;
		cout << course << endl;
		cout << gpa << endl;


		 a = a + gpa;
	
		 i++;
		
	}

	cout << "the average is " << a / i << endl;

	f.close();



}


//if we want to read the file from the parent directory then we use ../ helloworld.txt as our path

//if the text file is in a child directory then we just do this  hamza / helloworld.txt


//if grandchild sequence  ../ hamza / helloworld.txt