

#include<iostream>
using namespace std;


class forward_list {

private:

	struct node {
		node* next;
		int val;

	};

	node* head;


public:

	forward_list() {
		head = nullptr;
	}

	void push_(int value) {
		node* n = new node();
		n->val = value;
		n->next = head;
		head = n;


	}

	int  size() {
		node* temp = head;
		int count = 0;

		while (temp != nullptr) {
			temp = temp->next;
			count++;
		}

		return count;
	}


	void resize(int new_size) {

		int size_of_list = size();
		
		node* temp = nullptr;

		if (size_of_list == new_size) {
			return;
		}

		else if (size_of_list > new_size) {

			node* temp = head;

			int count = 1;


			while (count < new_size && temp != nullptr) {
				temp = temp->next;
				count++;

			}

			if (temp != nullptr && temp->next!=nullptr) {  //redundant

				node* del = temp->next;
				temp->next = nullptr;

				while (del != nullptr) {

					node* next1 = del->next;
					delete del;
					del = next1;
				}

			}




		}

		else {

			node* temp = head;

			while (temp->next != nullptr) {
				temp = temp->next;
			}

			int n = size_of_list;
			while (n < new_size) {
				n++;

				//creating
				node* new_node = new node();
				new_node->val = int();
				new_node->next = nullptr;


				//joining
				temp->next = new_node;
				temp = temp->next;
				
			}
		}
		
		//explanation for resize:
		

		

	}


	void display() {
		node* temp = head;

		while (temp != nullptr) {
			cout << temp->val << endl;
			temp = temp->next;
		}
	}


	void merge(forward_list& f) {

		if (this == &f) {
			cout << "you are pointing to the same object " << endl;
			return;
		}

		node* temp = head;

		while (temp->next != nullptr) {
			temp = temp->next;
		}

		temp->next = f.head;

		f.head = nullptr;
		

	}

	void unique() {
		if (!head) {
			cout << "it cannot merge as the list is empty " << endl;

		}

		node* temp = head;

		while (temp->next != nullptr) {
			
			if (temp->val == temp->next->val) {
				cout << "duplicate has been found " << endl;

				node* temp2 = temp->next;
				temp->next = temp2->next;

				delete temp;
			}

			else {
				temp = temp->next;
				cout << "No duplicate has been found " << endl;
			}
		}

		//Explanation for unique:
		
		//first of all i checked if the list is empty
		//then i traversed to nullptr
		//if the duplicate has been found...by usingt the logic that the value of temp shud be equal to temp.next.val
		//then i will store temp.next into temp2 and point temp.next to temp2.next..i did this bcz it couldnt be done directly..i had to make another temp
		//then i released temp

		//in case the duplicate is not found
		//i performed a simple traverse





	}




};


int main() {
	
	forward_list f;

	f.push_(5);
	f.push_(6);
	f.resize(3);
	

	f.unique();






}