//#include <iostream>
//using namespace std;
//
//class Complex {
//private:
//    double real;
//    double imag;
//
//public:
//    // Constructor
//    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
//
//    // Operator overloading for addition
//    Complex operator+(const Complex& other) const {
//        return Complex(real + other.real, imag + other.imag);
//    }
//
//    // Operator overloading for subtraction
//    Complex operator-(const Complex& other) const {
//        return Complex(real - other.real, imag - other.imag);
//    }
//
//    // Operator overloading for multiplication
//
//    Complex operator*(const Complex& other) const {
//        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
//    }
//
//    // Operator overloading for division
//    Complex operator/(const Complex& other) const {
//        double denom = other.real * other.real + other.imag * other.imag;
//        return Complex((real * other.real + imag * other.imag) / denom, (imag * other.real - real * other.imag) / denom);
//    }
//
//    // Pre-decrement operator
//    Complex& operator--() {
//        --real;
//        --imag;
//        return *this;
//    }
//
//    // Post-decrement operator
//    Complex operator--(int) {
//        Complex temp = *this;
//        --real;
//        --imag;
//        return temp;
//    }
//
//    // Friend function to overload input operator >>
//    friend istream& operator>>(istream& in, Complex& c) {
//        char sign, i;
//        in >> c.real >> sign >> c.imag >> i;
//        if (sign == '-') c.imag = -c.imag;
//        return in;
//    }
//
//    // Friend function to overload output operator <<
//    friend ostream& operator<<(ostream& out, const Complex& c) {
//        out << c.real << (c.imag >= 0 ? " + " : " - ") << abs(c.imag) << 'i';
//        return out;
//    }
//};
//
//int main() {
//    Complex c1, c2;
//
//    cout << "Enter the first complex number (a + bi): ";
//    cin >> c1;
//    cout << "Enter the second complex number (a + bi): ";
//    cin >> c2;
//
//    Complex sum = c1 + c2;
//    Complex diff = c1 - c2;
//    Complex prod = c1 * c2;
//    Complex quot = c1 / c2;
//
//    cout << "Sum: " << sum << endl;
//    cout << "Difference: " << diff << endl;
//    cout << "Product: " << prod << endl;
//    cout << "Quotient: " << quot << endl;
//
//    cout << "Pre-decrement of first complex number: " << --c1 << endl;
//    cout << "Post-decrement of second complex number: " << c2-- << endl;
//    cout << "After post-decrement, second complex number: " << c2 << endl;
//
//    return 0;
//}



#include<iostream>
using namespace std;

class complex {

private:
	double real;
	double imag;
public:
	complex(double r=0.0,double i=0.0):real(r),imag(i){}

	complex operator+(const complex& c) {
		return complex(real + c.real, imag + c.imag);
	}

	complex operator-(const complex& c) {
		return complex(real - c.real, imag - c.imag);


	}


	    complex operator*(const complex& other) const {
        return complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    
    complex operator/(const complex& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        return complex((real * other.real + imag * other.imag) / denom, (imag * other.real - real * other.imag) / denom);
    }

	complex& operator--() {

		--imag;
		--real;
		return *this;
	}

	complex& operator--(int) {
		complex temp = *this;
		--imag;
		--real;

		return temp;


	}

	friend istream& operator>>(istream& in, complex& c) {
		char sign, i;

		in >> c.real >> sign >> c.imag >> i;

		if (sign == '-') {
			c.imag = -c.imag;
			

		}
	
		return in;
	}

	friend ostream& operator<<(ostream& out, complex& c) {
		
		out << c.real << (c.imag >= 0 ? '+' : '-') << abs(c.imag) << "i" << endl;

		return out;
		
	}








};


int main() {
	complex c1, c2;
	
	    cout << "Enter the first complex number (a + bi): ";
	    cin >> c1;
	    cout << "Enter the second complex number (a + bi): ";
	    cin >> c2;
	
	    complex sum = c1 + c2;
	    complex diff = c1 - c2;
	    complex prod = c1 * c2;
	    complex quot = c1 / c2;
	
	    cout << "Sum: " << sum << endl;
	    cout << "Difference: " << diff << endl;
	    cout << "Product: " << prod << endl;
	    cout << "Quotient: " << quot << endl;
	
	    cout << "Pre-decrement of first complex number: " << --c1 << endl;
	    cout << "Post-decrement of second complex number: " << c2-- << endl;
	    cout << "After post-decrement, second complex number: " << c2 << endl;
	
	    return 0;
	}


