#pragma once
#include <ostream>
using namespace std;

class Coordinate
{
	//��Ԫ����������const���Σ���Ϊ���ǳ�Ա����
	friend Coordinate& operator-(Coordinate& coor);	//��Ԫ����-��������أ�û��thisָ��
	friend Coordinate& operator++(Coordinate& coor);
	friend Coordinate operator+(const Coordinate& coor1, const Coordinate& coor2);
	friend ostream& operator<<(ostream& out, const Coordinate& coor);	//��������<<����һ������������ostream���ͣ���˲���ͨ����Ա����ʵ������
public:
	Coordinate(int x = 0, int y = 0);
	~Coordinate();
	int getX();
	int getY();
	//Coordinate& operator-();	//������������,�������Coordinate�������ͣ���-(-coor)������-coor���һ��
	//Coordinate& operator++();	//ǰ������++
	Coordinate operator++(int);	//��Ԫ�����޷�ʵ�ֺ����������أ��������������õ�thisָ��

	//Coordinate operator+(const Coordinate& coor);	//��Ҫ���ؾֲ���ʱ�������������÷���
	int& operator[](int index);	//���������[]�����ǳ�Ա�������أ���Ԫ
private:
	int m_iX;
	int m_iY;
};
