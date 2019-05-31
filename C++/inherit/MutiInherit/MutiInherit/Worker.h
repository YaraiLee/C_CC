#pragma once
#include "Person.h"
#include <string>

/**
* ���幤����: Worker
* ��̳�����
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
