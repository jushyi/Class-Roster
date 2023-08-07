#include "roster.h"

int main()
{

	const string studentData[] =

	{ 
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
		"A5,Joshua,Maserin,jmaser3@wgu.edu,18,40,35,27,SOFTWARE"
	};

	const int numStudents = 5;
	Roster classRoster;

	cout << "SCRIPTING AND PROGRAMMING - APPLICATIONS - C867" << std::endl;
	cout << "C++" << std::endl;
	cout << "Student ID: 001533530" << std::endl;
	cout << "Joshua Jireh Maserin\n" << std::endl;

	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
	cout << "Displaying all students: " << std::endl;
	classRoster.printAll();
	cout << std::endl;

	cout << "Displaying invalid emails" << std::endl;
	classRoster.printInvalidEmails();
	cout << std::endl;

	cout << "Displaying average days taken to complete a course: " << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		classRoster.printAveragedaysInCourse(classRoster.classRosterArray[i]->getID());

	}
	cout << std::endl;

	//added this to main to prove you can print average days in course for one student that is passed as a parameter
	classRoster.printAveragedaysInCourse("A5"); 
	cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		cout << "Displaying by degree program: " << degreeProgramStrings[i] << std::endl;
		classRoster.printByDegreeProgram((DegreeProgram)i);
	}

	cout << "Removing student with ID A3:" << std::endl;
	classRoster.remove("A3");
	cout << std::endl;

	cout << "Displaying all students: " << std::endl;
	classRoster.printAll();
	cout << std::endl;

	cout << "Removing student with ID A3:" << std::endl;
	classRoster.remove("A3");
	cout << std::endl;

	system("pause");
	return 0;
}