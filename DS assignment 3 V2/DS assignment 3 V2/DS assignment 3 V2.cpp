

	#include<iostream>
	#include<list>
	#include<fstream>
	#include<string>


	using namespace std;

	class weapon {
	public:

		int id;
		int price;
		string name;
		string manufacture;
		string type;

	};

	void display_menu(list<weapon>& weapons);
	void display_weapons(list<weapon>& weapons);



	void save_to_file(list<weapon>(&weapons)) {

		ofstream ofile("TUPAC.bin", ios::binary);
		if (!ofile) {
			cout << "The file didnt open " << endl;
			return;

		}

		list<weapon>::iterator it;

		for (it = weapons.begin();it != weapons.end();it++) {

			size_t name_len = it->name.length();
			size_t type_len = it->type.length();
			size_t manuf_len = it->manufacture.length();

			ofile.write(reinterpret_cast<const char*>(&it->id), sizeof(it->id));

			ofile.write(reinterpret_cast<const char*>(&it->price), sizeof(it->price));
			ofile.write(reinterpret_cast<const char*>(&name_len), sizeof(name_len));
			ofile.write(it->name.data(), name_len);
			ofile.write(reinterpret_cast<const char*>(&type_len), sizeof(type_len));
			ofile.write(it->type.data(), type_len);
			ofile.write(reinterpret_cast<const char*>(&manuf_len), sizeof(manuf_len));
			ofile.write(it->manufacture.data(), manuf_len);


			char delimiter = '\0';

			ofile.write(&delimiter, sizeof(delimiter));




		}

		ofile.close();
		cout << "the data has been saved " << endl;
	}



	void load_from_file(list<weapon>& weapons) {



		ifstream ifile("TUPAC.bin", ios::binary);

		if (!ifile) {
			cout << "The file didnt open " << endl;
			return;
		}


		list<weapon>loaded_weapons;
		
		while (ifile) {
			weapon w;

			//read the weapon data

			ifile.read(reinterpret_cast<char*>(&w.id), sizeof(w.id));
			ifile.read(reinterpret_cast<char*>(&w.price), sizeof(w.price));

			size_t name_len;
			size_t type_len;
			size_t manuf_len;


			ifile.read(reinterpret_cast<char*>(&name_len), sizeof(name_len));
			w.name.resize(name_len);
			ifile.read(&w.name[0], name_len);



			ifile.read(reinterpret_cast<char*>(&type_len), sizeof(type_len));
			w.type.resize(type_len);
			ifile.read(&w.type[0], type_len);

			ifile.read(reinterpret_cast<char*>(&manuf_len), sizeof(manuf_len));
			w.manufacture.resize(manuf_len);
			ifile.read(&w.manufacture[0], manuf_len);

			loaded_weapons.push_back(w);

			char delimiter;
			ifile.read(&delimiter, sizeof(delimiter));


			if (delimiter != '\0') {
				break;
			}


		}

		weapons = loaded_weapons;

		ifile.close();
		cout << "Data has been loaded " << endl;



	}


	void add_weapon(list<weapon>& weapons) {

		weapon new_w;
		cout << "enter the id of the new weapon " << endl;
		cin >> new_w.id;
		while (new_w.id < 0)
		{
			cout << "The input that you have entered is invalid..enter again " << endl;
			cin >> new_w.id;
		}

		int c;
		int sr;

		while (1) {
			sr = new_w.id;
			c = 0;
			while (sr != 0) {
				sr /= 10;
				c++;
			}
			if (c <= 6) {
				break;
			}
			else {
				cout << "The input that you have given is invalid..it cannot go above 6 digits...enter again " << endl;
				cin >> new_w.id;

			}
		}

		for (list<weapon>::iterator it = weapons.begin();it != weapons.end();it++) {
			if (it->id == new_w.id) {
				cout << "A duplicate ID already exists " << endl;
				return;
			}
		}

		cout << "Enter the name of the weapon " << endl;
		cin.ignore();
		getline(cin, new_w.name);

		cout << "Enter the type of the weapon " << endl;
		cin.ignore();
		getline(cin, new_w.type);


		cout << "Enter the place of manufacture of the weapon " << endl;
		cin.ignore();
		getline(cin, new_w.manufacture);


		cout << "Enter the price of the weapon " << endl;
		
		cin >> new_w.price;

		while (new_w.price< 0)
		{
			cout << "The input that you have entered is invalid..it cannot be negative..enter again " << endl;
			cin >> new_w.id;
		}

		

		while (1) {
			sr = new_w.price;
			c = 0;
			while (sr != 0) {
				sr /= 10;
				c++;
			}
			if (c <= 6) {
				break;
			}
			else {
				cout << "The input that you have given is invalid..it cannot go above 6 digits...enter again " << endl;
				cin >> new_w.id;
			}
		}


		weapons.push_back(new_w);
		cout << "The weapon has been added successfully " << endl;




	}


	void delete_weapon(list<weapon>& weapons) {
		int id;
		cout << "Enter the id of weapon that i have to delete " << endl;
		cin >> id;

		bool found = false;
		list<weapon>::iterator it;
		for (it = weapons.begin();it != weapons.end();it++) {

			if (it->id == id) {
				cout << "The id has been found " << endl;
				found = true;
				break;

			}
		}

		if (!found) {

			cout << "the weapon was not found! " << endl;
			display_menu(weapons);

		}

		if (found) {
			weapons.erase(it);
			cout << "The weapon record has been deleted " << endl;
		}
	}


	void update_record(list<weapon>& weapons) {
		int id;
		cout << "Enter the id of the weapon that you want to update " << endl;
		cin >> id;


		while (id < 0) {
			cout << "The id that you have entered is negative..please enter again " << endl;
			cin >> id;
		}

		int c;
		int sr;


		while (1) {
			sr = id;
			c = 0;
			while (sr != 0) {
				sr /= 10;
				c++;
			}

			if (c <= 6) {
				break;
			}

			else {
				cout << " the id that u have entered is invalid (it cannot go above 6 digits) " << endl << endl;
				cout << " enter the serial number again " << endl;
				cin >> id;

			}
		}

		list<weapon>::iterator it;
		bool found = false;

		for (it = weapons.begin();it != weapons.end();it++) {
			if (it->id == id) {
				found = true;
				break;

			}
		}


		if (!found) {
			cout << "The weapon was not found " << endl;
			display_menu(weapons);
		}

		else {
			cout << "Enter the new weapon name " << endl;
			cin.ignore();
			getline(cin, it->name);


			cout << "Enter the type of the weapon " << endl;
			cin.ignore();
			getline(cin, it->type);


			cout << "Enter the place of manufacture of the weapon " << endl;
			cin.ignore();
			getline(cin, it->manufacture);


			cout << "Enter the price of the weapon " << endl;
			cin >> it->price;

			cout << "The weapon record has been updated succesfully " << endl;

		}
	}



	void import_csv(list<weapon>& weapons,const string& filename) {


		ifstream ifile(filename);

		if (!ifile) {
			cout << "The file couldnt open " << endl;
			return;

		}

		ofstream ofile("TUPAC.bin", ios::binary | ios::app);

		if (!ofile) {
			cout << "The binary file couldnt open " << endl;
			return;

		}

		weapon w;
		string line;
		int i;
		string id_;
		string price_;
		string name_;
		string type_;
		string manufacture_;

		while (getline(ifile, line)) {
			i = 0;
			id_ = "";
			price_ = "";
			name_ = "";
			type_ = "";
			manufacture_ = "";

			//For ID
			while (i < line.length() && line[i] != ',') {
				id_ += line[i];
				i++;

			}
			w.id = stoi(id_);
			i++;


			//For Name
			while (i < line.length() && line[i] != ',') {
				name_ += line[i];
				i++;
			}
			w.name = name_;
			i++;

			//For manufacture

			while (i < line.length() && line[i] != ',') {
				manufacture_ += line[i];
				i++;

			}

			w.manufacture = manufacture_;
			i++;


			//For price
			while (i < line.length() && line[i] != ',') {
				price_ += line[i];
				i++;

			}

			w.price = stoi(price_);

			//write to binary file

			size_t name_len = w.name.length();
			size_t type_len = w.type.length();
			size_t manuf_len = w.manufacture.length();

			ofile.write(reinterpret_cast<const char*>(&w.id), sizeof(w.id));
			ofile.write(reinterpret_cast<const char*>(&w.price), sizeof(w.price));
			ofile.write(reinterpret_cast<const char*>(&name_len), sizeof(name_len));
			ofile.write(w.name.data(), name_len);
			ofile.write(reinterpret_cast<const char*>(&type_len), sizeof(type_len));
			ofile.write(w.type.data(), type_len);
			ofile.write(reinterpret_cast<const char*>(&manuf_len), sizeof(manuf_len));



		}


		cout << "The record has been successfully imported from the csv file " << endl;
		ifile.close();
		ofile.close();
	}




	void export_csv(list<weapon>& weapons,const string& filename) {
		ifstream ifile("TUPAC.bin", ios::binary);

		ofstream ofile(filename);

		if (!ofile) {
			cout << "The csv file didnt open " << endl;

		}

		weapon w;

		while (ifile.read((char*)&w, sizeof(weapon))) {

			ofile << w.id << "," << w.manufacture << "," << w.name << "," << w.price << "," << w.type << endl;

		}

		cout << "The data has been successfully exported " << endl;


		ifile.close();
		ofile.close();

	}





	void display_menu(list<weapon>& weapons) {
		char ch;
		do {
			cout << "---------------------------------------------" << endl;
			cout << "** to add a Weapon            [1] " << endl;
			cout << "** to update a Weapon         [2] " << endl;
			cout << "** to delete a Weapon         [3] " << endl;
			cout << "** to display all the Weapons [4]" << endl;
			cout << "** to import from csv         [5]" << endl;
			cout << "** to import from csv         [6]" << endl;
			cout << "-----------------------------------------------" << endl;
			int n;
			string filename;
			cin >> n;
			switch (n) {
			case 1:
				add_weapon(weapons);
				break;

			case 2:
				update_record(weapons);
				break;

			case 3:
				delete_weapon(weapons);
				break;

			case 4:
				display_weapons(weapons);
				break;

			case 5:
				cout << "Enter the csv file name to import to " << endl;
				cin >> filename;
				import_csv(weapons,filename);


			case 6:
				cout << "Enter the file name to export to " << endl;
				cin >> filename;
				export_csv(weapons,filename);

			default:
				cout << "-> you pressed the wrong option...it doesnt exist " << endl;
			}
			cout << "--------------------------------------------------------------------------" << endl;
			cout << "-> do you want the menu to appear again?....click Y | y if 'yes' and any button to terminate the program  " << endl;
			cin >> ch;
			if (ch != 'Y' && ch != 'y') {
				break;
			}
		} while (ch == 'Y' || ch == 'y');

	}


	




	int main(int argc,char*argv[]) {

		
		list<weapon>weapons;

		if (argc < 2) {
			cout << "you did not provide a command line argument " << endl;
			display_menu(weapons);
		}


		else {
			string line = argv[1];

			if (line == "load") {
				cout << "The loading process has started " << endl;
				load_from_file(weapons);
				cout << "The data has been loaded! " << endl;
			}

			else if (line == "display") {

				display_weapons(weapons);

			}

			else if (line == "menu") {
				display_menu(weapons);
			}

			else if (line == "add") {
				add_weapon(weapons);
			}


			else if (line == "update") {
				update_record(weapons);
			}

			else if (line == "delete") {
				delete_weapon(weapons);
			}

			else if(line=="save"){
				cout << "The saving process has started " << endl;
				save_to_file(weapons);

				cout << "the saving process has ended " << endl;
			}

			else if (line == "import") {
				if (argc < 3) {
					cout << "Specifiy the csv file to import " << endl;

				}

				else {
					string filename = argv[2];
					import_csv(weapons, filename);
				}
			}

			else if (line == "export") {
				if (argc < 3) {
					cout << "Specifiy the csv file to export " << endl;
				}

				else {
					string filename = argv[2];
					export_csv(weapons, filename);
				}
			}

			else {
				cout << "the prompt is invalid " << endl;
			}

		}


		cout << "  Weapon Market   \n ";
		cout << "--------------------------------" << endl;
		load_from_file(weapons);
		display_menu(weapons);
		save_to_file(weapons);




	}