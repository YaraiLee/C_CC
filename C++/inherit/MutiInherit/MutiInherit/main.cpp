/************************************************************************/
/* 菱形继承
/************************************************************************/
#include "ChildLabourer.h"

int main(void) {
	Person* p = new ChildLabourer("lee", 10);
	p->eat();
	//p->work();
	//p->play();

	delete p;
	p = NULL;

	//通过指针偏移获取成员数据
	//Children ch(12);
	//int *q = (int *)&ch;
	//cout << (unsigned int)(*q) << endl;
	//q++;
	//cout << (unsigned int)(*q) << endl;
	system("pause");
	return 0;
}