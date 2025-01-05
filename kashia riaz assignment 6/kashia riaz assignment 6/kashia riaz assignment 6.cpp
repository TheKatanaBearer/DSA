//
//#include <iostream>
//using namespace std;
//class number {
//private:
//	int quantity;
//public:
//
//	number(int q):quantity(q){}
//
//
//	bool operator >=(const number& other)const {
//		return quantity >= other.quantity;
//	}
//
//	bool operator==(const number& other)const {
//		return quantity == other.quantity;
//	}
//
//	number addquantity(const number& other, int times)const {
//
//		return number(quantity + other.quantity * 3);
//
//	}
//
//	number subtractquantity(const number& other, int times)const {
//		return number(quantity - other.quantity * 3);
//	}
//
//	int getquantity()const {
//		return quantity;
//	}
//
//
//};
//
//int main()
//{
//	number item1(50);
//
//	number item2(30);
//
//	number result_quant(0);
//
//	if (item1 >= item2) {
//		result_quant = item1.addquantity(item2,3);
//
//	}
//
//	else {
//		result_quant = item1.subtractquantity(item2, 3);
//	}
//
//	cout << "the final quantity is " << result_quant.getquantity();
//
//	if (item1 == item2) {
//		cout << "they are equal " << endl;
//
//	}
//
//	else {
//		cout << "they are not equal " << endl;
//	}
//
//
//}








//
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//class money
//{
//	int rupees;
//	int paisas;
//
//	//helper function to convert paisas into rupees
//
//	//void convert() {
//
//	//	//in this case if paisas is greater than 100 we give the excess paisas to rupees
//
//	//	if (paisas >= 100) {
//	//		rupees += paisas / 100;
//	//		paisas = paisas % 100;
//	//	}
//
//	//	else if (paisas < 0) {
//
//	//		double new_rupees = static_cast<double>(rupees) - static_cast<double>(-paisas / 100);
//
//	//		rupees = new_rupees;
//	//		paisas = static_cast<int>(new_rupees*100) % 100;
//	//	}
//
//	//}
//
//public:
//	money(int r = 0, int p = 0) {
//		rupees = r;
//		paisas = p;
//	}
//
//	money operator+(const money& other)const {
//		money result(rupees + other.rupees, paisas + other.paisas);
//
//		return result;
//	}
//
//	money operator-(const money& other)const {
//		money result(rupees - other.rupees, paisas - other.paisas);
//
//		return result;
//	}
//
//	friend istream& operator>>(istream& in, money& m) {
//		cout << "enter rupees " << endl;
//		in >> m.rupees;
//		cout << "enter the paisas " << endl;
//		in >> m.paisas;
//
//		return in;
//
//
//	}
//
//	friend ostream& operator<<(ostream& out, const money& m) {
//		out << m.rupees << "rupees and " << m.paisas << "paisas " << endl;
//		return out;
//	}
//
//	int compare(const money& other)const {
//
//		if (rupees > other.rupees || rupees == other.rupees && paisas > other.paisas) {
//			return 1;
//		}
//
//		else if (rupees < other.rupees || (rupees == other.rupees && paisas < other.paisas)) {
//			return -1;
//		}
//
//		else {
//			return 0;
//		}
//	}
//
//
//
//
//
//
//};
//
//
//int main() {
//
//
//	money m1(6, 12);
//
//	money m2(4, 60);
//
//	cout << "money m1 is " << m1;
//
//	cout << "money m2 is " << m2;
//
//	money m3 = m1 + m2;
//
//	cout << "the sum is " << m3;
//
//	money m4 = m1 - m2;
//
//	cout << "the subtracation is "<<m4 << endl;
//
//	int x = m1.compare(m2);
//
//	if (x == 1) {
//		cout << "money 1 is greater than money 2 " << endl;
//
//		if (x == -1) {
//			cout << "money 1 is less than money 2 " << endl;
//
//		}
//
//
//		else {
//			cout << "money 1 is equal to money 2 " << endl;
//
//		}
//
//	}
//
//	return 0;
//
//
//}






