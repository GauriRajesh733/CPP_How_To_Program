#include "PhoneNumber.h"
#include "Entity.h"
#include <iomanip>
using namespace std;


ostream& operator<<(ostream& output, const PhoneNumber& number)
{
    output << "Area code: " << number.areaCode << "\nExchange: "
        << number.exchange << "\nLine: " << number.line << "\n";
    return output;
}

istream& operator>>(istream& input, PhoneNumber& number)
{
    input.ignore(); // ignore '('
    input >> setw(3) >> number.areaCode;
    input.ignore(2); // ignore ') '
    input >> setw(3) >> number.exchange;
    input.ignore(); // ignore '-'
    input >> setw(4) >> number.line;
    return input;
}




