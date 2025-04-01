#pragma warning(disable: 4996)
#pragma once
#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H
#include <iostream>
#include <vector>
class EmployeeInDep;
class Patient;
using namespace std;


class Department
{
public:

    //sets
    bool setName(const string& name) {this->name=name; return true; }
   //gets
    const string& getName() const { return name; }

    //func
    Department(const string& name); //c'tor
    ~Department(); //d'tor
    
    const Department& operator=(const Department& other) = delete;//=
    bool employeeExist(const EmployeeInDep& e) const;
    //bool nurseExist(const Nurse& d) const;
    bool patientExist(const Patient& p) const;
    friend ostream& operator<<(ostream& os, const Department& other);
    

    bool addEmployee(EmployeeInDep& e);
    bool addPatient(Patient& p);
    void print() const;
    void printPatients()const;
    friend class Hospital;
    Department(const Department& other)=default;//copy c'tor

private:
    
    string name;
    vector<EmployeeInDep*> allEmployees;
    vector<Patient> allPatients;

};
#endif