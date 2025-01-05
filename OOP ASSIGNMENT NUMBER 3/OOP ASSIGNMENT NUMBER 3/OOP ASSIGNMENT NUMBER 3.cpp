

//          Hamza Khan Tariq
//          04072313050




#include<iostream>
#include<string>
using namespace std;

class Date {
    int day;
    int month;
    int year;
public:
    Date(int x, int y, int z) :day(x), month(y), year(z) {}
    Date() :day(1), month(1), year(2000) {}
    void setDate(int x, int y, int z) {
        day = x;
        month = y;
        year = z;
    }
    ~Date() {}

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    friend ostream& operator<<(ostream& out, const Date& date) {
        out << date.day << "/" << date.month << "/" << date.year;
        return out;
    }

    friend istream& operator>>(istream& in, Date& date) {
        cout << "day is ? " << endl;
        in >> date.day;
        cout << "the month is? " << endl;
        in >> date.month;
        cout << "the year is? " << endl;
        in >> date.year;
        return in;
    }

    void print() const {
        cout << *this;
    }

    void read() {
        cin >> *this;
    }
};

class person {
private:
    string name;
    string cnic;
    string email;
    string contactno;
    Date dob;

public:
    person() :name(""), cnic(""), email(""), contactno(""), dob() {}
    person(const string& name, const string& cnic, const string& email, const string& contactinfo, const Date& dob)
        :name(name), cnic(cnic), email(email), contactno(contactinfo), dob(dob) {}

    // Getters and Setters
    string getname() const { return name; }
    void setname(const string& n) { name = n; }

    string getcnic() const { return cnic; }
    void setcnic(const string& c) { cnic = c; }

    string getemail() const { return email; }
    void setemail(const string& e) { email = e; }

    string getcontactno() const { return contactno; }
    void setcontactno(const string& c) { contactno = c; }

    Date getdob() const { return dob; }
    void setdob(const Date& d) { dob = d; }

    friend ostream& operator<<(ostream& out, const person& p) {
        out << "name: " << p.name << endl;
        out << "cnic: " << p.cnic << endl;
        out << "contactno: " << p.contactno << endl;
        out << "email: " << p.email << endl;
        out << "date of birth: " << p.dob;
        return out;
    }

    friend istream& operator>>(istream& in, person& p) {
        cout << "enter name: ";
        in >> p.name;
        cout << "enter cnic: ";
        in >> p.cnic;
        cout << "enter email: ";
        in >> p.email;
        cout << "enter contactno: ";
        in >> p.contactno;
        cout << "enter dob: ";
        in >> p.dob;
        return in;
    }

    void print() const {
        cout << *this;
    }

    void read() {
        cin >> *this;
    }

    virtual bool issucessful() const = 0;
};

class student : virtual public person {
private:
    int semester;
    int no_of_course;
    string* arr_courses;
    int* marks;

public:
    student(int sem, int no_crs) : semester(sem), no_of_course(no_crs), arr_courses(new string[no_of_course]), marks(new int[no_of_course]) {}
    student() : semester(1), no_of_course(4), arr_courses(new string[no_of_course]), marks(new int[no_of_course]) {}

    ~student() {
        delete[] arr_courses;
        delete[] marks;
    }

    int getsemester() const { return semester; }
    void setsemester(int sem) { semester = sem; }

    int get_no_of_courses() const { return no_of_course; }
    void set_no_of_courses(int no_crs) { no_of_course = no_crs; }

    string get_courses(int i) const {
        if (i >= 1 && i < no_of_course) {
            return arr_courses[i];
        }
        else {
            return "blank";
        }
    }

    void set_courses(const string& name, int i) {
        if (i >= 1 && i < no_of_course) {
            arr_courses[i] = name;
        }
    }

    int getmarks(int index) const {
        if (index >= 0 && index < no_of_course) {
            return marks[index];
        }
        else {
            return -1;
        }
    }

    void setmarks(int mark, int i) {
        if (i >= 0 && i < no_of_course) {
            marks[i] = mark;
        }
    }

    char calcgrade() const {
        int total = 0;
        for (int i = 0; i < no_of_course; i++) {
            total += marks[i];
        }
        if (total >= 80) {
            return 'A';
        }
        if (total >= 70) {
            return 'B';
        }
        if (total >= 60) {
            return 'C';
        }
        if (total < 60) {
            return 'F';
        }
    }

    friend ostream& operator<<(ostream& out, const student& s) {
        out << "Semester: " << s.semester << "\n";
        out << "Number of Courses: " << s.no_of_course << "\n";
        for (int i = 0; i < s.no_of_course; i++) {
            out << "Course " << i + 1 << ": " << s.arr_courses[i] << ", Marks: " << s.marks[i] << "\n";
        }
        return out;
    }

    friend istream& operator>>(istream& in, student& s) {
        cout << "Enter semester: ";
        in >> s.semester;
        cout << "Enter number of courses: ";
        in >> s.no_of_course;
        s.arr_courses = new string[s.no_of_course];
        s.marks = new int[s.no_of_course];
        for (int i = 0; i < s.no_of_course; i++) {
            cout << "Enter course " << i + 1 << ": ";
            in >> s.arr_courses[i];
            cout << "Enter marks for " << s.arr_courses[i] << ": ";
            in >> s.marks[i];
        }
        return in;
    }

    void print() const {
        cout << *this;
    }

