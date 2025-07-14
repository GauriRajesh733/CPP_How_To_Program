#include "Date.h"
using namespace std;

// class constant
const array<unsigned int, 13> Date::days{
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

Date& Date::operator++() {
	helpIncrement(); // increment date
	// NOTE: lvalue refers to something that can be 
	// located in memory and potentially modified
	return *this; // reference return to create lvalue
}

Date Date::operator++(int) {
	Date temp{ *this }; // hold current state
	helpIncrement();

	return temp; // return unincremented, temporary object
}


Date::Date(int m, int d, int y)
{
	setDate(m, d, y);
}

void Date::setDate(int m, int d, int y)
{
	if (m < 1 || m > 12) {
		throw invalid_argument("Month must be 1-12.");
	}

	if (y > 2100 || y < 1900) {
		throw invalid_argument("Year must be 1900-2100");
	}

	if ((d < 1 || d > days[m]) || (leapYear(y) && m == 2 && d > 29)) {
		throw invalid_argument("Day is invalid based on month and year.");
	}

	month = m;
	day = d;
	year = y;
}

Date& Date::operator+=(unsigned int addDays)
{
	for (unsigned int i = 0; i < addDays; i++) {
		helpIncrement();
	}

	return *this; // allow chaining
}

bool Date::leapYear(int y)
{
	return (y % 400 == 0
		|| (y % 100 != 0 && y % 4 == 0));
}

bool Date::endOfMonth(int d) const
{
	// February
	if (month == 2 && leapYear(year)) {
		return d == 29;
	}
	return d == days[month];
}

void Date::helpIncrement()
{
	// increment day
	if (!endOfMonth(day)) {
		day++;
	}
	else {
		// end of year
		if (month == 12) {
			year++;
			month = 1;
			day = 1;
		}
		// end of month
		else {
			month++;
			day = 1;
		}
	}
}

ostream& operator<<(ostream& output, Date d) {
	static string monthName[13]{ "", "January", "February", "March", "April", "May",
	"June", "July", "August", "September", "October", "November", "December" };

	output << monthName[d.month] << " " << d.day << ", " << d.year << endl;
	return output;
}
