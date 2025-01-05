

#include<iostream>
#include<string>
using namespace std;

class date {
	int day;
	int month;
	int year;

public:
	date(int day, int month, int year) : day(day), month(month), year(year) {}

	date() : day(1), month(1), year(2000) {} // Default date: January 1, 2000

	date(const date& d) : day(d.day), month(d.month), year(d.year) {}

	// Destructor
	~date() {}

	// Getters
	int getday() const { return day; }
	int getmonth() const { return month; }
	int getyear() const { return year; }

	// Setters
	void setday(int day) { this->day = day; }
	void setmonth(int month) { this->month = month; }
	void setyear(int year) { this->year = year; }

	// Friend functions for << and >> operator overloading
	friend ostream& operator<<(ostream& os, const date& d);
	friend istream& operator>>(istream& is, date& d);
};

// Overloading << operator for date
ostream& operator<<(ostream& os, const date& d) {
	os << d.day << "/" << d.month << "/" << d.year;
	return os;
}

// Overloading >> operator for date
istream& operator>>(istream& is, date& d) {
	cout << "Enter day: ";
	is >> d.day;
	cout << "Enter month: ";
	is >> d.month;
	cout << "Enter year: ";
	is >> d.year;
	return is;

};



class person {
	string name;
	string cnic;
	string email;
	string contact_no;
	date dob;

public:

	//paramterized constructor
	person(string name, string cnic, string email, string contact_no, date dob) {
		this->name = name;
		this->cnic = cnic;
		this->email = email;
		this->contact_no = contact_no;
		this->dob = dob;
	}

	person() :name(""), cnic(""), email(""), contact_no(""), dob() {};

	//copy constructor

	person(const person& p) {
		name = p.name;
		cnic = p.cnic;
		email = p.email;
		contact_no = p.contact_no;
		dob = p.dob;
	}

	~person();

	//getters and setters

	string getname()const {
		return name;

	}

	string getcnic()const {
		return cnic;

	}

	string getemail()const {
		return email;

	}

	date dob()const {
		return dob;

	}

	//setters

	void setname(const string& name) {
		this->name = name;

	}

	void setcnic(const string& cnic) {
		this->cnic = cnic;

	}

	void setemail(const string& email) {
		this->email = email;
	}

	void setdob(const date& dob) {
		this->dob = dob;
	}


	friend ostream& operator<<(ostream& os, const person& p) {
		os << "Name: " << p.name << "\n";
		os << "CNIC: " << p.cnic << "\n";
		os << "Email: " << p.email << "\n";
		os << "Contact No: " << p.contact_no << "\n";
		os << "Date of Birth: " <<p.dob << "\n";  // Assumes date class has an overloaded << operator
		return os;
	}

	friend istream& operator>>(istream& is, person& p) {
		cout << "Enter Name: ";
		is >> ws; // To consume any leading whitespace
		getline(is, p.name);

		cout << "Enter CNIC: ";
		is >> ws; // To consume any leading whitespace
		getline(is, p.cnic);

		cout << "Enter Email: ";
		is >> ws; // To consume any leading whitespace
		getline(is, p.email);

		cout << "Enter Contact No: ";
		is >> ws; // To consume any leading whitespace
		getline(is, p.contact_no);

		cout << "Enter Date of Birth (in the format your date class supports): ";
		is >> p.dob;  // Assumes date class has an overloaded >> operator

		return is;
	}

};


class student :public person {
	int semester;
	int no_of_courses;
	string* course_names;
	int* marks_course;
public:
	student() : semester(1), no_of_courses(0), course_names(nullptr), marks_course(nullptr) {}

	//paramtertized constructor

	student(string name, string cnic, string email, string contact_no, date dob, int sem, int courses, string* coourse_name, int* coourse_marks) :
		person(name, cnic, email, contact_no, dob), semester(sem), no_of_courses(courses) {
		course_names = new string[no_of_courses];

		marks_course = new int[no_of_courses];

		for (int i = 0; i < no_of_courses; i++) {
			course_names[i] = coourse_name[i];
			marks_course[i] = coourse_marks[i];
		}
	}

	//copy constructor

	student(const student& s) {
		person(s);

		semester = s.semester;
		no_of_courses = s.no_of_courses;

		//deep copying the dynamically allocated arrays

		course_names = new string[no_of_courses];
		marks_course = new int[no_of_courses];

		for (int i = 0; i < no_of_courses; i++) {
			course_names[i] = s.course_names[i];
			marks_course[i] = s.marks_course[i];

		}
	}

	~student() {
		delete[]course_names;
		delete[]marks_course;

	}

	//getter

	int getsemester()const {
		return semester;
	}

	int get_no_of_courses()const {
		return no_of_courses;
	}
	string* getcoursenames()const {
		return course_names;

	}

