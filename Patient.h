#pragma warning(disable: 4996)
#pragma once
#ifndef __PATIENT_H
#define __PATIENT_H
#include <iostream>
using namespace std;
#include "Person.h"
class Department;

class Patient : public Person
{
public:
    static const char* Gender[];
    enum eGender { Male, Female, Unkown };
    
    //sets
    bool setId(const int id) { this->id = id; return true; }
    bool setBirthYear(const int birthYear) {this->birthYear = birthYear; return true;}
    bool setGender(const int gender);
    bool setDepartment(Department* newDepartment);

    //gets
    int getGender() const { return gender; }
    int getId() const { return id; }
    int getBirthYear() const { return birthYear; }

    //func
    void print() const;
    friend ostream& operator<<(ostream& os, const Patient& other);


    Patient(const Person& base, int id, int birthYear, int gender);//c'tor
    const Patient& operator=(const Patient& other) = delete;//=
  
    static void printGender();
    Patient(const Patient& other);
    friend class Hospital;

protected:
    //Patient(const Patient& other);//copy c'tor
    int id;
    int birthYear;
    eGender gender;
    Department* department;
};
#endif