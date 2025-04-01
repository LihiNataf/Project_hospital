#pragma warning(disable: 4996)
#pragma once
#ifndef __DOCTOR_H
#define __DOCTOR_H
#include <iostream>
using namespace std;
#include "EmployeeInDep.h"
class Department;

class Doctor : public EmployeeInDep
{
public:
    static const char* Specialty[];
    enum eSpecialty { Cardiologist, Neurologist, Family };

    //sets
    bool setSpecialty(const int specialty); //in cpp
    bool setDepartment(Department* newDepartment);

    //gets
    int getSpecialty() const {return specialty;};
    
    //func
    void print() const;
    friend ostream& operator<<(ostream& os, const Doctor& other);

    virtual EmployeeInDep* clone() const override { return new Doctor(*this); }
    virtual void toOs(ostream& os) const override;

    Doctor(const string& name, int specialty);//c'tor
    const Doctor& operator=(const Doctor& other)=delete;//=
    virtual ~Doctor();//d'tor

    static void printSpecialty();

    friend class Hospital;
protected:
    Doctor(const Doctor& other);//copy c'tor
    eSpecialty specialty;
};
#endif