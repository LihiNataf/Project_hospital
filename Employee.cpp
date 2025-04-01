#pragma warning(disable: 4996)
#include <iostream>
#include "Employee.h"
using namespace std;

int Employee::counter = 0;

void Employee::print() const
{
	Person::print();
	cout << "tag is:" << tag << ", ";
}

ostream& operator<<(ostream& os, const Employee& other)
{
	os << (Person&)other;
	os << "Tag is:" << other.tag << ", ";
	other.toOs(os);
	return os;
}

Employee::Employee(const string& name) : Person(name)
{
	setTag();
}

Employee::~Employee()
{
}


Employee::Employee(const Employee& other) : Person(other), tag(other.tag) 
{
}


