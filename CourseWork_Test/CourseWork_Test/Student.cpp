#include "Student.h"

Student::Student() {}

Student::Student(string newFName, string newLName, UniversityGroup newGroupNum) :
	Person(newFName, newLName), groupNum(newGroupNum) {}

Student::Student(const Student& original) : Person(original)
{
	groupNum = original.groupNum;
}

Student::Student(Student&& other) noexcept : Person(move(other))
{
	groupNum = move(other.groupNum);
}

Student::~Student()
{
}

UniversityGroup Student::GetGroupNumber()
{
	return groupNum;
}

void Student::SetGroupNumber(UniversityGroup newGroupNum)
{
	this->groupNum = newGroupNum;
}

void Student::DisplayInfo()  
{
	Person::DisplayInfo(); // Call base class DisplayInfo
	cout << "Group number: " << groupNum << endl;
}


// Overloading Operators

// question -------> зробити його повністю константним????
Student Student::operator()(const string& newFirstName, const string& newLastName, UniversityGroup newGroupNum)
{
	// call the base class operator() to set Person values
	Person::operator()(newFirstName, newLastName);

	// change crrent obj data field values
	this->groupNum = newGroupNum;

	return *this;
}

Student& Student::operator=(const Student& original)
{
	/*if (&original == nullptr) {
		throw invalid_argument("Cannot copy from a nullptr");
	}*/

	Person::operator=(original);

	if (this != &original) {
		groupNum = original.groupNum;
	}

	return *this;
}

Student& Student::operator=(Student&& other) noexcept
{
	Person::operator=(move(other));

	if (this != &other) {
		groupNum = move(other.groupNum);
	}

	return *this;
}

istream& operator>>(istream& in, Student& student)
{
	in >> static_cast<Person&>(student);

	cout << "Enter group number: ";
	int groupIndex{};
	in >> groupIndex;

	if (groupIndex >= 0 && groupIndex <= UniversityGroup::Data_Science) {
		student.groupNum = static_cast<UniversityGroup>(groupIndex);
	}
	else {
		cout << "Invalid group number. Setting to Undefined. \n";
		student.groupNum = Underfiend;
	}

	return in;
}

ostream& operator<<(ostream& out, const Student& student)
{
	out << static_cast<const Person&>(student);

	out << "Group number: " << student.groupNum << endl;

	return out;
}
