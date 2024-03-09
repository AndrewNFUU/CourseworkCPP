#include "Exam.h"


Exam::Exam(string studFirstName, string studLastName, UniversityGroup group, 
	string teacherFirstName, string teacherLastName, TeacherPosition newPosition, 
	string subject, double hours, examDate date, double grade) :
	Student(studFirstName, studLastName, group),
	Teacher(teacherFirstName, teacherLastName, newPosition),
	subjectName(subject), 
	studyHours(hours), 
	examDate(date), 
	grade(grade) {}


//Exam::Exam(string studFirstName, string studLastName, UniversityGroup group, string teacherFirstName, 
//	string teacherLastName, string subject, double hours, examDate date, double grade) { }

Exam::Exam(const Exam& original) :
	Student(original), 
	Teacher(original), 
	subjectName(original.subjectName), 
	studyHours(original.studyHours), 
	examDate(original),
	grade(original.grade) {}

Exam::Exam(Exam&& other) noexcept : 
	Student(move(other)), 
	Teacher(move(other)), 
	subjectName(move(other.subjectName)), 
	studyHours(move(other.studyHours)), 
	examDate(move(other.examDate)),
	grade(move(other.grade)) {}

Exam::~Exam() {}


// Getters and Setters

string Exam::GetSubjectName()
{
	return subjectName;
}

double Exam::GetStudyHours()
{
	return studyHours;
}



examDate Exam::GetExamDate()
{
	return examDate;
}

double Exam::GetGrade()
{
	return grade;
}

void Exam::SetSubjectName(string newSubjectName)
{
	this->subjectName = newSubjectName;
}

void Exam::SetStudyHours(double newStudyHours)
{
	this->studyHours = newStudyHours;
}

void Exam::SetExamDate(examDate newExamDate)
{
	this->examDate = newExamDate;
}

void Exam::SetGrade(double newGrade)
{
	this->grade = newGrade;
}

void Exam::DisplayInfo() 
{
	cout << "\n-- Exam Information --\n";
	cout << "Subject: " << subjectName << endl;
	cout << "Study hours: " << studyHours << endl;
	examDate.ShowExamDate();                      // ------ ?
	cout << "Grade: " << grade << endl;
	cout << "----------------------\n";
	cout << "\tStudent: ";
	Student::DisplayInfo();

	cout << "\n\tTeacher: ";
	Teacher::DisplayInfo();
	cout << "----------------------\n";
}


// get grades
 
// такий самий для мінімальних балів?
double Exam::GetMaxGrades(vector<Exam>& exams) {
	if (exams.empty()) {
		return 0.0;
	}
	else {
		double maxGrade = exams[0].GetGrade();
		for (Exam& exam : exams) {
			if (exam.GetGrade() > maxGrade) {
				maxGrade = exam.GetGrade();
			}
		}
		return maxGrade;
	}
}

double GetAvgGrades(vector<Exam>& exams) {
	if (exams.empty()) {
		return 0.0;
	}
	else {
		double sumGrades{};
		for (Exam& exam : exams) {
			sumGrades += exam.GetGrade();
		}

		return sumGrades / exams.size();
	}
}