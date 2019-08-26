#pragma once

#include "Person.h"

class Soldier : public Person {
public:
	//默认构造函数
	Soldier(string name = "Lee", int age = 29);
	~Soldier();
	bool play(string name, int age);
	void work();
protected:
	int m_iAge;	//隐藏从父类继承的同名变量
};