//
//
//#include <iostream>
//using namespace std;
//
//class IntegerSet {
//private:
//    bool set[101]; // Array of bool values to represent the set (0-100)
//
//public:
//    // Default constructor initializes the set to the empty set
//    IntegerSet() {
//        for (int i = 0; i <= 100; i++) {
//            set[i] = false; // Empty set, all elements false
//        }
//    }
//
//    // Constructor to initialize from an array of integers
//    IntegerSet(int arr[], int size) {
//        for (int i = 0; i <= 100; i++) {
//            set[i] = false; // Initialize the empty set
//        }
//        for (int i = 0; i < size; i++) {
//            if (arr[i] >= 0 && arr[i] <= 100) {
//                set[arr[i]] = true; // Only add valid elements
//            }
//        }
//    }
//
//    // Overload the + operator to create a union of two sets
//    IntegerSet operator+(const IntegerSet& other) {
//        IntegerSet result;
//        for (int i = 0; i <= 100; i++) {
//            result.set[i] = this->set[i] || other.set[i]; // Union: true if either set has true
//        }
//        return result;
//    }
//
//    // Overload the * operator to create the intersection of two sets
//    IntegerSet operator*(const IntegerSet& other) {
//        IntegerSet result;
//        for (int i = 0; i <= 100; i++) {
//            result.set[i] = this->set[i] && other.set[i]; // Intersection: true if both sets have true
//        }
//        return result;
//    }
//
//    // Overload the pre-decrement operator to remove the last element
//    IntegerSet& operator--() {
//        for (int i = 100; i >= 0; i--) {
//            if (set[i]) {
//                set[i] = false; // Remove the last element
//                break;
//            }
//        }
//        return *this;
//    }
//
//    // Overload the post-decrement operator to remove the last element
//    IntegerSet operator--(int) {
//        IntegerSet temp = *this;
//        --(*this); // Call the pre-decrement function
//        return temp;
//    }
//
//    // Overload the == operator to check equality of two sets
//    bool operator==(const IntegerSet& other) const {
//        for (int i = 0; i <= 100; i++) {
//            if (this->set[i] != other.set[i]) {
//                return false; // Return false if any element is different
//            }
//        }
//        return true; // All elements are the same
//    }
//
//    // Overload the << operator to print the set
//    friend ostream& operator<<(ostream& os, const IntegerSet& s) {
//        bool empty = true;
//        os << "{ ";
//        for (int i = 0; i <= 100; i++) {
//            if (s.set[i]) {
//                os << i << " "; // Print the element
//                empty = false;
//            }
//        }
//        if (empty) {
//            os << " "; // For an empty set
//        }
//        os << "}";
//        return os;
//    }
//
//    // Function to add an element to the set
//    void insertElement(int element) {
//        if (element >= 0 && element <= 100) {
//            set[element] = true;
//        }
//    }
//
//    // Function to remove an element from the set
//    void deleteElement(int element) {
//        if (element >= 0 && element <= 100) {
//            set[element] = false;
//        }
//    }
//};
//
//// Driver program to test IntegerSet class
//int main() {
//    // Create two sets using the constructor with array
//    int arr1[] = { 1, 3, 5, 7, 100 };
//    int arr2[] = { 2, 3, 5, 99 };
//    IntegerSet set1(arr1, 5);
//    IntegerSet set2(arr2, 4);
//
//    // Test union (+ operator)
//    IntegerSet unionSet = set1 + set2;
//    cout << "Union of set1 and set2: " << unionSet << endl;
//
//    // Test intersection (* operator)
//    IntegerSet intersectionSet = set1 * set2;
//    cout << "Intersection of set1 and set2: " << intersectionSet << endl;
//
//    // Test pre-decrement (removing last element)
//    --set1;
//    cout << "Set1 after pre-decrement: " << set1 << endl;
//
//    // Test post-decrement (removing last element)
//    set2--;
//    cout << "Set2 after post-decrement: " << set2 << endl;
//
//    // Test equality operator (==)
//    if (set1 == set2) {
//        cout << "Set1 and Set2 are equal." << endl;
//    }
//    else {
//        cout << "Set1 and Set2 are not equal." << endl;
//    }
//
//    return 0;
//}










#include<iostream>
using namespace std;



class number {
	int quantity;

public:

	number() {};
	number(int n) {
		quantity = n;
	}

	number operator>=(number& n) {
		number result;
		if (this->quantity >= n.quantity) {
			return result.quantity=this->quantity + n.quantity * 3;
		}

		else {

			return result.quantity = this->quantity - n.quantity * 3;
		}


	}

	bool operator==(number& n) {
		if (this->quantity == n.quantity) {
			return true;
		}

		else {
			return false;

		}
	}



	
};


int main() {
	number item1;

	number item2;

	number result;

	result = item1 >= item2;

	if (item1 == item2) {
		cout << "it is printing " << endl;
	}
}