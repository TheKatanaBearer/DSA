


#include<iostream>
using namespace std;

int main() {

	int num;

	int largestno;
	int smallestno;
	int total = 0;
	bool first_num = true;


	cout << "enter the numbers that u want...if u enter -999 the loop will break " << endl;

	while (true) {

		cin >> num;

		if (num == -999) {
			cout << "u entered -999" << endl;
			break;
		}

		total += num;


		if (first_num) {
			largestno = num;
			smallestno = num;
			first_num = false;

		}

		else {
			if (num > largestno) {
				largestno = num;

			}
			if (num < smallestno) {
				smallestno = num;
			}

		}



	}

	if (first_num) {
		cout << "there was no valid click " << endl;
	}
	else {
		cout << "the sum is " << total;
		cout << "the largest no is " << largestno << endl;
		cout << "the smallest no is " << smallestno << endl;
	}



}