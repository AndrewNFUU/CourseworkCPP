#pragma once
#include "Person.h"

class Teacher : public Person
{
private: 
	TeacherPosition position;

public: 
	Teacher();

	Teacher(string newFName, string newLName, TeacherPosition newPosition);

	Teacher(const Teacher& original);

	Teacher(Teacher&& other) noexcept;

	~Teacher();

	TeacherPosition GetPosition();

	void SetPosition(TeacherPosition newPosition);

	void DisplayInfo() override;

	Teacher operator()(const string& newFirstName, const string& newLastName, TeacherPosition newPosition);

	// assignment operator = for COPYING
	Teacher& operator=(const Teacher& original);

	// assignment operator = for MOVING
	Teacher& operator=(Teacher&& other) noexcept;

	// input operator 
	friend istream& operator>>(istream& in, Teacher& teacher);

	friend ostream& operator<<(ostream& out, const Teacher& teacher);
};

enum TeacherPosition {
	Assistant = 1,
	Senior_Lecturer,
	Docent,
	Professor
};