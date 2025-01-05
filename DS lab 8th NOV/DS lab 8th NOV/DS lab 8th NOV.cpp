


#include<iostream>
#include<string>
using namespace std;



int main(int argc,char*argv[]) {

	int sum = 0;
	for (int i = 1; i < argc; i++) {
		string hamza = argv[i];

		for (int j = 0; hamza[j] != '\0'; j++) {
			if (hamza[j] < '0' && hamza[j] > '9') {
				cout << "there has been a non number found " << endl;
				exit(0);
			}
		}


		sum = sum + stoi(hamza);



	}
		cout << "The sum is " << sum << endl;


}