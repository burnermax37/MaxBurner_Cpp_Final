#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <cctype>

#include "Roster.h"



Roster::Roster() {
    this->numStudents = 0;
    return;
}


Roster::~Roster() {
    for (int i = 0; i < this->numStudents; ++i) {
        delete (this->studentRecords)[i];
    }
    return;
}


//Add: Add a new student to the array, incrementing the variable that counts the highest array index used.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompletion[3], DegreeProgram studentProgram) {
    ++(this->numStudents);
    (this->studentRecords[numStudents - 1]) = new Student(studentID, firstName, lastName, emailAddress, age, daysToCompletion, studentProgram);
    return;
}



void Roster::fillSpaces(string& input) const {

    for (unsigned int i = 0; i < input.size(); ++i) {
        if (isspace(input.at(i))) {
            input.at(i) = '~';
        }
    }

    return;
}


void Roster::unFill(string& input) const {

    for (unsigned int i = 0; i < input.size(); ++i) {
        if (input.at(i) == '~') {
            input.at(i) = ' ';
        }
    }

    return;
}


void Roster::commasToSpaces(string& input) const{
    int commaLoc = -1;

    for (unsigned int i = 0; i < input.size(); ++i) {
        commaLoc = input.find(',');
        if (commaLoc >= 0) {
            input.at(commaLoc) = ' ';
        }
        else {
            break;
        }
    }

    return;
}



DegreeProgram Roster::stringToDegree(const string& input) const{
    if (input == "SECURITY") {
        return DegreeProgram::SECURITY;
    }
    else if (input == "SOFTWARE") {
        return DegreeProgram::SOFTWARE;
    }
    else if (input == "NETWORK") {
        return DegreeProgram::NETWORK;
    }
    else {
        cout << "Error: Unrecognized input string" << endl;;
        return DegreeProgram::SOFTWARE; //Change to an exception?
    }
}



void Roster::add(string student) {
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToCompletion[3];

    string degreeString;
    DegreeProgram degreeProgram;

    istringstream studentStream;

    this->fillSpaces(student); //Fill spaces to prevent incorrect extraction
    this->commasToSpaces(student);


    studentStream.str(student);


    studentStream >> studentId;
    this->unFill(studentId);

    studentStream >> firstName;
    this->unFill(firstName);

    studentStream >> lastName;
    this->unFill(lastName);

    studentStream >> emailAddress;
    this->unFill(emailAddress);

    studentStream >> age;


    for (int i = 0; i < 3; ++i) {
        studentStream >> daysToCompletion[i];
    }

    studentStream >> degreeString;
    this->unFill(degreeString);
    degreeProgram = this->stringToDegree(degreeString);

    this->add(studentId, firstName, lastName, emailAddress, age, daysToCompletion, degreeProgram);

    return;
}



// Remove: remove a student from the array, move all subsequent students in the array back one step
void Roster::remove(string studentID) {
    //cout << "Removal Begins" << endl << flush;
    string checkID;
    bool found = false;
    for (int i = 0; i < (this->numStudents); ++i) {
        checkID = (this->studentRecords)[i]->getStudentID();
        if (checkID == studentID) {
            //cout << "Matching record found for " << studentID << endl << flush;
            delete this->studentRecords[i];
            //cout << "Record Deleted" << endl << flush;
            --numStudents;
            for(int j = i; j < (this->numStudents); ++j) {
                (this->studentRecords)[j] = (this->studentRecords)[j + 1]; //Replcae current record with next record
            }
            //cout << "Records shifted" << endl << flush;
            (this->studentRecords)[numStudents] = nullptr; //Convert redudnant pointer to null pointer
            found = true;
            break;
        }
    }
    //cout << "Loop ended" << endl << flush;
    if (!found) {
        cout << "No student found with indicated ID" << endl;
    }
    return;
}




//Printall
void Roster::printAll() const {
    Student* const* sPoint = studentRecords;
    for (int i = 0; i < (this->numStudents); ++i) {
        (*sPoint)->print();
        ++sPoint;
    }

    return;
}


void Roster::printByIndex(int i) const{
    cout << "Current number of students is " << this->numStudents << endl;
    (this->studentRecords)[i]->print();
    return;
}



//Print average days in course for one student, identified by student ID

void Roster::printAverageDaysInCourse(string studentID) const {
    bool found = false;
    Student* sPoint = nullptr;
    for (int i = 0; i < this->numStudents; ++i) {
        sPoint = (this->studentRecords)[i];
        if (studentID == sPoint->getStudentID()) {
            found = true;
            break;
        }
    }
    if (found) {
        double averageDays = 0;
        for (int i = 0; i < 3; ++i) {
            averageDays += sPoint->getDaysToCompletion(i);
        }
        averageDays = averageDays / 3.0;
        cout << "Average days to completion for " << sPoint->getLastName() << ", " << sPoint->getFirstName();
        cout << " (" << sPoint->getStudentID() << ")" << " is " << averageDays << endl;
    }
    return;
}







//Check for and print any invalid emails
bool Roster::isValidEmail(string email) const{
    bool isValid = true; //Start by assuming email is valid
    int numPeriods = 0;
    int numAts = 0;



    for (unsigned int i = 0; i < email.size(); ++i) {
        if (isspace(email.at(i))) {
            isValid = false; //If email contains whitespace, it is invalid
            break;
        }
        else if (email.at(i) == '.') {
            ++numPeriods;
        }
        else if (email.at(i) == '@') {
            ++numAts;
        }
    }


    if(isValid){ //Skip this check if email is already known to be invalid
        if ((numPeriods != 1) || (numAts != 1)) { //Email is invalid if it doesn't contain exactly one period and exactly one "at" sign
            isValid = false;
        }
    }


    return isValid;
}





void Roster::printInvalidEmails() const {
    Student* sPoint = nullptr;
    bool isValid = false;
    string currentEmail = "";
    for(int i = 0; i < this->numStudents; ++i){
        sPoint = (this->studentRecords)[i];
        currentEmail = sPoint->getEmailAddress();
        isValid = this->isValidEmail(currentEmail);

        if (!isValid) {
            cout << sPoint->getLastName() << ", " << sPoint->getFirstName() << " (" << sPoint->getStudentID() << ") ";
            cout << "has an invalid email address: " << currentEmail << endl;
        }
    }
    return;
}



//Print by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    Student* const * sPoint = this->studentRecords;
    bool found = false;

    for (int i = 0; i < this->numStudents; ++i) {
        if ((*sPoint)->getDegreeProgram() == degreeProgram) {
            (*sPoint)->print();
            if (!found) {
                found = true;
            }
        }
        ++sPoint;
    }

    if (!found) {
        --sPoint; //Move back to last student
        cout << "No students found in " << (*sPoint)->degreeToString(degreeProgram) << " program." << endl;
    }
    return;
}


/*

//Debugging function
void Roster::check() const {

    cout << "Number of students is: " << this->numStudents << endl;
    for (int i = 0; i < this->numStudents; ++i) {
        cout << i << ": ";
;
        if ((this->studentRecords)[i] == nullptr) {
            cout << "Missing Record" << endl;
        }
        else {
            cout << this->studentRecords << " ";
            cout << (this->studentRecords)[i]->getStudentID() << " ";
            cout << (this->studentRecords)[i]->getLastName() << " ";
            cout << this->studentRecords[i]->getFirstName() << endl;
        }
    }
    return;
}

*/


int Roster::getNumStudents() const {
    return this->numStudents;
}

string Roster::getStudentID(int studentNum) const {
    Student* sPoint = (this->studentRecords)[studentNum];
    string out = sPoint->getStudentID();
    return out;
}