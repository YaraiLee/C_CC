#pragma once

class Coordinate
{
	friend Coordinate& operator-(Coordinate& coor);	//��Ԫ����-��������أ�û��thisָ��
	friend Coordinate& operator++(Coordinate& coor);
public:
	Coordinate(int x = 0, int y = 0);
	~Coordinate();
	int getX();
	int getY();
	//Coordinate& operator-();	//������������,�������Coordinate�������ͣ���-(-coor)������-coor���һ��
	//Coordinate& operator++();	//ǰ������++
	Coordinate operator++(int);	//��Ԫ�����޷�ʵ�ֺ����������أ��������������õ�thisָ��
private:
	int m_iX;
	int m_iY;
};
