#include "Time.h"
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <string>

using namespace std;

Time::Time(int hour, int minute, int second) {
	setTime(hour, minute, second);
}

Time::Time() {
	Time(0, 0, 0);
}

Time::Time(int hour, int minute)
{
	Time(hour, minute, 0);
}

void Time::setTime(int h, int m, int s) {
	if ((h >= 0 && h <= 24) && (m >= 0 && m <= 59) && (s >= 0 && s <= 59)) {
		hour = h;
		minute = m;
		second = s;
	}
	else {
		throw invalid_argument("hour, minute, or second was out of range.");
	}
}

void Time::setHour(int h) {
	setTime(h, this->minute, this->second);
}

void Time::setMinute(int m) {
	setTime(this->hour, m, this->second);
}

void Time::setSecond(int s) {
	setTime(this->hour, this->minute, s);
}

string Time::toUniversalString() const {
	ostringstream output;
	output << setfill('0') << setw(2) << hour << ":" <<
		setw(2) << minute << setw(2) << second;
	return output.str();
}

string Time::toStandardString() const {
	ostringstream output;
	output << setfill('0') << setw(2) << hour % 12 << ":" <<
		setw(2) << minute << ":" << setw(2) << second << (hour < 12 ? "AM" : "PM");
	return output.str();
}

