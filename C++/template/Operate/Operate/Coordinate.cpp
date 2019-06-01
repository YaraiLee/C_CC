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

//Coordinate& Coordinate::operator++() {
//	m_iX++;
//	m_iY++;
//	return *this;
//}

Coordinate& operator++(Coordinate& coor) {
	coor.m_iX++;
	coor.m_iY++;
	return coor;
}

Coordinate Coordinate::operator++(int) {
	Coordinate old(*this);
	m_iX++;
	this->m_iY++;
	return old;
}

//Coordinate Coordinate::operator+(const Coordinate& coor) {
//	Coordinate temp;
//	temp.m_iX = this->m_iX + coor.m_iX;
//	temp.m_iY = this->m_iY + coor.m_iY;
//	return temp;
//}

Coordinate operator+(const Coordinate& coor1, const Coordinate& coor2) {
	Coordinate temp;
	temp.m_iX = coor1.m_iX + coor2.m_iX;
	temp.m_iY = coor1.m_iY + coor2.m_iY;
	return temp;
}

ostream& operator<<(ostream& out, const Coordinate& coor) {
	out << coor.m_iX << ", " << coor.m_iY;
	return out;
}

int& Coordinate::operator[](int index) {
	if (0 == index) {
		return this->m_iX;
	} else {
		return this->m_iY;
	}
}
