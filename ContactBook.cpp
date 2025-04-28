#include"ContactBook.h"
#include<iostream>
#include<fstream>
#include<string>
void ContactBook::add_contact(const Contact& contact)
{
	/*
		- Check if the list is full, if it is full call the resize function
		- If list is not full add the contact to the end of the array
		- (end means the place where last contact was inserted)
		- At start it will be 0th index as no contact has been inserted before so
		- count is zero (contacts_count member)
		- Increment the count
		- As inserted successfully, return 1
	*/
	if (size_of_list == 0)
	{
		size_of_list = 1;
		std::cout << "creating an default array of size 1" << std::endl;
		contact_list = new Contact[size_of_list];
		contact_list[contacts_count++] = contact;
		std::cout << "contact inserted" << std::endl;

	}
	else if (contacts_count == size_of_list)
	{
		resize_list();
		contact_list[contacts_count++] = contact;
		std::cout << "contact inserted" << std::endl;
		return;
	}
	else
	{

		contact_list[contacts_count++] = contact;
		std::cout << "contact inserted" << std::endl;

	}
}

int ContactBook::total_contacts()
{
	return contacts_count;
	/*
	*	Return the total contacts currently stored
	*/

	/*
	*	Remove this return -1; before writing your code
	*/
	//return -1;
}

bool ContactBook::full()
{
	/*
	* Return true if list is full, false otherwise
	*/

	/*
	*	Remove this return false; before writing your code
	*/
	if (contacts_count == size_of_list)
	{
		return true;
	}
	else
	{
		return false;
	}
}	/*
	*	Here you will resize the contact list, see example code given in lab manual to see how to resize arrays
	*	You will allocate a temporary new array of double the current size and copy the contacts from
	*       previous array to this array one by one, get the copy of each contact using copy_contact
	*       function of Contact class
	*	Delete the previous array
	*	Assign the new temporary array to the contacts_list pointer
	*	Updated the this->size_of_contacts with new size
	*/

void ContactBook::resize_list()
{
	int new_size = size_of_list * 2;
	Contact* new_contacts_list = new Contact[new_size];
	for (int i = 0; i < size_of_list; i++)
	{
		new_contacts_list[i] = contact_list[i];
	}
	delete[] contact_list;
	contact_list = new_contacts_list;
	size_of_list = new_size;
	std::cout << "List resized to " << new_size << std::endl;
}
Contact* ContactBook::search_name(std::string first_name, std::string last_name)
{
	/*
	*	In all search functions perform the searching according the given parameter and return a copy of the contact using copy func
	*	Remove this return nullptr; before writing your code
	*/
	for (int i = 0; i < contacts_count; i++)
	{
		if (contact_list[i].getfname() == first_name && contact_list[i].getlname() == last_name)
		{
			std::cout << "found " << std::endl;
			return &contact_list[i];

		}
	}
	std::cout << "not found" << std::endl;
	return nullptr;
}
Contact* ContactBook::search_phone(std::string phone)
{
	for (int i = 0; i < contacts_count; i++)
	{
		if (contact_list[i].getmobileno() == phone)
		{
			std::cout << "found " << std::endl;
			return &contact_list[i];

		}
	}
	std::cout << "not found" << std::endl;
	return nullptr;
	/*
	*	Remove this return nullptr; before writing your code
	*/
}
Contact* ContactBook::search_address(const Address& address)
{
	for (int i = 0; i < contacts_count; i++)
	{
		Address* a = contact_list[i].getaddress();
		if (a->equals(address))
		{
			std::cout << "found " << std::endl;
			return &contact_list[i];

		}
	}
	std::cout << "not found" << std::endl;
	return nullptr;
	/*
	*	Remove this return nullptr; before writing your code
	*/
	//return nullptr;
}
Contact* ContactBook::gp(int n)
{
	for (int i = 0; i < contacts_count; i++)
	{
		if (contact_list[i].getId() == n)
		{
			return &contact_list[i];
		}
	}
	std::cout << "Not found" << std::endl;
	return NULL;
}
void ContactBook::deletecontact(int c)
{
	if (c >0 && c < contacts_count) 
	{
		for (int i = c - 1; i < contacts_count - 1; i++) 
		{
			contact_list[i] = contact_list[i + 1];
		}
		contacts_count--;
		std::cout << "contact deleted" << std::endl;
	}
	else if(c==contacts_count)
	{
		contacts_count--;
		std::cout << "contact deleted" << std::endl;
	}
	else
	{
		std::cout << "valid not index" << std::endl;

	}
}
Contact* ContactBook::search_contact(std::string str)
{
	s[cou] = str;
	cou++;
	int j = str.length();
	for (int i = 0; i < contacts_count; i++)
	{
		    std::string d = contact_list[i].getfname();
	    	int l = 0;	
	     	while (l < j)
			{
				for (int k = 0; k < d.length(); k++)
				{
					if (str[l] == d[k])
					{
						std::cout << "found " << std::endl;
						return &contact_list[i];

					}
				}
				l++;
	        }
	}
	for (int i = 0; i < contacts_count; i++)
	{
		std::string d = contact_list[i].getlname();
		int l = 0;
		while (l < j)
		{
			for (int k = 0; k < d.length(); k++)
			{
				if (str[l] == d[k])
				{
					std::cout << "found " << std::endl;
					return &contact_list[i];

				}
			}
			l++;
		}
	}
	for (int i = 0; i < contacts_count; i++)
	{
		if( contact_list[i].getmobileno()==str)
		{
			std::cout << "found " << std::endl;

			return &contact_list[i];

		}
	}
	for (int i = 0; i < contacts_count; i++)
	{
		if (contact_list[i].getfullname() == str)
		{
			std::cout << "found " << std::endl;
			return &contact_list[i];

		}
	}
	std::cout << "not found" << std::endl;
	return nullptr;
}
void ContactBook::search()
{
	if (cou == 0)
	{
		std::cout << "Search history is empty" << std::endl;
		return;
	}
	std::cout << "Search history:" << std::endl;
	for (int i = 0; i < cou; i++)
	{
		std::cout << s[i] << std::endl;
	}

}
ContactBook::ContactBook(int size)
{
	size_of_list = size;
	contact_list = new Contact[size_of_list];
	/*
	*	Initialize the contacts_list array, also initialize the size and count members accordingly
	*/
}

