#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person	//������
{
public:
	Person(string name);
	virtual ~Person();
	virtual void printInfo() = 0;	//���麯��
protected:
	string m_strName;
private:
};
