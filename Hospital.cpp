#pragma warning(disable: 4996)
#include <iostream>
#include "Hospital.h"
#include "ResearchCenter.h"
#include <vector>
using namespace std;

void Hospital::printDepartments()const
{
    vector<Department>::const_iterator itr = allDepartments.begin();
    vector<Department>::const_iterator itrEnd = allDepartments.end();
    for (; itr != itrEnd; ++itr)
    {
        cout << (*itr).name << ", ";
    }
    cout << endl;
}

void Hospital::printEmployees() const
{
    cout << "Employees:" << endl;
    int i;
    vector<EmployeeInDep*>::const_iterator itr = allEmployees.begin();
    vector<EmployeeInDep*>::const_iterator itrEnd = allEmployees.end();
    for (i=0; itr != itrEnd; ++itr,i++)
    {
        cout << i + 1 << ". ";
        (*itr)->print();
        cout << endl;
    }
    vector<Researcher*>::const_iterator itr2 = researchCenter.allResearchers.begin();
    vector<Researcher*>::const_iterator itrEnd2 = researchCenter.allResearchers.end();
    for (; itr2 != itrEnd2; ++itr2, i++)
    {
        cout << i + 1 << ". ";
        (*itr2)->print();
        cout << endl;
   }
}

bool Hospital::printDepartmentByName(const string& department) const
{
    vector<Department>::const_iterator itr = allDepartments.begin();
    vector<Department>::const_iterator itrEnd = allDepartments.end();
    for (; itr != itrEnd; ++itr)
    {
        if (itr->getName() == department)
        {
            itr->printPatients();
            return true;
        }
    }
    return false;
}


Hospital::Hospital(const string& HospitaName, const string& ResearchName) : researchCenter(ResearchName)
{
    setName(HospitaName);
}







const Patient* Hospital::findPatientById(const int id) const
{
    vector<Patient>::const_iterator itr = allPatients.begin();
    vector<Patient>::const_iterator itrEnd = allPatients.end();
    for (; itr != itrEnd; ++itr)
    {
        if (itr->getId() == id)
            return &(*itr);
    }
    return nullptr;
}

const EmployeeInDep* Hospital::findEmployeeByTag(const int tag) const
{
    vector<EmployeeInDep*>::const_iterator itr = allEmployees.begin();
    vector<EmployeeInDep*>::const_iterator itrEnd = allEmployees.end();
    for (; itr != itrEnd; ++itr)
    {
        if ((*itr)->getTag() == tag)
            return *itr;
    }
    return nullptr;
}




void Hospital::operator+=(const EmployeeInDep& e)
{
    if (employeeExist(e.getTag()) == false)
    {
        allEmployees.push_back(e.clone());
    }
}

bool Hospital::AddEmployeeToDepartment(const EmployeeInDep& e, const string& department)
{
    if (employeeExist(e.getTag()) == false || departmentExist(department) == false)
        return false;

    vector<Department>::iterator itr = allDepartments.begin();
    vector<Department>::iterator itrEnd = allDepartments.end();
    for (; itr != itrEnd; ++itr)
    {
        if (department == itr->getName())
        {
            itr->addEmployee(*allEmployees[allEmployees.size() - 1]);
            //itr->addEmployee(*allEmployees.end());
        }
    }
    if (typeid(*allEmployees[allEmployees.size() - 1]) == typeid(ResearcherDoctor))
    {
        Researcher* temp = dynamic_cast<Researcher*>(const_cast<EmployeeInDep*>(&e));
        getResearchCenter().addNewResearcher(*temp);
    }
    return true;
}



bool Hospital::employeeExist(const int tag) const
{
    vector<EmployeeInDep*>::const_iterator itr = allEmployees.begin();
    vector<EmployeeInDep*>::const_iterator itrEnd = allEmployees.end();
    for (; itr != itrEnd; ++itr)
    {
        if ((*itr)->getTag() == tag)
            return true;
    }
    return false;
}


bool Hospital::patientExist(const int id) const
{
    vector<Patient>::const_iterator itr = allPatients.begin();
    vector<Patient>::const_iterator itrEnd = allPatients.end();
    for (; itr != itrEnd; ++itr)
    {
        if (itr->getId() == id)
            return true;
    }
    return false;
}

bool Hospital::departmentExist(const string& name) const
{
    vector<Department>::const_iterator itr = allDepartments.begin();
    vector<Department>::const_iterator itrEnd = allDepartments.end();
    for (; itr != itrEnd; ++itr)
    {
        if (itr->getName()==name)
            return true;
    }
    return false;
}


bool Hospital::addNewVisit(const Visit& v)
{
    allVisits.push_back(v);
    return true;
}
bool Hospital::addNewEmployee(const EmployeeInDep& e,const string& department)
{
    if (employeeExist(e.getTag()) || !departmentExist(department))
        return false;

    allEmployees.push_back(e.clone());

    if (employeeExist(e.getTag()) == false || departmentExist(department) == false)
        return false;

    vector<Department>::iterator itr = allDepartments.begin();
    vector<Department>::iterator itrEnd = allDepartments.end();
    for (; itr != itrEnd; ++itr)
    {
        if (department == itr->getName())
        {
            itr->addEmployee(*allEmployees[allEmployees.size() - 1]);
        }
    }
    if (typeid(*allEmployees[allEmployees.size() - 1]) == typeid(ResearcherDoctor))
    {
        Researcher* temp = dynamic_cast<Researcher*>(const_cast<EmployeeInDep*>(allEmployees[allEmployees.size()-1]));
        getResearchCenter().addNewResearcher(*temp);
    }
    return true;

}



bool  Hospital::addNewPatient(const Patient& p, const string& department)
{
    if (patientExist(p.getId())==true || departmentExist(department)==false)
        return false;

    allPatients.push_back(p);

    vector<Department>::iterator itr = allDepartments.begin();
    vector<Department>::iterator itrEnd = allDepartments.end();
    for (; itr != itrEnd; ++itr)
    {
        if (department == itr->getName())
        {
            itr->addPatient(allPatients[allPatients.size()-1]);
        }
    }
    return true;
}

bool Hospital::addNewDepartment(const string& name )
{
    if (departmentExist(name))
        return false;
    allDepartments.push_back(Department(name));
    return true;
}


ostream& operator<<(ostream& os, const Hospital& other)
{
    os << "Hospital: " << other.name << endl;
    os << "Research center: " << other.researchCenter << endl;
    vector<Department>::const_iterator itr = (other.allDepartments).begin();
    vector<Department>::const_iterator itrEnd = (other.allDepartments).end();
    int i;
    for (i=0; itr != itrEnd; ++itr,i++)
    {
        os << i + 1 << ". ";
        os << *itr;
        os << endl;
    }
    vector<Visit>::const_iterator itr2 = (other.allVisits).begin();
    vector<Visit>::const_iterator itrEnd2 = (other.allVisits).end();
    for (; itr2 != itrEnd2; ++itr2)
    {
        os << i + 1 << ". ";
        os << *itr2;
        os << endl;
    }
    return os;
}



Hospital::~Hospital()
{
    vector<EmployeeInDep*>::const_iterator itr = allEmployees.begin();
    vector<EmployeeInDep*>::const_iterator itrEnd = allEmployees.end();
    for (; itr != itrEnd; ++itr)
    {
        delete *itr;
    }

}