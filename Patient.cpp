#pragma warning(disable: 4996)
#include <iostream>
#include "Patient.h"
#include "Department.h"
using namespace std;


const char* Patient::Gender[] = { "Male", "Female", "Unkown"};

void Patient::printGender()
{
	cout << "\n";
	for (int i = 0; i < sizeof(Gender) / sizeof(Gender[0]); i++)
		cout << i << " for " << Gender[i]<< endl;
}


bool Patient::setGender(const int gender)
{
	int size = sizeof(Gender) / sizeof(Gender[0]);
	if (gender >= 0 && gender < size)
	{
		this->gender = (eGender)gender;
		return true;
	}
	else
		return false;
}

bool Patient::setDepartment(Department* newDepartment)
{
	department = newDepartment;
	return true;
}


void Patient::print() const
{
	cout << "Patient ";
	Person::print();
	cout << "Id: " << id << ", ";
	cout << "Birth Year: " << birthYear << ", ";
	cout << "Gender: " << Gender[gender] << endl;

}

ostream& operator<<(ostream& os, const Patient& other)
{
	os << "Patient " << (Person&)other;
	os << "Id: " << other.id << ", ";
	os << "Birth Year: " << other.birthYear << ", ";
	os << "Gender: " << other.Gender[other.gender] << endl;
	return os;
}

Patient::Patient(const Person& base, int id, int birthYear, int gender) : Person(base)
{
	setGender(gender);
	setId(id);
	setBirthYear(birthYear);
	setDepartment(nullptr);
}


Patient::Patient(const Patient& other) : Person(other)
{
	gender = other.gender;
	id = other.id;
	birthYear = other.birthYear;
	department = other.department;
}