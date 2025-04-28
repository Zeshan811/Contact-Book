#include "Contact.h"
#include<string>
/*
*	Implement a constructor that initializes all the Contact parts, including address. Call the setter to set values
*	as they have the logic to check correct input
*	Declaration is given in Contact.h
*/
Contact::Contact(std::string first, std::string last, std::string number, std::string email, Address* add, int n) :first_name(first), last_name(last),
mobile_number(number), email_address(email), address(add), id(n) {
	char arr[10];
	char arr1[10];
	char arr2[20];
	int i = 0;
	strcpy_s(arr, first_name.c_str());
	strcpy_s(arr1, last_name.c_str());
	std::string s1(arr);
	std::string s2(arr1);
	std::string temp = s1 + ' ' + s2;
	full_name = temp;

}
/*
*	Implement getter/setters for all the member variables of Contact. Also declare them in the Contact.h header file
*	In each setter, do not set value if string is empty ("" 0 size).
*   Check in phone number setter, Phone number must be 11 digits
*/
void Contact::setaddress(Address* a)
{
	address = a;
}
void Contact::setfirstname(std::string f)
{
	if (f == "")
	{
		std::cout << "Enter again " << std::endl;
		std::string p;
		std::cin >> p;
		first_name = p;
		return;
	}
	else
	{
		first_name = f;
	}
}
void Contact::setlastname(std::string l)
{
	if (l == "")
	{
		std::cout << "Enter again " << std::endl;
		std::string p;
		std::cin >> p;
		last_name = p;

		return;
	}
	else
	{
		last_name = l;
	}
}
std::string Contact::getfullname()
{
	return full_name;
}
void Contact::setmobileno(std::string m)
{
	int l = m.length();
	if (l == 11)
	{
		mobile_number = m;
		std::cout << "Mobile number is 11 digit" << std::endl;
	}
	else
	{
		std::cout << "Number is not 11 digit" << std::endl;
		std::cout << "Enter again " << std::endl;
		std::string p;
		std::cin >> p;
		mobile_number = p;
	}

}
void Contact::setemail(std::string e)
{
	if (e == "")
	{
		std::cout << "Enter again " << std::endl;
		std::string p;
		std::cin >> p;
		email_address = p;
		return;
	}
	else
	{

		email_address = e;
	}
}
Address* Contact::getaddress()
{
	return address;
}
std::string Contact::getemail()
{
	return email_address;
}
std::string Contact::getfname()
{
	return first_name;
}
std::string Contact::getlname()
{
	return last_name;
}
std::string Contact::getmobileno()
{
	return mobile_number;
}
/*
*	Implement the equals function(as declared in header file) that takes a
*   Contact object and checks if it is equal to current object refered by (this pointer).
*   Compare all the attributes.
*   For comparing address of contact you can call the equals function of the Address object;
*   For example: this.address.equals
*/

bool Contact::equals(Contact& c)
{
	if (this->first_name == c.first_name && this->last_name == c.last_name && this->email_address == c.email_address &&
		this->mobile_number == c.mobile_number && this->address->equals(*c.address) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Contact* Contact::copy_contact()
{
	address = new Address;
	this->address = address;
	return this;
	/*
		Return a new object(deep copy of "this"[due to Address pointer, which should also be copied])
	*/
}
void Contact::display()
{
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "Address: ";
	this->getaddress()->print_address();
	std::cout << "first name: " << first_name << std::endl;
	std::cout << "last name: " << last_name << std::endl;
	std::cout << "mobile no: " << mobile_number << std::endl;
	std::cout << "email: " << email_address << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
}
void Contact::setId(int n)
{
	id = n;
}
int Contact::getId()
{
	return id;
}