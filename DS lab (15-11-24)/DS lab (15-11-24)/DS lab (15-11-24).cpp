

#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<exception>
using namespace std;












void reverse_queue(queue<char>q,stack<char>s,queue<char>q2) {


	
	
	while(!q.empty()) {
		s.push(q.front());
		q.pop();
	}

	

	while (!s.empty()) {
		q2.push(s.top());
		s.pop();
	}



}


void display(queue<char>q) {

	while (!q.empty()) {
		cout << q.front();
		q.pop();
	}
}





//int main(){




	//string hamza;

	//getline(cin, hamza);


	//int size = hamza.length();
	//bool flag = true;
	//for (int i = 0; i < size/2; i++) {
	//	if (hamza[i] != hamza[size - 1 - i]) {
	//		flag = false;
	//		break;
	//	}

	//	

	//
	//}


	//if (flag) {
	//	cout << "the string is a palindrome " << endl;
	//}

	//
	//	if (flag==false) {
	//		cout << "the string is not a palindrome " << endl;
	//	}






	//Question 1




//
//	queue<char>q;
//	stack<char>s;
//
//		q.push('m');
//		q.push('a');
//		q.push('d');
//		q.push('a');
//		q.push('M');
//
//
//
//		s.push('M');
//		s.push('a');
//		s.push('d');
//		s.push('a');
//		s.push('M');
//
//		int size_queue = q.size();
//		int size_stack = s.size();
//
//		int min_size = size_queue > size_stack ? size_queue : size_stack;
//
//		
//
//		bool saqib = false;
//		for (int i = 0; i < min_size; i++) {
//			if (q.front() == s.top() ) {
//
//				q.pop();
//				s.pop();
//
//
//			}
//
//			else {
//				saqib = true;
//			}
//		}
//
//		if (saqib) {
//			cout << "the string is not a palindrome " << endl;
//		}
//
//		if (saqib == false) {
//			cout << "The string is a palindrome " << endl;
//		}
//
//	
//
//
//
//
//}






//Question 2



	int main() {

		stack<char>s;
		queue<char>q;
		queue<char>q2;

		


		
		q.push('h');
		q.push('a');
		q.push('m');

		display(q);
		cout << endl;

		reverse_queue(q, s, q2);
		

		display(q2);
			
		
		



	}



