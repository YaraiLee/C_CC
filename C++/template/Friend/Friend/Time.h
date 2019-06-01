#pragma once

class Time
{
	friend void gPrintTime(Time &time);	//全局友元函数，可以放在Time任何访问限定符(public\private\protected)下，但是建议放在类定义的最前面
public:
	Time(int hour, int min, int sec);
	~Time();
	
private:
	int m_iHour;
	int m_iMin;
	int m_iSec;
};
