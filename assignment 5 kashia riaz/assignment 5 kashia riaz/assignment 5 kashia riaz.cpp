//
//#include<iostream>
//using namespace std;
//
//class entertainment {
//    string title;
//    string air_date;
//    string* genre;
//    string type;
//    string runtime;
//    string country;
//    string* actors;
//    double rating;
//    string* owner;
//    int no_genre;
//    int no_actors;
//    int no_owners;
//
//public:
//    entertainment(string t, string air_d, string* g, string typ, string run_t, string cntry, string* act, double rt, string* own, int n_g, int n_act, int n_own)
//        : title(t), air_date(air_d), type(typ), runtime(run_t), country(cntry), rating(rt), no_genre(n_g), no_actors(n_act), no_owners(n_own) {
//        genre = new string[no_genre];
//        for (int i = 0; i < no_genre; i++) {
//            genre[i] = g[i];
//        }
//
//        actors = new string[no_actors];
//        for (int i = 0; i < no_actors; i++) {
//            actors[i] = act[i];
//        }
//
//        owner = new string[no_owners];
//        for (int i = 0; i < no_owners; i++) {
//            owner[i] = own[i];
//        }
//    }
//
//    ~entertainment() {
//        delete[] genre;
//        delete[] actors;
//        delete[] owner;
//    }
//
// 
//    // Copy constructor
// 
// 
//    entertainment(const entertainment& e, string title = "NIL", string air_date = "NIL", string runtime = "NIL", string* actors = nullptr, string* owners = nullptr, string type = "NIL")
//        : title(title), air_date(air_date), runtime(runtime), type(type), country(e.country), rating(e.rating), no_genre(e.no_genre), no_actors(e.no_actors), no_owners(e.no_owners) {
//
//        genre = new string[no_genre];
//        for (int i = 0; i < no_genre; i++) {
//            genre[i] = e.genre[i];
//        }
//
//        if (actors) {
//            this->actors = new string[no_actors];
//            for (int i = 0; i < no_actors; i++) {
//                this->actors[i] = actors[i];
//            }
//        }
//        else {
//            this->actors = new string[no_actors];
//            for (int i = 0; i < no_actors; i++) {
//                this->actors[i] = "NIL";
//            }
//        }
//
//        if (owners) {
//            this->owner = new string[no_owners];
//            for (int i = 0; i < no_owners; i++) {
//                this->owner[i] = owners[i];
//            }
//        }
//        else {
//            this->owner = new string[no_owners];
//            for (int i = 0; i < no_owners; i++) {
//                this->owner[i] = "NIL";
//            }
//        }
//    }
//
//    friend void print_elements(const entertainment& e);
//};
//
//void print_elements(const entertainment& e) {
//    cout << "The title of the movie is " << e.title << endl;
//    cout << "The air date of the movie is " << e.air_date << endl;
//    cout << "The genre of the movie is " << endl;
//    for (int i = 0; i < e.no_genre; i++) {
//        cout << e.genre[i] << endl;
//    }
//    cout << "The actors in the movie are " << endl;
//    for (int i = 0; i < e.no_actors; i++) {
//        cout << e.actors[i] << endl;
//    }
//    cout << "The type of the movie is " << e.type << endl;
//    cout << "The run time of the movie is " << e.runtime << endl;
//    cout << "The country of the movie is " << e.country << endl;
//    cout << "The rating of the movie is " << e.rating << endl;
//    cout << "The owner of the movie is " << endl;
//    for (int i = 0; i < e.no_owners; i++) {
//        cout << e.owner[i] << endl;
//    }
//}
//
//int main() {
//    string genre_[] = { "happy", "very good", "friendly", "family" };
//    string actors[] = { "mehmood saab", "momo", "nabeel", "khoobsorat" };
//    string owners[] = { "geo", "PTV", "ARY", "pakistan" };
//
//    entertainment e1("pele", "27th sept", genre_, "fun", "2 hours", "brazil", actors, 5.0, owners, 4, 4, 4);
//    entertainment e2(e1, "jungle book", "26th september", "2 hours", nullptr, nullptr, "children");
//
//    print_elements(e2);
//
//    return 0;
//}
//









