#pragma once
#include <iostream>
#include <string>

using namespace std;

class Entity
{
public:
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

