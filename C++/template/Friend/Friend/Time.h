#pragma once

class Time
{
	friend void gPrintTime(Time &time);	//ȫ����Ԫ���������Է���Time�κη����޶���(public\privaet\protected)�£����ǽ�������ඨ�����ǰ��
public:
	Time(int hour, int min, int sec);
	~Time();
	
private:
	int m_iHour;
	int m_iMin;
	int m_iSec;
};
