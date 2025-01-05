

#include<iostream>
using namespace std;


class node {
public:
	int key;
	int data;
	node* next;


	node() {
		key = 0;
		data = 0;
		next = NULL;

	}

	node(int k, int d) {
		key = k;
		data = d;

	}

};

class stack {
public:
	node* top;

	stack() {
		top = NULL;

	}

	bool isEmpty() {
		if (top == NULL) {
			return true;
		}

		else {
			return false;
		}
	}


	
		bool checkIfNodeExist(node* n) {
			node* temp = top;
			bool exist = false;
			while (temp != NULL) {
				if (temp->key == n->key) {
					exist = true;
					break;
				}
				temp = temp->next;
			}
	}






	void push(node* n) {
		if (top == NULL) {
			top = n;
		}

		else if (checkIfNodeExist(n)) {
			cout << "node already exists...enter with a different key value  " << endl;

		}

		else {
			node* temp = top;
			top = n;
			n->next = temp;
			cout << "the node has been pushed successfully " << endl;

		}
	}


	node* pop() {
		node* temp = NULL;
		if (isEmpty()) {
			cout << "stack undersflow " << endl;

		}
		else {
			temp = top;
			top = top->next;
			return temp;
		}
	}

	node* peek() {
		if (isEmpty()) {
			cout << "stack underflow " << endl;
			return NULL;

		}

		else {
			return top;
		}
	}


	int count() {
		int count = 0;
		node* temp = top;
		while (temp != NULL) {
			count++;
			temp = temp->next;
		}

		return count;
	}

};


int main() {


}


