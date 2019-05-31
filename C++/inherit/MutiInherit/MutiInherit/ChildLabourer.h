#pragma once
#include "Children.h"
#include "Worker.h"
/**
* ����ͯ���ࣺChildLabourer
* ���м̳й�����Ͷ�ͯ��
*/
class ChildLabourer : public Worker, public Children
{
public:
	ChildLabourer(string name, int age) :Worker(name), Children(age)
	{
		cout << "ChildLabourer" << endl;
	}

	~ChildLabourer()
	{
		cout << "~ChildLabourer" << endl;
	}
};
