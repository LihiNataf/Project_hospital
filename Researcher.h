#pragma warning(disable: 4996)
#pragma once
#ifndef __RESEARCHER_H
#define __RESEARCHER_H
#include <iostream>
using namespace std;
#include "Employee.h"
#include "Artical.h"
#include <vector>


class Researcher : virtual public Employee
{
public:

    bool articalExist(const string& name) const;
    bool addNewArtical(const Artical& other);
    //func
    friend ostream& operator<<(ostream& os, const Researcher& other);
    Researcher(const string& name);//c'tor
    const Researcher& operator=(const Researcher& other) = delete;//=
    virtual ~Researcher(); // d'tor

    int numOfArticals() const;
    bool operator>(const Researcher& other) const;

    virtual Employee* clone() const override { return new Researcher(*this); }
    virtual void toOs(ostream& os) const override;


    void print();
   

    friend class ResearchCenter;
protected:
    vector<Artical> allArticals;
};
#endif