#include "Line.h"
#include <iostream>

using namespace std;

int main(void) {
	Line* pLine = new Line(1, 2, 3, 4);
	pLine->printLine();

	delete pLine;
	pLine = NULL;

	system("pause");
	return 0;
}