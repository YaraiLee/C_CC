#pragma once

#include "Time.h"
//class Time;	//������

class Watch
{
public:
	Watch(int hour, int min, int sec);
	~Watch();
	void printTime(Time &time);
	void print();
	static int getCount();	//��̬��Ա����ֻ�ܷ��ʾ�̬���ݳ�Ա�͵��þ�̬��Ա����
private:
	Time m_cTime;
	static int sm_iCount;	//���о�̬��Ա�������Ա���ֱ�ӵ���,˽�еĵ�ͨ����̬��Ա����
};

