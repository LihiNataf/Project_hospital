#pragma warning(disable: 4996)
#include <iostream>
#include "Department.h"
#include "Employee.h"
#include "EmployeeInDep.h"
#include "Patient.h"
#include <vector>
using namespace std;

Department :: Department (const string& name) 
{
    setName(name);

}

Department::~Department()
{

}



bool Department::employeeExist(const EmployeeInDep& e) const
{
    vector<EmployeeInDep*>::const_iterator itr = allEmployees.begin();
    vector<EmployeeInDep*>::const_iterator itrEnd = allEmployees.end();
    for (; itr != itrEnd; ++itr)
    {
        if ((*itr)->getTag() == e.getTag())
            return true;
    }
    return false;
}

bool Department::patientExist(const Patient& p) const
{
    vector<Patient>::const_iterator itr = allPatients.begin();
    vector<Patient>::const_iterator itrEnd = allPatients.end();
    for (; itr != itrEnd; ++itr)
    {
        if (itr->getId() == p.getId())
            return true;
    }
    return false;
}

bool Department::addEmployee(EmployeeInDep& e)
{
    if (employeeExist(e))
        return false;

    allEmployees.push_back(&e);

 
    allEmployees[allEmployees.size() - 1]->setDepartment(this);

    return true;
}



bool Department::addPatient(Patient& p)
{
    if (patientExist(p))
        return false;
    allPatients.push_back(p);
    p.setDepartment(this);
    return true;
}



void Department::print() const
{
    cout << "Department: " << name << endl;
    cout << "Employees:"<< endl;
    vector<EmployeeInDep*>::const_iterator itr = allEmployees.begin();
    vector<EmployeeInDep*>::const_iterator itrEnd = allEmployees.end();
    int i;
    for (i=0; itr != itrEnd; ++itr,i++)
    {
        cout << i+1 <<". ";
        (*itr)->print();
        cout << endl;
    }

    cout << "Patients:" << endl;
    vector<Patient>::const_iterator itr2 = allPatients.begin();
    vector<Patient>::const_iterator itrEnd2 = allPatients.end();
    for (; itr2 != itrEnd2; ++itr2,i++)
    {
        cout << i + 1 << ". ";
        (*itr2).print(); /////////////////////////////////////////////////////////////
        cout << endl;
    }
}


void Department::printPatients() const
{
    cout << "Department: " << name << endl;
    cout << "Patients: " << endl;
    vector<Patient>::const_iterator itr = allPatients.begin();
    vector<Patient>::const_iterator itrEnd = allPatients.end();
    int i;
    for (i=0; itr != itrEnd; ++itr,i++)
    {
        cout << i + 1 << ". ";
        itr->print();
        cout << endl;
    }
}


ostream& operator<<(ostream& os, const Department& other)
{
    os << "Department: " << other.name << endl;
    os << "Employees:" << endl; 
    vector<EmployeeInDep*>::const_iterator itr = (other.allEmployees).begin();
    vector<EmployeeInDep*>::const_iterator itrEnd = (other.allEmployees).end();
    int i;
    for (i = 0; itr != itrEnd; ++itr, i++)
    {
        os << i + 1 << ". ";
        os << *other.allEmployees[i];
        os << endl;
    }
    os << "Patients:" << endl;
    vector<Patient>::const_iterator itr2 = (other.allPatients).begin();
    vector<Patient>::const_iterator itrEnd2 = (other.allPatients).end();
    for (; itr2 != itrEnd2; ++itr2, i++)
    {
        os << i + 1 << ". ";
        os << *itr2;
        os << endl;
    }
    return os;
}










