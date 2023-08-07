#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student
{
public:
	const static int daysInCourse = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	string age;
	double days[daysInCourse];
	DegreeProgram degreeprogram;
public:
	Student();/*setting default value*/
	Student(string studentID, string firstName, string lastName, string emailAddress, string age, double daysInCourse[], DegreeProgram degreeprogram);
	~Student();/*destructor*/

	/*getters*/
	string getID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	string getAge();
	double* getDays();
	DegreeProgram getDegreeProgram();

	/*setters*/
	void setID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(string age);
	void setDays(double daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print();
	void printAve();
};