#pragma warning(disable: 4996)
#pragma once
#ifndef __ARTICAL_H
#define __ARTICAL_H
#include <iostream>
using namespace std;
#include "Date.h"

class Artical
{
public:
  
    //sets
    bool setDate(const Date& date) 
    {this->date = date; return true; };
    bool setName(const string& name) { this->name=name ; return true; }
    bool setMagazin(const string& magazin) { this->magazin=magazin; return true; }

    //gets
    const Date& getDate() const { return date;};
    const string& getName() const { return name; };
    const string& getMagazin() const { return magazin; };

    //func
    friend ostream& operator<<(ostream& os, const Artical& other);


    Artical(const int day, const int month, const int year, const string& name, const string& magazin);//c'tor
    

    

    const Artical& operator=(const Artical& other) = delete;//=
    friend class Researcher;
    //friend class vector;
    Artical(const Artical& other) = default;
private:
    
    Date date;
    string magazin;
    string name;
};
#endif