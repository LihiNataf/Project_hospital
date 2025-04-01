#pragma warning(disable: 4996)
#include <iostream>
#include "Date.h"
using namespace std;


ostream& operator<<(ostream& os, const Date& other)
{
	os << other.day<<"/"<< other.month << "/" << other.year << endl;
	return os;
}

