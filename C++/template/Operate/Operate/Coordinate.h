#pragma once

class Coordinate
{
	friend Coordinate& operator-(Coordinate& coor);	//��Ԫ����-��������أ�û��thisָ��
	friend Coordinate& operator++(Coordinate& coor);
	friend Coordinate operator+(const Coordinate& coor1, const Coordinate& coor2);
public:
	Coordinate(int x = 0, int y = 0);
	~Coordinate();
	int getX();
	int getY();
	//Coordinate& operator-();	//������������,�������Coordinate�������ͣ���-(-coor)������-coor���һ��
	//Coordinate& operator++();	//ǰ������++
	Coordinate operator++(int);	//��Ԫ�����޷�ʵ�ֺ����������أ��������������õ�thisָ��

	//Coordinate operator+(const Coordinate& coor);	//��Ҫ���ؾֲ���ʱ�������������÷���
private:
	int m_iX;
	int m_iY;
};
