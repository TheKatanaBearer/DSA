//
//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//int main() {
//	//declaring a vector of integers
//
//	vector<int>numbers;
//
//	//adding an element to the vectors
//	numbers.push_back(6);
//
//	numbers.push_back(2);
//
//	numbers.push_back(3);
//
//	//accessing and printing the numbers
//
//	cout << "the first elemet is " << numbers[0] << endl;
//	cout << "the second element is " << numbers.at(1) << endl;
//
//
//	cout << "the size of the vector is " << numbers.size() << endl;
//
//
//	//iterate and print all elemets
//
//	for (int num : numbers) {
//		cout << num << " ";
//	}
//
//	//remove the last element
//
//	numbers.pop_back();
//	cout << endl;
//	cout<<numbers.size();
//
//	if (numbers.empty()) {
//		cout << "the vector is empty " << endl;
//
//
//
//	}
//
//	else {
//		cout << "the vector is not empty " << endl;
//
//	}
//
//
//}



//#include<iostream>
//#include<vector>
//using namespace std;
//int main() {
//	vector<char>charvector;
//
//	charvector.push_back('H');
//	charvector.push_back('L');
//
//	cout << "the characters are " << endl;
//	for (char c : charvector) {
//		cout << c << endl;
//	}
//
//
//
//}

//
//#include <iostream>
//#include <vector>
//#include <string> // Required for std::string
//using namespace std;
//
//int main() {
//    // Declare a vector of std::string
//    std::vector<std::string> stringVector;
//
//    // Adding strings to the vector
//    stringVector.push_back("Hello");
//    stringVector.push_back("world");
//    stringVector.push_back("!");
//
//    // Print the strings in the vector
//    std::cout << "Strings in stringVector: ";
//    for (const  string& str : stringVector) {
//        std::cout << str << " ";  // Output: Hello world !
//    }
//    std::cout << std::endl;
//
//    // Modify an element
//    stringVector[1] = "C++"; // Change "world" to "C++"
//
//    // Print modified vector
//    std::cout << "Modified stringVector: ";
//    for (const std::string& str : stringVector) {
//        std::cout << str << " ";  // Output: Hello C++ !
//    }
//    std::cout << std::endl;
//
//    return 0;
//}



