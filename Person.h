#pragma warning(disable: 4996)
#pragma once
#ifndef __PERSON_H
#define __PERSON_H
#include <iostream>
using namespace std;

class Person
{
public:

    //sets
    bool setName(const string& name) { this->name = name;  return true; }
      //gets
    const string& getName() const { return name; };

    //func
    void print() const;
    Person(const Person& other);//copy c'tor
    ~Person(); //d'tor
    Person(const string& name);//c'tor
    const Person& operator=(const Person& other) = delete;//=
    friend ostream& operator<<(ostream& os, const Person& other);

protected:
    string name;
};
#endif