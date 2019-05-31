#pragma once
#include "Person.h"

/**
* �����ͯ��:Children
* ��̳�����
*/
class Children : virtual public Person
{
public:
	Children(int age)
	{
		m_iAge = age;
		cout << "Children" << endl;
	}
	virtual ~Children()
	{
		cout << "~Children" << endl;
	}
	void play()
	{
		cout << m_iAge << endl;
		cout << "play" << endl;
	}
protected:
	int m_iAge;
};