

#include<iostream>
#include<forward_list>
using namespace std;


namespace my_std {
	
	template<typename T>
	struct node {
		T val;
		node* next;

		node(T val) :val(val), next(nullptr) {};
	};

	template <typename T>
	class forward_list {
		node<T>* head, *tail;
		int n;

		node<T>* getMiddle() {

			node<T>* slow = head;
			node<T>* fast = head;

			while (slow != nullptr && fast != nullptr) {
				slow = slow->next;
				fast = fast->next->next;

			}

			return slow;
		}

	public:

		forward_list() :head(nullptr), tail(nullptr), n(0) {};

		~forward_list() {
			clear();
		}

		void push_front(T val) {
			node<T>* new_node = new node<T>(val);

			if (this->head == nullptr) {
				this->head = new_node;
				this->tail = new_node;


			}

			else {
				node<T>* temp = this->head;

				this->head = new_node;
				this->head->next = temp;

			}

			++n;
		}


		void pop_front() {
			if (this->head == nullptr) {
				cout << "the forward_list is empty " << endl;
				return;

			}

			else {

				node<T>* temp = head->next;
				delete this->head;
				head = temp;


				if (head == nullptr) {			//check if the list becomes empty...if head becomes empty then tail also becomes empty
					tail == nullptr;

				}
			}
			--n;

		}

		void print_list() {
			if (head == nullptr) {
				cout << "the list is empty.." << endl;
				return;
			}

			node<T>* temp = head;
			cout << "List:[ ";
			while (temp != nullptr) {
				cout << temp->val << ",";
				temp = temp->next;

			}
			cout << "]" << endl;

		}


		T front()const {
			if (this->head == nullptr) {
				cout << "error: the list is empty " << endl;

			}

			return head->val;

		}

		T back()const {
			if (this->head == nullptr) {
				cout << "the list is empty " << endl;
			}

			return this->tail->val;



		}

		int size()const {
			return this->n;


		}

		bool empty()const {
			return n == 0;

		}

		void clear() {
			node* temp = head;

			while (temp != nullptr) {
				node* nex_temp = temp->next;
				delete temp;
				temp = nex_temp;

			}

			head = tail = nullptr;
			n = 0;
		}

		void insert_after(node<T>* position,T val) {
			if (position == nullptr) {
				cout << "invalid position " << endl;
				return;
			}


		}




	};

}

int main() {



}