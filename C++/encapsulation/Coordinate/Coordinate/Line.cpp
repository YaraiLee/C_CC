#include "Line.h"
#include <iostream>

using namespace std;
/*
*	成员对象没有默认构造函数或者有常成员变量，则必须使用初始化列表初始化对象成员
*	构造顺序 m_coorA->m_coorB->Line
*	析构顺序 Line->m_coorB->m_coorA
*/
Line::Line(int x1, int y1, int x2, int y2):m_coorA(x1, y1),m_coorB(x2, y2) {
	cout << "Line(int x1, int y1, int x2, int y2)" << endl;
}

Line::~Line() {
	cout << "~Line()" << endl;
}

void Line::printLine() const{
	m_coorA.printXY();
	m_coorB.printXY();
}

void Line::change() {

}