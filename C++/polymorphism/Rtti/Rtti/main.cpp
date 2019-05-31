/************************************************************************/
/* RTTI 
	1.dynamic_cast
		1)ֻ��Ӧ����ָ������õ�ת��
		2��Ҫת�������ͱ�������麯��
		3��ת���ɹ���������ĵ�ַ��ʧ�ܷ���NULL
	2.typeid
		1)����һ��type_info���������
		2)�����ͨ�����۵�ָ������������������ͣ������������麯��
		3��ֻ�ܻ�ȡ�����ʵ������
*/
/************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <typeinfo>
using namespace std;

/**
* �����ƶ��ࣺMovable
* ���麯����move
*/
class Movable
{
public:
	virtual void move() = 0;
};

/**
* ���幫�����ࣺBus
* ���м̳��ƶ���
* ���з���carry
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
* ����̹���ࣺTank
* ���м̳��ƶ���
* ���з���fire
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
* ���庯��doSomething������
* ʹ��dynamic_castת������
*/
void doSomething(Movable *obj)
{
	obj->move();
	cout << typeid(*obj).name() << endl;

	if (typeid(*obj) == typeid(Bus))
	{
		Bus *bus = dynamic_cast<Bus *>(obj); //ֻ��Ӧ����ָ������õ�ת��
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