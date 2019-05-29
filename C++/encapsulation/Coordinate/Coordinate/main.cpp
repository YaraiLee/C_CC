#include "Line.h"
#include <iostream>

using namespace std;

int main(void) {
	Line* pLine = new Line(1, 2, 3, 4);
	pLine->printLine();

	delete pLine;
	pLine = NULL;

	const Line line(2, 3, 4, 5);	//常对象
	line.printLine();	//const常对象只能调用常对象方法
	//line.change();	//错误，const常对象不能调用非对象方法

	Line line_1(1, 2, 3, 4);
	const Line& c_line(line_1);	//常对象引用
	c_line.printLine();
	//c_line.change();	//错误

	const Line* p_line = &line_1;
	//p_line->change();	//错误同上，指向常对象的指针

	Line * const p_line_1 = &line_1;
	p_line_1->change();	//正确
	p_line_1->printLine();
	//p_line_1 = &line;	//错误，常指针不能修改指向对象

	system("pause");
	return 0;
}