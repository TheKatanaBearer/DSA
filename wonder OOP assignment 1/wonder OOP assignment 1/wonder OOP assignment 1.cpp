// wonder OOP assignment 1.cpp : This file contains the 'main' function. Program execution begins and e

//
//#include<iostream>
//using namespace std;
//
//int main() {
//
//	double x, x1, x2;
//	cout << "enter the price of pampers for this year " << endl;
//	cin >> x;
//
//	cout<<"enter the price of pampers 1 year ago "<<endl;
//	cin >> x1;
//
//
//	cout << "enter the price of the pampers 2 years ago " << endl;
//	cin >> x2;
//
//	double i;
//
//	cout << "the inflation from 1 year ago is " << endl;
//
//	i = x - x1 / x1;
//
//	cout  << i << endl;
//
//	cout << "the inflation from 2 years ago is " << endl;
//
//	i = x - x2 / x2;
//
//	cout << i << endl;
//}


//
//Write a C++ program that takes size of an array and array’s elements from
//“Data1.txt” and displays the sorted list(in ascending order) of elements after
//applying Bubble Sort.


//
//#include<iostream>
//#include<string>
//#include<cmath>
//#include<fstream>
//
//using namespace std;
//
//void bubble_sort(int ar[], int size) {
//	for (int i = 0; i < size - 1; i++) {
//		for (int j = 0; j < size - 1 - i; j++) {
//			if (ar[j] > ar[j + 1]) {
//				//swapping
//				int temp = ar[j];
//				ar[j] = ar[j + 1];
//				ar[j + 1] = ar[j];
//			}
//		}
//	}
//
//}
//
//
//
//
//
//int main() {
//
//	ifstream inputfile("C:\\Users\\USER\\Data1.txt");
//
//	if (!inputfile) {
//		cout << "the file didnt even open lol " << endl;
//		return 1;
//	}
//
//	
//	int n;
//
//	inputfile >> n;
//
//	//dynamically allocating the memory
//	
//	int* ar = new int[n];
//
//	for (int i = 0; i < n; i++) {
//		inputfile >> ar[i];
//	}
//
//	inputfile.close();
//
//	bubble_sort(ar, n);
//
//	for (int i = 0; i < n; i++) {
//		cout << ar[i];
//	}
//
//	cout << endl;
//
//	delete[]ar;
//
//
//
//	
//
//
//}

//
//Write a program that takes two sorted arrays and merges the arrays in sorted order.
//You are not allowed to use any sorting algorithm.Your program will take data from
//“Data1.txt”
//
//Test Case 1:
//Array 1 : 2, 5, 9
//Array 2 : 1, 2, 3, 6
//Merged Array :
//1, 2, 2, 3, 5, 6, 9
//
//Use pointers to scan / traverse the array.Any loop iterating from index
//zero to size(i.e. using integer iterators to traverse the array) is not
//allowed.
//- You cannot use subscript operator [] to manipulate arrays in your
//program.
//
//Note: We are not taking ANYTHING from user.




#include<iostream>
using namespace std;


void merge_array(int* arr1, int size1, int* arr2, int size2, int* merged) {
	int* ptr1 = arr1;
	int* ptr2 = arr2;

	int* ptrmerged = merged;

	while (ptr1 < arr1 + size1 && ptr2 < arr2 + size2) {

		if (*ptr1 < *ptr2) {
			*merged = *ptr1;
			ptr1++;
			
		}

		else {
			*merged = *ptr2;
			ptr2++;


		}

		merged++;
	}




}

int main() {



}
