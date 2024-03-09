#pragma once
#include <iostream>
#include <string>

using namespace std;

class examDate
{
private:
	int day;
	int month;
	int year;

	/*time_t currentTime = time(nullptr);
	tm* localTime = localtime(&currentTime);*/

public:

	examDate();

	examDate(int newDay, int newMonth, int newYear);

	examDate(const examDate& original);

	examDate(examDate&& other) noexcept;

	void ShowExamDate();

	void DeleteDate();

	string GetMonthName() const;

	string FormatDate();

	examDate& operator=(const examDate& other);
};

enum Month
{
	empty,
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};