#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person	//³éÏóÀà
{
public:
	Person(string name);
	virtual ~Person();
	virtual void printInfo() = 0;	//´¿Ğéº¯Êı
protected:
	string m_strName;
private:
};
