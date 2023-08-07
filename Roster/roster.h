#pragma once
#include "student.h"
class Roster
{
private:
	int lastIndex = -1;
	/*const static int numStudents = 5;
	Student* classRosterArray[numStudents];*/

public:
	const static int numStudents = 5;
	Student* classRosterArray[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	void parse(string row);
	void add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		string age,
		double daysInCourse1,
		double daysInCourse2,
		double daysInCourse3,
		DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAveragedaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	~Roster();
};