#pragma warning(disable: 4996)
#include <iostream>
#include "Nurse.h"
#include "Department.h"
using namespace std;



void Nurse::print() const
{
	cout << "Nurse ";
	Employee::print();
	cout << "Experience: " << experience << endl;
}

ostream& operator<<(ostream& os, const Nurse& other)
{
	os << "Nurse " << (Employee&)other;
	os << "Experience: " << other.experience << endl;
	return os;
}


Nurse::Nurse(const string& name, int experience) : EmployeeInDep(name), Employee(name)
{
	setExperience(experience);
}

Nurse::~Nurse()
{
}

void Nurse::toOs(ostream& os) const
{
	os << "Nurse " << endl;
	os << "Experience: " << experience << endl;
}


Nurse::Nurse(const Nurse& other) : EmployeeInDep(other), Employee(other)
{
	experience = other.experience;
}
