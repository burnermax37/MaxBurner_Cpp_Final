#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <ctype.h>
#include "Student.h"



using namespace std;

/*Constructors*/

Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = -1;
    for (int i = 0; i < 3; ++i) {
        this->daysToCompletion[i] = -1;
    }
    this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompletion[3], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; ++i) {
        this->daysToCompletion[i] = daysToCompletion[i];
    }
    this->degreeProgram = degreeProgram;
    return;

}




/* Setters / Mutators */

void Student::setStudentID(string studentID) {
    this->studentID = studentID;
    return;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
    return;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
    return;
}

void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
    return;
}

void Student::setAge(int age) {
    this->age = age;
    return;
}

void Student::setDaysToCompletion(int* daysToCompletion) {
    int* destPoint = this->daysToCompletion;
    int* sourcePoint = daysToCompletion;
    for (int i = 0; i < 3; ++i) {
        *destPoint = *sourcePoint;
        ++destPoint;
        ++sourcePoint;
    }
    return;
}


void Student::setProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
    return;
}




/* Getters / Accessors */

string Student::getStudentID() const {
    return (this->studentID);
}

string Student::getFirstName() const {
    return (this->firstName);
}

string Student::getLastName() const {
    return (this->lastName);
}

string Student::getEmailAddress() const {
    return (this->emailAddress);
}


int Student::getAge() const {
    return (this->age);
}


int Student::getDaysToCompletion(int course) const{
    int output = -1;
    if ((course > -1) && (course < 3)) {
        const int* daysPoint = this->daysToCompletion;
        for (int i = 0; i < course; ++i) {
            ++daysPoint;
        }
        output = *daysPoint;
    }
    return output;
}


DegreeProgram Student::getDegreeProgram() const {
    return this->degreeProgram;
}




string Student::degreeToString(DegreeProgram degreeProgram) const {
    switch (degreeProgram) {
    case DegreeProgram::NETWORK:
        return "Network";
        break;
    case DegreeProgram::SECURITY:
        return "Security";
        break;
    case DegreeProgram::SOFTWARE:
        return "Software";
        break;
    default:
        return "unknown";
    }
}

//Printing





void Student::print() const {
    ostringstream studentPrint;

    studentPrint << this->getStudentID() << " \t ";
    studentPrint << "First Name: " << this->firstName << " \t ";
    studentPrint << "Last Name: " << this->lastName << " \t ";
    studentPrint << "Age: " << this->age << " \t";
    studentPrint << "daysInCourse: {";
    for (int j = 0; j < 3; ++j) {
        studentPrint << this->daysToCompletion[j];
        if (j < 2) {
            studentPrint << ", ";
        }
    }
    studentPrint << "} Degree Program: " << this->degreeToString(this->degreeProgram);
    studentPrint << "." << endl;

    cout << studentPrint.str();
}


