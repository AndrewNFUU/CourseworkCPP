#pragma once
#include "Person.h"

class Student : public Person
{

private:
	UniversityGroup groupNum;

public: 
	Student();

	// 1
	Student(string newFName, string newLName, UniversityGroup newGroupNum);

	Student(const Student& original);

	Student(Student&& other) noexcept;

	~Student();

	// 2
	UniversityGroup GetGroupNumber();

	// 3
	void SetGroupNumber(UniversityGroup newGroupNum);

	void DisplayInfo() override;

	// 4
	// Overloading Operators
	Student operator()(const string& newFirstName, const string& newLastName, UniversityGroup newGroupNum);

	// assignment operator = for COPYING
	Student& operator=(const Student& original);

	// assignment operator = for MOVING
	Student& operator=(Student&& other) noexcept;

	// input operator 
	friend istream& operator>>(istream& in, Student& student);

	friend ostream& operator<<(ostream& out, const Student& student);
};

enum UniversityGroup {
	Underfiend,
	Computer_Science,
	Software_Engineering,
	Information_Technology,
	Cybersecurity,
	Data_Science
};