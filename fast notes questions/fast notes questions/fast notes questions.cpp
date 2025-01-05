// fast notes questions.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include<fstream>
using namespace std;

//void bubble_sort(int arr[], int size) {
//
//	//it is in descending order
//
//
//	for (int i = 0; i < size - 1; i++) {
//		for (int j = 1; j < size - i; j++) { // Corrected the loop condition
//			if (arr[j] > arr[j - 1]) { // Corrected the comparison
//				int temp = arr[j];
//				arr[j] = arr[j - 1]; // Corrected the swapping indices
//				arr[j - 1] = temp;
//			}
//		}
//	}
//
//}
//
//
//
//int main()
//{
//	const int size = 100;
//
//	int numbers[size];
//
//	cout << "generating random numbers between 0 to 1000\n";
//
//	for (int i = 0; i < size; i++) {
//
//		numbers[i] = rand() % 1001;
//
//	}
//
//	cout << "now i am sorting the numbers";
//
//	bubble_sort(numbers, size);
//
//	cout << "now i am writing the sorted numbers to file\n";
//
//	ofstream hamza("abdullah.txt");
//
//	if (hamza.is_open()) {
//
//		for (int i = 0; i < size; i++) {
//			hamza << numbers[i] << endl;
//
//
//		}
//
//
//
//		hamza.close();
//
//		cout << "the sorted numbers have been written to the file \n";
//
//
//	}
//
//	else {
//		cerr << "there was an error in openionig the file";
//
//
//	}
//
//
//	return 0;
//	
//}
//




//
//
////THIS IS FOR PROBLEM NUMBER 2
//
//const int SIZE = 10;
//
////fucntion to replace the old value with the new value in the array
//
//void replace_value(int arr[], int old_val, int new_val) {
//
//	bool found = false;
//
//	for (int i = 0; i < SIZE; i++) {
//
//		if (arr[i] == old_val) {
//			arr[i] == new_val;
//			found = true;
//		}
//
//	}
//	if (!found) {
//		cerr << "the old value is not found isnide the array" ;
//
//
//	}
//}
//
//
//int main() {
//
//	int hamza[SIZE];
//
//	//input an array of 10 intergers
//
//	for (int i = 0; i < SIZE; i++) {
//
//		cin >> hamza[i];
//	}
//
//	int old_value, new_value;
//
//	cout << "enter the old value\n";
//	cin >> old_value;
//
//	cout << "enter the new value\n";
//	cin >> new_value;
//
//	replace_value(hamza, old_value, new_value);
//
//	//output the modified array
//
//	for (int i = 0; i < SIZE; i++) {
//		cout << hamza[i];
//
//
//	}
//
//	cout << endl;;
//	return 0;
//}

//
//
//// THIS IS FOR PROBLEM NUMBER 3
//
//const int SIZE = 10;
//
//int similar_check(int arr1[], int arr2[]) {
//	int count = 0;
//
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++) {
//			if (arr1[i] == arr2[j]) {
//				count++;
//				break;
//			}
//		}
//	}
//	return count;
//
//
//}
//
//
//int main() {
//
//	int arr1[SIZE];
//	int arr2[SIZE];
//
//	//input values for the 1st array
//
//	for (int i = 0; i < SIZE; i++) {
//		cin >> arr1[SIZE];
//
//
//	}
//	//input values for the 2nd array
//
//	for (int i = 0; i < SIZE; i++) {
//		cin >> arr2[SIZE];
//
//
//	}
//
//	int THE_COUNT = similar_check(arr1, arr2);
//
//
//	cout << "the numebr of common elemets are" << THE_COUNT;
//
//
//}


//
////THIS IS FOR PROGRAM 4
//
////function to check for an armstrong number
//
//
//bool armstrong_no(int num) {
//	int original_num = num;
//	int sum = 0;
//	int numDigits = 0;
//
//
////calculating the num of digits
//	while (num != 0) {
//		num /= 10;
//		numDigits++;
//
//	}
//
//	//reset num to the original value
//
//	num = original_num;
//	//calculating the sum of each digit raised to the power of the numDigits
//
//	while (num != 0) {
//		int digit = num % 10;
//		sum += pow(digit, numDigits);
//
//		num /= 10;
//	}
//	return sum == original_num;
//
//}
//
//bool perfect_num(int num) {
//	int sum = 0;
//
//	//find the factors and add them to the sum
//
//	for (int i = 0; i < num / 2; i++) {
//		if (num % i == 0) {
//			sum += i;
//		}
//	}
//	return sum == num;
//}
//
//
//int main() {
//
//	int num;
//
//	cout << "enter a number";
//	cin >> num;
//
//	//check if the number is an armstrong number
//
//	if (armstrong_no(num)) {
//	cout << num << "is an armstrong num";
//	}
//
//
//	else {
//		cout << num << " is not an armstrong number";
//
//	}
//
//	if (perfect_num(num)) {
//		cout << num << "is a perfect number";
//
//
//	}
//
//	else {
//		cout << num << "is not a perfect number";
//	}
//}



// THIS IS FOR PROGRAM 5

void readfile(int arr[], int& size) {
	ifstream hamza("abdullah.txt");

	if (hamza.is_open()) {
		int i = 0;
		while (hamza >> arr[i]) {
			i++;
		}
		size = i;
		hamza.close();
	}

	else {
		cout << "file is not open";
	}



	
}

int sumArray(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}

int main() {
	int arr[100];
	int size = 0;
	readfile(arr, size);
	int sum = sumArray(arr, size);
	cout << "The sum of all the numbers in the array is: " << sum << endl;
	return 0;
}