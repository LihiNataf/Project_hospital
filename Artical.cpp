#pragma warning(disable: 4996)
#include <iostream>
#include "Artical.h"
#include "Date.h"
using namespace std;


ostream& operator<<(ostream& os, const Artical& other)
{
	os << "Date of publish is:" << (Date&)other ;
	os << "Name of artical:" << other.name << ", ";
	os << "Name of magazin:" << other.magazin << endl;
	return os;
}
Artical::Artical(const int day, const int month, const int year, const string& name, const string& magazin) :date(day,month,year)
{
	setName(name);
	setMagazin(magazin);
}



