#pragma once

// NOTE: ifndef and endif are include guards that prevent
// headers from being included more than once in a source code file

#include <string>
#ifndef TIME_H
#define TIME_H

class Time
{
public:
	Time();
	explicit Time(int, int, int); // default constructor
    Time(int, int); // overloaded constructor
	void setTime(int, int, int); // hour, minute, second
	void setHour(int);
	void setMinute(int);
	void setSecond(int);

	std::string toUniversalString() const; // 24 hour clock
	std::string toStandardString() const; // 12 hour clock
private:
	unsigned int hour{ 0 };
	unsigned int minute{ 0 };
	unsigned int second{ 0 };
};

#endif


