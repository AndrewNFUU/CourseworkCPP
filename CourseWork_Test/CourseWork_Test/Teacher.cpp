#include "Teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(string newFName, string newLName, TeacherPosition newPosition) :
	Person(newFName, newLName), position(newPosition) {}

Teacher::Teacher(const Teacher& original) : Person(original)
{
	position = original.position;
}

Teacher::Teacher(Teacher&& other) noexcept : Person(move(other))
{
	position = move(other.position);
}

Teacher::~Teacher()
{
}


// Getters and Setters
TeacherPosition Teacher::GetPosition()
{
	return position;
}

void Teacher::SetPosition(TeacherPosition newPosition)
{
	this->position = newPosition;
}

void Teacher::DisplayInfo()
{
	Person::DisplayInfo();
	cout << "Position: " << position << endl;
}


// Overloading Operators

Teacher Teacher::operator()(const string& newFirstName, const string& newLastName, TeacherPosition newPosition)
{
	Person::operator()(newFirstName, newLastName);

	this->position = newPosition;

	return *this;
}

Teacher& Teacher::operator=(const Teacher& original)
{
	Person::operator=(original);

	// to avoid self-appropriation
	if (this != &original) {
		position = original.position;
	}

	return *this;
}

Teacher& Teacher::operator=(Teacher&& other) noexcept
{
	Person::operator=(move(other));

	if (this != &other) {
		position = move(other.position);
	}

	return *this;
}

istream& operator>>(istream& in, Teacher& teacher)
{
	in >> static_cast<Person&>(teacher);

	cout << "Enter position: ";
	int positionValue{};
	in >> positionValue;
		//teacher.position;

	// перевірку на введення?

	return in;
}

ostream& operator<<(ostream& out, const Teacher& teacher)
{
	out << static_cast<const Person&>(teacher);

	out << "Position: " << teacher.position << endl;

	return out;
}
