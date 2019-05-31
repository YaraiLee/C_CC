#pragma once
#include "Person.h"
#include <string>

/**
* 定义工人类: Worker
* 虚继承人类
*/
class Worker : virtual public Person
{
public:
	Worker(string name)
	{
		m_strName = name;
		cout << "Worker" << endl;
	}
	virtual ~Worker()
	{
		cout << "~Worker" << endl;
	}
	void work()
	{
		cout << m_strName << endl;
		cout << "work" << endl;
	}

	void eat() {
		cout << "Worker eat()" << endl;
	}
protected:
	string m_strName;
};
