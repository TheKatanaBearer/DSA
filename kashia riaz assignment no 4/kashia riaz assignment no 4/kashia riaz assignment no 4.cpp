
// Question 1

//
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//class planePoint {
//private:
//	int x;
//	int y;
//public:
//
//	planePoint(int x = 0, int y = 0) : x(x), y(y) {}
//	int getx()const {
//		return x;
//
//	}
//	int gety()const {
//		return y;
//	}
//
//	double planeDistance(const planePoint& p)const {
//		int valX = x - p.x;
//		int valY = y - p.y;
//		return sqrt((valX * valX) + (valY * valY));
//	}
//
//};
//
//class spacePoint :public planePoint {
//private:
//	int z;
//public:
//	spacePoint() : planePoint(), z(0) {}
//	spacePoint(int x, int y, int z) : planePoint(x, y), z(z) {}
//
//	int getZ()const {
//		return z;
//	}
//	double spaceDistance(const spacePoint& p) const {
//		int dx = getx() - p.getx();
//		int dy = gety() - p.gety();
//		int dz = z - p.z;
//		return sqrt(dx * dx + dy * dy + dz * dz);
//	}
//
//};
//
//int main() {
//
//	planePoint p1(3, 4);
//	planePoint p2(6, 8);
//
//	cout << "Distance between p1 and p2 in the plane: " << p1.planeDistance(p2) << endl;
//
//	spacePoint s1(1, 2, 3);
//	spacePoint s2(4, 5, 6);
//
//	cout << "Distance between s1 and s2 in the space: " << s1.spaceDistance(s2) << endl;
//
//}
//

//question 2

//
//#include <iostream>
//#include <string>
//using namespace std;
//class Company {
//public:
//    int companyID;
//    string companyName;
//
//
//    Company(int id, string name) : companyID(id), companyName(name) {}
//
//    int getCompanyID() const 
//    {
//        return companyID; 
//    }
//    string getCompanyName() const { 
//        return companyName; 
//    }
//
//    void setCompanyID(int id) { 
//        companyID = id;
//    }
//    void setCompanyName(string name) {
//        companyName = name; 
//    }
//};
//
//class MobilePhone : public Company {
//private:
//    string mobilePhoneName;
//    int mobileID;
//    int mobilePrice;
//
//public:
//    MobilePhone(int companyID, string companyName, string mobileName, int mobileID, int mobilePrice): Company(companyID, companyName), mobilePhoneName(mobileName), mobileID(mobileID), mobilePrice(mobilePrice) {}
//
//
//    string getMobilePhoneName() const {
//        return mobilePhoneName; 
//    }
//    int getMobileID() const { 
//        return mobileID; 
//    }
//    int getMobilePrice() const { 
//        return mobilePrice; 
//    }
//
//    void setMobilePhoneName(string name) {
//        mobilePhoneName = name; 
//    }
//    void setMobileID(int id) {
//        mobileID = id; 
//    }
//    void setMobilePrice(int price) {
//        mobilePrice = price; 
//    }
//
//    void display() const {
//        std::cout << "Company ID: " << getCompanyID() << std::endl;
//        std::cout << "Company Name: " << getCompanyName() << std::endl;
//        std::cout << "Mobile Phone Name: " << mobilePhoneName << std::endl;
//        std::cout << "Mobile ID: " << mobileID << std::endl;
//        std::cout << "Mobile Price: " << mobilePrice << std::endl;
//    }
//};
//
//class Laptop : public Company {
//private:
//    std::string laptopName;
//
//public:
//    Laptop(int companyID, std::string companyName, std::string laptopName) : Company(companyID, companyName), laptopName(laptopName) {}
//
//    string getLaptopName() const {
//        return laptopName; 
//    }
//
//    void setLaptopName(std::string name) {
//        laptopName = name; 
//    }
//
//    void display() const {
//        std::cout << "Company ID: " << getCompanyID() << std::endl;
//        std::cout << "Company Name: " << getCompanyName() << std::endl;
//        std::cout << "Laptop Name: " << laptopName << std::endl;
//    }
//};
//
//int main() {
//    MobilePhone mobile(1, "apple", "iphone 13", 123, 999);
//    Laptop laptop(2, "dell", "infinix");
//
//    mobile.display();
//    cout << endl;
//    laptop.display();
//
//    mobile.companyID = 10;    //we would not have been able to do this if protected was enabled
//    laptop.companyName = "mac book";//we would not have been able to do this if protected was enabled
//
//    mobile.display();
//    cout<<endl;
//    laptop.display();
//
//    return 0;
//}
//
//

