

#include<iostream>
#include<string>
using namespace std;
////string reverse function
//
//string reverse_function(string str) {
//
//	string temp_str = str;
//
//	int index_pos = 0;
//
//	for (int i = str.length() - 1; i >= 0; i--) {
//
//		str[index_pos] = temp_str[i];
//		index_pos++;
//
//	}
//
//	return str;
//}
//
//int main() {
//
//
//	string hamza = "hamza";
//
//	cout << reverse_function(hamza);
//
//
//
//}



//change to the next character in the alphabet

//string change_char(string hamza) {
//
//	int char_code;
//
//	for (int i = 0; i < hamza.length(); i++) {
//
//		int char_code = int(hamza[i]);
//
//		if (char_code == 122) {
//
//			hamza[i] = char(97);
//
//
//		}
//
//		if (char_code == 90) {
//
//			hamza[i] = char(65);
//		}
//
//		if (char_code >= 65 && char_code <= 90 || char_code >= 97 && char_code <= 122) {
//
//			hamza[i] = char(char_code + 1);
//		}
//	}
//	return hamza;
//}


//this is to capitalize the start of the word

//string capital(string hamza) {
//
//
//
//	for (int i = 0; i < hamza.length(); i++) {
//
//		if (i == 0 || hamza[i - 1] == ' ') {
//
//			hamza[i] = toupper(hamza[i]);
//		}
//
//
//	}
//
//	return hamza;
//}


//this is to check the largest word inside a string

//string find_largest(const string hamza) {
//
//	string largest_word;
//	string current_word;
//
//	for (char c : hamza) {
//
//		if (c != ' ') {
//
//			current_word += c;
//		}
//
//		else {
//
//			if (current_word.length() > largest_word.length()) {
//
//				largest_word = current_word;
//			}
//
//			current_word = "";
//		}
//
//	}
//
//	//check the last word
//
//	if (current_word.length() > largest_word.length()) {
//
//		largest_word = current_word;
//	}
//
//	return largest_word;
//}

//
//string sort_characters(string hamza) {
//
//	bool flag;
//
//	char temp;
//
//	do {
//		flag = false;
//
//		for (int i = 0; i < hamza.length(); i++) {
//
//			if (hamza[i] > hamza[i + 1]) {
//
//				temp = hamza[i];
//				hamza[i] = hamza[i + 1];
//				hamza[i + 1] = temp;
//
//				flag = true;
//			}
//		}
//	} while (flag);//it remains false over here
//	
//
//	//remove spaces from the sorted string
//
//
//	string str;
//
//	for (int i = 0; i < hamza.length(); i++) {
//		if (hamza[i] != ' ') {
//
//			str.push_back(hamza[i]);
//		}
//	}
//
//	return str;
//}


