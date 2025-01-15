

#include<iostream>
using namespace std;

template<typename T>
void Reheap_up(T data[],int first,int last) {
	int p = (last - 1) / 2;

	if (last == 0) {
		return;
	}

	else if (data[last] <= data[p]) {
		return;
	}
	else{

		swap(data[last], data[p]);
		Reheap_up(data, first, p);
	}
	
}


void Reheap_down(int data[], int first, int last) {
	int lc, int rc, int mc;
	lc = first * 2 + 1;
	rc = first * 2 + 2;
	mc = lc;

	if (lc > last) {
		return;

	}

	else if (rc <= last && data[rc] > data[lc]) {
		mc = rc;
	}
	if (data[mc] <= data[first]) {
		return;
	}
	else {
		swap(data[first], data[mc]);
		Reheap_down(data, mc, last);
	}
}

int main() {

}