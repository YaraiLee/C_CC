#include "Coordinate.h"
#include <iostream>

using namespace std;

int main(void) {
	Coordinate coor1(1, 2);
	//测试成员函数和友元函数实现一元运算符负运算符(-)重载
	cout << coor1.getX() << ", " << coor1.getY() << endl;
	-(-coor1);
	cout << coor1.getX() << ", " << coor1.getY() << endl;

	system("pause");
	return 0;
}