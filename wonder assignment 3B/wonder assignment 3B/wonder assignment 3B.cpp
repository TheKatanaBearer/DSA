

//HUGE INTEGER


#include<iostream>
#include<string>
using namespace std;

class hugeinteger {
private:
	static const int MAX_LEN = 40;
	int digits[MAX_LEN];
public:
	hugeinteger() {
		for (int i = 0; i < MAX_LEN; i++) {
			digits[i] = 0;
		}
	}

	hugeinteger(const string& num) {
		for (int i = 0; i < MAX_LEN; i++) {
			digits[i] = 0;
		}
		int length = num.length();

	}
};

int main() {

}