//question 3
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//class CafeService {
//protected:
//    string orderID;
//    double price;
//
//public:
//    CafeService() : orderID("NIL"), price(0.0) {}
//
//    CafeService(string id, double p) : orderID(id), price(p) {}
//
//    string getOrderID() const {
//        return orderID; 
//    }
//    double getPrice() const { 
//        return price; 
//    }
//};
//
//class StaffService : public CafeService {
//private:
//    double serviceFee;
//    int cabinNumber;
//
//public:
//    StaffService(string id, double p, double fee, int cabin): CafeService(id, p), serviceFee(fee), cabinNumber(cabin) {}
//
//    double totalCharges() const { 
//        return getPrice() + serviceFee; 
//    }
//
//    void display() const {
//        cout << "Order ID: " << getOrderID() << endl;
//        cout << "Price: " << getPrice() << endl;
//        cout<< "Service Fee: " << serviceFee << endl;
//        cout << "Cabin Number: " << cabinNumber << endl;
//        cout << "Total Charges: " << totalCharges() << endl;
//    }
//};
//
//int main() {
//    StaffService staff("34124", 20.0, 5.0, 12);
//
//    staff.display();
//
//    return 0;
//}


//question 4


//#include <iostream>
//#include <string>
//using namespace std;
//
//class Automobile {
//protected:
//    int current_speed;
//
//public:
//
//    Automobile() : current_speed(0) {}
//    void set_current_speed(int current_speed) {
//        this->current_speed = current_speed;
//    }
//
//    int get_current_speed()const {
//        return current_speed;
//    }
//
//};
//
//class car :public Automobile {
//protected:
//    string color;
//public:
//    car(int current_speed, const string& color) {
//        this->current_speed = current_speed;
//        this->color = color;
//    }
//
//    void set_color(const string& color) {
//        this->color = color;
//    }
//    string get_color()const {
//        return color;
//    }
//
//};
//
//
//class limousine :public car {
//public:
//
//    limousine(int speed,const string& limocolor):car(speed,limocolor){}
//
//    void set_current_speed(int current_speed) {
//        this->current_speed = current_speed;
//    }
//
//    int get_current_speed()const {
//        return current_speed;
//    }
//
//    void set_color(const string& color) {
//        this->color = color;
//    }
//
//    string get_color()const {
//        return color;
//    }
//};
//
//int main() {
//    limousine lim(65, "red");
//
//    lim.set_current_speed(100);
//    cout << "the current speed of the limo is " << lim.get_current_speed() << endl;
//
//    lim.set_color("yellow ");
//    cout << "the color of the limo is " << lim.get_color();
//
//
//    return 0;
//}
//
//
//




//question 5

