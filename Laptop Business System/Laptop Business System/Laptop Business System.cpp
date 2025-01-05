

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct laptop {
	int serialNo;
	char brand[20];
	char model[20];
	int price;
	int pieces;


	laptop() {
		serialNo = 0;
		brand[0] = '\0';
		model[0] = '\0';
		price = 0;
		pieces = 0;


		
	}
};

void display_menu();

void clearFile() {
	ofstream myfile("laptop.bin", ios::binary | ios::trunc);
	if (!myfile.is_open()) {
		cout << "Error: Could not open the file to clear its contents." << endl;
	}
	else {
		cout << "The file has been successfully cleared." << endl;
	}
	myfile.close();
}

void addRecord() {

	
	
	laptop l;
	laptop sno;
	cout << "enter the serial no of the laptop " << endl;
	cin >> sno.serialNo;

	//adding validation for this

	ifstream ifile("laptop.bin", ios::binary);


	bool store = false;

	while (ifile.read((char*)(&l), sizeof(laptop))) {
		;
		if (l.serialNo == sno.serialNo) {
			store = true;
			break;

		}
	}

	if (store) {
		cout << "The serial number already exists ! " << endl;
		exit(0);

	}

	l.serialNo = sno.serialNo;







	cout << "enter the brand of the laptop " << endl;
	cin.ignore();
	cin.getline(l.brand, 20);

	cout << "enter the model of the brand " << endl;
	cin.getline(l.model, 20);

		cout << "enter the price of the laptop " << endl;
		cin >> l.price;
	
	while (1) {

		while (l.price < 0) {
			
				cout << "why are u inputting a negative number...input again ? " << endl;
				cin >> l.price;
			}
		int price = l.price;
		int count = 0;

		if (price == 0) {
			break;
		}


		while (price != 0) {
			price /= 10;
			count++;
		}

		if (count <= 6) {
			break;
		}

		else {
			cout << "the price that u have entered is invalid (it cannot go above 6 digits) " << endl;
			cout << "enter the price again " << endl;
			cin >> l.price;
		}

	}


	cout << "Enter the number of machines (it cannot exceed 1000) " << endl;
	cin >> l.pieces;
	
	

		while (l.pieces < 0) {
			cout << "why are u inputting a negative number...input again  " << endl;
			cin >> l.pieces;
		}

		while (l.pieces > 1000) {
			cout << "why are you inputing an unrealistic number(it should be till 1000)..input again " << endl;
			cin >> l.pieces;
		}
	

	
	
	ofstream myfile("laptop.bin", ios::binary | ios::app);

	if (!myfile.is_open()) {
		cout << "the file didnt open " << endl;
	}

	myfile.write((char*)&l, sizeof(laptop));
	cout << "the record has been added successfully " << endl;

	ifile.close();
	myfile.close();

	
}

