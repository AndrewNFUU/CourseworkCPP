#include "Person.h"

Person::Person() {}

Person::Person(string newFName, string newLName) : firstName(newFName), lastName(newLName){}

Person::Person(const Person& original) {
	firstName = original.firstName;
	lastName = original.lastName;
}

Person::Person(Person&& other) noexcept
{
	// move values from other_obj in current obj
	firstName = move(other.firstName);  // this->firstName = other.firstName
	lastName = move(other.lastName);

	// clear data in other
	other.firstName = "";
	other.lastName = "";
}

Person::~Person()
{
	// cleanup smth~
}


// Getters and Setters

string Person::GetFirstName()
{
	return firstName;
}

string Person::GetLastName()
{
	return lastName;
}

void Person::SetFirstName(string newFirstName)
{
	this->firstName = newFirstName;
}

void Person::SetLastName(string newLastName)
{
	this->lastName = newLastName;
}

void Person::DisplayInfo() 
{
	//cout << "\n---- Information ----\n";
	cout << "\nFirst name: " << firstName << endl;
	cout << "Last name: " << lastName << endl;
}


// Overloading Operators
Person Person::operator()(const string& newFirstName, const string& newLastName)
{
	// change crrent obj data fields values
	this->firstName = newFirstName;
	this->lastName = newLastName;

	// returns ref to current obj
	return *this;
}

Person& Person::operator=(const Person& original)
{
	/*if (&original == nullptr) {
		throw invalid_argument("Cannot copy from a nullptr");
	}*/ 
	
	//  ??????????????????????????

	// to avoid self-appropriation
	if (this != &original) {
		firstName = original.firstName;
		lastName = original.lastName;
	}
	// returns ref to current obj
	return *this;
}

Person& Person::operator=(Person&& other) noexcept
{
	// to avoid self-appropriation
	if (this != &other) {
		// move values from other to current obj
		firstName = move(other.firstName);
		lastName = move(other.lastName);

		// clear data in other
		other.firstName = "";
		other.lastName = "";
	}
	return *this;
}


/*Input >> and output << operators are not part of interface
of the class itself, so they can be defined outside its scope.*/
istream& operator>>(istream& in, Person& person)
{
	cout << "Enter first name: ";
	in >> person.firstName;

	cout << "Enter last name: ";
	in >> person.lastName;

	return in;
}

ostream& operator<<(ostream& out, const Person& person)
{
	out << "\n---- Information ----\n";
	out << "First name: " << person.firstName << endl;
	out << "Last name: " << person.lastName << endl;

	return out;
}
