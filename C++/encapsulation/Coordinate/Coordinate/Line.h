#pragma once
#include "Coordinate.h"

class Line
{
public:
	Line(int x1, int y1, int x2, int y2);
	Line(const Line& line);	//�������캯��
	~Line();
	void printLine()const;
	void change();
	Line & getLine();
	Line * getLinePointer();
private:
	const Coordinate m_coorA;
	Coordinate m_coorB;
	Coordinate* m_pcoorC;
};