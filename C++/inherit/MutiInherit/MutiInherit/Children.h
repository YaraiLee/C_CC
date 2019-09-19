#pragma once
#include "Person.h"

/**
* 定义儿童类:Children
* 虚继承人类
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

	void eat() {
		cout << "Children eat()" << endl;
	}
protected:
	int m_iAge;
};