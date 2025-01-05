

#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>

#include<fstream>
using namespace std;


class User {
protected:
	string cnic;
	string password;
	string email;


public:
	User();
	virtual void resetpassword() = 0;
	virtual bool login() = 0;

	void maskpassword(char*);
};


User::User() :cnic("-"), password("*"), email("@") {};


void User::maskpassword(char* typepassword)
{
	{

		int i = 0; char ch;
		do
		{
			ch = _getch();
			if (ch == 13)
			{
				typepassword[i] = '\0';
				break;
			}
			else if (ch == 8)
			{
				if (i > 0) {
					cout << "\b \b";
					i--;
				}
			}
			else
			{
				typepassword[i] = ch;
				cout << "*";
				i++;
			}
		} while (1);
	}
}


class Customer :virtual public User {

private:
	string name;
public:
	Customer();

	bool checkUserExists();

	void resetpassword()override;

	bool signup();

	bool login()override;
};



Customer::Customer() :User(), name("") {};


bool Customer::login() {
	bool success = false;
	char ch;



	cin.ignore();

	if (!(checkUserExists())) {
		cout << "\n \t \t the user is not found plz sign up first ";
		return success;
	}


	else {
		cout << "\n \t \t \t welcome Mr " << name;

		int i = 3;

		char pass[20];

		char choice;

		while (i > 0) {
			cout << "\n \t \t please enter your password: ";

			maskpassword(pass);

			if (password == pass) {
				cout << "\n \t \t u have logged in successfully " << endl;

				success = true;

				return success;
			}

			else {
				cout << "\n \t \t u have input the wrong password please enter forget password (" << i - 1 << ")" << "try's left " << endl;
				cout << "input f or F for forget password " << endl;
				cout << "press any key to try again " << endl;
				i--;

				cin >> choice;

				if (choice == 'f' || choice == 'F') {
					i = 3;

					resetpassword();
					cout << "do u wanna try logging in again ?? " << endl;
					cout << "press any key to exit " << endl;

					cin >> ch;
				}
			}
		}




	}while (ch == 'y' || ch == 'Y');

}


void Customer::resetpassword()
{
	char choice;
	do {
		cin.ignore();
		string mail;
		cout << "\n\t\t\t Input Your Email: ";
		getline(std::cin, mail);

		if (this->email == mail)
		{
			cout << "\n\t\t\t Input new password: ";
			char pass[20];
			maskpassword(pass);
			this->password = pass;

			ifstream infile("Customer.txt");
			if (!infile)
			{
				cout << "File cannot be opened to read customer data..." << endl;
				return;
			}

			// First, count the number of customers
			string nam, nic, pa, m;
			int lineCount = 0;
			while (getline(infile, nam) && getline(infile, nic) && getline(infile, pa) && getline(infile, m))
			{
				lineCount += 4;
			}
			infile.clear();
			infile.seekg(0, ios::beg);

			int customerCount = lineCount / 4;
			Customer* customers = new Customer[customerCount];

			// Read customers into array
			int index = 0;
			while (getline(infile, nam) && getline(infile, nic) && getline(infile, pa) && getline(infile, m))
			{
				customers[index].name = nam;
				customers[index].cnic = nic;
				customers[index].password = pa;
				customers[index].email = m;
				index++;
			}
			infile.close();

			// Update password for the matching customer
			for (int i = 0; i < customerCount; ++i)
			{
				if (customers[i].cnic == this->cnic)
				{
					customers[i].password = this->password;
				}
			}

			// Write updated customers back to file
			std::ofstream outfile("Customer.txt");
			if (!outfile)
			{
				cout << "File cannot be opened to write updated customer data..." << endl;
				delete[] customers;
				return;
			}

			for (int i = 0; i < customerCount; ++i)
			{
				outfile << customers[i].name << endl;
				outfile << customers[i].cnic << endl;
				outfile << customers[i].password << endl;
				outfile << customers[i].email << endl;
			}

			outfile.close();
			delete[] customers;

			cout << "\n\t\t\t Password updated successfully...";
			break;
		}
		else
		{
			cout << "\n\t\t\t Wrong email....!" << endl;
			cout << "\n\t\t\t Input Again? [Y/y]: ";
			cout << "\n\t\t\t Press any key to Exit: ";
			cin >> choice;
		}
	} while (choice == 'Y' || choice == 'y');
}



