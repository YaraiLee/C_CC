#include "Line.h"
#include <iostream>

using namespace std;
/*
*	��Ա����û��Ĭ�Ϲ��캯�������г���Ա�����������ʹ�ó�ʼ���б��ʼ�������Ա
*	����˳�� m_coorA->m_coorB->Line
*	����˳�� Line->m_coorB->m_coorA
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