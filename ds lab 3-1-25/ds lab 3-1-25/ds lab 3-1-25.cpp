
#include<map>
#include<iostream>
#include<fstream>
#include<string>
						//make two trees...one to store a stop word and the other a normal word
						//if the word is found in the stop word tree..then ignore it and put it in another tree
						//keep in mind..the words with capital and small are the same words and should be treated as the same
int main() {
	std::map <std::string, int > word_count;
	std::map<std::string, int>::iterator it;

	std::ifstream file("input.txt");
	std::string word;


	while (file >> word) {
		it = word_count.find(word);												//this returns an iterator an we come to know that the word is present in the map
		if (it != word_count.end()) {											//this checks if we have reached the end of the map
			it->second++;													    //if we havent reached the end of map it means that the word is present in the map
		}																		//so then we increment its second value by 1....(keep in mind the iterator is pointing to the word)
		else {																	//if we reached the end of the tree..it means the word is not present in the map so we insert it in the map with a value of 1
			word_count.insert(std::pair<std::string, int>(word, 1));
		}
	}

	std::ofstream file_("cloudword.html");

	file_ << "<html><head><title>Word Cloud</title></head><body><div style='text-align:center;'>";

	while (it != word_count.end()) {
		file_ << "<span style='font-size:" << it->second * 10 << "px;'>" << it->first << "</span>";
		it++;
	}


}





// m[word]=m[word]+1;
// this is done by getting 0 on the left side..when found..it increments it by 1
// we can comment the entire first while loop
//this is the alternate method..this is done by overloading the operator[] of the map class

// i have its picture in my fone..will upload it later