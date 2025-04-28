#pragma once
#pragma once
#include "Address.h"
#include "Contact.h"
#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB
class ContactBook
{
private:
	Contact* contact_list; // array of contacts
	int size_of_list;   // storage limit
	int contacts_count = 0;     // total contacts currently stored, next contact will be 
	// stored at this count plus 1 index
public:
	void update(int n);
	Contact* search_name(std::string first_name, std::string last_name);
	Contact* gp(int n);
	Contact* search_address(const Address& address);
	void book_display();
	void deletecontact(int c);
	void add_contact(const Contact& contact);
	Contact* search_phone(std::string phone);
	int total_contacts();
	/*Contact* search_contact(std::string first_name, std::string last_name);
	Contact* search_contact(std::string phone);
	Contact* search_contact(const Address& address);*/
	int cou = 0;
	void search();
	std::string s[100];
	Contact* search_contact(std::string str);
	ContactBook(int size);
	Contact* getlist();
	ContactBook() :contacts_count(0), contact_list(NULL), size_of_list(0) {}
	void print_contacts_sorted(std::string choice); // Only two choices first_name or last_name
	void merge_duplicates(); // Implement this function that finds and merges all the duplicates
	// Duplicate means exact equal, this means if
/*
*  This function loads contacts from the given file (see details in ContactsBook.cpp)
*/
	void load_from_file(std::string file_name);
	void save_to_file(std::string file_name);
private:
	bool full();
	void resize_list();
	void sort_contacts_list(Contact* contacts_list, std::string choice);
};
