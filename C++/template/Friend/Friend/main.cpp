#include <iostream>
#include "Time.h"

using namespace std;
void gPrintTime(Time &time);

int main(void) {
	Time time(10, 19, 20);
	printTime(time);
	system("pause");
	return 0;
}

void gPrintTime(Time &time) {
	cout << time.m_iHour << ":" << time.m_iMin << ":" << time.m_iSec << endl;
}