#include <iostream>
#include "Watch.h"

using namespace std;
void gPrintTime(Time &time);

int main(void) {
	Time time(10, 19, 20);
	gPrintTime(time);

	//Watch watch;
	//watch.printTime(time);
	Watch watch(11,12,23);
	watch.printTime(time);
	watch.print();
	system("pause");
	return 0;
}

//����˽�г�Ա
void gPrintTime(Time &time) {
	time.getTime();	
	cout << time.m_iHour << ":" << time.m_iMin << ":" << time.m_iSec << endl;
}