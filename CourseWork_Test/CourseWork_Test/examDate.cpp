#include "examDate.h"
examDate::examDate() : day(0), month(0), year(0) {}

examDate::examDate(int newDay, int newMonth, int newYear)
{
	if (newDay > 0 && newDay <= 31) {
		this->day = newDay;
	}
	else {
		throw "Incorrect day input. ";
	}

	if (newMonth > 0 && newMonth <= 12) {
		this->month = newMonth;
	}
	else {
		throw "Incorret month input. ";
	}
	this->year = newYear;
}

examDate::examDate(const examDate& original)
{
	day = original.day;
	month = original.month;
	year = original.year;
}

examDate::examDate(examDate&& other) noexcept
{
	day = move(other.day);
	month = move(other.month);
	year = move(other.year);

	other.day = 0;
	other.month = 0;
	other.year = 0;
}

void examDate::ShowExamDate()
{
	string formattedData = FormatDate();
	cout << "Exam date: " << formattedData << endl;
}

void examDate::DeleteDate()
{
	day = 0;
	month = 0;
	year = 0;
}

string examDate::GetMonthName() const
{
	static const string monthName[] = { "Invalid Month", "January", "February", "March",
		"April", "May", "June", "July", "August", "September", "October", "November", "December" };
	if (month >= 1 && month <= 12)
	{
		return monthName[month];
	}
	else {
		return monthName[0];
	}
}

string examDate::FormatDate()
{
	string monthName = GetMonthName();
	return to_string(day) + "." + monthName + "." + to_string(year);
}

examDate& examDate::operator=(const examDate& other)
{
	if (this != &other) {
		day = other.day;
		month = other.month;
		year = other.year;
	}
	return *this;
}
