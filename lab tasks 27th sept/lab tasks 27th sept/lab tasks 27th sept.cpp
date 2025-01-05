
#include<iostream>
#include<fstream>
#include<string>
int main() {

	
	std::string var;
	

	std::ifstream f("TextFile1.txt");


	std::getline(f, var);

	std::cout<<var<<std::endl;


}