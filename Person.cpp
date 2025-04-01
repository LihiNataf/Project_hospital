#pragma warning(disable: 4996)
#include <iostream>
#include "Person.h"
using namespace std;

void Person::print() const
{
	cout << "name is: " << name << ", ";
}
ostream& operator<<(ostream& os, const Person& other)
{
	os << "name is: " << other.name << ", ";
	return os;
}

Person::Person(const string& name)
{   
	setName(name);
}


Person::Person(const Person& other)
{
	name = other.name;
}


Person::~Person()
{
}

