//
//
//#include<iostream>
//using namespace std;
//
//void insertionSort(int A[], int n) {				//the max time for it is O(n^2)
//													//the min time for it is O(n)
//	int x;
//	int j;
//	for (int i = 1; i < n; i++) {
//		 j = i - 1;
//		 x = A[i];
//		 while (j > -1 && A[j] > x) {
//			 A[j + 1] = A[j];
//			 j--;	
//		}
//
//		 A[j + 1] = x;
//
//	}
//}
//	
//int main() {
//
//}
//
//
////adaptive or not?
////No of comparisons n-1
////therefore the max time for comparisons are O(n)
//
//
//
////as there are no swaps in an already sorted array therefore the max time complex for it is O(1)
//
////insertion sort is stable as well



#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<stdio.h>

class BOOK
{
	float price;
	std::string name;
	int bookid;
public:
	BOOK()
	{
		bookid = 0;
		this->price = 0.0;
		this->name = "";
	}
	void setprice(float p)
	{
		this->price = p;
	}
	void setname(std::string n)
	{
		this->name = n;
	}
	void setid(int id)
	{
		this->bookid = id;
	}
	float getprice()
	{
		return this->price;
	}
	int getid() {
		return this->bookid;
	}
	std::string getname()
	{
		return this->name;

	}
};
class bookshop {
	BOOK* books;
	int count;
	int No_books;
	std::ofstream myfile;
public:
	bookshop() {
		myfile.open("data.csv");
		myfile.close();
		remove("data.csv");
		myfile.open("data.csv");
		myfile << "ID,BookName,Price\n";
		books = nullptr;
		this->No_books = 0;
		this->count = 0;
	}
	void set_No_books(int n)
	{
		this->No_books = n;
		books = new BOOK[this->No_books];
	}
	void addbook(std::string n, int id, float price)
	{
		bool flag = true;
		for (int i = 0; i < count; i++)
		{
			if (books[i].getid() == id)
			{
				std::cout << "Id Already used please Use Another ID";
				flag = false;
			}
		}
		if (flag == true) {
			if (!myfile)
				std::cout << "unable to open file";

			this->books[count].setid(id);
			myfile << books[count].getid();
			myfile << ",";
			this->books[count].setname(n);
			myfile << books[count].getname();
			myfile << ",";
			this->books[count].setprice(price);
			myfile << books[count].getprice();
			myfile << "\n";
			count++;

		}
	}
	void display()
	{
		/*if (count == 0)
		{
			std::cout << "There are no records to be displayed";
	}
		else*/
		for (int i = 0; i < count; i++)
		{
			std::cout << "===================================================\n";
			std::cout << "Book Name: " << this->books[i].getname() << std::endl;
			std::cout << "Book ID: " << this->books[i].getid() << std::endl;
			std::cout << "Book Price: " << this->books[i].getprice() << std::endl;
			std::cout << "===================================================\n";


		}
	}
	void edit(std::string name, int id, int nid, float price)
	{
		bool flag = false;
		int i = 0;

		for (i = 0; i < count; i++)
			if (this->books[i].getid() == id)
			{
				flag = true;
				break;
			}

		if (flag == false)
		{
			std::cout << "invalid book ID " << std::endl;
		}
		else {
			myfile.close();
			remove("data.csv");


			this->books[i].setid(nid);
			this->books[i].setname(name);

			this->books[i].setprice(price);

			myfile.open("data.csv");
			if (!myfile)
			{
				std::cout << "Unable to open file\n";
			}
			else {
				myfile << "ID,BOOKNAME,PRICE\n";
				for (int i = 0; i < count; i++)
				{
					myfile << books[i].getid() << ",";
					myfile << books[i].getname() << ",";
					myfile << books[i].getprice() << "\n";

				}
			}
		}

	}
	void deletebook(int id)
	{

		myfile.close();
		remove("data.csv");

		myfile.open("data.csv");
		int i = 0;
		for (i = 0; i < count; i++)
		{
			if (books[i].getid() == id)
			{
				break;
			}
		}
		for (int j = i; j < count - 1; j++)
		{
			books[j] = books[j + 1];
		}
		count--;
		for (int j = 0; j < count; j++)
		{
			myfile << books[j].getid() << ',';
			myfile << books[j].getname() << ',';
			myfile << books[j].getprice() << '\n';

		}
	}
	int getcount()
	{
		return this->count;
	}
	~bookshop()
	{
		delete[] books;
		myfile.close();
	}

};
int main() {
	std::ofstream myfile2;
	myfile2.open("data2.bin", std::ios::binary);
	bool flag = false;
	bookshop s1;

	int n;
	std::string name;
	int id, nid;
	char input = 'y';

	float price;
	std::cout << "================================================\n";
	std::cout << "||please enter the number of books in the shop||\n";
	std::cout << "================================================\n";

	std::cout << "Enter:";
	std::cin >> n;
	std::cout << "\n";
	s1.set_No_books(n);
	while (input != 'x')
	{
		std::cout << "=================================\n";
		std::cout << " ||To add books press 'a'      ||\n"
			<< " ||To edit a record press 'e'  ||\n"
			<< " ||To delete a record press 'z'||\n"
			<< " ||To display records press 'd'||\n"
			<< " ||To import records press 'i' ||\n"
			<< " ||To exit press 'x'           ||\n"
			<< " ||For Help press 'h/H'        ||\n";
		std::cout << "=================================\n||Enter: ";

		std::cin >> input;
		if (input == 'a' || input == 'e' || input == 'd' || input == 'z' || input == 'i' || input == 'x' || (input == 'h' || input == 'H'))
		{
			if (input == 'i')
			{
				std::string line = "";
				std::string TEMP;
				std::ifstream myfile3("IMPORT.csv");

				std::getline(myfile3, line);
				if (!myfile3)
				{
					std::cout << "unable to open file \n";
				}
				else
				{
					while (std::getline(myfile3, line))
					{


						std::string ID = "", PRICE = "";
						TEMP = line;
						std::istringstream temp(TEMP);
						std::getline(temp, ID, ',');
						std::getline(temp, name, ',');
						std::getline(temp, PRICE);
						id = std::stoi(ID);
						price = std::stof(PRICE);
						s1.addbook(name, id, price);
						line = "";
					}
					std::cout << "Books successfully imported\n";
				}
				myfile3.close();

			}
			else if (input == 'a')
			{
				char c = 'y';
				while (c == 'y' || c == 'Y')
				{
					if (s1.getcount() >= n)
					{
						std::cout << "\n\n-----Records Full Delete A Record To Add More-----\n\n";
						break;
					}
					else {
						std::cout << "====================\n";
						std::cout << "Enter book name: ";
						std::cin >> name;
						std::cout << std::endl;

						std::cout << "Enter book ID: ";
						std::cin >> id;
						std::cout << std::endl;

						std::cout << "Enter book Price: ";
						std::cin >> price;
						std::cout << "====================\n";

						s1.addbook(name, id, price);
						std::cout << std::endl;
					}
					std::cout << "=========================================================================\n";
					std::cout << "If you want to add more records press Y/y else press any other key \n";
					std::cout << "=========================================================================\n";
					std::cout << "Enter: ";
					std::cin >> c;
					std::cout << "\n";

				}
			}
			else if (input == 'e')
			{
				std::cout << "Enter the ID of book you want to edit: ";
				std::cin >> id;
				std::cout << std::endl;
				std::cout << "Enter Name Of The New Book: ";
				std::cin >> name;
				std::cout << std::endl;
				std::cout << "Enter New ID: ";
				std::cin >> nid;
				std::cout << std::endl;
				std::cout << "Enter Price Of The New Book: ";
				std::cin >> price;
				s1.edit(name, id, nid, price);
			}
			else if (input == 'z')
			{
				std::cout << "enter ID of the product you want to remove";
				std::cin >> id;
				s1.deletebook(id);
			}
			else if (input == 'd')
			{
				std::cout << "\n";
				s1.display();
			}
			else if (input == 'x')
			{
				std::cout << "====================================\n";
				std::cout << "||THANK YOU FOR USING THIS PROGRAM|| \n";
				std::cout << "====================================\n";

			}
			else if (input == 'h' || input == 'H')
			{
				std::cout << "\n\n=====================================================\n";
				std::ifstream myfile4;
				myfile4.open("HELP.txt");
				std::string line;
				while (getline(myfile4, line))
				{
					std::cout << line << "\n";
				}
				myfile4.close();
				std::cout << "\n=====================================================\n";


			}
		}
	}
	if (!myfile2)
	{

		std::cout << "unable to open file";
	}
	else
		myfile2.write((char*)&s1, sizeof(bookshop));
	myfile2.close();

}