	int* getcoursemarks()const {
		return marks_course;
	}

	//setters

	void setsemester(int sem) {
		semester = sem;
	}

	void setnoofcourses(int courses) {
		delete[]course_names;
		delete[]marks_course;

		no_of_courses = courses;

		course_names = new string[no_of_courses];
		marks_course = new int[no_of_courses];
	}


	void set_course_names(string* coorse_names) {
		for (int i = 0; i < no_of_courses; i++) {
			course_names[i] = coorse_names[i];

		}
	}


	void set_course_marks(int* course_marks) {
		for (int i = 0; i < no_of_courses; i++) {
			marks_course[i] = course_marks[i];
		}
	}

	//function to calculate the overall grade

	char calcGrade() const {
		if (no_of_courses == 0) return 'F'; // No courses case

		int totalMarks = 0;
		for (int i = 0; i < no_of_courses; i++) {
			totalMarks += marks_course[i];
		}

		int average = totalMarks / no_of_courses;

		if (average >= 90) return 'A';
		else if (average >= 80) return 'B';
		else if (average >= 70) return 'C';
		else if (average >= 60) return 'D';
		else return 'F';
	}


	friend ostream& operator<<(ostream& os, const student& s);
	friend istream& operator>>(istream& is, student& s);
};


ostream& operator<<(ostream& os, const student& s) {
	os << static_cast<const person&>(s);
	os << "semester : " << s.getsemester() << "\n" << endl;
	os << "Number of Courses: " << s.get_no_of_courses() << "\n";

	for (int i = 0; i < s.get_no_of_courses(); i++) {
		os << "Course " << (i + 1) << ": " << s.getcoursenames()[i]
			<< ", Marks: " << s.getcoursemarks()[i] << "\n";
	}
	os << "Overall Grade: " << s.calcGrade() << "\n";
	return os;
}


istream& operator>>(istream& is, student& s) {
	is >> static_cast<person&>(s); // Input person part first
	cout << "Enter Semester: ";
	is >> s.semester;
	cout << "Enter Number of Courses: ";
	is >> s.no_of_courses;

	s.course_names = new string[s.no_of_courses];
	s.marks_course = new int[s.no_of_courses];

	for (int i = 0; i < s.no_of_courses; i++) {
		cout << "Enter Course Name " << (i + 1) << ": ";
		is >> ws;
		getline(is, s.course_names[i]);
		cout << "Enter Marks for Course " << (i + 1) << ": ";
		is >> s.marks_course[i];
	}

	return is;
}

class Faculty : public person {
	double salary;
	string qualification;
	string area_of_expertise;
	int num_papers_published;

public:
	// Default constructor
	Faculty() : salary(0.0), qualification(""), area_of_expertise(""), num_papers_published(0) {}

	// Parameterized constructor
	Faculty(string name, string cnic, string email, string contact_no, date dob, double salary, string qualification, string area_of_expertise, int num_papers_published)
		: person(name, cnic, email, contact_no, dob), salary(salary), qualification(qualification), area_of_expertise(area_of_expertise), num_papers_published(num_papers_published) {}


	Faculty(const Faculty& f) : person(f), salary(f.salary), qualification(f.qualification), area_of_expertise(f.area_of_expertise), num_papers_published(f.num_papers_published) {}


	~Faculty() {}

	double getsalary() const { return salary; }
	string getqualification() const { return qualification; }
	string getarea_of_expertise() const { return area_of_expertise; }
	int getnum_papers_published() const { return num_papers_published; }

	// Setters
	void setsalary(double salary) { this->salary = salary; }
	void setqualification(const string& qualification) { this->qualification = qualification; }
	void setarea_of_expertise(const string& area_of_expertise) { this->area_of_expertise = area_of_expertise; }
	void setnum_papers_published(int num_papers_published) { this->num_papers_published = num_papers_published; }

	friend ostream& operator<<(ostream& os, const Faculty& f) {
		os << static_cast<const person&>(f); // Output person part
		os << "Salary: " << f.salary << "\n";
		os << "Qualification: " << f.qualification << "\n";
		os << "Area of Expertise: " << f.area_of_expertise << "\n";
		os << "Number of Papers Published: " << f.num_papers_published << "\n";
		return os;
	}
	friend istream& operator>>(istream& is, Faculty& f) {
		is >> static_cast<person&>(f); // Input person part first
		cout << "Enter Salary: ";
		is >> f.salary;
		cout << "Enter Qualification: ";
		is >> ws; // Consume any leading whitespace
		getline(is, f.qualification);
		cout << "Enter Area of Expertise: ";
		is >> ws; // Consume any leading whitespace
		getline(is, f.area_of_expertise);
		cout << "Enter Number of Papers Published: ";
		is >> f.num_papers_published;
		return is;
	}
};




int main() {

}