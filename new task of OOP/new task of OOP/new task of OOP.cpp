#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class STUDENT {
	string name, father_name;
	int age;
	float gpa;
	fstream file_;
public:
	STUDENT()
	{
		file_.open("hamza2.dat");
	}
	void getFunction();
	void writeInFile(STUDENT&);
	void readFromFile(STUDENT&);
	~STUDENT()
	{

		file_.close();

	}
};

void STUDENT::readFromFile(STUDENT& x)
{
	file_.open("hamza.dat", ios::in | ios::binary);
	file_.read((char*)&x, sizeof(x));
	cout << " Name: " << x.name << endl;
	cout << " Father Name: " << x.father_name << endl;
	cout << " Age: " << x.age << endl;
	cout << " GPA: " << x.gpa << endl;
}

void STUDENT::getFunction()
{
	cout << " Input name: ";
	getline(cin, name);
	cout << " Input father name: ";
	getline(cin, father_name);
	cout << " Input your age: ";
	cin >> age;
	cout << " Input your GPA: ";
	cin >> gpa;
}

void STUDENT::writeInFile(STUDENT& J)
{
	file_.open("hamza2.dat", ios::out | ios::binary);
	file_.write((char*)&J, sizeof(J));


}


int main()
{
	STUDENT a1;
	a1.getFunction();
	a1.writeInFile(a1);
	cout << "---------------------" << endl;
	a1.readFromFile(a1);
	
	
}