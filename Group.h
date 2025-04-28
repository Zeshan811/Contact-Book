#pragma once
#pragma once
#ifndef GROUP_H
#define GROUP_H
#include<iostream>
using namespace std;
class Group
{
private:
	int id;
	string name;
	int total;
	int* list;
public:
	Group(string n);
	Group() {}
	void addContact(int n);
	void deleteContact(int n);
	void setName(string n);
	int* getlist();
	int gettotal();
	std::string getname();
};
#endif // !GROUP_H
