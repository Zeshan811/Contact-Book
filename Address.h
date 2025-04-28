#pragma once
#pragma once
#include <iostream>
#include <string>
class Address
{
private:
	std::string house;
	std::string street;
	std::string city;
	std::string country;
public:
	bool equals(const Address& address);
	void print_address();
	Address copy_address();
	void sethouse(std::string);
	void setstreet(std::string);
	void setcity(std::string);
	void setcountry(std::string);
	std::string getcountry();
	std::string getcity();
	std::string getstreet();
	std::string gethouse();
	Address(std::string house, std::string street, std::string city, std::string country);
	Address() {}
	Address(const Address& o);
};