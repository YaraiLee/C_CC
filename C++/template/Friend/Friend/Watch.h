#pragma once

#include "Time.h"
//class Time;	//ÉùÃ÷Àà

class Watch
{
public:
	Watch(int hour, int min, int sec);
	void printTime(Time &time);
	void print();
private:
	Time m_cTime;
};