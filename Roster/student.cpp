#include "student.h"
Student::Student()/*setting default value*/
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = "";
	for (int i = 0; i < daysInCourse; i++) this->days[i] = 0;
	this->degreeprogram = DegreeProgram::UNDECIDED;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, string age, double days[], DegreeProgram degreeprogram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysInCourse; i++) this->days[i] = days[i];
	this->degreeprogram = degreeprogram;
}

Student::~Student() {}

string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
string Student::getAge() { return this->age; }
double* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeProgram() { return this->degreeprogram; }

void Student::setID(string ID) { this->studentID = ID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(string age) { this->age = age; }
void Student::setDays(double days[])
{
	for (int i = 0; i < daysInCourse; i++) this->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeprogram = degreeProgram; }


void Student::print() /*formatting for the print*/
{
	cout << this->getID() << '\t';
	cout << "First Name: " << this->getFirstName() << '\t';
	cout << "Last Name: " << this->getLastName() << '\t';
	cout << "Age: " << this->getAge() << '\t';
	cout << "Days In Course: {" << this->getDays()[0] << ',';
	cout << this->getDays()[1] << ',';
	cout << this->getDays()[2] << "}" << '\t';
	cout << "Degree Program: " << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}

void Student::printAve() //formatting for print average days in course
{
	cout << this->getID() << ": ";//getting ID of student
	cout << (this->getDays()[0]
		+ this->getDays()[1]
		+ this->getDays()[2]) / 3.0 << std::endl;//taking all numbers in days in course and dividing by three
}