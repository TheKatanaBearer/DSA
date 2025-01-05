
//Question 1


//
//#include<iostream>
//using namespace std;
//
//int main() {
//
//	double hours_worked;
//	double hour_rate;
//	double regular_Pay = 0;
//	double ovetime_Pay = 0;
//	double total_pay;
//
//	cout << "enter the hours that are worked by the person " << endl;
//	cin >> hours_worked;
//
//	cout << "enter the per hour rate " << endl;
//	cin >> hour_rate;
//
//
//	if (hours_worked <= 40) {
//		cout << "as the hours worked are less than or equal to 40 the weekly gross earnings for the employee is " << endl;
//		regular_Pay= hours_worked * hour_rate;
//		cout << "the regular pay " << regular_Pay << endl;
//		cout << "the overtime pay " << ovetime_Pay << endl;
//		total_pay = regular_Pay + ovetime_Pay;
//		cout << "the total pay is " << total_pay << endl;
//	}
//	
//	else {
//		cout << "as the worked hours are more than 40 " << endl;
//			regular_Pay = hours_worked * hour_rate;
//			cout << "the regular pay is " << regular_Pay << endl;
//			ovetime_Pay=(hours_worked - 40) * hour_rate * 1.30;
//			cout << "the overtime pay is " << ovetime_Pay << endl;
//			total_pay = regular_Pay + ovetime_Pay;
//			cout << "the total pay is " << total_pay << endl;
//	}
//
//	
//
//}

//question 2






//#include<iostream>
//using namespace std;
//
//int main() {
//	int n;
//	cout << "enter the number that you want to stop on " << endl;
//	cin >> n;
//
//	for (int i = 0; i <= n; i++) {
//		cout << i << " ";
//	}
//
//}




//question 3 

//
//#include<iostream>
//using namespace std;
//
//void product(int& pow1, int& pow2) {
//	
//	cout << "the sum of the powers are " << endl;
//	cout << pow1 + pow2 << endl;
//	
//}
//
//
//int main() {
//
//	int base1;
//	int base2;
//	int pow1;
//	int pow2;
//
//
//
//	cout << "enter the base and power of the first digit " << endl;
//	cin >> base1 >> pow1;
//
//	cout << "enter the base and power of the second digit " << endl;
//	cin >> base2 >> pow2;
//
//
//	if (base1 == base2) {
//
//		cout << "as the bases are the same so... " << endl;
//		product(pow1, pow2);
//	}
//	else {
//		cout << "the base are not same " << endl;
//
//	}
//
//
//}



//question 4


#include<iostream>
#include<string>
using namespace std;

struct course {
	int course_id;
	string course_title;
	int credit_hrs;
};


struct student {

	int student_id;
	string student_name;
	string student_subject;

};

const int MAX_STUDENTS = 100;

student students[MAX_STUDENTS];

int student_count = 0;

void addstudent() {
	student s;
	cout << "enter the id of the student " << endl;
	cin >> s.student_id;

	cout << "enter the name of the student " << endl;
	cin.ignore();
	getline(cin, s.student_name);


	cout << "enter the subject of the student " << endl;
	cin.ignore();
	getline(cin, s.student_subject);




	students[student_count++] = s;
	cout << "student addition complete ! " << endl;
}


void updateStudent() {
	int id;
	cout << "enter the id of the student " << endl;
	cin >> id;


	for (int i = 0; i < student_count; i++) {
		if (students[i].student_id==id) {
			cout << "the student id has been found " << endl;
			cout << "enter the student name " << endl;
			cin.ignore();
			getline(cin, students[i].student_name);
			cout << "enter the student subject " << endl;
			cin.ignore();
			getline(cin, students[i].student_subject);
			cout << "the student data has been updated " << endl;
		}


	}

}


void deleteAstudent() {

	int id;
	cout << "enter the id that u are searching " << endl;
	cin >> id;
	for (int i = 0; i < student_count; i++) {
		if (students[i].student_id == id) {
			for (int j = i; j < student_count - 1; j++) {
				students[j] = students[j + 1];
			}
			--student_count;
			cout << "student deleted successfully " << endl;
			
		}
	}

	
}


void searchAndDisplay() {
	int id;
	cout << "enter the student id " << endl;
	cin >> id;

	for (int i = 0; i < student_count; i++) {
		if (students[i].student_id == id) {
			cout << "student id: " << students[i].student_id << endl;
			cout << "students name: " << students[i].student_name << endl;
			cout << "students subject: " << students[i].student_subject << endl;
		}
		else {
			cout << "student is not found " << endl;
		}
		}

}



void displayallstudents() {

	for (int i = 0; i < student_count; i++) {
		cout << "student id: " << students[i].student_id << endl;
		cout << "students name: " << students[i].student_name << endl;
		cout << "student subject is " << students[i].student_subject << endl;
		cout << "-------------------------------------------------------" << endl;
	}
}



int main() {


	course courses[5] = {
		{1, "islamiat", 3},
		{2, "hsitory", 4},
		{3, "english", 3},
		{4, "physics", 2},
		{5, "cs", 3}
	};



	char choice;

	do {
		cout << "-------------------------------------" << endl;
		cout << "press 1 to add a student  " << endl;
		cout << "press 2 to update a student " << endl;
		cout << "press 3 to delete a student " << endl;
		cout << "press 4 to search and display a student " << endl;
		cout << "press 5 to display all studnets " << endl;
		cout << "press e to exit the program " << endl;
		cout << "----------------------------------------" << endl;
		cout << "enter your choice " << endl;
		cin >> choice;

		switch (choice) {
		case '1':
			addstudent();
			break;

		case '2':
			updateStudent();
			break;
		case '3':
			deleteAstudent();
			break;
		case '4':
			searchAndDisplay();
			break;
		case '5':
			displayallstudents();
			break;
		case 'e':
			cout << "program exit has occured " << endl;
			break;
		default:
			cout << "the choice is invalid...try again " << endl;
		}
	



	} while (choice != 'e');



}