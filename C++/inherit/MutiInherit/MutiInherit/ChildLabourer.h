#pragma once
#include "Children.h"
#include "Worker.h"
/**
* 定义童工类：ChildLabourer
* 公有继承工人类和儿童类
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

	void eat() {
		cout << "ChildLabourer eat()" << endl;
	}
};
