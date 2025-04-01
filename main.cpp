#pragma warning(disable: 4996)
#include <iostream>
#include "Hospital.h"
#include "Artical.h"

using namespace std;
void Q1(Hospital& myHospital);
void Q2(Hospital& myHospital);
void Q3(Hospital& myHospital);
void Q4(Hospital& myHospital);
void Q5(Hospital& myHospital);
void Q6(Hospital& myHospital);
void Q7(Hospital& myHospital);
void Q8(Hospital& myHospital);
void Q9(Hospital& myHospital);
void Q10(Hospital& myHospital);
void Q11(Hospital& myHospital);
void Q12(Hospital& myHospital);
void Q13(Hospital& myHospital);
void Q14();

int main()
{
    cout << "PROJECT WRITTEN BY Michel Albrecht 324563378 & Lihi Nataf 322697988";
    Hospital myHospital("Shiba", "AdaYonat");


    myHospital.addNewDepartment("cardiologic");
    myHospital.addNewEmployee(Doctor("shahar", 0), "cardiologic");
    myHospital.addNewEmployee(Doctor("michel", 2), "cardiologic");
    myHospital.addNewEmployee(Doctor("lihi", 1), "cardiologic");
    myHospital.addNewEmployee(Doctor("ofir", 0), "cardiologic");
    myHospital.addNewEmployee(Nurse("guy", 25), "cardiologic");
    myHospital.addNewPatient(Patient((Person("lili")), 1111, 2002, 0), "cardiologic");
    Researcher r("michel");
    Artical a(5, 6, 7, "hii", "yediot");
    r.addNewArtical(a);
    myHospital.getResearchCenter().addNewResearcher(r);
    ResearcherDoctor r1("shlomi", 0);
    myHospital.addNewEmployee(r1, "cardiologic");
    myHospital.addNewEmployee(ResearcherDoctor("nika", 0), "cardiologic");




    int choice = 0;

    do {

        cout << "\n====================\n";
        cout << "       MENU         \n";
        cout << "====================\n";
        cout << "1. Add Doctor\n";
        cout << "2. Add Nurse\n";
        cout << "3. Add Researcher\n";
        cout << "4. Add Doctor Researcher\n";
        cout << "5. Add artical to researcher\n";
        cout << "6. Add Department\n";
        cout << "7. Add Patient visit\n";
        cout << "8. Print patient in department\n";
        cout << "9. Print all Emloyees in hospital\n";
        cout << "10. Print all reserchers\n";
        cout << "11. Add doctor to Hospital by +=\n";
        cout << "12. Add nurse to Hospital by +=\n";
        cout << "13. Which Researcher has more articals?\n";
        cout << "14. Exit\n";
        cout << "====================\n";
        cout << "Enter your choice: ";
        cin >> choice;
            switch (choice) {
            case 1: Q1(myHospital); break;
            case 2: Q2(myHospital); break;
            case 3: Q3(myHospital); break;
            case 4: Q4(myHospital); break;
            case 5: Q5(myHospital); break;
            case 6: Q6(myHospital); break;
            case 7: Q7(myHospital); break;
            case 8: Q8(myHospital); break;
            case 9: Q9(myHospital); break;
            case 10: Q10(myHospital); break;
            case 11: Q11(myHospital); break;
            case 12: Q12(myHospital); break;
            case 13: Q13(myHospital); break;
            case 14: Q14(); break;
            default:
                cout << "Invalid choice, please try again." << endl;
            }

            } while (choice != 14);


            cout << myHospital;

        
}

void Q1(Hospital& myHospital) {
    char name[20], department[20];
    int speciality;
    cout << "doctor's name is: ";
    cin >> name;
    cout << "choose speciality number: ";
    Doctor::printSpecialty();
    cin >> speciality;
    cout << "Departments in Hospital: " << endl;
    myHospital.printDepartments();
    cout << "enter Department's name between the Departments above: ";
    cin >> department;
    if (myHospital.addNewEmployee(Doctor(name, speciality), department))
        cout << "Adding doctor succeed" << endl;
    else
        cout << "Adding doctor failed" << endl;
}

void Q2(Hospital& myHospital) {
    char name[20], department[20];
    int experience;
    cout << "nurse's name is: ";
    cin >> name;
    cout << "enter experience: ";
    cin >> experience;
    cout << "Departments in Hospital: " << endl;
    myHospital.printDepartments();
    cout << "enter Department's name between the Departments above: ";
    cin >> department;
    if (myHospital.addNewEmployee(Nurse(name, experience), department))
        cout << "Adding nurse succeed" << endl;
    else
        cout << "Adding nurse failed" << endl;
}

void Q3(Hospital& myHospital) {
    char name[20];
    cout << "name of researcher is: ";
    cin >> name;
    myHospital.getResearchCenter().addNewResearcher(Researcher(name));
}

void Q4(Hospital& myHospital) {
    char name[20], department[20];
    int speciality;
    cout << "doctor's name is: ";
    cin >> name;
    cout << "choose speciality number: ";
    Doctor::printSpecialty();
    cin >> speciality;
    cout << "Departments in Hospital: " << endl;
    myHospital.printDepartments();
    cout << "enter Department's name between the Departments above: ";
    cin >> department;
    if (myHospital.addNewEmployee(ResearcherDoctor(name, speciality), department))
        cout << "Adding ResearcherDoctor succeed" << endl;
    else
        cout << "Adding ResearcherDoctor failed" << endl;
}

