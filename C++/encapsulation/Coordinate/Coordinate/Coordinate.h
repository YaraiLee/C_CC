#pragma once

class Coordinate {
public:
	Coordinate(int x = 0, int y = 0);
	~Coordinate();
	void setX(int x);
	void setY(int y);
	void printXY()const;
	void operator=(const Coordinate& c);
private:
	int m_iX;
	int m_iY;
};
