#pragma warning(disable: 4996)
#include <iostream>
#include "Researcher.h"
using namespace std;

ostream& operator<<(ostream& os, const Researcher& other)
{
    os << "Researcher " << (Employee&)other << endl;
    return os;
}

void Researcher::print() 
{
    Employee::print();
    cout << "Researcher " << endl;
    cout << "Articals:  ";
    vector<Artical>::const_iterator itr = allArticals.begin();
    vector<Artical>::const_iterator itrEnd = allArticals.end();
    for (int i=0; itr != itrEnd; ++itr,i++)
    {
        cout << i + 1 << ". ";
        cout << *itr;
        cout << endl;
    }
}


Researcher::Researcher(const string& name) : Employee(name)
{

}




bool Researcher::articalExist(const string& name) const
{
    vector<Artical>::const_iterator itr = allArticals.begin();
    vector<Artical>::const_iterator itrEnd = allArticals.end();
    for (; itr != itrEnd; ++itr)
    {
        if (itr->getName() == name)
            return true;
    }
    return false;
}

bool Researcher::addNewArtical(const Artical& other)
{
    if (articalExist(other.getName()))
        return false;
    allArticals.push_back(other);
    return true;
}

Researcher::~Researcher()
{
}

int Researcher::numOfArticals() const
{
    return allArticals.size();
}

bool Researcher::operator>(const Researcher& other) const
{
    return (this->numOfArticals() > other.numOfArticals());
}

void Researcher::toOs(ostream& os) const
{
    os << "Researcher"<<endl ;
    os << "Articals:"<<endl;
    vector<Artical>::const_iterator itr = allArticals.begin();
    vector<Artical>::const_iterator itrEnd = allArticals.end();
    for (int i = 0; itr != itrEnd; ++itr, i++)
    {
        os << i + 1 << ". ";
        os << *itr;
        os << endl;
    }
}