void Q5(Hospital& myHospital) {
    char name[50], magazin[50];
    int id, day, month, year;
    cout << "enter Tag of wanted researcher: ";
    cin >> id;
    cout << "enter name of article: ";
    cin >> name;
    cout << "enter magazine name: ";
    cin >> magazin;
    cout << "date of published: " << endl << "enter day: ";
    cin >> day;
    cout << "enter month: ";
    cin >> month;
    cout << "enter year: ";
    cin >> year;
    if (myHospital.getResearchCenter().getResearcherByTag(id)->addNewArtical(Artical(day, month, year, name, magazin)))
        cout << "adding article succeeded" << endl;
    else
        cout << "adding article failed" << endl;
}

void Q6(Hospital& myHospital) {
    char department[20];
    cout << "new department's name is: ";
    cin >> department;
    if (myHospital.addNewDepartment(department))
        cout << "Adding department succeed" << endl;
    else
        cout << "Adding department failed" << endl;
}

void Q7(Hospital& myHospital) {
    int id, tag1, day, month, year, birthYear, gender;
    char description[20];
    char name[20];
    char department[20];
    cout << "enter the ID" << endl;
    cin >> id;
    if (myHospital.patientExist(id))
    {
        cout << "patient exist in system " << endl;
        cout << "add new visit to system" << endl;
        cout << "what is the attending doctor's tag?" << endl;
        cin >> tag1;
        if (myHospital.findEmployeeByTag(tag1) == nullptr || typeid(*myHospital.findEmployeeByTag(tag1)) != typeid(Doctor))
        {
            //check if is doctor/nurse/researcherDoctor
            cout << "Doctor not exist, Pleas try again" << endl;
            return;
        }
        else
        {
            cout << "enter day: ";
            cin >> day;
            cout << "enter month: ";
            cin >> month;
            cout << "enter year: ";
            cin >> year;
            cout << "enter description of the visit: ";
            cin >> description;
            myHospital.addNewVisit(Visit(myHospital.findPatientById(id), myHospital.findEmployeeByTag(tag1), Date(day, month, year), description));
        }
    }
    else
    {
        cout << "adding new patient" << endl;
        cout << "Patient's name is: ";
        cin >> name;
        cout << "birthYear is: ";
        cin >> birthYear;
        cout << "choose gender number: ";
        Patient::printGender();
        cin >> gender;//need to check
        cout << "Departments in Hospital: " << endl;
        myHospital.printDepartments();
        cout << "choose name between the Department's above: ";
        cin >> department;
        if (myHospital.addNewPatient(Patient(Person(name), id, birthYear, gender), department))
            cout << "Adding patient succeed" << endl;
        else
        {
            cout << "Adding patient failed, Pleas try again" << endl;
            return;
        }
        cout << "add new visit to system" << endl;
        cout << "what is the attending doctor's tag?" << endl;
        cin >> tag1;
        if (myHospital.findEmployeeByTag(tag1) == nullptr || typeid(*myHospital.findEmployeeByTag(tag1)) != typeid(Doctor))
        {
            //check if is doctor/nurse/researcherDoctor
            cout << "Doctor not exist, Pleas try again" << endl;
            return;
        }
        cout << "enter day: ";
        cin >> day;
        cout << "enter month: ";
        cin >> month;
        cout << "enter year: ";
        cin >> year;
        cout << "enter description of the visit";
        cin >> description;
        myHospital.addNewVisit(Visit(myHospital.findPatientById(id), myHospital.findEmployeeByTag(tag1), Date(day, month, year), description));
    }
}

void Q8(Hospital& myHospital) {
    char department[20];
    myHospital.printDepartments();
    cout << "choose name between the Department's above: ";
    cin >> department;
    if (!myHospital.printDepartmentByName(department))
        cout << "Department Not Found";
}

void Q9(Hospital& myHospital) {
    cout << "Employees In Hospital";
    myHospital.printEmployees();
}

void Q10(Hospital& myHospital) {
    cout << myHospital.getResearchCenter();
}

void Q11(Hospital& myHospital) {
    char name[20], department[20];
    int speciality;
    Doctor* d;
    cout << "doctor's name is: ";
    cin >> name;
    cout << "choose speciality number: ";
    Doctor::printSpecialty();
    cin >> speciality;
    d = new Doctor(name, speciality);
    myHospital += *d;
    cout << "Departments in Hospital: " << endl;
    myHospital.printDepartments();
    cout << "enter Department's name between the Departments above: ";
    cin >> department;
    if (myHospital.AddEmployeeToDepartment(*d, department))
        cout << "Adding doctor succeed" << endl;
    else
        cout << "Adding doctor failed" << endl;
}

void Q12(Hospital& myHospital) {
    char name[20], department[20];
    int experience;
    Nurse* n;
    cout << "nurse's name is: ";
    cin >> name;
    cout << "enter experience: ";
    cin >> experience;
    n = new Nurse(name, experience);
    myHospital += *n;
    cout << "Departments in Hospital: " << endl;
    myHospital.printDepartments();
    cout << "enter Department's name between the Departments above: ";
    cin >> department;
    if (myHospital.AddEmployeeToDepartment(*n, department))
        cout << "Adding nurse succeed" << endl;
    else
        cout << "Adding nurse failed" << endl;
}

void Q13(Hospital& myHospital) {
    int tag1, tag2;
    cout << "enter Tag of researcher 1: ";
    cin >> tag1;
    cout << "enter Tag of researcher 2: ";
    cin >> tag2;
    if (myHospital.getResearchCenter().whoHaveMoreArticals(tag1, tag2))
        cout << "Researcher 1 has more Articles\n";
    else
        cout << "Researcher 2 has more Articles\n";
}

void Q14() {
    cout << "Goodbye!" << endl << "====================" << endl;
}