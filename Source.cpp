#include<iostream>	
#include<string>
#include"Contact.h"
#include"Address.h"
#include"ContactBook.h"
#include"Group.h";
#include<cstdlib>
using namespace std;
int c = 0;
bool check = false;
ContactBook scnerio1();
void scenerio2(ContactBook& b);
void scnerio3();
Address createAddress();
void menudriven();
int main()
{
	bool exit = true;
	ContactBook book;
	int choice;
	cout << "Enter 1 for scnerio 1" << endl << "Enter 2 for menudriven " << endl << "Enter 3 for scnerio 2 "
		<< endl << "Enter 4 for scnerio  3 and 4 " << endl << "Enter any other number to exit" << endl;
	while (exit == true)
	{
		cout << "Enter your choice" << endl;
		while (!(cin >> choice))
		{
			cout << "Invalid input. Please enter a valid integer" << endl;
			cin.clear();
			cin.ignore();		
		}
		system("cls");
		if (choice == 1)
		{
			system("cls");
			book = scnerio1();

		}
		if (choice == 2)
		{
			system("cls");
			menudriven();
		}
		else if (choice == 3)
		{
			system("cls");
			scenerio2(book);
		}
		else if (choice == 4)
		{
			system("cls");
			scnerio3();
		}
		else if (choice == 5) 
		{
			exit = false;
		}
		else
		{
			cout << "invalid input" << endl;
			exit = false;
		}
	}
	system("pause");
	return 0;
}
Address createAddress()
{
	string house, street, city, country;
	cout << "Enter house ";
	cin.ignore();
	getline(cin, house);
	cout << "Enter street ";
	getline(cin, street);
	cout << "Enter city ";
	getline(cin, city);
	cout << "Enter country ";
	getline(cin, country);
	return Address(house, street, city, country);
}
void scenerio2(ContactBook& book)
{
	cout << "Initial count of contacts " << book.total_contacts() << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "Enter details for Contact " << 5 + i + 1 << endl;
		Contact contact;
		cout << "Enter first name " << endl;
		string fi, li, mo, em;
		cin >> fi;
		contact.setfirstname(fi);
		cout << "Enter last name " << endl;
		cin >> li;
		contact.setlastname(li);
		cout << "Enter mobile number ";
		cin >> mo;
		contact.setmobileno(mo);
		cout << "Enter email address ";
		cin >> em;
		contact.setemail(em);
		Address a = createAddress();
		contact.setaddress(&a);
		book.add_contact(contact);
	}
	cout << "Total number of contacts " << book.total_contacts() << endl;
}
void scnerio3()
{
	// Scenario 3: Add 5 contacts with 1 duplicate display all the contacts sorted
	int s = 5;
	ContactBook book(s);
	cout << "Adding 5 contacts with 1 duplicate" << endl;
	for (int i = 0; i < s; i++)
	{
		Contact contact;
		cout << "Enter details for Contact " << i + 1 << endl;
		cout << "Enter first name ";
		string fi, li, mo, em;
		cin >> fi;
		contact.setfirstname(fi);
		cout << "Enter last name ";
		cin >> li;
		contact.setlastname(li);
		cout << "Enter mobile number ";
		cin >> mo;
		contact.setmobileno(mo);
		cout << "Enter email address ";
		cin >> em;
		contact.setemail(em);
		Address* a = new Address(createAddress());
		contact.setaddress(a);
		book.add_contact(contact);
	}
	cout << "Contacts sorted by First Name" << endl;
	book.print_contacts_sorted("f");
	cout << endl << "Running duplicate merge" << endl;
	book.merge_duplicates();
	cout << endl << "Contacts after duplicate merge" << endl;
	book.print_contacts_sorted("f");
	//	 Scenario 4  Show the working of store contacts and load cntact
	cout << endl << "Storing contacts" << endl;
	book.save_to_file("contacts.txt");
	ContactBook load;
	cout << endl << "Loading contacts" << endl;
	load.load_from_file("contacts.txt");
	cout << endl << "Loaded contacts" << endl;
	load.print_contacts_sorted("f");
}
ContactBook scnerio1()
{
	int s = 5;
	ContactBook book(s);
	for (int i = 0; i < s; i++)
	{
		cout << "Enter details for Contact " << i + 1 << endl;
		Contact contact;
		cout << "Enter first name " << endl;
		string fi, li, mo, em;
		cin >> fi;
		contact.setfirstname(fi);
		cout << "Enter last name " << endl;
		cin >> li;
		contact.setlastname(li);
		cout << "Enter mobile number ";
		cin >> mo;
		contact.setmobileno(mo);
		cout << "Enter email address ";
		cin >> em;
		contact.setemail(em);
		Address* a = new Address(createAddress());
		contact.setaddress(a);
		book.add_contact(contact);
	}
	book.print_contacts_sorted("f");
	cout << "Unsorted contacts" << endl;
	book.book_display();
	return book;
}

