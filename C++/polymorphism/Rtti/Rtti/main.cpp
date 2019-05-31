/************************************************************************/
/* RTTI 
	1.dynamic_cast
		1)只能应用于指针和引用的转换
		2）要转换的类型必须包含虚函数
		3）转换成功返回子类的地址，失败返回NULL
	2.typeid
		1)返回一个type_info对象的引用
		2)如果想通过积累的指针获得派生类的数据类型，基类必须带有虚函数
		3）只能获取对象的实际类型
*/
/************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <typeinfo>
using namespace std;

/**
* 定义移动类：Movable
* 纯虚函数：move
*/
class Movable
{
public:
	virtual void move() = 0;
};

/**
* 定义公交车类：Bus
* 公有继承移动类
* 特有方法carry
*/
class Bus : public Movable
{
public:
	virtual void move()
	{
		cout << "Bus -- move" << endl;
	}

	void carry()
	{
		cout << "Bus -- carry" << endl;
	}
};

/**
* 定义坦克类：Tank
* 公有继承移动类
* 特有方法fire
*/
class Tank :public Movable
{
public:
	virtual void move()
	{
		cout << "Tank -- move" << endl;
	}

	void fire()
	{
		cout << "Tank -- fire" << endl;
	}
};

/**
* 定义函数doSomething含参数
* 使用dynamic_cast转换类型
*/
void doSomething(Movable *obj)
{
	obj->move();
	cout << typeid(*obj).name() << endl;

	if (typeid(*obj) == typeid(Bus))
	{
		Bus *bus = dynamic_cast<Bus *>(obj); //只能应用于指针和引用的转换
		bus->carry();
	}

	if (typeid(*obj) == typeid(Tank))
	{
		Tank *tank = dynamic_cast<Tank *>(obj);
		tank->fire();
	}
}

int main(void)
{
	Bus b;
	Tank t;
	doSomething(&b);
	doSomething(&t);

	system("pause");
	return 0;
}