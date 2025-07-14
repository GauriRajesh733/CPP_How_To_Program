#pragma once
#include <array>
#include <iostream>
using namespace std;

class Date
{
	friend 	ostream& operator<<(ostream&, Date);
public:
	Date(int m = 1, int d = 1, int y = 1900);

	void setDate(int, int, int);

	Date& operator++(); // prefix increment operator
	
	Date operator++(int); // postfix incrememnt operator
	
	Date& operator+=(unsigned int); // add days and modify object
	
	static bool leapYear(int);
	
	bool endOfMonth(int) const;

private:
	unsigned int month;
	unsigned int day;
	unsigned int year;

	static const array<unsigned int, 13> days;
	void helpIncrement();
};

