#include "Point.h"

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "(" << point.x << "," << point.y << ")" << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, const Point& point)
{
    int x;
    int y;
    
    // if input not valid set failbit to indicate improper input
    
    
    // cannot display point after input error occurred
}
