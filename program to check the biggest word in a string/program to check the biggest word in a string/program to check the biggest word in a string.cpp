

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

bool is_alpha(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

string find_longest_word(string text) {

	string current_word, result;

	for (char c : text) {

		if (is_alpha(c)) {
			current_word += c;
		}

		else {
			if (current_word.length() > result.length()) {

				result = current_word;

			}

			current_word.clear();

		}

	}


		if (current_word.length() > result.length()) {
			result = current_word;
		}
		return result;

	

}

	int main() {
		cout << find_longest_word("is this sentence big enough ?" );

	}