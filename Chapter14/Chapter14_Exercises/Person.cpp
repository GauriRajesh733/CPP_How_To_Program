#include "Person.h"

Person::Person(std::string lastname, std::string firstname, int age, int id)
    : age(age), id(id)
{
    setFirstName(firstname);
    setLastName(lastname);
}

void Person::setId(int newid)
{
    id = newid;
}

int Person::getId() const
{
    return id;
}

void Person::setFirstName(const std::string& newfirstname)
{
    size_t length{ newfirstname.size()};
    length = length < 10 ? length : 9;
    newfirstname.copy(firstName, length);
    firstName[length] = '\0';
}

std::string Person::getFirstName() const
{
    return firstName;
}

void Person::setLastName(const std::string& newlastname)
{
    size_t length{ newlastname.size() };
    length = length < 15 ? length : 14;
    newlastname.copy(lastName, length);
    lastName[length] = '\0';
}

std::string Person::getLastName() const
{
    return lastName;
}

void Person::setAge(int newage)
{
    age = newage;
}

int Person::getAge() const
{
    return age;
}
