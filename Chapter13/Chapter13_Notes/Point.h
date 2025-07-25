#pragma once
#include <iostream>
class Point
{
public:
	friend std::ostream& operator<<(std::ostream&, const Point&);
	friend std::istream& operator>>(std::istream&, const Point&);


private:
	int x;
	int y;
};