bool Customer::signup() {

	bool success = false;


	fstream nicfile("customerNIC.txt", ios::out | ios::app);

	fstream emailfile("customeremail.txt", ios::out | ios::app);


	fstream file_("customer.txt", ios::out | ios::app);

	if (!file_) {
		cout << "the file cannot be opened to store the customers data... " << endl;
		return success;

	}

	cin.ignore();

	cout << "\n \t \t input ur name " << endl;

	getline(cin, name);


	file_ << name << endl;

	char op;

	do {

		op = '-';
		cout << "\n \t \t input ur cnic " << endl;

		getline(cin, cnic);


		fstream nic_file("customer.txt ", ios::in);

		string check;

		bool exist = false;

		while (getline(nic_file, check)) {
			if (cnic == check) {
				exist = true;
				break;
			}
		}

		if (exist) {
			cout << "the cnic already exists " << endl;

			cout << "\t \t option 1..try again " << endl;

			cout << "\t \t option 2...login " << endl;

			cout << "\t \t option 3..exit " << endl;

			cout << "input the ption number " << endl;

			cin >> op;

			cin.ignore();


		}

	} while (op == '1');

	if (op == '2') {
		if (login()) {
			return true;
		}
		else {
			return false;
		}



	}


	else if (op == '3') {
		return false;
	}

	else {
		file_ << cnic << endl;
		nicfile << cnic << endl;
		char pass[20];

		cout << "\t \t input ur password " << endl;

		maskpassword(pass);

		password = pass;

		file_ << password << endl;

		cout << "input ur email " << endl;

		getline(cin, email);

		file_ << email << endl;

		emailfile << email << endl;

		cout << "\t \t the sign up is successful " << endl;

		success = true;

		emailfile.close();

		file_.close();


	}

	return success;


}


bool Customer::checkUserExists() {
	bool flag = false;

	ifstream file_("customer.txt");
	if (!file_)
	{
		cout << "File could not be opened to check user data..." << endl;
		return flag;
	}

	string n, c, p, e;

	while (getline(file_, n) && getline(file_, c) && getline(file_, p) && getline(file_, e)) {

		if (cnic == c) {

			flag = true;

			name = n;

			cnic = c;

			password = p;

			email = e;

			break;
		}
	}

	file_.close();

	return flag;

}

class movie {

private:
	static const int seat_count = 30;

	string seats[seat_count] = {


		 "[G01]", "[G02]", "[G03]", "[G04]", "[G05]", "[G06]", "[G07]", "[G08]", "[G09]", "[G10]",
										"[H01]", "[H02]", "[H03]", "[H04]", "[H05]", "[H06]", "[H07]", "[H08]", "[H09]", "[H10]",
										"[E01]", "[E02]", "[E03]", "[E04]", "[E05]", "[E06]", "[E07]", "[E08]", "[E09]", "[E10]"



	};

protected:
	void add_movie();

public:
	void bookticket(Customer&);
	void displayseats();
	void createseatfile(int,int,int,int);
	void updateseatfile(int, int, int, int);
	void checkyourbooking(Customer&);

};

void movie::displayseats() {

	cout << "\n\t\t\tSeats (X means that seat is booked):\n\t\t\t";
	for (int i = 0; i < seat_count; i++) {
		cout << setw(6) << left << seats[i] << " ";
		if ((i + 1) % 10 == 0) {
			cout << "\n\t\t\t";
		}
	}
}





int main() {




}
