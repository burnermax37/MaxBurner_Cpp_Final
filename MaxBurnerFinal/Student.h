#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>

class Student {
public:
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompletion[3], DegreeProgram degreeProgram);

    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysToCompletion(int* daysToCompletion);
    void setProgram(DegreeProgram degreeProgram);

    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    int getDaysToCompletion(int course) const;
    DegreeProgram getDegreeProgram() const;
    string degreeToString(DegreeProgram degreeProgram) const;


    void print() const; //TODO?


private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    const static int COURSE_NUMBER = 3;
    int age;
    int daysToCompletion[COURSE_NUMBER];
    DegreeProgram degreeProgram;



};


#endif // !STUDENT_H
