#pragma warning(disable: 4996)
#include <iostream>
#include "Visit.h"
#include "Patient.h"
#include "Employee.h"
#include <vector>
using namespace std;


ostream& operator<<(ostream& os, const Visit& other)
{
    os << "Visit Details :  "<< endl;
    os << *(other.patient);
    os << "Date:  "<< other.visitDate;
    os << "Description:  " << other.description << endl;
    os <<"Attending Doctor: " << *(other.doctor) << endl;
  
    return os;
}

Visit :: Visit (const Patient* patient,const Employee* doctor, const Date& date, const string& description) : patient(patient), doctor(doctor), visitDate(date)
{ setDescription(description); }

Visit::Visit(const Visit& other) //copy c'tor
{
    description = other.description;
    patient = other.patient;
    doctor = other.doctor;
    visitDate = other.visitDate;
}


Visit:: ~Visit()
{
}


