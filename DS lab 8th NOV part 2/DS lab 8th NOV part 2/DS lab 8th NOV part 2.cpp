

#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main(int argc, char* argv[]) {

	for (int i = 1; i < argc; i++) {
		string hamza = argv[i];
		fstream ifile(hamza, ios::in);

		if (!ifile) {
			cout << "the file wasnt opened " << endl;
			return 1;

		}


		   string read_var;

		   cout << "The contents of the file are " << endl;

		while (getline(ifile,read_var)) {

			cout << read_var << endl;
		}


		ifile.close();
	}
}