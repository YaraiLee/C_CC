#include <iostream>
#include "Rect.h"

using namespace std;

template <typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	Rect<int> rect(2, 6);
	cout << rect.calcArea() << endl;
	cout << rect.calePerimeter() << endl;

	int a = 4, b = 5;
	mySwap(a, b);
	cout << a << " " << b << endl;

	double c = 1.11, d = 2.2;
	mySwap(c, d);
	cout << c << " " << d << endl;

	system("pause");
	return 0;
}