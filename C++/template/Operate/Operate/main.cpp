#include "Coordinate.h"
#include <iostream>

using namespace std;

int main(void) {
	Coordinate coor1(1, 3);
	//测试成员函数和友元函数实现一元运算符负运算符(-)重载
	cout << "测试成员函数和友元函数实现一元运算符负运算符(-)重载" << endl;
	cout << coor1.getX() << ", " << coor1.getY() << endl;
	-coor1;	//成员函数 相当于 coor1.operator-() 友元函数 operator-(coor1)
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
	
	//测试成员函数和友元函数实现二元运算符加号(+)运算符重载
	Coordinate coor2(1, 2);
	Coordinate coor3(2, 3);
	Coordinate coor4 = coor2 + coor3; //成员函数 相当于 coor2.operator+(coor3) 友元函数 operator+(coor2, coor3)
	cout << coor4.getX() << ", " << coor4.getY() << endl;
	//测试友元函数实现二元运算符输出(<<)运算符重载
	cout << "测试友元函数实现二元运算符输出(<<)运算符重载" << endl;
	cout << coor4 << endl;

	//测试成员函数实现二元运算符索引([])运算符重载
	cout << coor4[0] << endl;
	cout << coor4[2] << endl;
	system("pause");
	return 0;
}