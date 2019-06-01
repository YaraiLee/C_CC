#include <iostream>
#include "Rect.h"

using namespace std;

int main(void)
{
	Rect<int> rect(2, 6);
	cout << rect.calcArea() << endl;
	cout << rect.calePerimeter() << endl;

	system("pause");
	return 0;
}