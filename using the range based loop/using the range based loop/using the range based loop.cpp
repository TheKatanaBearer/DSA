



#include<iostream>
#include<string>
using namespace std;
int main() {

	string hamza;


	cout << "Enter a number " << endl;
	getline(cin, hamza);


	for (char ch : hamza) {
		cout << ch << endl;
	}


}