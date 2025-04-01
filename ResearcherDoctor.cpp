#pragma warning(disable: 4996)
#include <iostream>
#include "ResearcherDoctor.h"
#include "Doctor.h"
#include "Researcher.h"
using namespace std;

ostream& operator<<(ostream& os, const ResearcherDoctor& other)
{
    os << "ResearcherDoctor " << (Doctor&)other << ", ";
    os << "Articals:  ";
    vector<Artical>::const_iterator itr = other.allArticals.begin();
    vector<Artical>::const_iterator itrEnd = other.allArticals.end();
    for (int i = 0; itr != itrEnd; ++itr, i++)
    {
        os << i + 1 << ". ";
        os << *itr;
        os << endl;
    }
    return os;
}



void ResearcherDoctor::toOs(ostream& os) const
{
    Doctor::toOs(os);
    vector<Artical>::const_iterator itr = allArticals.begin();
    vector<Artical>::const_iterator itrEnd = allArticals.end();
    for (int i = 0; itr != itrEnd; ++itr, i++)
    {
        os << i + 1 << ". ";
        os << *itr;
        os << endl;
    }
}
