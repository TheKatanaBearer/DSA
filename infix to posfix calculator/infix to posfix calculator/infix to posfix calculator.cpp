

#include<iostream>
#include<string>
#include<stack>
using namespace std;



bool is_char(char ch) {
	if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') ){
		return true;
	}

	else {
		return false;
	}
}


int precedence_return(char ch) {
	if ((ch == '+') || (ch == '-')) {
		return 1;

	}

	if ((ch == '*') || (ch == '/')) {
		return 2;
	}
}

string infixToPostfix(string expression) {      // a+b/c*a

	string postfix;
	stack<char>s;
	char symbol;


	for (int i = 0;expression[i] != '\0';i++) {

		symbol = expression[i];

		if (isdigit(symbol)) {

			while (isdigit(expression[i])) {
				postfix += expression[i];
				i++;

			}
			postfix += " ";
			i--;
		}

		 if (is_char(symbol)) {

			while (!s.empty() && precedence_return(s.top()) >= precedence_return(symbol)) {
				postfix += s.top();
				postfix += " ";
				s.pop();
			}

			s.push(symbol);
		}

		 if (symbol == '(') {
			s.push(symbol);
		}

		 if (symbol == ')') {
			while (!s.empty() && s.top()!='(') {
				postfix += s.top();
				s.pop();
				postfix += " ";
			}
			if (!s.empty() && s.top() == '(') {
				s.pop(); 
			}
		}

	}


	

	return postfix;

}



double calcualte(char op, stack<double> &s) {
	double result = 0;
	if (op == '+') {
		result = s.top();
		s.pop();
		result += s.top();
		s.pop();
	}

	if (op == '-') {
		result = s.top();
		s.pop();
		result = s.top()-result;
		s.pop();
	}

	if (op == '*') {
		result = s.top();
		s.pop();
		result *= s.top();
		s.pop();
	}

	if (op == '/') {

		result = s.top();
		s.pop();
		result = s.top() / result;
		s.pop();

	}

	

	return result;

}



double result_postfix(string infix) {
	double result = 0;
	string postfix = infixToPostfix(infix);

	cout << postfix << endl;

	stack<double>numbers;

	for (int i = 0;postfix[i] != '\0';i++) {
		if (isdigit(postfix[i])) {
			string num;
			while (isdigit(postfix[i])) {
				num += postfix[i];
				i++;
			}
			numbers.push(stod(num));
		}
	}

	for (int i = 0;postfix[i] != '\0';i++) {
		if (is_char(postfix[i])) {
			double result= calcualte(postfix[i], numbers);
			numbers.push(result);

		}
	}

	return numbers.top();


}

int main(int argc,char*argv[]) {

	string infix;
	if (argc > 1) {

		infix = argv[1];

	}

	else {
		cout << "Enter the infix " << endl;
		cin >> infix;
	}


	double result = result_postfix(infix);

	cout << "the result is " << result << endl;







}