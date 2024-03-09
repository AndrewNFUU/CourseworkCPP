#pragma once

#include <iostream>
using namespace std;

class Person
{
private: 
	string firstName = "";
	string lastName = "";

public: 
	Person(); 

	Person(string newFName, string newLName); 

	Person(const Person& original); 

	Person(Person&& other) noexcept; // ----------------- question 

	~Person();

	// Getters and Setters
	string GetFirstName();

	string GetLastName();

	void SetFirstName(string newFirstName);

	void SetLastName(string newLastName);

	virtual void DisplayInfo();


	// Overloading Operators
	Person operator()(const string& newFirstName, const string& newLastName);

	// assignment operator = for COPYING
	Person& operator=(const Person& original);

	// assignment operator = for MOVING
	Person& operator=(Person&& other) noexcept;

	friend istream& operator>>(istream& in, Person& person);

	friend ostream& operator<<(ostream& out, const Person& person);
};


