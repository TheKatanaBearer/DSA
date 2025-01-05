////
////
//#include<iostream>
//using namespace std;
//	class arc {
//	private:
//		double radius;
//		double angle;
//		int arc_length;
//	public:
//		void set_radius(double radius) {
//			this->radius = radius;
//
//		}
//
//		void set_angle(double angle) {
//			this->angle = angle;
//		}
//
//		
//
//		double get_Arc_length()const {
//			return radius * angle;
//		}
//
//	};
//
//
//
//int main() {
//	arc a;
//	a.set_angle(15);
//	
//	a.set_radius(15.5);
//
//
//	cout << a.get_Arc_length();
//
//
//}


//
//
//class pizza {
//	double size;
//	string toppings;
//	double price;
//	double thickness;
//	string extra_toppings;
//
//
//public:
//
//	pizza(){
//
//		set_size();
//		set_price();
//		set_toppings();
//		set_extratoppings();
//		set_thickness();
//
//	}
//
//	pizza(double size, string toppings, double price, double thickness, string extra_toppings) {
//		this->size = size;
//		this->toppings = toppings;
//		this->price = price;
//		this->thickness = thickness;
//		this->extra_toppings = extra_toppings;
//	}
//
//	void set_size() {
//		cout << "enter the size " << endl;
//		cin >> size;
//	}
//
//
//	void set_toppings() {
//		cout << "enter the toppings that you want to add " << endl;
//		cin >> toppings;
//
//	}
//	void set_price() {
//		cout << "Set the price " << endl;
//		cin >> price;
//
//	}
//	void set_thickness() {
//		cout << "Set the thickness " << endl;
//		cin >> extra_toppings;
//	}
//
//	void set_extratoppings() {
//		cout << "set the extra toppings " << endl;
//		cin >> extra_toppings;
//	}
//
//
//
//};

//

//#include<iostream>
//using namespace std;
//class student {
//	string name;
//	int age;
//
//public:
//	student() {
//
//		cout << "enter the name of the student " << endl;
//		cin >> name;
//
//		cout << "enter the age of the student " << endl;
//		cin >> age;
//	}
//
//	student(string name, int age) {
//		this->name = name;
//		this->age = age;
//	}
//
//
//	void displayAll() {
//		cout << "the name of the student is " << name << endl;
//		cout << "the age of the studen is " << age << endl;
//	}
//
//};
//
//int main() {
//	student s1;
//	s1.displayAll();
//
//
//	student s2("hamza ", 18);
//	s2.displayAll();
//
//}

//
//class english {
//	string sentence;
//	int size;
//
//public:
//
//	english(string sentence) {
//		this->sentence = sentence;
//	}
//
//	english(const  english& s) {
//		sentence = s.sentence;
//
//
//	}
//
//	int get_size()const {
//		int count = 0;
//		for (int i = 0; sentence[i] !='\0'; i++) {
//			count++;
//		}
//		return count;
//
//	}
//
//};
//
//int main() {
//	english hamza("hamza");
//	cout<<hamza.get_size();
//
//
//	english abdullah = hamza;
//
//	cout << abdullah.get_size() << endl;
//
//
//}





//
//class circle {
//
//private:
//	static int count;
//public:
//	 static int get_count();
//	 circle();
//	 ~circle();
//};
//int circle::get_count()
//{
//	return count;
//}
//int circle :: count = 0;
//
//circle::circle() {
//	count++;
//}
//
//circle::~circle() {
//	count--;
//}
//
//int main() {
//	cout << "at the start count " << circle::get_count() << endl;
//	circle c1;
//
//	cout << "after creating the first object " << circle::get_count() << "-----------" << c1.get_count();
//
//	circle c2;
//
//	cout << "After creating the second object " << circle::get_count() << "-------------------" << c2.get_count();
//}




//
//#include<iostream>
//using namespace std;
//class student{
//
//	int age;
//	static string name;
//
//
//public:
//
//	student() {
//		age = 16;
//		name = "abdullah";
//	}
//	~student() {
//		name = "hamza ";
//		cout << name;
//	}
//
//	static string name_func();
//	
//};
//
//string student::name = "hamza ";
//string student::name_func() {
//	return name;
//}
//
//
//int main() {
//	cout << student::name_func();
//
//	student s1;
//
//	cout << student::name_func();
//}



//function to find the power
//
//#include<iostream>
//using namespace std;
//
//int powerfunc(int x, int y) {
//	cout << "the question is " << x << "^" << y << endl;
//	int b = 1;
//	for (int i = 0; i < y; i++) {
//		b = b * x;
//	}
//	return b;
//}
//
//
//
//int main() {
//
//	int x, y;
//	cout << "enter the base and coefficent " << endl;
//	cin>>x >> y;
//
//	cout << powerfunc(x, y);
//
//}


//
//#include<iostream>
//using namespace std;
//
//class average {
//private:
//	int x;
//	int y;
//public:
//	average() {
//		x = 5;
//		y = 5;
//	}
//
//	friend float average_function(average obj);
//
//};
//
//
//float average_function( average a) {
//	cout << "the average of the two numbers are " << endl;
//	float b;
//	b = (a.x + a.y) / 2;
//	return b;
//}
//
//int main() {
//
//	average avg;
//
//	cout<<average_function(avg);
//
//
//}



//now doing the same but using two different classes

class A;

class B;



class A {
	int x;
public:
	A() {
		x = 5;
	}
	friend double average_func(A a, B b);
};

class B {
	int y;
public:
	B() {
		y = 5;
	}
	friend double average_func(A a, B b);
};

double average_func(A a, B b) {
	double t;
	t = (a.x + b.y) / 2.0; 
	return t;  
}
