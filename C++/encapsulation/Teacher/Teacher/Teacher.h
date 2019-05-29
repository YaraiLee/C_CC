#pragma once
#include <iostream>
#include <string>

using namespace std;

class Teacher {
public:
	Teacher(string name = "Jim", int age = 10);	//��������Ĭ��ֵ������Ĭ�Ϲ��캯��
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