#pragma once
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include "examDate.h"

class Exam : public Student
{
private: 
	string subjectName = "";
	double studyHours{};
	examDate examDate;
	double grade{};
	Teacher examenator;

public: 
	Exam() {};

	Exam(string studFirstName, string studLastName, UniversityGroup group, string teacherFirstName,
		string teacherLastName, TeacherPosition newPosition, string subject, double hours, examDate date, double grade);

	Exam(const Exam& original);

	Exam(Exam&& other) noexcept;

	~Exam(); 

	
	// Getters and Setters
	string GetSubjectName();

	double GetStudyHours();

	examDate GetExamDate();

	double GetGrade();

	void SetSubjectName(string newSubjectName);
	
	void SetStudyHours(double newStudyHours);

	void SetExamDate(examDate newExamDate);

	void SetGrade(double newGrade);

	void DisplayInfo() override;

	// grades satic methods
	static double GetMaxGrades(vector<Exam>& exams);
	
	static double GetMinGrades(vector<Exam>& exams);
	
	static double GetAvgGrades(vector<Exam>& exams);

	// Overloading Operators
	
};