//#include<iostream>
//#include<fstream>
//#include<string>
//
//using namespace std;
//
//class student {
//private:
//    string name;
//    int age;
//    int registration;
//
//public:
//    student() {}
//
//    student(string name, int age, int registration) {
//        this->name = name;
//        this->age = age;
//        this->registration = registration;
//    }
//
//    // Inputting student data
//    void input_Data() {
//        cin.ignore(); 
//        cout << "Enter the name of the student: ";
//        getline(cin, name);
//        cout << "Enter the age of the student: ";
//        cin >> age;
//        cout << "Enter the registration number of the student: ";
//        cin >> registration;
//    }
//
//    // Writing data to the file
//    void writeToFile() {
//        ofstream file_("student.txt", ios::app);
//
//        if (!file_) {
//            cerr << "The file didn't open!" << endl;
//            return;
//        }
//
//        file_ << name << " " << age << " " << registration << endl;
//        file_.close();
//    }
//
//    static void search_file() {
//        ifstream file_("student.txt");
//
//        if (!file_) {
//            cerr << "The file didn't open!" << endl;
//            return;
//        }
//
//        int choice;
//        int registrationno, search_age;
//        string search_name;
//        bool found = false;
//
//        cout << "Enter your choice for search: 1. By name, 2. By age, 3. By registration number: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Enter the name you want to search: ";
//            cin.ignore();
//            getline(cin, search_name);
//            break;
//        case 2:
//            cout << "Enter the age you want to search: ";
//            cin >> search_age;
//            break;
//        case 3:
//            cout << "Enter the registration number you want to find: ";
//            cin >> registrationno;
//            break;
//        default:
//            cout << "You entered a wrong value!" << endl;
//            return;
//        }
//
//        string nm;
//        int ag, regno;
//
//        while (file_ >> nm >> ag >> regno) {
//            if (choice == 1 && search_name == nm) {
//                cout << "Found student: Name: " << nm << ", Age: " << ag << ", Registration No: " << regno << endl;
//                found = true;
//                break;
//            }
//
//            if (choice == 2 && search_age == ag) {
//                cout << "Found student: Name: " << nm << ", Age: " << ag << ", Registration No: " << regno << endl;
//                found = true;
//                break;
//            }
//
//            if (choice == 3 && regno == registrationno) {
//                cout << "Found student: Name: " << nm << ", Age: " << ag << ", Registration No: " << regno << endl;
//                found = true;
//                break;
//            }
//        }
//
//        if (!found) {
//            cout << "The student was not found." << endl;
//        }
//
//        file_.close();
//    }
//};
//
//int main() {
//    int option;
//
//    while (true) {
//        cout << "Choose an option:\n1. Input and write student info to file\n2. Search student info\n3. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> option;
//
//        if (option == 1) {
//            for (int i = 0; i < 5; i++) {
//                student s;
//                s.input_Data();
//                s.writeToFile();
//                cout << "The info of student " << i + 1 << " has been written to the file." << endl;
//            }
//            cout << "All students' info has been recorded." << endl;
//        }
//        else if (option == 2) {
//            student::search_file();
//        }
//        else if (option == 3) {
//            break;
//        }
//        else {
//            cout << "You entered a wrong option!" << endl;
//        }
//    }
//
//    return 0;
//}
//
//
//
//
//
//
//

//
//#include<iostream>
//using namespace std;
//
//template<typename T>
//class calculator {
//	T num1;
//	T num2;
//
//public:
//	calculator(T n1, T n2) {
//		num1 = n1;
//		num2 = n2;
//	}
//
//
//	double addition() {
//		double d = num1 + num2;
//		return d;
//	}
//
//	double subtraction() {
//		double d = num1 - num2;
//		return d;
//	}
//
//
//	double multiplication() {
//		double d = num1 * num2;
//		return d;
//
//	}
//
//	double division() {
//		double d = num1 / num2;
//		return d;
//	}
//
//
//};
//
//
//int main() {
//	calculator<double> c1(12.5, 12.6);
//
//	cout << c1.addition() << endl;
//
//	cout << c1.division() << endl;
//
//	cout << c1.multiplication() << endl;
//	
//	cout << c1.subtraction() << endl;
//
//	calculator<int>c2(4, 7);
//
//	cout << c2.addition() << endl;
//
//	cout << c2.division() << endl;
//
//	cout << c2.multiplication() << endl;
//
//	cout << c2.subtraction() << endl;
//}
//
//
//
//




#include<iostream>
using namespace std;

template<typename T>

class queue {
private:
	T list[10];

public:
	queue() {
		for (int i = 0; i < 10; i++) {
			list[i] = static_cast<T>(0);
		}
	}

	void sort_() {

		//using the bubble sort algorithm
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10 - 1 - i; j++) {
				if (list[j] > list[j + 1]) {
					T temp = list[j];
					list[j] = list[j + 1];
					list[j + 1] = temp;
				}
			}
		}
	}


	//function to find the maximum value and its frequency

	T max_() {
		T max_val = list[0];

		int count = 1;
		for (int i = 1; i < 10; i++) {
			if (list[i] > max_val) {
				max_val = list[i];
				count = 1;
			}
			else if (list[i] == max_val) {
				count++;
			}
		}

		cout << "the max value is " << max_val << "and it comes " << count << "many times " << endl;

		return max_val;

	}


	T min_() {
		T min_val = list[0];

		int count = 1;
		for (int i = 0; i < 10; i++) {
			if (list[i] < min_val) {
				min_val = list[i];
				count = 1;

			}

			else if (list[i] == min_val) {
				count++;
			}
		}

		cout << "the min value is " << min_val << "and it comes " << count << "many times " << endl;
		return min_val;



	}
 


	void display() {
		cout << "all the elements are " << endl;

		for (int i = 0; i < 10; i++) {
			cout << list[i] << endl;
		}
	}
 
	void set_vals(T val[10]) {
		for (int i = 0; i < 10; i++) {
			list[i] = val[i];
		}
	}



 
};



int main() {

	queue<int> q;

	int ar_[10] = { 1,2,3,4,5,6,7,8,9,10 };

	q.set_vals(ar_);

	q.sort_();

	q.max_();

	q.min_();

	q.display();




	queue<float>o;


	float ar[10] = { 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0 };

	o.set_vals(ar);

	o.max_();

	o.min_();

	o.sort_();

	o.display();


}

