#pragma warning(disable: 4996)
#pragma once
#ifndef __EMPLOYEEINDEP_H
#define __EMPLOYEEINDEP_H
#include <iostream>
#include "Employee.h"
using namespace std;

class Department;

class EmployeeInDep : virtual public Employee
{
public:

    //sets
    bool setDepartment(Department* newDepartment)
    {
        department = newDepartment;
        return true;
    }




    //func
    virtual void print() const;
    EmployeeInDep(const EmployeeInDep& other) :Employee(other) { department = other.department; }//copy c'tor
    EmployeeInDep(const string& name) : Employee(name) {setDepartment(nullptr);  }//c'tor
    virtual ~EmployeeInDep() { };//d'tor
    const Employee& operator=(const EmployeeInDep& other) = delete;//=
    friend ostream& operator<<(ostream& os, const EmployeeInDep& other);

    virtual EmployeeInDep* clone() const = 0;


protected:
    Department* department;
};
#endif
