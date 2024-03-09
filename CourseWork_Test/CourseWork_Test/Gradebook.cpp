#include "Gradebook.h"

Gradebook::Gradebook() {}

Gradebook::Gradebook(const vector<Exam>& newExams) : exams(newExams)
{
}

void Gradebook::addExam(const Exam& exam)
{
	exams.push_back(exam);
}

void Gradebook::showExamResults()
{
	cout << "----- Exam Book -----\n";
	for (Exam& exam : exams) {
		exam.DisplayInfo();
	}
		
}
