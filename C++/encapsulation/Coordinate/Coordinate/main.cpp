#include "Line.h"
#include <iostream>

using namespace std;

int main(void) {
	Line* pLine = new Line(1, 2, 3, 4);
	pLine->printLine();

	delete pLine;
	pLine = NULL;

	const Line line(2, 3, 4, 5);	//������
	line.printLine();	//const������ֻ�ܵ��ó����󷽷�
	//line.change();	//����const�������ܵ��÷Ƕ��󷽷�

	Line line_1(1, 2, 3, 4);
	const Line& c_line(line_1);	//����������
	c_line.printLine();
	//c_line.change();	//����

	const Line* p_line = &line_1;
	//p_line->change();	//����ͬ�ϣ�ָ�򳣶����ָ��

	Line * const p_line_1 = &line_1;
	p_line_1->change();	//��ȷ
	p_line_1->printLine();
	//p_line_1 = &line;	//���󣬳�ָ�벻���޸�ָ�����

	system("pause");
	return 0;
}