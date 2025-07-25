#pragma once
#include <string>

class Person
{
public:
	Person(std::string = "unassigned", std::string = "", int = 0, int = -1);

	void setId(int);
	int getId() const;

	void setFirstName(const std::string&);
	std::string getFirstName() const;

	void setLastName(const std::string&);
	std::string getLastName() const;

	void setAge(int);
	int getAge() const;
private:
	char lastName[15];
	char firstName[10];
	int age;
	int id;
};

