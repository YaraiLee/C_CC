#include <iostream>
#include "Watch.h"

using namespace std;
void gPrintTime(Time &time);

int main(void) {
	Time time(10, 19, 20);
	gPrintTime(time);


	//Watch watch;
	//watch.printTime(time);

	cout << Watch::getCount() << endl;

	Watch watch(11,12,23);
	watch.printTime(time);
	watch.print();

	cout << Watch::getCount() << endl;
	
	Watch *pWatch = new Watch(12, 12, 11);

	cout << Watch::getCount() << endl;

	delete pWatch;
	pWatch = NULL;

	cout << Watch::getCount() << endl;
	system("pause");
	return 0;
}

//访问私有成员
void gPrintTime(Time &time) {
	time.getTime();	
	cout << time.m_iHour << ":" << time.m_iMin << ":" << time.m_iSec << endl;
}