    void read() {
        cin >> *this;
    }

    
    virtual bool issucessful() const override {
        char grade = calcgrade();
        return (grade == 'A' || grade == 'B' || grade == 'C');
    }
};

class faculty : virtual public person {
private:
    int salary;
    string qualification;
    string expertise;
    int no_of_pubs;

public:
    faculty() : salary(0), qualification(""), expertise(""), no_of_pubs(0) {}
    faculty(int sal, string qual, string exp, int pubs)
        : salary(sal), qualification(qual), expertise(exp), no_of_pubs(pubs) {}

    int getSalary() const { return salary; }
    void setSalary(int sal) { salary = sal; }

    string getQualification() const { return qualification; }
    void setQualification(const string& qual) { qualification = qual; }

    string getExpertise() const { return expertise; }
    void setExpertise(const string& exp) { expertise = exp; }

    int getNoOfPubs() const { return no_of_pubs; }
    void setNoOfPubs(int pubs) { no_of_pubs = pubs; }

    friend ostream& operator<<(ostream& out, const faculty& f) {
        out << "salary: " << f.salary << "\n";
        out << "qualification: " << f.qualification << "\n";
        out << "expertise: " << f.expertise << "\n";
        out << "number of Publications: " << f.no_of_pubs << "\n";
        return out;
    }

    friend istream& operator>>(istream& is, faculty& f) {
        cout << "Enter salary: ";
        is >> f.salary;
        is.ignore();
        cout << "Enter qualification: ";
        getline(is, f.qualification);
        cout << "Enter expertise: ";
        getline(is, f.expertise);
        cout << "Enter number of publications: ";
        is >> f.no_of_pubs;
        return is;
    }


    void print() const {
        cout << *this;
    }

    void read() {
        cin >> *this;
    }


    virtual bool issucessful() const override {
        return no_of_pubs >= 10;
    }
};

class TA : public student, public faculty {
private:
    int no_of_assisting_courses;
    string* assisting_courses;
    faculty* faculty_advisor;
    string thesis_title;

public:
    TA() : no_of_assisting_courses(0), assisting_courses(nullptr), faculty_advisor(nullptr), thesis_title("") {}
    TA(int sem, int no_crs, int sal, const string& qual, const string& exp, int pubs, int no_assists, faculty* advisor, const string& thesis)
        : student(sem, no_crs), faculty(sal, qual, exp, pubs), no_of_assisting_courses(no_assists), faculty_advisor(advisor), thesis_title(thesis) {}

    ~TA() {
        delete[] assisting_courses;
    }

    int getnoofassistingcourses() const { return no_of_assisting_courses; }
    string* getassistingcourses() const { return assisting_courses; }

    faculty* getadvisor() const { return faculty_advisor; }
    void setadvisor(faculty* f) { faculty_advisor = f; }

    string getthesistitle() const { return thesis_title; }
    void setthesistitle(const string& s) { thesis_title = s; }

    friend ostream& operator<<(ostream& out, const TA& t) {
        out << "Number of Assisting Courses: " << t.no_of_assisting_courses << "\n";
        out << "Advisor: " << *(t.faculty_advisor) << "\n";
        out << "Thesis Title: " << t.thesis_title << "\n";
        return out;



    }


    friend istream& operator>>(istream& in, TA& t) {
        cout << "Enter number of assisting courses: ";
        in >> t.no_of_assisting_courses;
        t.assisting_courses = new string[t.no_of_assisting_courses];
        cout << "Enter assisting courses: ";
        for (int i = 0; i < t.no_of_assisting_courses; ++i) {
            in >> t.assisting_courses[i];
        }
        cout << "Enter thesis title: ";
        in >> t.thesis_title;
        return in;
    }


    void print() const {
        cout << *this;
    }

    void read() {
        cin >> *this;
    }



    virtual bool issucessful() const override {
        return (student::issucessful() && (no_of_assisting_courses >= 2 || faculty_advisor->getNoOfPubs() >= 1));
    }
};


int main()
{
    student* s = new student();
    faculty* f = new faculty();
    TA* t = new TA();

    person* p[3];
    p[0] = s;
    p[1] = f;
    p[2] = t;

    cout << " Input details of the Student: " << endl;
    p[0]->read();

    cout << "\n----------------------\n";
    cout << " Input details of the Faculty: " << endl;
    p[1]->read();

    cout << "\n----------------------\n";
    cout << " Input details of TA: " << endl;
    p[2]->read();

    s->read();

    t->setadvisor(f);

    cout << "\n\n----------------------\n\n";
    cout << " Details of the Student: " << endl;
    p[0]->print();
    if (p[0]->issucessful())
    {
        cout << "\nCongrats.You are Successful." << endl;
    }
    else
    {
        cout << "\n You are not Successful" << endl;
    }

    cout << "\n\n----------------------\n\n";
    cout << " Details of the Faculty Member: " << endl;
    p[1]->print();
    if (p[1]->issucessful())
    {
        cout << "\nCongrats.You are Successful." << endl;
    }
    else
    {
        cout << " \nYou are not Successful" << endl;
    }

    cout << "\n\n----------------------\n\n";
    cout << " Details of the TA: " << endl;
    p[2]->print();
    if (p[2]->issucessful())
    {
        cout << "\nCongrats.You are Successful." << endl;
    }
    else
    {
        cout << "\nYou are not Successful" << endl;
    }

    cout << "\n\n";

    delete f;
    delete t;
    delete s;

    return 0;
}
