#pragma once
#include <iostream>

using namespace std;
/**
* ��������: Person
*/
class Person
{
public:
	Person()
	{
		cout << "Person" << endl;
	}
	virtual ~Person()
	{
		cout << "~Person" << endl;
	}
	virtual void eat()
	{
		cout << "Person eat()" << endl;
	}

};