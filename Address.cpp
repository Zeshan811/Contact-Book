#include "Address.h"
/*
*	Implement a constructor that initializes all the address parts
*
*/
Address::Address(std::string hou, std::string str, std::string ci, std::string cou)
{
	house = hou;
	street = str;
	city = ci;
	country = cou;
}
/*
*	Implement getter/setters for all the member variables of Address. Also declare them in the Address.h header file
*
*/
void Address::setcity(std::string c)
{
	city = c;
}
void Address::setcountry(std::string co)
{
	country = co;
}
void Address::sethouse(std::string h)
{
	house = h;
}
void Address::setstreet(std::string s)
{
	street = s;
}
std::string Address::getcountry()
{
	return country;
}

std::string Address::getstreet()
{
	return street;
}
std::string Address::gethouse()
{
	return house;
}
std::string Address::getcity()
{
	return city;
}
/*
*	Implement the equals function that takes an Address object and checks if it is equal to
*	current object refered by (this pointer)
*	Two addresses are equal if all the attributes of addresses are equal
*/
bool Address::equals(const Address& address)
{
	/*
	* Todo
	*/
	if (this->city == address.city && this->country == address.country && this->house == address.house && this->street == address.street)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Address::print_address()
{
	/*
	*	Print address on one line as
	*	House, Street, City, Country
	*/
	std::cout << "house is: " << house << "\n street is: " << street << "\n city is: " << city << "\n country is: " << country << std::endl;
	std::cout << "-----------------------------------------" << std::endl;

}

Address Address::copy_address()
{

	return *this;
	/*
		return a copy of this
	*/
}

Address::Address(const Address& o)
{
	this->city = o.city;
	this->country = o.country;
	this->house = o.house;
	this->street = o.street;
}