#pragma once
#include <iostream>
#include <string>

using namespace std;

class Teacher {
public:
	Teacher(string name = "Jim", int age = 10);	//参数都有默认值，则是默认构造函数
	Teacher(const Teacher& t);
	~Teacher();
	void setName(string name);
	string getName();
	void setAge(int age);
	int getAge();
private:
	string m_strName;
	int m_iAge;
};