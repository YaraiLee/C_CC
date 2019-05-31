#pragma once
#include "Person.h"

class Worker : public Person
{
public:
	Worker(string name, string code);
	virtual ~Worker();
	virtual void printInfo() = 0;
	virtual void work();
protected:
	string m_strCode;
};

