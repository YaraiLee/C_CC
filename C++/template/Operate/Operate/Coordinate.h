#pragma once

class Coordinate
{
	friend Coordinate& operator-(Coordinate& coor);	//友元函数-运算符重载，没有this指针
	friend Coordinate& operator++(Coordinate& coor);
public:
	Coordinate(int x = 0, int y = 0);
	~Coordinate();
	int getX();
	int getY();
	//Coordinate& operator-();	//返回引用类型,如果返回Coordinate对象类型，则-(-coor)操作和-coor结果一样
	//Coordinate& operator++();	//前置自增++
private:
	int m_iX;
	int m_iY;
};
