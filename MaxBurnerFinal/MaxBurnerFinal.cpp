// MaxBurnerFinal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Roster.h"

#define LINE cout << endl







const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Maxwell,Burner,mbur215@wgu.edu,30,22,15,31,SOFTWARE" };





int main()
{
    cout << "C867 - Scripting and Programming - Applications" << endl;
    cout << "C++" << endl;
    cout << "ID: 002005686, Name: Maxwell Burner" << endl;

    Roster classRoster;
    int rosterLength = 5;

    for (int i = 0; i < rosterLength; ++i) {
        classRoster.add(studentData[i]);
    }

    //Print ALl
    classRoster.printAll();

    LINE;

    //Print invalid emails
    classRoster.printInvalidEmails();

    LINE;

    //Print average days in course
    string currentID = "";
    for (int i = 0; i < rosterLength; ++i) {
        currentID = classRoster.getStudentID(i);
        classRoster.printAverageDaysInCourse(currentID);
    }

    LINE;

    //Print software students
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);


    //Remove student and print all
    classRoster.remove("A3");
    classRoster.printAll();

    LINE;

    classRoster.remove("A3");


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
