//#include<iostream>
//using namespace std;
//
//class arith_series {
//	int first;
//	int last;
//	int total_entries_for_sum;
//	double sum;
//	
//public: 
//	arith_series() {
//
//		cout << "enter the values " << endl;
//
//		cout << "the first digit is " << endl;
//	cin >> first;
//
//	cout << "the last digit is " << endl;
//	cin >> last;
//
//	cout << "the total entries for the sum is " << endl;
//	cin >> total_entries_for_sum;
//
//	sum = 0;
//
//
//	}
//
//	friend double arith_sum(arith_series a);
//};
//
//
//double arith_sum(arith_series a) {
//
//	a.sum = (a.total_entries_for_sum) / 2 * (a.first + a.last);
//
//	return a.sum;
//		
//
//}
//
//int main() {
//
//	arith_series a;
//
//	cout << "The sum of the arithmetic series is " << arith_sum(a);
//
//
//
//
//}



//
//#include<iostream>
//using namespace std;
//
//class rectangle {
//	int length;
//	int width;
//
//public:
//	void set_width(int width) {
//		this->width = width;
//	}
//
//	void set_length(int length) {
//		this->length = length;
//	}
//
//	int get_width() const{
//		return width;
//	}
//
//	int get_length() const{
//		return length;
//	}
//
//	int recArea() {
//		return get_width()* get_length();
//	}
//};
//
//
//class cuboid :public rectangle {
//private:
//	int height;
//public:
//	void set_height(int height) {
//		this->height = height;
//
//	}
//
//	int get_height() const{
//		return height;
//	}
//	int cuboidArea() {
//		return get_height() * get_length() * get_width();
//	}
//
//
//};
//
//int main() {
//	
//
//	cuboid c;
//
//	c.set_length(15);
//
//	c.set_width(19);
//
//	c.set_height(15);
//
//	cout << "the area of the cuboid is " << c.cuboidArea() << endl;
//
//}
//
//







//
//
//
//#include<iostream>
//using namespace std;
//
//class graduate_course {
//    string course_ID;
//    string course_name;
//    string credit_hours;
//    string course_fee;
//public:
//    graduate_course(string course_ID, string course_name, string credit_hours,string course_fee) {
//        this->course_ID = course_ID;
//        this->course_name = course_name;
//        this->credit_hours = credit_hours;
//        this->course_fee = course_fee;
//
//    }
//
//    string get_course_ID()const {
//        return course_ID;
//    }
//
//    string get_course_name()const {
//        return course_name;
//
//    }
//
//
//    string get_course_hours()const {
//        return credit_hours;
//    }
//
//    string get_course_fee()const {
//        return course_fee;
//    }
//
//    
//    
//};
//
//class researach_course : public graduate_course {
//public:
//    string experiment_fee;
//public:
//    researach_course(string course_ID, string course_name, string credit_hours,string course_fee, string experiment_fee) : graduate_course(course_ID, course_name, credit_hours,course_fee) { 
//             this->experiment_fee = experiment_fee;
//    }
//
//    void set_experiment_fee(string experiment_fee) {
//        this->experiment_fee = experiment_fee;
//    }
//
//    string get_experiment_fee()const {
//        return experiment_fee;
//    }
//
//    void display()const {
//
//        cout << "the course ID is " << get_course_ID() << endl;
//        cout << "the course name is " << get_course_name() << endl;
//        cout << "the course credit hours are " << get_course_hours() << endl;
//        cout << "the course fee is " << get_course_fee() << endl;
//        cout << "the experiment fee is " << get_experiment_fee() << endl;
//    }
//
//    friend int my_stoi(const string& str);
//    friend int total_fee(researach_course r);
//
//};
//
//
//int my_stoi(const string& str) {
//    int num = 0;
//    int sign = 1;
//    int i = 0;
//
//    if (str[0] == '-') {
//        sign = -1;
//        i = 1;
//
//    }
//
//    for (; i < str.length(); i++) {
//
//        if (str[i] < '0' || str[i]>'9') {
//            cout << "invalid argument " << endl;
//        }
//
//        num = num * 10 + (str[i] - '0');
//    }
//
//    return num * sign;
//
//}
//
//int total_fee(researach_course r) {
//
//    int experiment_fee = my_stoi(r.get_experiment_fee());
//
//    int course_fee = my_stoi(r.get_course_fee());
//
//
//    return experiment_fee + course_fee;
//
//    
//
//
//}
//
//
//int main() {
//
//   
//    researach_course r("212341", "OOP", "3", "30000", "3000");
//
//    cout << "the aggregate fee is " << total_fee(r);
//
//
//}





#include<iostream>
using namespace std;

class Car {

protected:

	string carName;
	bool ignition;
	int currentSpeed;

public:


    
    Car() : carName("Dinky"), ignition(false), currentSpeed(0) {}

    
    Car(string name, bool ign, int speed) : carName(name), ignition(ign), currentSpeed(speed) {}

    
    void setCarName(string name) {
        carName = name;
    }

    void setIgnition(bool ign) {
        ignition = ign;
    }

    void setCurrentSpeed(int speed) {
        currentSpeed = speed;
    }

    
    string getCarName() const {
        return carName;
    }

    bool getIgnition() const {
        return ignition;
    }

    int getCurrentSpeed() const {
        return currentSpeed;
    }

    
    void setSpeed(int speed) {
        currentSpeed = speed;
    }



};




class Convertible : public Car {
private:
    bool top;

public:
   
    Convertible() : Car(), top(false) {}

    
    Convertible(string name, bool ign, int speed, bool t) : Car(name, ign, speed), top(t) {}

    
    void setTop(bool t) {
        top = t;
    }

    
    void show() const {
        std::cout << "Car Name: " << carName << std::endl;
        std::cout << "Ignition: " << (ignition ? "On" : "Off") << std::endl;
        std::cout << "Current Speed: " << currentSpeed << " km/h" << std::endl;
        std::cout << "Top: " << (top ? "Up" : "Down") << std::endl;
    }
};

int main() {
    
    Convertible myConvertible;
    myConvertible.show();

    
    Convertible myCustomConvertible("mercedes", true, 80, true);
    myCustomConvertible.show();

    
    myConvertible.setCarName("honda");
    myConvertible.setIgnition(true);
    myConvertible.setCurrentSpeed(120);
    myConvertible.setTop(true);
    myConvertible.show();

    return 0;
}




