void menudriven()
{
	Group grp("");
	Address* sd;
	ContactBook book;
	int choice;
	bool o = true;
	do
	{
		choice = 0;
		cout << "Enter 1 to create contact list(size)" << endl;
		cout << "Enter 2 for add contact" << endl;
		cout << "Enter 3 for merge duplicate" << endl;
		cout << "Enter 4 for store to file" << endl;
		cout << "Enter 5 for load from file" << endl;
		cout << "Enter 6 print contact sorted" << endl;
		cout << "Enter 7 print contacts" << endl;
		cout << "Enter 8 to search contacts" << endl;
		cout << "Enter 9 display count" << endl;
		cout << "Enter 10 to create group" << endl;
		cout << "Enter 11 to add contact in group" << endl;
		cout << "Enter 12 to delete contact from group" << endl;
		cout << "Enter 13 to view group" << endl;
		cout << "Enter 14 to show search history" << endl;
		cout << "Enter 15 to update contact" << endl;
		cout << "Enter 16 to delete contact" << endl;
		cout << "Enter 17 to exit" << endl;
		cout << "Enter your choice" << endl;
		while (!(cin >> choice))
		{
			cout << "Invalid input. Please enter a valid integer" << endl;
			cin.clear();
			cin.ignore();

		}
		system("cls");
		switch (choice)
		{

		case 1:
		{
			cout << "enter size" << endl;
			int size;
			cin >> size;
			cin.ignore();
			ContactBook book2(size);
			book = book2;
			break;
		}
		case 2:
		{
			Contact con;
			int cou = ++c;
			cout << "Enter information related to address" << endl;
			string c, co, ho, stre;
			cout << "enter street" << endl;
			cin.ignore();
			getline(cin, stre);
			cout << "enter house" << endl;
			getline(cin, ho);
			cout << "enter city" << endl;
			getline(cin, c);
			cout << "enter country" << endl;
			getline(cin, co);
			sd = new Address(ho, stre, c, co);
			cout << "Enter person information " << endl;
			string f, l, n, e;
			cout << "enter first name" << endl;
			getline(cin, f);
			cout << "enter last name" << endl;
			getline(cin, l);
			cout << "enter mobile number" << endl;
			getline(cin, n);
			con.setmobileno(n);
			cin.ignore();
			cout << "enter  email" << endl;
			getline(cin, e);
			con.setfirstname(f);
			con.setlastname(l);
			con.setId(cou);
			con.setemail(e);
			con.setaddress(sd);
			book.add_contact(con);
			check = true;
			break;
		}
		case 3:
		{
			book.merge_duplicates();
			break;

		}
		case 4:
		{
			book.save_to_file("contacts.txt");
			break;
		}
		case 5:
		{
			book.load_from_file("contacts.txt");
			break;
		}
		case 6:
		{
			string s;
			cout << "enter f for sort by first name and enter l for sort by last name" << endl;
			cin >> s;
			book.print_contacts_sorted(s);
			break;
		}
		case 7:
		{
			book.book_display();
			break;
		}
		case 8:
		{
			//basic search
			/*
			string fi, ph, la;
			cout << "by searching first name and last name enter first name " << endl;
			cin >> fi;
			cout << "enter last name" << endl;
			cin >> la;
			Contact *oc=book.search_name(fi,la);
			if (oc != nullptr)
			{
				oc->display();
			}
			cout << "enter phone number to search" << endl;
			cin >> ph;
			Contact *op=book.search_phone(ph);
			if (op != nullptr)
			{
				op->display();
			}
			cout << "enter address to search" << endl;
			cout << "Enter information related to address" << endl;
			string c, co, ho, str;
			cout << "enter street" << endl;
			cin.ignore();
			getline(cin, str);
			cout << "enter house" << endl;
			getline(cin, ho);
			cout << "enter city" << endl;
			getline(cin, c);
			cout << "enter country" << endl;
			getline(cin, co);
			Address add(ho, str, c, co);
			Contact* oi=book.search_address(add);
			if (oi != nullptr)
			{
				oi->display();
			}
		*/
			string fn;
			cout << "Enter any letter of name/phone number/full name: ";
			cin.ignore();
			getline(cin, fn);
			Contact* oj = NULL;
			oj = book.search_contact(fn);
			if (oj != nullptr)
			{
				oj->display();
			}
			break;
		}
		case 9:
		{
			cout << book.total_contacts() << endl;
			break;
		}
		case 10:
		{
			string gn;
			cout << "Enter group name: ";
			cin.ignore();
			getline(cin, gn);
			grp.setName(gn);
			break;
		}
		case 11:
		{
			int n;
			cout << "Enter id of the contact to be added:(id is contact index) ";
			cin >> n;
			if (check == true)
			{
				grp.addContact(n);
				break;
			}
			else
			{
				cout << "add contact first" << endl;
			}
		}
		case 12:
		{
			int n;
			cout << "Enter id of the contact to be added: ";
			cin >> n;
			grp.deleteContact(n);
			break;
		}
		case 13:
		{
			string p;
			int* list = grp.getlist();
			p = grp.getname();
			for (int i = 0; i < grp.gettotal(); i++)
			{
				cout << p[i] << endl;
				Contact* c = book.gp(list[i]);
				c->display();

			}
			break;

		}
		case 14:
		{
			book.search();
			break;
		}
		case 15:
		{
			int y;
			cout << "enter index" << endl;
			cin >> y;
			book.update(y);
			break;
		}
		case 16:
		{
			cout << "enter index" << endl;
			int n;
			cin >> n;
			book.deletecontact(n);
			break;
		}
		case 17:
		{
			cout << "program exit" << endl;
			o = false;
			break;
		}
		default:
		{
			cout << "Invalid input. Please enter a valid integer" << endl;
			break;
		}
		}
	} while (o == true);
}