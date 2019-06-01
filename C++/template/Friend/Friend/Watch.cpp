#include "Watch.h"
#include <iostream>
using namespace std;

int Watch::sm_iCount = 0; //不要再头文件初始化，重复包含出现重定义错误

Watch::Watch(int hour, int min, int sec): m_cTime(hour, min, sec)
{
	sm_iCount++;
}

Watch::~Watch() {
	sm_iCount--;
}

void Watch::printTime(Time &time) {
	cout << "Watch::printTime(Time &time)" << endl;
	cout << time.m_iHour << ":" << time.m_iMin << ":" << time.m_iSec << endl;
}

void Watch::print()
{
	cout << "Watch::print()" << endl;
	m_cTime.getTime();
	cout << m_cTime.m_iHour << ":" << m_cTime.m_iMin << ":" << m_cTime.m_iSec << endl;
}

int Watch::getCount() {
	return sm_iCount;
}