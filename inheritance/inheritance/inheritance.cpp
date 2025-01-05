//
//
//#include<iostream>
//using namespace std;
//
//class father {
//protected:
//
//	string name;
//public:
//	father() {
//		 name = "Hamza ";
//	}
//
//};
//
//class son1 :public father {
//public:
//
//	void intro()const {
//		cout << "the name is " << name << endl;
//	}
//};
//
//
//class son2 :public son1 {
//
//private:
//	string surname;
//public:
//	son2() {
//		 surname = "Tariq ";
//	}
//	void fullintro()const {
//		cout << "the full name is: " << name << "and the surname is " << surname;
//	}
//};
//
//int main() {
//	son2 s;
//	s.fullintro();
//}

//
//#include<iostream>
//using namespace std;
//
//class person {
//protected:
//	string name;
//	string surname;
//public:
//	person() {
//		name = "hamza ";
//		surname = "Tariq ";
//	}
//		string getsurname()const {
//			return surname;
//		}
//	
//};
//
//
//class student :public person {
//public:
//	void displayname()const {
//		cout << "the name is " << name << "and the surname is " << getsurname() << endl;
//	}
//};
//
//
//
//int main() {
//	student s;
//	s.displayname();
//
//}


//#include<iostream>
//using namespace std;
//
//class base {
//public:
//
//	base() {
//		cout << "this is the base class constructor " << endl;
//	}
//
//	~base() {
//		cout << "this is the base class destructor " << endl;
//	}
//
//};
//
//class derived : public base {
//public:
//	derived() {
//
//		cout << "this is the derived class constructor " << endl;
//	}
//		~derived() {
//			cout << "this is the derived class destructor " << endl;
//		}
//	
//};
//
//
//
//int main() {
//	derived d;
//	
//}


//#include<iostream>
//using namespace std;
//
//class shape {
//public:
//	virtual void draw() {
//		cout << "the shape is..." << endl;
//	}
//};
//
//class circle :public shape {
//public:
//	void draw()override {
//		cout << "the circle is golll " << endl;
//	}
//};
//
//
//int main() {
//	shape* shapes = new shape();
//	shapes->draw();
//	circle* circles = new circle();
//	circles->draw();
//}


//#include<iostream>
//using namespace std;
//
//class person {
//protected:
//	string name;
//	int age;
//public:
//	person(string x, int y) {
//		name = x;
//		age = y;
//	}
//
//	void display()const {
//		cout << "the name is " << name << "the age is " << age << endl;
//	}
//
//};


//class student :public person {
//protected:
//	int stud_id;
//
//public:
//	
//	student(string x, int y, int stid) :person(x, y), stud_id(stid) {}
//	
//	void display()const  {
//		cout << "the name is " << name << "and the age is " << age << "and the student id is " << stud_id << endl;
//	}
//
//	
//
//};
//
//
//class graduate_student:public student{
//protected:
//	string research_topic;
//public:
//	graduate_student(string x,int y,int stid,const string& rt):student(x,y,stid),research_topic(rt){}
//	void display()const {
//		student::display();
//		cout << "the research topic is " << research_topic;
//	}
//};
//
//
//int main() {
//	graduate_student gs("hamza", 8, 5, "china and their food ");
//
//	gs.display();
//}

//
//#include<iostream>
//using namespace std;
//
//class base {
//public:
//	virtual ~base() {
//		cout << "base class destructor " << endl;
//	}
//};
//
//
//class derived :public base {
//public:
//	~derived() {
//		cout << "this is the dervived class destructor " << endl;
//	}
//};
//
//
//
//int main() {
//	base* b = new derived();
//	delete b;
//}
//
//
//
//#include<iostream>
//using namespace std;
//class base {
//public:
//	base() {
//		cout << "this is the base class constructor " << endl;
//	}
//
//	~base() {
//		cout << "this is the base class destructor " << endl;
//	}
//};
//
//
//class Intermediate : public base {
//public:
//    Intermediate() {
//        cout << "Intermediate class constructor" << endl;
//    }
//    ~Intermediate() {
//        cout << "Intermediate class destructor" << endl;
//    }
//};
//
//class Derived : public Intermediate {
//public:
//    Derived() {
//        cout << "Derived class constructor" << endl;
//    }
//    ~Derived() {
//        cout << "Derived class destructor" << endl;
//    }
//};
//
//int main() {
//    Derived d;
//
//}



//#include <iostream>
//using namespace std;
//
//class Base {
//protected:
//    int baseData;
//public:
//    Base() : baseData(10) {}
//    void showBaseData() {
//        cout << "Base data: " << baseData << endl;
//    }
//};
//
//class Intermediate : public Base {
//protected:
//    int intermediateData;
//public:
//    Intermediate() : intermediateData(20) {}
//    void showIntermediateData() {
//        cout << "Intermediate data: " << intermediateData << endl;
//    }
//};
//
//class Derived : public Intermediate {
//private:
//    int derivedData;
//public:
//    Derived() : derivedData(30) {}
//    void showDerivedData() {
//        cout << "Derived data: " << derivedData << endl;
//    }
//};
//
//int main() {
//    Derived d;
//    d.showBaseData();           // Outputs: Base data: 10
//    d.showIntermediateData();   // Outputs: Intermediate data: 20
//    d.showDerivedData();        // Outputs: Derived data: 30
//    return 0;
//}


//multi lvl inheritance using polymorphism

//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//    virtual void display() {
//        cout << "Display of Base class" << endl;
//    }
//};
//
//class Intermediate : public Base {
//public:
//    void display() override {
//        cout << "Display of Intermediate class" << endl;
//    }
//};
//
//class Derived : public Intermediate {
//public:
//    void display() override {
//        cout << "Display of Derived class" << endl;
//    }
//};
//
//void show(Base* b) {
//    b->display();
//}
//
//int main() {
//    Base* basePtr = new Base();
//    Base* intermediatePtr = new Intermediate();
//    Base* derivedPtr = new Derived();
//
//    show(basePtr);           // Outputs: Display of Base class
//    show(intermediatePtr);   // Outputs: Display of Intermediate class
//    show(derivedPtr);        // Outputs: Display of Derived class
//
//    delete basePtr;
//    delete intermediatePtr;
//    delete derivedPtr;
//
//    return 0;
//}

#include <iostream>
using namespace std;

class A {
public:
    int value;
    A(int v) : value(v) {
        cout << "Constructor of A with value " << value << endl;
    }
    ~A() {
        cout << "Destructor of A" << endl;
    }
};

class B : virtual public A {
public:
    B(int v) : A(v) {
        cout << "Constructor of B" << endl;
    }
    ~B() {
        cout << "Destructor of B" << endl;
    }
};

class C : virtual public A {
public:
    C(int v) : A(v) {
        cout << "Constructor of C" << endl;
    }
    ~C() {
        cout << "Destructor of C" << endl;
    }
};

class D : public B, public C {
public:
    D(int v) : A(v), B(v), C(v) {
        cout << "Constructor of D" << endl;
    }
    ~D() {
        cout << "Destructor of D" << endl;
    }
};

int main() {
    D obj(100);
    cout << "Value in D is " << obj.value << endl;
    return 0;
}