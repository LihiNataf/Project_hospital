#pragma warning(disable: 4996)
#include <iostream>
#include "ResearchCenter.h"
#include "ResearcherDoctor.h"
#include <vector>
using namespace std;




ResearchCenter::ResearchCenter(const string& name)
{
	setName(name);
}



ResearchCenter::~ResearchCenter()
{
    vector<Researcher*>::const_iterator itr = allResearchers.begin();
    vector<Researcher*>::const_iterator itrEnd = allResearchers.end();
    for (; itr != itrEnd; ++itr)
    {
        if (typeid(*itr) == typeid(Researcher))
            delete *itr;
    }

}

ostream& operator<<(ostream& os, const ResearchCenter& other)
{
    os << "Name is: " << other.name << endl;
    vector<Researcher*>::const_iterator itr = (other.allResearchers).begin();
    vector<Researcher*>::const_iterator itrEnd = (other.allResearchers).end();
    int i;
    for (i=0; itr != itrEnd; ++itr,i++)
    {
        os << i + 1 << ". ";
        os << **itr;
        os << endl;
    }
    return os;
}

void ResearchCenter::print() const
{
    cout << "Research Center" << endl;
    cout << "Researchers:  ";
    vector<Researcher*>::const_iterator itr = allResearchers.begin();
    vector<Researcher*>::const_iterator itrEnd = allResearchers.end();
    int i;
    for (i = 0; itr != itrEnd; ++itr, i++)
    {
        cout << i + 1 << ". ";
        (*itr)->print();
        cout << endl;
    }
}


bool ResearchCenter::whoHaveMoreArticals(int tag1, int tag2)
{

    vector<Researcher*>::const_iterator itr = allResearchers.begin();
    vector<Researcher*>::const_iterator itrf1 = allResearchers.begin();
    vector<Researcher*>::const_iterator itrf2 = allResearchers.begin();
    vector<Researcher*>::const_iterator itrEnd = allResearchers.end();
    while( itr != itrEnd )
    {
        if ((*itr)->getTag() == tag1)
            itrf1 = itr;
        if ((*itr)->getTag() == tag2)
            itrf2 = itr;
        itr++;
    }
        return ((*itrf1)->numOfArticals() > (*itrf2)->numOfArticals());
}


bool ResearchCenter::researcherExist(const string& name) const
{
    vector<Researcher*>::const_iterator itr = allResearchers.begin();
    vector<Researcher*>::const_iterator itrEnd = allResearchers.end();
    for (; itr != itrEnd; ++itr)
    {
        if ((*itr)->getName() == name)
            return true;
    }
    return false;
}

const Researcher* ResearchCenter::getResearcherByTag(int tag) const
{
    vector<Researcher*>::const_iterator itr = allResearchers.begin();
    vector<Researcher*>::const_iterator itrEnd = allResearchers.end();
    for (; itr != itrEnd; ++itr)
    {
        if ((*itr)->getTag() == tag)
        {
            return (*itr);

        }
    }
    return nullptr;
}

Researcher* ResearchCenter::getResearcherByTag(int tag) 
{
    vector<Researcher*>::const_iterator itr = allResearchers.begin();
    vector<Researcher*>::const_iterator itrEnd = allResearchers.end();
    for (; itr != itrEnd; ++itr)
    {
        if ((*itr)->getTag() == tag)
        {
            return (*itr);

        }
    }
    return nullptr;
}



//will be hetrogeni array of Resercher and Resercherdoctor need to change this methos new only for Researcher and not for researcherDoctor, need to change d'tor too
bool ResearchCenter::addNewResearcher(const Researcher& other)
{
    if (researcherExist(other.getName()))  //need to change can be to researcher with same name
        return false;
    if (typeid(other)==typeid(Researcher))
       allResearchers.push_back(dynamic_cast<Researcher*>(other.clone()));
    else
        allResearchers.push_back(dynamic_cast<ResearcherDoctor*>(const_cast<Researcher*>(&other)));
    return true;
}
