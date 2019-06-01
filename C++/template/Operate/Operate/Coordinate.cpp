#include "Coordinate.h"

Coordinate::Coordinate(int x, int y)
{
	m_iX = x;
	m_iY = y;
}

Coordinate::~Coordinate()
{
}

int Coordinate::getX() {
	return m_iX;
}

int Coordinate::getY() {
	return m_iY;
}

//Coordinate& Coordinate::operator-() {
//	m_iX = -m_iX;
//	this->m_iY = -m_iY;
//	return *this;
//}

Coordinate& operator-(Coordinate& coor) {
	coor.m_iX = -coor.m_iX;
	coor.m_iY = -coor.m_iY;
	return coor;
}