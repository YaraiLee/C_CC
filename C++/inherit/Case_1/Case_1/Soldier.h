#pragma once

#include "Person.h"

class Soldier : public Person {
public:
	//Ĭ�Ϲ��캯��
	Soldier(string name = "Lee", int age = 29);
	~Soldier();
	bool play(string name, int age);
	void work();
protected:
	int m_iAge;	//���شӸ���̳е�ͬ������
};
