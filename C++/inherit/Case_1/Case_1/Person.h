#pragma once
#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
	//Ĭ�Ϲ��캯��
	Person(string name = "jim", int age = 10);
	virtual ~Person();
	void play();
protected:
	string m_strName;
private:
	int m_iAge;	//private��Ա���ܱ�����̳�
};