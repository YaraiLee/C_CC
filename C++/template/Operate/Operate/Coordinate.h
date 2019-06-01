#pragma once
#include <ostream>
using namespace std;

class Coordinate
{
	//友元函数不能用const修饰，因为不是成员函数
	friend Coordinate& operator-(Coordinate& coor);	//友元函数-运算符重载，没有this指针
	friend Coordinate& operator++(Coordinate& coor);
	friend Coordinate operator+(const Coordinate& coor1, const Coordinate& coor2);
	friend ostream& operator<<(ostream& out, const Coordinate& coor);	//输出运算符<<，第一个参数必须是ostream类型，因此不能通过成员函数实现重载
public:
	Coordinate(int x = 0, int y = 0);
	~Coordinate();
	int getX();
	int getY();
	//Coordinate& operator-();	//返回引用类型,如果返回Coordinate对象类型，则-(-coor)操作和-coor结果一样
	//Coordinate& operator++();	//前置自增++
	Coordinate operator++(int);	//友元函数无法实现后置自增重载，后置自增必须用到this指针

	//Coordinate operator+(const Coordinate& coor);	//需要返回局部临时变量，不用引用返回
	int& operator[](int index);	//索引运算符[]必须是成员函数重载，友元
private:
	int m_iX;
	int m_iY;
};
