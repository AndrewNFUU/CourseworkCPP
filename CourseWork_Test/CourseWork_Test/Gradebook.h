#pragma once
#include <vector>
#include "Exam.h"

using namespace std;

class Gradebook {
private:
	vector<Exam> exams;

public:
	Gradebook();

	Gradebook(const vector<Exam>& newExams);

	void addExam(const Exam& exam);

	void showExamResults();
};

