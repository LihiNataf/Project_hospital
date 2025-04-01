#pragma warning(disable: 4996)
#pragma once
#ifndef __DATE_H
#define __DATE_H
#include <iostream>
using namespace std;

class Date
{
public:

    bool setDay(const int day) { this->day = day;  return true; }
    bool setMonth(const int month) { this->month = month;  return true; }
    bool setYear(const int year) { this->year = year;  return true; }
    //gets
    int getDay() const { return day;}
    int getMonth() const { return month;}
    int getYear() const { return year;}

    Date(const int d = 0, const int m = 0, const int y = 0) : day(d), month(m), year(y) {};
    friend ostream& operator<<(ostream& os, const Date& other);

    friend class Artical;
private:
    int day;
    int month;
    int year;
};
#endif