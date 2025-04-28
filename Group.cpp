#include "Group.h"
Group::Group(string n)
{
    name = n;
    list = NULL;
    total = 0;
}
void Group::addContact(int n)
{
    int* arr = new int[total + 1];
    for (int i = 0; i < total; i++)
    {
        arr[i] = list[i];
    }
    arr[total] = n;
    delete[] list;
    list = new int[++total];
    for (int i = 0; i < total; i++)
    {
        list[i] = arr[i];
    }
    delete[] arr;
    std::cout << "contact added" << std::endl;
}
void Group::deleteContact(int n)
{
    int* arr = new int[total - 1];
    for (int i = 0, j = 0; i < total; i++)
    {
        if (list[i] != n)
        {
            arr[j++] = list[i];
        }
    }
    delete[] list;
    list = new int[--total];
    for (int i = 0; i < total; i++)
    {
        list[i] = arr[i];
    }
    delete[] arr;
    std::cout << "contact deleted" << std::endl;
}
void Group::setName(string n)
{
    name = n;
    std::cout << "name is set" << std::endl;
}
int* Group::getlist()
{
    return list;
}
int Group::gettotal()
{
    return total;
}
std::string Group::getname()
{
    return name;
}