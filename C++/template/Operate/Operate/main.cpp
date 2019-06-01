#include "Coordinate.h"
#include <iostream>

using namespace std;

int main(void) {
	Coordinate coor1(1, 3);
	//测试成员函数和友元函数实现一元运算符负运算符(-)重载
	cout << "测试成员函数和友元函数实现一元运算符负运算符(-)重载" << endl;
	cout << coor1.getX() << ", " << coor1.getY() << endl;
	-(-coor1);
	cout << coor1.getX() << ", " << coor1.getY() << endl;

	//测试成员函数和友元函数实现一元运算符前置自增运算符(++)重载
	cout << "测试成员函数和友元函数实现一元运算符前置自增运算符(++)重载" << endl;
	++coor1;
	cout << coor1.getX() << ", " << coor1.getY() << endl;
	
	//测试成员函数实现一元运算符后置自增运算符(++)重载
	cout << "测试成员函数和友元函数实现一元运算符后置自增运算符(++)重载" << endl;
	cout << coor1++.getX() << ", ";	//两行打印区别	cout << coor1++.getX() << ", " << coor1++.getY() << endl;输出结果不同，单行是从右往左顺序执行
	cout << coor1++.getY() << endl;

	cout << coor1.getX() << ", " << coor1.getY() << endl;

	system("pause");
	return 0;
}