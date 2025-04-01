#pragma warning(disable: 4996)
#include <iostream>
#include "EmployeeInDep.h"
#include "Department.h"
using namespace std;


void EmployeeInDep::print() const
{
	Employee::print();
}

ostream& operator<<(ostream& os, const EmployeeInDep& other)
{
	os << (Employee&)other;
	return os;
}





