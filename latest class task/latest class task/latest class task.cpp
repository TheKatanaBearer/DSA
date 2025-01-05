//
//
//#include<iostream>
//using namespace std;
//
//class MyArray {
//private:
//	int size;
//	int* arr;
//public:
//	MyArray();
//	MyArray(int);
//	MyArray(int, int);
//	~MyArray();
//	MyArray(int*, int);
//	MyArray(const MyArray&);
//	const MyArray& operator()(int start, int n)const;
//	const int& operator[](int)const;
//	const MyArray& operator=(const MyArray&);
//	friend ostream& operator<<(ostream&, const MyArray&);
//	friend istream& operator>>(istream&, MyArray&);
//};
//
//
//
//
//MyArray::MyArray()
//{
//	size = 0;
//	arr = nullptr;
//}
//
//MyArray::MyArray(int s)
//{
//	size = s;
//	arr = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = -1;
//
//	}
//}
//
//MyArray::MyArray(int s, int value)
//{
//	size = s;
//	arr = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = value;
//	}
//}
//
//MyArray::~MyArray()
//{
//	if (size > 0)
//	{
//		delete[]arr;
//	}
//}
//
//MyArray::MyArray(int* array, int s)
//{
//	size = s;
//	arr = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = array[i];
//	}
//}
//
//MyArray::MyArray(const MyArray& aray)
//{
//	if (this != &aray) {
//		size = aray.size;
//		arr = new int[size];
//		for (int i = 0; i < size; i++)
//		{
//			arr[i] = aray.arr[i];
//		}
//	}
//}
//
//const MyArray& MyArray::operator=(const MyArray& aray)
//{
//	if (this != &aray)
//	{
//		delete[]arr;
//		size = aray.size;
//		arr = new int[size];
//		for (int i = 0; i < size; i++)
//		{
//			arr[i] = aray.arr[i];
//		}
//
//	}
//	return *this;
//
//}
//
//ostream& operator<<(ostream& out, const MyArray& aray)
//{
//	for (int i = 0; i < aray.size; i++)
//	{
//		out << aray.arr[i] << " ";
//	}
//	return out;
//}
//
//istream& operator>>(istream& in, MyArray& aray)
//{
//	if (aray.size == 0)
//	{
//		do {
//			cout << " Input size in Positive: ";
//			cin >> aray.size;
//		} while (aray.size < 0 || aray.size == 0);
//		delete[]aray.arr;
//		aray.arr = new int[aray.size];
//	}
//	cout << " Input array Elemenets: " << endl;
//	for (int i = 0; i < aray.size; i++)
//	{
//		cout << " Element [" << i + 1 << "]";
//		in >> aray.arr[i];
//	}
//	return in;
//}
//
//const int& MyArray::operator[](int size)
//{
//	return arr[size];
//}
//
//const MyArray& MyArray::operator()(int start, int n) const {
//	MyArray temp(n);
//
//	for (int i = start, j = 0; i < start + n; i++, j++) {
//		temp[j] = arr[i];
//	}
//	return temp;
//}




#include<iostream>
using namespace std;

class MyArray {
private:
    int size;
    int* arr;
public:
    MyArray();
    MyArray(int);
    MyArray(int, int);
    ~MyArray();
    MyArray(int*, int);
    MyArray(const MyArray&);
    MyArray operator()(int start, int n) const;
    int& operator[](int);
    const int& operator[](int) const;
    MyArray& operator=(const MyArray&);
    friend ostream& operator<<(ostream&, const MyArray&);
    friend istream& operator>>(istream&, MyArray&);
};

// Default constructor
MyArray::MyArray() : size(0), arr(nullptr) {}

// Constructor with size
MyArray::MyArray(int s) : size(s), arr(new int[s]) {
    for (int i = 0; i < size; i++) {
        arr[i] = -1;
    }
}

// Constructor with size and value
MyArray::MyArray(int s, int value) : size(s), arr(new int[s]) {
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}

// Destructor
MyArray::~MyArray() {
    delete[] arr;
}

// Constructor with array and size
MyArray::MyArray(int* array, int s) : size(s), arr(new int[s]) {
    for (int i = 0; i < size; i++) {
        arr[i] = array[i];
    }
}

// Copy constructor
MyArray::MyArray(const MyArray& aray) : size(aray.size), arr(new int[aray.size]) {
    for (int i = 0; i < size; i++) {
        arr[i] = aray.arr[i];
    }
}

// Assignment operator
MyArray& MyArray::operator=(const MyArray& aray) {
    if (this != &aray) {
        delete[] arr;
        size = aray.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = aray.arr[i];
        }
    }
    return *this;
}

// Output stream operator
ostream& operator<<(ostream& out, const MyArray& aray) {
    for (int i = 0; i < aray.size; i++) {
        out << aray.arr[i] << " ";
    }
    return out;
}

// Input stream operator
istream& operator>>(istream& in, MyArray& aray) {
    if (aray.size == 0) {
        do {
            cout << "Input size in Positive: ";
            in >> aray.size;
        } while (aray.size <= 0);
        delete[] aray.arr;
        aray.arr = new int[aray.size];
    }
    cout << "Input array Elements: " << endl;
    for (int i = 0; i < aray.size; i++) {
        cout << "Element [" << i + 1 << "]: ";
        in >> aray.arr[i];
    }
    return in;
}

// Non-const subscript operator
int& MyArray::operator[](int index) {
    return arr[index];
}

// Const subscript operator
const int& MyArray::operator[](int index) const {
    return arr[index];
}

// Sub-array operator
MyArray MyArray::operator()(int start, int n) const {
    MyArray temp(n);
    for (int i = start, j = 0; j < n; i++, j++) {
        temp[j] = arr[i];
    }
    return temp;
}

int main() {
    MyArray arr1(5, 2); // Create array of size 5 with all values 2
    cout << "arr1: " << arr1 << endl;

    MyArray arr2;
    cin >> arr2; // Input elements for arr2
    cout << "arr2: " << arr2 << endl;

    MyArray arr3 = arr1(1, 3); // Create sub-array from arr1
    cout << "arr3: " << arr3 << endl;

    arr2[2] = 10; // Modify arr2
    cout << "Modified arr2: " << arr2 << endl;

    return 0;
}