//#include<iostream>
//#include<string>
//using namespace std;
//
//class laboratory {
//protected:
//
//	string name;
//	string location;
//
//public:
//	laboratory() {
//		name = "no name ";
//		location = "Null ";
//
//	}
//
//	virtual void input() {
//		cout << "enter the name " << endl;
//		getline(cin, name);
//
//		cin.ignore();
//
//		cout << "enter the location of the lab " << endl;
//		cin >> location;
//
//	}
//
//	virtual void show()const {
//		cout << "the name is " << name << endl;
//		cout << "the location is " << location << endl;
//	}
//
//};
//
//class wetlab :public laboratory {
//	int no_of_microscopes;
//	string scientist_name;
//public:
//
//	void set_no_of_microscopes(int no_of_microscopes){
//		this->no_of_microscopes = no_of_microscopes;
//	}
//
//	int get_no_of_microscopes()const{
//		return no_of_microscopes;
//	}
//
//	void set_scientist_name(const string& scientist_name) {
//		this->scientist_name = scientist_name;
//	}
//
//	string get_scientist_name()const {
//		return scientist_name;
//	}
//
//	void input()override {
//		laboratory::input();
//		cout << "enter the number of microscopes " << endl;
//		cin>> no_of_microscopes;
//
//	
//
//		cout << "enter the sceintist name " << endl;
//
//		cin.ignore();
//		getline(cin, scientist_name);
//
//		
//	}
//
//	void show()const override {
//		laboratory::show();
//		cout << "the number of microscopes are " << no_of_microscopes << endl;
//		cout << "the scientists name is " << scientist_name << endl;
//	}
//};
//
//class drylab :public laboratory {
//private:
//	int no_of_computers;
//	int capacity;
//public:
//	void set_no_of_computers(int computers) {
//		no_of_computers = computers;
//
//	}
//	int get_no_of_computers()const {
//		return no_of_computers;
//
//	}
//
//	void set_capacity(int capacity) {
//		this->capacity -= capacity;
//	}
//
//
//	int get_capacity()const {
//
//		return capacity;
//
//	}
//
//	void input()override {
//		laboratory::input();
//		cout << "enter the number of computers " << endl;
//		cin >> no_of_computers;
//
//		cout << "enter the capacity of lab " << endl;
//		cin >> capacity;
//	}
//
//
//	void show()const override {
//		laboratory::show();
//
//		cout << "the number of computers are " << no_of_computers << endl;
//		cout << "the lab capacity is " << capacity << endl;
//	}
//
//
//
//
//};
//
//
//
//int main() {
//	laboratory lab;
//	wetlab wet;
//	drylab dry;
//
//	lab.show();
//
//	wet.input();
//	cout << "the wet lab details are " << endl;
//	wet.show();
//
//	dry.input();
//
//	cout << "the dry lab details are " << endl;
//	dry.show();
//
//
//
//}


//question 6

//#include<iostream>
//#include<string>
//using namespace std;
//
//
//class record {
//private:
//	int rollno;
//	string course1_name;
//	string course2_name;
//
//public:
//	record(int rollno, const string& course1name, const string& course2name) :rollno(rollno), course1_name(course1name), course2_name(course2name) {}
//    int getRollNo() const {
//        return rollno;
//    }
//
//    string getCourse1Name() const {
//        return course1_name;
//    }
//
//    string getCourse2Name() const {
//        return course2_name;
//    }
//};
//
//
//class CourseRecord : public record {
//private:
//    int marks_course1;
//    int marks_course2;
//
//public:
//    CourseRecord(int rollNo, const string& course1Name, const string& course2Name, int marksCourse1, int marksCourse2) : record(rollNo, course1Name, course2Name), marks_course1(marksCourse1), marks_course2(marksCourse2) {}
//
//    int getMarksCourse1() const {
//        return marks_course1;
//    }
//
//    int getMarksCourse2() const {
//        return marks_course2;
//    }
//
//
//
//};
//
//
//class CourseResult : public CourseRecord {
//public:
//    CourseResult(int rollNo, const string& course1Name, const string& course2Name, int marksCourse1, int marksCourse2) : CourseRecord(rollNo, course1Name, course2Name, marksCourse1, marksCourse2) {}
//
//    int marksObtained() const {
//        return getMarksCourse1() + getMarksCourse2();
//    }
//
//    void display() const {
//        cout << "Roll Number: " << getRollNo() << endl;
//        cout << "Course 1 Name: " << getCourse1Name() << endl;
//        cout << "Course 2 Name: " << getCourse2Name() << endl;
//        cout << "Marks in Course 1: " << getMarksCourse1() << endl;
//        cout << "Marks in Course 2: " << getMarksCourse2() << endl;
//        cout << "Total Marks: " << marksObtained() << endl;
//    }
//};
//
//int main() {
//    CourseResult student(120, "OOP", "Physics", 86,83);
//
//   
//    student.display();
//
//    return 0;
//}


#include<iostream>
using namespace std;


class clock
{
	int hr, min;

public:
	clock()
	{
		cout<<"Clock constructor"<<endl;
	}
	clock(int a, int b)
	{
		hr = a;
		min = b;
		cout << "Clock constructor called at " << hr << min << endl;
	}
	~clock()
	{
		cout << "Clock destructor called" << endl;
	}
};

class postoffice
{
public:

	postoffice()
	{
		cout << "post office constructor called" << endl;

	}

	~postoffice()
	{
		cout << "Postoffice destructor called" << endl;
	}

};
int main()
{
	postoffice a;
	clock c(10, 20);
}