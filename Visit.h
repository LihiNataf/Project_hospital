#pragma warning(disable: 4996)
#pragma once
#ifndef __VISIT_H
#define __VISIT_H
#include <iostream>
using namespace std;
#include "Date.h";
class Patient;
class Employee;


class Visit 
{
public:

    bool setDescription(const string& description)
    {
        this->description=description;
        return true; 
    }

    //func
    friend ostream& operator<<(ostream& os, const Visit& other);


    Visit(const Patient* patient,const Employee* doctor, const Date& date, const string& description);//c'tor
    const Visit& operator=(const Visit& other) = delete;//=
    ~Visit();//d'tor

    Visit(const Visit& other);   //copy c'tor
    friend class Hospital;

private:

    const Patient* patient;
    Date visitDate;
    string description;
    const Employee* doctor;
};
#endif