void updateRecord() {
	int search;

	cout << "enter the serial number of the record that you want to search " << endl;
	cin >> search;

	fstream ifile("laptop.bin", ios::binary | ios::in | ios::out);

	laptop l;

	bool store = false;
	int record_size = sizeof(laptop);
	int start = 0;

	while (ifile.read((char*)&l, sizeof(laptop))) {
		
		if (l.serialNo == search) {

				

			store = true;
			cout << "the record has been found...go ahead and update it " << endl;

			cout << "Enter the new brand " << endl;
			cin.ignore();

			cin.getline(l.brand, 20);

			cout << "Enter the new model " << endl;
			cin.getline(l.model, 20);

			cout << "Enter the new price of the laptop " << endl;
			cin >> l.price;
			while (1) {

				while (l.price < 0) {

					cout << "why are u inputting a negative number...input again ? " << endl;
					cin >> l.price;
				}
				int price = l.price;
				int count = 0;

				if (price == 0) {
					break;
				}


				while (price != 0) {
					price /= 10;
					count++;
				}

				if (count <= 6) {
					break;
				}

				else {
					cout << "the price that u have entered is invalid (it cannot go above 6 digits) " << endl;
					cout << "enter the price again " << endl;
					cin >> l.price;
				}

			}


			cout << "Enter the new number of pieces of the system " << endl;
			cin >> l.pieces;

			while (l.pieces < 0) {
				cout << "why are u inputting a negative number...input again  " << endl;
				cin >> l.pieces;
			}

			while (l.pieces > 1000) {
				cout << "why are you inputing an unrealistic number(it should be till 1000)..input again " << endl;
				cin >> l.pieces;
			}

			ifile.seekp(start);
			ifile.write((char*)&l, sizeof(laptop));

			cout << "the record has been updated " << endl;
			break;
		}

		start = start + record_size;

		
	}
	if (!store) {
		cout << "the record was not found...do u want to continue searching(click s or S) or go to menu again(click Y or y for menu)? " << endl;
		char ch;
		cin >> ch;

		while (ch != 'Y' && ch != 'y' && ch != 'S' && ch != 's') {
			cout << "you entered an invalid character..enter again! " << endl;
			cin >> ch;

		}

		if (ch == 'Y' && ch == 'y') {
			display_menu();

		}

		else if (ch == 'S' && ch == 's') {
			updateRecord();
			
		}

	}
		  
		ifile.close();

	
}

void deleteRecord() {

	//dealing this task with modularity
	
}

void displayRecords() {
	ifstream ifile("laptop.bin", ios::binary);

	laptop l;

	cout << "these are all the records that are present " << endl;
	cout << "----------------------------------------------------" << endl;

	while (ifile.read((char*)&l, sizeof(laptop))) {
		
		cout << "The serial number is " << l.serialNo << endl;
		cout << "The brand is " << l.brand << endl;
		cout << "The model is " << l.model << endl;
		cout << "The price is " << l.price << endl;
		cout << "The number of pieces are " << l.pieces << endl;
		cout << "---------------------------------------------------" << endl;

	}
}

void importCSV() {
	cout << "hamza " << endl;
}

void exportCSV() {
	cout << "hamza " << endl;
}

void showHelp() {
	cout << "THIS IS THE HELP SECTION " << endl;
	cout << "--------------------------------------" << endl;
	cout << "This code is very user friendly and easy to understand but if you still have any confusion then we can explain " << endl;
	cout << "Basically this code is divided into a menu system where upon pressing specific buttons we get specific functionality that relates to filing " << endl;
	cout << "The file is instantiated automatically the moment that you add your first record...later on all are the modifications to that file " << endl;
	cout << "This code is created by me Hamza Khan Tariq 04072313050 3rd semester " << endl;
}


void display_menu() {
		char ch;
	do {
		cout << "---------------------------------------------" << endl;
		cout << "press 1 to add record " << endl;
		cout << "press 2 to update a record " << endl;
		cout << "press 3 to delete a record " << endl;
		cout << "press 4 to display all the records" << endl;
		cout << "press 5 to import from csv " << endl;
		cout << "press 6 to export csv " << endl;
		cout << "press 7 to show help " << endl;
		cout << "-----------------------------------------------" << endl;
		int n;
		cin >> n;
		switch (n) {
		case 1:
			addRecord();
			break;

		case 2:
			updateRecord();
			break;

		case 3:
			deleteRecord();
			break;

		case 4:
			displayRecords();
			break;
		case 5:
			importCSV();
			break;
		case 6:
			exportCSV();
			break;
		case 7:
			showHelp();
			break;

		default:
			cout << "you pressed the wrong option...it doesnt exist " << endl;
		}
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "do you want the menu to appear again?....click Y | y if 'yes' and any button to terminate the program  " << endl;
		cin >> ch;
		if (ch != 'Y' && ch != 'y') {
			break;
		}
	} while (ch == 'Y' || ch == 'y');

}




int main() {

	cout << "--------------WELCOME TO THE MENU------------------" << endl;
	
	display_menu();


}