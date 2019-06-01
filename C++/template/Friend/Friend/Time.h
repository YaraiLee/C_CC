#pragma once
//#include "Watch.h"

class Watch;

class Time
{
	friend Watch;	//友元类，已覆盖友元成员函数功能，二者取其一
	friend void gPrintTime(Time &time);	//友元全局函数，可以放在Time任何访问限定符(public\private\protected)下，但是建议放在类定义的最前面
	//friend void Watch::printTime(Time &time); //友元成员函数
public:
	Time(int hour, int min, int sec);
	~Time();
	
private:
	void getTime();
	int m_iHour;
	int m_iMin;
	int m_iSec;
};
