#pragma warning(disable: 4996)
#pragma once
#ifndef __RESEARCHCENTER_H
#define __RESEARCHCENTER_H
#include "Researcher.h"
#include <iostream>
using namespace std;

class ResearchCenter
{
public:
  
    bool setName(const string& name) { this->name=name; return true; }

    //gets
    const string& getName() const { return name; };

    bool addNewResearcher(const Researcher& other);
    bool researcherExist(const string& name) const;
    const Researcher* getResearcherByTag(int tag) const;
          Researcher* getResearcherByTag(int tag);
    void print()const;
    bool whoHaveMoreArticals(int tag1, int tag2);
   
    //func
    friend ostream& operator<<(ostream& os, const ResearchCenter& other);
    const ResearchCenter& operator=(const ResearchCenter& other) = delete;
    ~ResearchCenter();//d'tor
    ResearchCenter(const string& name);//c'tor

    friend class Hospital;

private:
    ResearchCenter(const ResearchCenter& other);//copy c'tor dont need
    string name;
    vector<Researcher*> allResearchers;
};
#endif