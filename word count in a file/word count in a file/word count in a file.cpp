

#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
#include<cctype>


using namespace std;

void remPunct(string& s) {

	string after_punct;
	
	for (int i = 0; i < s.size(); i++) {
		if (!ispunct(s[i])) {
			after_punct += s[i];
		}	
	}

	s = after_punct;

}


void toLower( string& s) {
	string lower;
	for (int i = 0; i < s.size(); i++) {
		lower += tolower(s[i]);
	}
	
	s = lower;

}


int main(int argc, char* argv[]) {
	string file_name;

	if (argc > 1) {
		file_name = argv[1];

	}

	else {
		cout << "Enter the file name: " << endl;
		cin >> file_name;

	}

	ifstream _file("textFile.txt");
	if (!_file) {
		cerr << "File not found" << endl;
		return -1;
	}

	set<string>stop_words = { "a","an","the","in","on","at","to","for","by","of","off","up","and","as","but","or" };

	map<string, int>Word_freq;
	string line;
	while (getline(_file, line)) {
		istringstream iss(line);
		string word;
		while (iss >> word) {
			remPunct(word);
			toLower(word);

			if (!word.empty()) {
				if (stop_words.count(word) == 0) {
					Word_freq[word] += 1;
				}
			}
		}
	}
}
