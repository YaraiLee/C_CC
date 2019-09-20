#pragma once

#include "Time.h"
//class Time;	//声明类

class Watch
{
public:
	Watch(int hour, int min, int sec);
	~Watch();
	void printTime(Time &time);
	void print();
	static int getCount();	//静态成员函数只能访问静态数据成员和调用静态成员函数
private:
	Time m_cTime;
	static int sm_iCount;	//公有静态成员函数可以被类直接调用,私有的得通过静态成员函数
};

