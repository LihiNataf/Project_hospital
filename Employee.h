#pragma warning(disable: 4996)
#pragma once
#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include <iostream>
#include "Person.h"
using namespace std;
class Employee;

class Employee: public Person
{
public:

    //sets
    bool setTag() { this->tag = ++counter; return true; };
    //gets
    int getTag() const { return tag; };

    //func
    void print() const;
    Employee(const Employee& other);//copy c'tor
    Employee(const string& name);//c'tor
    virtual ~Employee();//d'tor
    const Employee& operator=(const Employee& other)=delete;//=
    friend ostream& operator<<(ostream& os, const Employee& other);

    virtual Employee* clone() const = 0;
    virtual void toOs(ostream& os) const {};

protected:
    static int counter;
    int tag;
};
#endif#pragma once
