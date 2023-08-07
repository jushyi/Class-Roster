#include "roster.h"
void Roster::parse(string studentData)
{
	DegreeProgram degreeProgram = UNDECIDED;
	if (studentData.back() == 'K') degreeProgram = NETWORK;/*finds last letter of each program which tells us the degree*/
	else if (studentData.back() == 'Y') degreeProgram = SECURITY;
	else if (studentData.back() == 'E') degreeProgram = SOFTWARE;

	int rhs = studentData.find(",");/*finds first comma in input string*/
	string studentID = studentData.substr(0, rhs);/*takes everything before the comma*/
	/*this is the student ID*/

	int lhs = rhs + 1;/*moves past the first comma*/
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);/*first name*/

	lhs = rhs + 1;/*repeating for each comma*/
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);/*last name*/


	lhs = rhs + 1;/*repeating for each comma*/
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);/*email address*/

	lhs = rhs + 1;/*repeating for each comma*/
	rhs = studentData.find(",", lhs);
	string age = studentData.substr(lhs, rhs - lhs);/*age*/

	lhs = rhs + 1;/*repeating for each comma*/
	rhs = studentData.find(",", lhs);
	double daysInCourse1 = stod(studentData.substr(lhs, rhs - lhs));/*days to complete course 1*/
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double daysInCourse2 = stod(studentData.substr(lhs, rhs - lhs));/*days to complete course 2*/
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double daysInCourse3 = stod(studentData.substr(lhs, rhs - lhs));/*days to complete course 3*/


	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, string age, double daysInCourse1, double daysInCourse2, double daysInCourse3, DegreeProgram degreeProgram)
{
	double parr[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, parr, degreeProgram);
}


void Roster::remove(string studentID)/*removes a student based on the student ID*/
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << studentID << " removed from list." << std::endl << std::endl;
		this->printAll();
		cout << std::endl;
	}
	else cout << studentID << " not found." << std::endl << std::endl;
}


void Roster::printAll()/*displays all students and data following format*/
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			classRosterArray[i]->print();
		}
		{
			/*cout << classRosterArray[i]->getID(); cout << '\t';
			cout << "First Name: " << classRosterArray[i]->getFirstName(); cout << '\t';
			cout << "Last Name: " << classRosterArray[i]->getLastName(); cout << '\t';
			cout << "Age: " << classRosterArray[i]->getAge(); cout << '\t';
			cout << "Days In Course: {" << classRosterArray[i]->getDays()[0]; cout << ',';
			cout << classRosterArray[i]->getDays()[1]; cout << ',';
			cout << classRosterArray[i]->getDays()[2]; cout << "}" << '\t';
			cout << "Degree Program: " << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;*/
		}
		
	}
}

void Roster::printAveragedaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID) classRosterArray[i]->printAve();
		//getting ID of student and then using the printAve function from student.cpp to print average days in course
		{
			/*cout << classRosterArray[i]->getID() << ": ";//getting ID of student
			cout << (classRosterArray[i]->getDays()[0]
				+ classRosterArray[i]->getDays()[1]
				+ classRosterArray[i]->getDays()[2]) / 3.0 << std::endl;//taking all numbers in days in course and dividing by three*/
		}
	}
}

void Roster::printInvalidEmails() 
/*valid email has no spaces and requires both a "@" and "."*/
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++) 
	{
		string emailAddress = (classRosterArray[i]->getEmailAddress());
		if ((emailAddress.find("@") == string::npos) || (emailAddress.find(".") == string::npos) || (emailAddress.find(" ") != string::npos))
		{

			any = true;
			cout << ": " << emailAddress <<  std::endl;
		}
	}
	if (!any) cout << "No invalid emails!" << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram dp)
{
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();
	}
	cout << std::endl;
}

Roster::~Roster()
{
	cout << "Destructer GO!!!" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}