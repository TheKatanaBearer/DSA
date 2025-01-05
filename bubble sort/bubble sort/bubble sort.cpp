

#include<iostream>
using namespace std;

void bubble_sort(int A[], int n) {											//when the elements are already sorted then we do not go through any swaps
																			//thus this makes bubble sort adaptive...
	int flag;																//it isnt naturally adaptive, we make it adaptive by using flag
																			// best case is O(n)
	for (int i = 0; i < n - 1; i++) {										//Worst case is O(n^2)				
		flag = 0;															//bubble sort is stable as well...the duplicate numbers remain in front of eachother
		for (int j = 0; j < n - 1 - i; j++) {			
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}
}

int main() {


}