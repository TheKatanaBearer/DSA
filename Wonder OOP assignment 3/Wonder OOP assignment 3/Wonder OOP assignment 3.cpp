

#include<iostream>
#include<cmath>
using namespace std;

class vectorType {
private:
	double* x;
	double* y;
	double* z;

	void allocate_memory() {
		x = new double;
		y = new double;
		z = new double;

	}

public:
	vectorType() {
		allocate_memory();
		*x = 0.0;
		*y = 0.0;
		*z = 0.0;

	}

	vectorType(double xVal, double yVal, double zVal) {
		allocate_memory();
		*x = xVal;
		*y = yVal;
		*z = zVal;
	}

	vectorType(const vectorType& v) {
		allocate_memory();
		*x = *(v.x);
		*y = *(v.y);
		*z = *(v.z);
	}

	~vectorType() {
		delete x;
		delete y;
		delete z;
	}

	vectorType& operator=(const vectorType& v) {

		if (this != &v) {
			*x = *(v.x);
			*y = *(v.y);
			*z = *(v.z);

		}
		
		return *this;
	}

	double operator*(const vectorType& v)const {
		return ((*x) * (*(v.x)) + ((*y) * (*(v.y))) + (*(z) * (*(v.z))));
	}

	double length()const {
		return sqrt((*x) * (*x) + (*y) * (*y) + (*z) * (*z));
	}

	double operator^(const vectorType& v)const {
		return this->length() * v.length();
	}

	double angle(const vectorType& v)const {
		double dotproduct = *this * (v);
		double lengthproduct = *this ^ (v);
		return acos(dotproduct / lengthproduct);
	}

	vectorType operator+(const vectorType& v)const {
		return vectorType((*x) + (*(v.x)), (*y) + (*(v.y)), (*z) + (*(v.z)));
	}

	vectorType operator-(const vectorType& v) const {
		return vectorType((*x) - (*(v.x)), (*y) - (*(v.y)), (*z) - (*(v.z)));
	}

	vectorType& operator++() {
		++(*x);
		++(*y);
		++(*z);
		return *this;
	}

	vectorType operator++(int) {
		vectorType temp = *this;

		++(*this);
		return temp;
	}

	friend bool operator==(const vectorType& v, const vectorType& s) {
		return (*(v.x) == *(s.x) && *(v.y) == *(s.y) && *(v.z) == *(s.z));
	}

	friend bool operator!=(const vectorType& v1, const vectorType& v2) {
		return !(v1 == v2);
	}

	friend istream& operator>>(istream& in, const vectorType& v) {
		in >> *(v.x) >> *(v.y) >> *(v.z);
		return in;

	}

	friend ostream& operator<<(ostream& out, const vectorType& v) {
		out << "Vector(" << *(v.x) << ", " << *(v.y) << ", " << *(v.z) << ")";
		return out;
	}

};


int main() {

}