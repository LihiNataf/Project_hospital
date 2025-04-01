#pragma warning(disable: 4996)
#pragma once
#ifndef __HOSPITAL_H
#define __HOSPITAL_H
#include <iostream>
#include "Doctor.h"
#include "Nurse.h"
#include "ResearcherDoctor.h"
#include "Patient.h"
#include "Department.h"
#include "Visit.h"
#include "ResearchCenter.h"
using namespace std;
#include <vector>



class Hospital
{
public:

    //sets
    bool setName(const string& name) { this->name = name; return true; }
    
    //gets
    
    const ResearchCenter& getResearchCenter() const { return researchCenter; };
          ResearchCenter& getResearchCenter()       { return researchCenter; };

    //func
    Hospital(const string& HospitaName, const string& ResearchName); //c'tor
    ~Hospital(); //d'tor

    bool employeeExist(const int tag) const;
    bool patientExist(const int id) const;
    bool departmentExist(const string& name) const;
    bool addNewEmployee(const EmployeeInDep& e,const string& department);
    bool addNewPatient(const Patient& p, const string& department);
    bool addNewDepartment(const string& name );
    bool addNewVisit(const Visit& n);
    const Patient* findPatientById(const int id) const;
    const EmployeeInDep* findEmployeeByTag(const int tag) const;

    void operator+=(const EmployeeInDep& e);
    bool AddEmployeeToDepartment(const EmployeeInDep& e, const string& department);

;
    friend ostream& operator<<(ostream& os, const Hospital& other);
    
    Hospital(const Hospital& h) = delete; //block copy c'tor
    const Hospital& operator=(const Hospital& other) = delete;//no =
    void printDepartments() const;
    void printEmployees() const;
    bool printDepartmentByName(const string& department) const;

private:
    string name;
    vector<EmployeeInDep*> allEmployees;
    vector<Patient> allPatients;
    vector<Department> allDepartments;
    ResearchCenter researchCenter;
    vector<Visit> allVisits;
};
#endif