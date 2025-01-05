//
//
//#include<iostream>
//#include<list>
//#include<fstream>
//#include<string>
//
//
//using namespace std;
//
//struct weapon {
//
//	int id;
//	int price;
//	string name;
//	string manufacture;
//	string type;
//
//};
//
//void display_menu();
//
//
//void add_weapon(list<weapon>& weapons) {
//
//	weapon new_w;
//	cout << "enter the id of the new weapon " << endl;
//	cin >> new_w.id;
//
//	for (list<weapon>::iterator it = weapons.begin();it != weapons.end();it++) {
//		if (it->id == new_w.id) {
//			cout << "A duplicate ID already exists " << endl;
//			return;
//		}
//	}
//
//	cout << "Enter the name of the weapon " << endl;
//	cin.ignore();
//	getline(cin, new_w.name);
//
//	cout << "Enter the type of the weapon " << endl;
//	cin.ignore();
//	getline(cin, new_w.type);
//
//
//	cout << "Enter the place of manufacture of the weapon " << endl;
//	cin.ignore();
//	getline(cin, new_w.manufacture);
//
//
//	cout << "Enter the price of the weapon " << endl;
//	cin.ignore();
//	cin >> new_w.price;
//
//
//	weapons.push_back(new_w);
//	cout << "The weapon has been added successfully " << endl;
//
//
//
//
//}
//
//
//void delete_weapon(list<weapon>& weapons) {
//	int id;
//	cout << "Enter the id of weapon that i have to delete " << endl;
//	cin >> id;
//
//	bool found = false;
//	list<weapon>::iterator it;
//	for (it = weapons.begin();it != weapons.end();it++) {
//
//		if (it->id == id) {
//			cout << "The id has been found " << endl;
//			found = true;
//			break;
//
//		}
//	}
//
//	if (!found) {
//
//		cout << "the weapon was not found! " << endl;
//		display_menu();
//		
//	}
//
//	if (found) {
//		weapons.erase(it);
//		cout << "The weapon record has been deleted " << endl;
//	}
//}
//
//
//void update_record(list<weapon>&weapons) {
//	int id;
//	cout << "Enter the id of the weapon that you want to update " << endl;
//	cin >> id;
//	list<weapon>::iterator it;
//	bool found = false;
//
//	for (it = weapons.begin();it != weapons.end();it++) {
//		if (it->id == id) {
//			found = true;
//			break;
//
//		}
//	}
//
//
//	if (!found) {
//		cout << "The weapon was not found " << endl;
//		display_menu();
//	}
//
//	else {
//		cout << "Enter the new weapon name " << endl;
//		cin.ignore();
//		getline(cin, it->name);
//
//
//		cout << "Enter the type of the weapon " << endl;
//		cin.ignore();
//		getline(cin, it->type);
//
//
//		cout << "Enter the place of manufacture of the weapon " << endl;
//		cin.ignore();
//		getline(cin, it->manufacture);
//
//
//		cout << "Enter the price of the weapon " << endl;
//		cin >> it->price;
//
//		cout << "The weapon record has been updated succesfully " << endl;
//
//	}
//}
//
//
//
//
//
//
//int main() {
//
//
//	cout << " ]--,-'->  Kohat Weapon Market  <-'-,--[  \n ";
//
//	
//	
//
//}

int main() {

	dnode* nn;
	nn = new dnode;
	nn.val = val;
	nn.next = this.H;
	nn.prev = this.h.prev;
	h.prev.next = nn;
	h.prev = nn;



	nnode.prev = H;
	nnode.next = h.next;
	h.next.prev = nnode;
	h.next = nnode;



	node* temp = head;
	while (temp != nullptr) {
		node* temp2 = temp.next;

		while (temp2 != nullptr) {
			if (temp.val > temp2.val) {
				swap(temp.val, temp2.val);
			}
			temp2 = temp2.val;

		}

		temp1 = temp1.next;
	}








}