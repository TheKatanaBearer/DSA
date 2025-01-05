
#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<conio.h>
#include<fstream>
#include<ctime>
#include<stdlib.h>
#include<windows.h>


using namespace std;


//*****************************************************************************\\
//-------------------------Abstract Class User---------------------------------\\





class User
{
protected:
	string cnic;
	string password;
	string email; // use for password reset

public:
	User();
	virtual void resetpassword() = 0;  // Pure Virtual Function
	virtual bool login() = 0;          // Pure Virtual Function
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


//**************************************************************************\\
//---------------------------  Class Customer -----------------------------------\\

class Customer :virtual public User
{
private:
	string name;

public:
	Customer();
	bool checkUserExist();
	void resetpassword()override;
	bool signup();
	bool login()override;

	friend class Movie;   // Allow Class Movie to Access the private data members of Customer Class
};


Customer::Customer() :User(), name("") {};


bool Customer::login()
{
	bool success = false; char ch;
	cin.ignore();

	do {
		ch = 'z';
		cout << "\t\t\t Input your cnic: ";
		getline(cin, cnic);

		if (!(checkUserExist()))
		{
			cout << "\n\t\t\t User did not Found. Please Sign Up First.";
			return success;	
		}

		else
		{
			cout << "\n\t\t\t Welcome Mr " << name;
			char pass[20], choice;

			//check the password and gives you 3 tries

			int i = 3;

			while (i > 0)
			{
				cout << "\n\t\t\t Please Enter Your Password: ";
				maskpassword(pass);
				if (password == pass)
				{
					cout << "\n\t\t\t You have logged in Successfully.." << endl;
					success = true;
					return success;
				}
				else
				{
					cout << "\n\t\t\t You input wrong password .. Try Forget password.. (" << i - 1 << ") try's left.";
					cout << "\n\t\t\t Input [F/f] for reset password option...";
					cout << "\n\t\t\t Press any Key to Try Again: ";
					i--;
					cin >> choice;

					if (choice == 'f' || choice == 'F')
					{
						i = 3;
						this->resetpassword();
						cout << "\n\t\t\t Do you Wanna Try Logging in Again? [Y/y]: \n"
							<< "\n\t\t\t Press any key to exit: ";
						cin >> ch;
					}
				}
			}

		}
	} while (ch == 'y' || ch == 'Y');

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




bool Customer::signup()
{

	bool success = false;
	fstream nicfile("CustomerNIC.txt", ios::out | ios::app);
	fstream emailfile("Customeremail.txt", ios::out | ios::app);



	fstream file_("Customer.txt", ios::out | ios::app);
	if (!file_)
	{
		cout << "file cannot be opened to store customer's data.." << endl;						
		return success;
	}
	cin.ignore();
	cout << "\n\t\t\t Input Your Name: ";
	getline(cin, name);
	file_ << name << endl;
	char op;
	do
	{
		op = '-';
		cout << "\t\t\t Input Your CNIC: ";
		getline(cin, cnic);

		// THis File contains previous Customer CNIC
		fstream nic_file("CustomerNIC.txt", ios::in);
		string check;
		bool exist = false;
		while (getline(nic_file, check))
		{
			if (cnic == check)
			{
				exist = true;
				break;
			}
		}
		if (exist)
		{
			cout << "\n\t\t\t CNIC Already Exist!";
			cout << "\n\t\t\t Option 1 (Try Again):";
			cout << "\n\t\t\t Option 2 (Login): ";
			cout << "\n\t\t\t Option 3 (Exit): ";
			cout << "\n-------------------";
			cout << "\n\t\t\tInput Option Number: ";
			cin >> op;
			cin.ignore();
		}
	} while (op == '1');

	if (op == '2')
	{
		if (login())
			return true;
		else
			return false;
	}
	else if (op == '3')
	{
		return false;
	}
	else
	{
		file_ << cnic << endl;
		nicfile << cnic << endl;
		char pass[20];
		cout << "\t\t\t Input Your Password: ";
		maskpassword(pass);
		password = pass;
		file_ << password << endl;
		cout << "\n\t\t\t Input Your email: ";
		getline(cin, email);
		file_ << email << endl;
		emailfile << email << endl;
		cout << "\n\t\t\t Sign Up successful....";
		success = true;
		emailfile.close();
		file_.close();

	}
	return success;
}




bool Customer::checkUserExist()
{
	bool flag = false;
	ifstream file_("Customer.txt");
	if (!file_)
	{
		cout << "File could not be opened to check user data..." << endl;
		return flag;
	}

	string n, c, p, e;
	while (getline(file_, n) && getline(file_, c) && getline(file_, p) && getline(file_, e)) {
		if (this->cnic == c) {
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



//**************************************************************************************\\
//--------------------------------- Class Movie -----------------------------------------\\

class Movie
{
private:

	static const int seat_count = 30;

	string seats[seat_count] = { "[G01]", "[G02]", "[G03]", "[G04]", "[G05]", "[G06]", "[G07]", "[G08]", "[G09]", "[G10]",
										"[H01]", "[H02]", "[H03]", "[H04]", "[H05]", "[H06]", "[H07]", "[H08]", "[H09]", "[H10]",
										"[E01]", "[E02]", "[E03]", "[E04]", "[E05]", "[E06]", "[E07]", "[E08]", "[E09]", "[E10]" };

protected:
	void addmovie();

public:
	void bookticket(Customer&);
	void displaySeats();
	void createSeatsFile(int, int, int, int);
	void updateSeatsFile(int, int, int, int);
	void checkYourbooking(Customer&);

};


void Movie::displaySeats()
{
	cout << "\n\t\t\tSeats (X means that seat is booked):\n\t\t\t";
	for (int i = 0; i < seat_count; i++) {
		cout << setw(6) << left << seats[i] << " ";
		if ((i + 1) % 10 == 0) {
			cout << "\n\t\t\t";
		}
	}
}

void Movie::updateSeatsFile(int movieCode, int day, int month, int year)
{
	fstream seatsFile("Seats_" + to_string(movieCode) + "_" + to_string(day) + "_" + to_string(month) + "_" + to_string(year) + ".txt");
	if (seatsFile.is_open()) {
		for (int i = 0; i < seat_count; i++) {
			seatsFile << seats[i] << " ";
		}
		seatsFile.close();
	}
}

void Movie::createSeatsFile(int movieCode, int day, int month, int year)
{
	fstream seatsFile("Seats_" + to_string(movieCode) + "_" + to_string(day) + "_" + to_string(month) + "_" + to_string(year) + ".txt", ios::out);
	{
		for (int i = 0; i < seat_count; i++) {
			seatsFile << seats[i] << " ";
		}
		seatsFile.close();
	}
}



bool isLeapYear(int y)
{
	return (y % 4 == 0);
}


int daysInMonth(int month, int year)
{
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		return isLeapYear(year) ? 29 : 28;
	default:
		return 0;
	}
}

void getCurrentDate(int& day, int& month, int& year)
{
	time_t t = time(0);  // Get current time
	tm now;
	localtime_s(&now, &t);  // Convert to local time
	day = now.tm_mday;
	month = now.tm_mon + 1;  // Months since January (0-11)
	year = now.tm_year + 1900;  // Years since 1900
}

void Movie::addmovie()
{
	int currentDay, currentMonth, currentYear;
	getCurrentDate(currentDay, currentMonth, currentYear);

	cout << "\n\t\t\t Today's Date: " << currentDay << "/" << currentMonth << "/" << currentYear;

	// Schedule movies for three consecutive days
	for (int day_ = 0; day_ < 3; day_++)
	{
		int scheduledDay = currentDay + day_;
		int scheduledMonth = currentMonth;
		int scheduledYear = currentYear;

		// Adjust scheduled date if it exceeds the days in the current month
		while (scheduledDay > daysInMonth(scheduledMonth, scheduledYear))
		{
			scheduledDay -= daysInMonth(scheduledMonth, scheduledYear);
			scheduledMonth++;
			if (scheduledMonth > 12) {
				scheduledMonth = 1;
				scheduledYear++;
			}
		}

		cout << "\n\t\t\t Schedule for Day " << day_ + 1 << ": " << scheduledDay << "/" << scheduledMonth << "/" << scheduledYear << endl;


		string fileName = "Movies_" + to_string(scheduledDay) + "_" + to_string(scheduledMonth) + "_" + to_string(scheduledYear) + ".txt";


		ofstream datesFile("AvailableDates.txt", ios::out | ios::app);
		if (datesFile.is_open())
		{
			datesFile << scheduledDay << " " << scheduledMonth << " " << scheduledYear << endl;
			datesFile.close();
		}
		else
		{
			cout << "Failed to open AvailableDates.txt" << endl;
			return;
		}


		ofstream file(fileName, ios::out | ios::app);
		if (file.is_open())
		{
			int numMovies;
			cout << "\n\t\t\t How many movies do you want to schedule for this day? ";
			cin >> numMovies;

			for (int i = 0; i < numMovies; i++)
			{
				cin.ignore();
				string title, time;
				cout << "\n\t\t\t Movie " << i + 1 << " Title: ";
				getline(cin, title);
				cout << "\n\t\t\t Showtime: ";
				getline(cin, time);


				file << title << endl;
				file << time << endl;
			}

			file.close();
		}
		else
		{
			cout << "Failed to open " << fileName << endl;
			return;
		}
	}
}



void Movie::bookticket(Customer& customer)
{
	// Read available dates from file
	ifstream dateFile("AvailableDates.txt");
	if (!dateFile.is_open())
	{
		cout << "Failed to open AvailableDates.txt" << endl;
		return;
	}

	string availableDates[100];
	int dateCount = 0;
	string line;

	cout << "\n\t\t\t Available Dates:" << endl;
	while (getline(dateFile, line)) {
		cout << dateCount + 1 << ". " << line << endl;
		availableDates[dateCount] = line;
		dateCount++;
	}
	dateFile.close();

	if (dateCount == 0) {
		cout << "\n\t\t\t No shows available." << endl;
		return;
	}

	int dateChoice;
	cout << "\n\t\t\t Enter the number corresponding to the date you want to book: ";
	cin >> dateChoice;

	if (dateChoice <= 0 || dateChoice > dateCount)
	{
		cout << "\n\t\t\t Invalid date choice." << endl;
		return;
	}

	// Since Date is stored as a string 12/5/24 this part extarcts the day month and year from the string
	string chosenDate = availableDates[dateChoice - 1];
	size_t pos1 = chosenDate.find(' ');
	size_t pos2 = chosenDate.find(' ', pos1 + 1);

	int day = stoi(chosenDate.substr(0, pos1));
	int month = stoi(chosenDate.substr(pos1 + 1, pos2 - pos1 - 1));
	int year = stoi(chosenDate.substr(pos2 + 1));

	// Generate the filename for the respective date
	string fileName = "Movies_" + to_string(day) + "_" + to_string(month) + "_" + to_string(year) + ".txt";

	ifstream file(fileName);
	if (!file.is_open())
	{
		cout << "\n\t\t\t No movies scheduled for this date." << endl;
		return;
	}

	string movies[100];
	string times[100];
	int lineNumber = 0;
	int movieNumber = 1;

	cout << "\n\t\t\t Available Movies:" << endl;
	while (getline(file, line))
	{
		if (lineNumber % 2 == 0)
		{
			cout << "\n\t\t\t " << movieNumber << ". Movie: " << line << endl;
			movies[movieNumber - 1] = line;
		}
		else
		{
			cout << "\n\t\t\t Show time: " << line << endl;
			times[movieNumber - 1] = line;
			movieNumber++;
		}
		lineNumber++;
	}
	file.close();

	int movieCode;
	cout << "\n\t\t\t Enter the movie code to book: ";
	cin >> movieCode;

	if (movieCode <= 0 || movieCode >= movieNumber)
	{
		cout << "\n\t\t\t Invalid movie code." << endl;
		return;
	}

	// Generate the seat file name for the movie
	string seatFileName = "Seats_" + to_string(movieCode) + "_" + to_string(day) + "_" + to_string(month) + "_" + to_string(year) + ".txt";

	// Read the seat availability from the file
	fstream seatsFile(seatFileName, ios::in);
	if (!seatsFile.is_open())
	{
		createSeatsFile(movieCode, day, month, year);
	}

	for (int i = 0; i < seat_count; ++i)
	{
		seatsFile >> seats[i];
	}
	seatsFile.close();


	displaySeats();

	int tickets;
	do
	{
		char ch = '0';
		cout << "\n\t\t\t How many tickets do you want to book? (1-5): ";
		cin >> tickets;
		if (tickets > 5 || tickets < 1) {
			cout << "\n\t\t\t You can book a maximum of 5 seats.\n"
				<< "\n\t\t\t Do you want to try again [Y/y]: \n"
				<< "\n\t\t\t Press any key to exit. ";
			cin >> ch;
			if (ch != 'y' && ch != 'Y') {
				return;
			}
		}
		else
		{
			break;
		}
	} while (true);

	string bookedSeats = "";
	for (int i = 0; i < tickets; i++)
	{
		string seatNumber;
		bool validSeat = false;
		while (!validSeat) {
			cout << "\n\t\t\t Enter seat number to book (e.g., G01, H05): ";
			cin >> seatNumber;

			for (int j = 0; j < seat_count; j++)
			{
				if (seats[j] == "[" + seatNumber + "]")
				{
					seats[j] = "X";
					bookedSeats += seatNumber + " ";
					validSeat = true;
					break;
				}
			}

			if (!validSeat)
			{
				cout << "Invalid seat number or seat already booked. Try again." << endl;
			}
		}
	}

	updateSeatsFile(movieCode, day, month, year);

	fstream bookingFile("Bookings.txt", ios::out | ios::app);
	bookingFile << day << "/" << month << "/" << year << endl; // Write date
	bookingFile << customer.name << "\n" << movies[movieCode - 1] << "\n" << times[movieCode - 1] << "\n" << bookedSeats << endl;
	bookingFile.close();

	cout << "\n\t\t\t Tickets successfully booked." << endl;
	displaySeats();
}

void Movie::checkYourbooking(Customer& customer)
{
	fstream file("Bookings.txt", ios::in);
	if (!file) {
		cout << "\n\t\t\tNo bookings found." << endl;
		return;
	}

	string dt, nm, movieTitle, showTime, seatNumbers;
	bool found = false;
	while (getline(file, dt) && getline(file, nm) && getline(file, movieTitle) && getline(file, showTime) && getline(file, seatNumbers)) {

		if (customer.name == nm) {
			found = true;

			cout << "\n\t\t|------------------------------------------------|";
			cout << "\n\t\t| " << setw(46) << left << ("Booking for Mr: " + nm) << "|";
			cout << "\n\t\t| " << setw(46) << left << ("Movie: " + movieTitle) << "|";
			cout << "\n\t\t| " << setw(46) << left << ("Date: " + dt) << "|";
			cout << "\n\t\t| " << setw(46) << left << ("Show time: " + showTime) << "|";
			cout << "\n\t\t| " << setw(46) << left << ("Seats: " + seatNumbers) << "|";
			cout << "\n\t\t|------------------------------------------------|\n";
		}
	}

	if (!found)
	{
		cout << "\n\t\t\t No bookings found for " << customer.name << endl;
	}

	file.close();
}




//*********************************************************************************\\
//------------------------------- Class Manager -----------------------------------\\


class Manager : virtual public User, public Movie
{
private:

public:
	Manager();
	void resetpassword()override;
	bool login()override;
	void AddMovies();

};


Manager::Manager() :User(), Movie() {};


void Manager::AddMovies()
{
	addmovie();
}

bool Manager::login()
{
	bool success = false;
	fstream file_("C:\\Users\\USER\\Manager.txt", ios::in);

	if (!file_) {
		cout << "File of Manager cannot be opened.\n";
		return success;
	}

	char pass[20], choice;
	string p, mail;

	do {
		bool success = false;
		fstream file_("C:\\Users\\USER\\Manager.txt", ios::in);

		if (!file_) {
			cout << "File of Manager cannot be opened.\n";
			return success;
		}
		cout << "\n\t\t\tPlease Enter Password: ";
		maskpassword(pass);
		password = pass;


		choice = '-';
		file_.seekg(0, ios::beg);

		while (getline(file_, p) && getline(file_, mail)) {
			email = mail;
			if (password == p) {
				success = true;
				file_.close();
				return success;
			}
		}

		cout << "\n\t\t\tYou input the wrong password. Try 'Forget password'.";
		cout << "\n\t\t\tPress [F/f] for reset password option.";
		cout << "\n\t\t\tPress [C/c] to Try Again.";
		cout << "\n\t\t\tPress any key to exit.";
		cin >> choice;

		if (choice == 'f' || choice == 'F')
		{
			this->resetpassword();
			cout << "\n\t\t\tDo you want to try logging in again? [C/c]";
			cout << "\n\t\t\tPress any key to exit.";
			cin >> choice;
		}

	} while (choice == 'C' || choice == 'c');

	file_.close();
	return success;
}

void Manager::resetpassword()
{
	string mail;
	char ch;

	fstream file("C:\\Users\\USER\\Manager.txt", ios::out);


	do {
		ch = '-';
		cin.ignore();
		cout << "\n\t\t\tInput Your Email: ";
		getline(cin, mail);

		if (email == mail)
		{
			char pass[20];
			cout << "\n\t\t\tInput your new password: (max 20 characters) ";
			maskpassword(pass);
			password = pass;
			file << pass << endl;
			file << mail << endl;
			cout << "\n\t\t\tPassword updated Succesfully.";
			return;
		}
		else
		{
			cout << "\n\t\t\tYou input wrong email id!"
				<< "\n\t\t\tPress [C/c] to continue: "
				<< "\n\t\t\tPress any key to exit: ";
			cin >> ch;
		}
	} while (ch == 'C' || ch == 'c');
	file.close();
	return;
}

//---------------------------------------------------------------------------------//








int main()
{

	Movie movie;
	char choice, ch;
	int i;
	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t *************************\t\t\n";
	cout << "\t\t\t ********/Welcome\\********\t\t\n";
	cout << "\t\t\t *************************\t\t\n";

	bool flag;

	do
	{
		flag = false;
		cout << "\n\n\t\t\t To Continue as Manager Press [M/m]: ";
		cout << " \n\t\t\t To Continue as Customer Press [C/c]: ";
		cin >> choice;
		if (choice != 'm' && choice != 'M' && choice != 'c' && choice != 'C')
		{
			cout << "\n\t\t\t Invalid Option! Please Input Again.";
			flag = true;
		}

	} while (flag);


	if (choice == 'm' || choice == 'M')
	{
		Manager M;
		cout << "\n\t\t\t Please Login First: \n ";
		if (M.login())
		{
			for (i = 3; i >= 1; i--)
			{
				system("cls");
				cout << "\n\n\n\t\t\t\t\t Loading.... Please Wait ....(" << i << ")";
				Sleep(1000);
			}
			system("cls");
			cout << "\n\n\n\n\n\n";
			do
			{
				ch = '-';
				i = 0;
				cout << "\n\t\t\t Welcome, Mr. Manager.";
				cout << "\n\t\t\t Press [A/a] to add movies: "
					<< "\n\t\t\t If You Wanna Exit Press [X/x]: ";
				cin >> ch;
				if (ch != 'a' && ch != 'A' && ch != 'X' && ch != 'x')
				{
					cout << "\n\t\t\t Please Input Valid Option: ";
					flag = true;
				}
				else if (ch == 'X' || ch == 'x')
				{
					break;
				}
				else if (ch == 'a' || ch == 'A')
				{
					system("cls");
					M.AddMovies();
					break;
				}
			} while (flag);

		}
		else
		{
			cout << "\n\t\t\t Error Ocurred Cannot Log in Right Now.";
		}
	}

	else if (choice == 'c' || choice == 'C')
	{
		Customer C;
		cout << "\n\t\t\t For Sign Up [S/s] ";
		cout << " \n\t\t\t For Log in [L/l] ";
		cout << " \n\t\t\t Input Option: ";
		cin >> choice;

		switch (choice)
		{
		case'S':
		case's':
		{
			if (C.signup())
			{
				for (int i = 3; i >= 1; i--)
				{
					system("cls");
					cout << "\n\n\n\t\t\t\t\t Loading.... Please Wait ....(" << i << ")";
					Sleep(1000);
				}
				system("cls");
				cout << "\n\n\n\n\n\n";
				do
				{
					ch = '-';
					flag = false;
					cout << "\n\t\t\t Welcome.";
					cout << "\n\t\t\t Press [B/b] to Book movies: "
						<< "\n\t\t\t If You Wanna Exit Press [X/x]: ";
					cin >> ch;
					if (ch != 'B' && ch != 'b' && ch != 'X' && ch != 'x')
					{
						cout << "\n\t\t\t Please Input Valid Option: ";
						flag = true;
					}
					else if (ch == 'X' || ch == 'x')
					{
						break;
					}
					else if (ch == 'b' || ch == 'B')
					{
						system("cls");
						movie.bookticket(C);

					}
				} while (flag);

			}
			else
			{
				cout << "\n\t\t\t Cannot Sign in Customer Right Now.";
			}

			break;
		}

		case'L':
		case'l':
		{
			if (C.login())
			{
				for (int i = 3; i >= 1; i--)
				{
					system("cls");
					cout << "\n\n\n\t\t\t\t\t Loading.... Please Wait ....(" << i << ")";
					Sleep(1000);
				}
				system("cls");
				cout << "\n\n\n\n\n\n";
				do
				{
					ch = '-';
					flag = false;
					cout << "\n\t\t\t To Book Tickets Press [B/b] "
						<< "\n\t\t\t To Check Your Booking Press [T/t] "
						<< "\n\t\t\t If You Wanna Exit Press [X/x]: ";
					cin >> ch;
					if (ch != 'B' && ch != 'b' && ch != 'X' && ch != 'x' && ch != 't' && ch != 'T')
					{
						cout << "\n\t\t\t Please Input Valid Option: ";
						flag = true;
					}
					else if (ch == 'X' || ch == 'x')
					{
						break;
					}
					else if (ch == 'b' || ch == 'B')
					{
						system("cls");
						movie.bookticket(C);
						break;
					}
					else if (ch == 't' || ch == 'T')
					{
						system("cls");
						movie.checkYourbooking(C);

						break;
					}
				} while (flag);
			}

		}

		}

	}
	return 0;
}







