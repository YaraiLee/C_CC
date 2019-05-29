#pragma once
#include "Coordinate.h"

class Line
{
public:
	Line(int x1, int y1, int x2, int y2);
	Line(const Line& line);	//¿½±´¹¹Ôìº¯Êý
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