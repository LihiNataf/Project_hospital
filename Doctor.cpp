#pragma warning(disable: 4996)
#include <iostream>
#include "Doctor.h"
#include "Department.h"
using namespace std;



const char* Doctor::Specialty[] = { "Cardiologist", "Neurologist", "Family"};

void Doctor::printSpecialty()
{
	cout << "\n";
	for (int i = 0; i < sizeof(Specialty) / sizeof(Specialty[0]); i++)
		cout << i << " for " << Specialty[i] << endl;
}


bool Doctor::setSpecialty(const int specialty)
{
	int size = sizeof(Specialty) / sizeof(Specialty[0]);
	if (specialty >= 0 && specialty < size)
	{
		this->specialty = (eSpecialty)specialty;
		return true;
	}
	else
		return false;
}



void Doctor::print() const
{
	cout << "Dr ";
	Employee::print();
	cout << "Specialty: " << Specialty[specialty]<< endl;
}
ostream& operator<<(ostream& os, const Doctor& other)
{
	os << "Dr " << (Employee&)other;
	os << "Specialty: " << other.Specialty[other.specialty] << endl;
	return os;
}

void Doctor::toOs(ostream& os) const
{
	os << "Dr" << endl;
	os << "Specialty: " << Specialty[specialty] << endl;
}

Doctor::Doctor(const string& name, int specialty) : EmployeeInDep(name), Employee(name)
{
	setSpecialty(specialty);
}

Doctor::~Doctor()
{
}


Doctor::Doctor(const Doctor& other) : EmployeeInDep(other), Employee(other)
{
	specialty = other.specialty;
}