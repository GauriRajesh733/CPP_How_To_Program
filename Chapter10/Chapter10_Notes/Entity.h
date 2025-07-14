#pragma once
#include <iostream>
#include <string>

using namespace std;

class Entity
{
	friend ostream& operator<<(ostream& os, Entity& e) {
		os << "Name: " << e.m_Name << " Age: " << e.m_Age << endl;
	}
public:
	Entity(const string& name, int age)
		: m_Name(name), m_Age(age) {
	}
	explicit Entity(const string& name)
		: m_Name(name), m_Age(-1) {
	}

	Entity(int age)
		: m_Name("Unknown"), m_Age(age) {
	}

private:
	string m_Name;
	int m_Age;
};

