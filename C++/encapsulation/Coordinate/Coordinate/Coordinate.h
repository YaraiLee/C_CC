#pragma once

class Coordinate {
public:
	Coordinate(int x, int y);
	~Coordinate();
	void setX(int x);
	void setY(int y);
	void printXY();
private:
	int m_iX;
	int m_iY;
};
