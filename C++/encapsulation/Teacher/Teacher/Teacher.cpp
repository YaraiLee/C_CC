#include "Teacher.h"
#include <iostream>
using namespace std;
//构造函数建议使用初始化列表，初始化成员变量
Teacher::Teacher(string name, int age):m_strName(name),m_iAge(age)
{
	cout << "Teacher(string name, int age):m_strName(name),m_iAge(age)" << endl;
}
//拷贝构造函数
Teacher::Teacher(const Teacher& t)
{
	m_strName = t.m_strName;
	m_iAge = t.m_iAge;
	cout << "Teacher(const Teacher& t)" << endl;
}

Teacher::~Teacher()
{
	cout << "~Teacher()" << endl;
}

string Teacher::getName()
{
	return m_strName;
}

void Teacher::setName(string name)
{
	m_strName = name;
}

void Teacher::setAge(int age)
{
	m_iAge = age;
}

int Teacher::getAge()
{
	return m_iAge;
}