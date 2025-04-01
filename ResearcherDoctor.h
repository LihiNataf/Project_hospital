#pragma warning(disable: 4996)
#pragma once
#ifndef __ResearcherDoctor_H
#define __ResearcherDoctor_H
#include <iostream>
using namespace std;
#include "Doctor.h"
#include "Researcher.h"

class ResearcherDoctor : public Doctor, public Researcher
{
public:

    //func
    friend ostream& operator<<(ostream& os, const ResearcherDoctor& other);


    ResearcherDoctor(const string& name, int speciality) : Employee(name), Doctor(name, speciality), Researcher(name) {};//c'tor
    const ResearcherDoctor& operator=(const ResearcherDoctor& other) = delete;//=

   // ResearcherDoctor(const ResearcherDoctor& other) :Employee(other), Doctor(other), Researcher(other) {};

    virtual EmployeeInDep* clone() const override { return new ResearcherDoctor(*this); }
    virtual void toOs(ostream& os) const override;
    void print() const { Doctor::print(); }
};
#endif