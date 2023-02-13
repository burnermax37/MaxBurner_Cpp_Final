#ifndef ROSTER_H
#define ROSTER_H

#include "Student.h"


class Roster {
public:
    Roster();
    ~Roster();

    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompletion[3], DegreeProgram studentProgram);
    void add(string student);
    void remove(string studentID);
    void printAll() const;
    void printAverageDaysInCourse(string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;


    void printByIndex(int i) const;

    int getNumStudents() const;
    string getStudentID(int studentNum) const;

    //void check() const; //For debugging
private:
    static const int MAX_RECORDS = 50;
    Student* studentRecords[MAX_RECORDS];
    int numStudents;

    void fillSpaces(string& input) const;
    void unFill(string& input) const;
    void commasToSpaces(string& input) const;

    DegreeProgram stringToDegree(const string& input) const;
    //string degreeToString(DegreeProgram degreeProgram) const;


    bool isValidEmail(string email) const; //TODO
};

#endif // !ROSTER_H

