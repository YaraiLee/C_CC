#pragma once
#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
	//默认构造函数
	Person(string name = "jim", int age = 10);
	virtual ~Person();
	void play();
protected:
	string m_strName;
private:
	int m_iAge;	//private成员不能被子类继承
};