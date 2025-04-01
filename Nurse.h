#pragma warning(disable: 4996)
#pragma once
#ifndef __NURSE_H
#define __NURSE_H
#include <iostream>
#include "EmployeeInDep.h"
using namespace std;
class Department;

class Nurse : public EmployeeInDep
{
public:

    //sets
    bool setExperience(const int experience) { this->experience = experience; return true; };
    bool setDepartment(Department* newDepartment);
    //gets
    int getExperience() const { return experience; };

    //func
    void print() const;
    Nurse (const string& name, int experience);//c'tor
    const Nurse& operator=(const Nurse& other)=delete;//=
    friend ostream& operator<<(ostream& os, const Nurse& other);
    virtual ~Nurse();

    virtual EmployeeInDep* clone() const override { return new Nurse(*this); }
    virtual void toOs(ostream& os) const override;

    friend class Hospital;

private:
    Nurse(const Nurse& other);//copy c'tor
    int experience;
};
#endif