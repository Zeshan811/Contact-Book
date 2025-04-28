#pragma once
#pragma once
#pragma once
#pragma once
#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB
#include "Address.h"
class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	std::string full_name;
	int id;
	Address* address;
public:
	void setfirstname(std::string s);
	void setlastname(std::string s);
	void setmobileno(std::string s);
	void setemail(std::string s);
	void setaddress(Address* add);
	void setId(int n);
	int getId();
	std::string getlname();
	std::string getmobileno();
	std::string getemail();
	std::string getfname();
	std::string getfullname();
	Address* getaddress();
	bool equals(Contact& contact);
	Contact* copy_contact();
	Contact() :first_name(""), last_name(""), address(NULL), email_address(""), mobile_number(""), id(0) {}
	Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address, int n);
	void display();
};