void ContactBook::print_contacts_sorted(std::string choice)
{

	/*
	*	Create a copy of this->contacts_list array here (do it by creating a new function that returns copy)
	*	Call the sort function sort_contacts_list to sort the newly created copy
	*	This copy is created to avoid changing the original insertion order of contact list
	*	Then print the contacts in following format:
	*	[First Name] [Last Name] [Mobile] [Email]
	*	Call the address print function to print address on next line
	*/
	Contact* cpy = new Contact[contacts_count];
	for (int i = 0; i < contacts_count; i++)
	{
		cpy[i] = contact_list[i];
	}
	if (choice == "f")
	{
		sort_contacts_list(cpy, "f");
	}
	else if (choice == "l")
	{
		sort_contacts_list(cpy, "l");
	}
	else
	{
		std::cout << "Invalid choice for sorting contacts." << std::endl;
		return;
	}
	for (int i = 0; i < contacts_count; i++)
	{
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "first name\tlast name\tmobile no\temail" << std::endl;
		std::cout << cpy[i].getfname() << "\t" << cpy[i].getlname() << "\t"
			<< cpy[i].getmobileno() << "\t" << cpy[i].getemail() << std::endl;
		Address* a = cpy[i].getaddress();
		a->print_address();
	}
	delete[]cpy;
}
void ContactBook::sort_contacts_list(Contact* contacts_list, std::string choice)
{

	/*
		You should not duplicate the code to sort based on choices
		Follow the strategy provided in manual/tutorial to avoid duplicating the code (Section B & E only)
		Sort by the fist letter of first name or last name as given in choice
	*/
	if (choice == "f")
	{
		for (int i = 0; i < contacts_count - 1; i++)
		{
			for (int j = i + 1; j < contacts_count; j++)
			{
				std::string g = contacts_list[i].getfname();
				std::string k = contacts_list[j].getfname();
				if (g > k)
				{
					Contact temp = contacts_list[i];
					contacts_list[i] = contacts_list[j];
					contacts_list[j] = temp;
				}
			}
		}
		std::cout << "Contacts sorted by first name." << std::endl;
	}
	else if (choice == "l")
	{
		{
			for (int i = 0; i < contacts_count - 1; i++)
			{
				for (int j = i + 1; j < contacts_count; j++)
				{
					std::string g = contacts_list[i].getlname();
					std::string k = contacts_list[j].getlname();
					if (g > k)
					{
						Contact temp = contacts_list[i];
						contacts_list[i] = contacts_list[j];
						contacts_list[j] = temp;
					}
				}
			}
			std::cout << "Contacts sorted by last name" << std::endl;
		}
	}
	else
	{
		std::cout << "Invalid choice for sorting contacts." << std::endl;
	}
}
void ContactBook::merge_duplicates()
{
	// Implement this function that finds and merges all the duplicates
	// Duplicate means exact equal
	// If there are three copies of a Contact, then only one should remain
	// For example: If total contact are 10, and 2 contacts are same, after removing duplicates
	// 9 contacts will be left; and the this->contacts_count of list will 9
	// At the end display contacts merged, and count of merged contacts
	for (int i = 0; i < contacts_count; i++)
	{
		for (int j = i + 1; j < contacts_count; j++)
		{
			if (contact_list[i].equals(contact_list[j]))
			{
				for (int k = j; k < contacts_count - 1; k++)
				{
					contact_list[k] = contact_list[k + 1];
				}
				contacts_count--;
				j--;
			}
		}
	}
	std::cout << "Duplicate merged" << std::endl;

}
void ContactBook::update(int n)
{
	std::string f;
	std::cout << "Enter first name" << std::endl;
	std::cin >> f;
	contact_list[n - 1].setfirstname(f);
	std::string l;
	std::cout << "Enter last name" << std::endl;
	std::cin >> l;
	contact_list[n - 1].setlastname(l);
	std::string v;
	std::cout << "Enter  no" << std::endl;
	std::cin >> v;
	contact_list[n - 1].setmobileno(v);
	std::string e;
	std::cout << "Enter  email" << std::endl;
	std::cin >> e;
	contact_list[n - 1].setemail(e);
}
void ContactBook::load_from_file(std::string file_name)
{
	/*
	//	*	Read contacts back from file in the same format
	//	*	Read the contacts_count, and run a loop for this contacts_count and read the
	//	*	contacts in the same format as you stored
	//	*	Add them to contact book (this.add_contact function can be used)
	//	*	Finally, close the file
	//	*/
	std::ifstream infile;
	infile.open(file_name);
	int num;
	int n;
	infile >> num;
	for (int i = 0; i < num; i++)
	{
		std::string first, last, number, email;
		std::string hou, str, ci, co;
		infile >> first >> last >> number >> email;
		infile >> hou >> str >> ci >> co >> n;
		Address* add = new Address(hou, str, ci, co);
		Contact contact(first, last, number, email, add, n);
		add_contact(contact);
	}
	infile.close();
}
void ContactBook::save_to_file(std::string file_name)
{
	/*
//	*	In this function you will store all the contacts to a file
//	*	On first line store contacts_count
//	*	On next lines store contacts in the following format:
//	*       2 lines for each contact
//	*       On oneline write contact attributes(except address) in comma separated format. On second line
//	*	store address atributes in the same format
//	*	first_name,last_name,mobile_number,email_address
//	*	house,street,city,country
//	*	Close the file
//	*/
	std::ofstream outfile;
	outfile.open(file_name);
	outfile << contacts_count << std::endl;
	for (int i = 0; i < contacts_count; i++)
	{
		outfile << contact_list[i].getfname() << " " << contact_list[i].getlname() << " "
			<< contact_list[i].getmobileno() << " " << contact_list[i].getemail() << std::endl;
		Address* a = contact_list[i].getaddress();
		outfile << a->gethouse() << " " << a->getstreet() << " " << a->getcity() << " " << a->getcountry() << std::endl;
	}
	std::cout << "data enter in file" << std::endl;
	outfile.close();
}
void ContactBook::book_display()
{
	for (int i = 0; i < contacts_count; i++)
	{
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "first name\tlast name\tmobile no\temail" << std::endl;
		std::cout << contact_list[i].getfname() << "\t" << contact_list[i].getlname() << "\t"
			<< contact_list[i].getmobileno() << "\t" << contact_list[i].getemail() << std::endl;
		Address* a = contact_list[i].getaddress();
		a->print_address();
	}
}
Contact* ContactBook::getlist()
{
	return contact_list;
}