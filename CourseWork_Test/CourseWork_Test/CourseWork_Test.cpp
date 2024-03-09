#include <iostream>
#include <vector>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Exam.h"
#include "Gradebook.h"

using namespace std;

int main()
{
	/*Person person("John", "Wick");
	
	Person person_2 = person; 

	Person person_3 = move(person_2); 
	person_3.DisplayInfo();

	
	Student student("Allen", "Iverson", "CS 41/2");
	cout << student << endl;
 

	Teacher teacher("Stephen", "King", "Professor");
	teacher.DisplayInfo();


	Person person222(person);
	cout << person222 << endl;

	
	Student student_test = move(student);
	student_test.DisplayInfo();*/

	// late binding e.g.
	Student st1("LeBron", "James", "Lakers");
	Person* perPtr = &st1;
	perPtr->DisplayInfo(); // ств масив 

	// task 6 ---> output exam results
	examDate examDate_1(5, 5, 2024);
	examDate examDate_2(6, 5, 2024);
	examDate examDate_3(3, 5, 2024);

	Exam exam1("Anthony", "Davis", "LAL 21/2", "Steve", "Kerr", "Basketball", 180.5, examDate_1, 4.9);
	Exam exam2("Jannis", "Free", "MLB 22/1", "Steve", "Kerr", "Basketball", 190.0, examDate_2, 4.8);
	Exam exam3("Jimmy", "Butler", "HET 21/1", "Steve", "Kerr", "Basketball", 200.5, examDate_3, 5.0);

	Gradebook gradeBook;

	gradeBook.addExam(exam1); gradeBook.addExam(exam2); gradeBook.addExam(exam3);

	gradeBook.showExamResults();

	return 0;
}