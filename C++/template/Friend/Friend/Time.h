#pragma once
//#include "Watch.h"

class Watch;

class Time
{
	friend Watch;	//��Ԫ�࣬�Ѹ�����Ԫ��Ա�������ܣ�����ȡ��һ
	friend void gPrintTime(Time &time);	//��Ԫȫ�ֺ��������Է���Time�κη����޶���(public\private\protected)�£����ǽ�������ඨ�����ǰ��
	//friend void Watch::printTime(Time &time); //��Ԫ��Ա����
public:
	Time(int hour, int min, int sec);
	~Time();
	
private:
	void getTime();
	int m_iHour;
	int m_iMin;
	int m_iSec;
};
