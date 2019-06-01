#include "Time.h"
#include <iostream>
using namespace std;

Time::Time(int hour, int min, int sec)
{
	m_iHour = hour;
	m_iMin = min;
	m_iSec = sec;
}

Time::~Time()
{
}

void Time::getTime() {
	cout << "Time::getTime()" << endl;
}