/************************************************************************/
/* ���μ̳�
/************************************************************************/
#include "ChildLabourer.h"

int main(void) {
	Person* p = new ChildLabourer("lee", 10);
	p->eat();
	//p->work();
	//p->play();

	delete p;
	p = NULL;

	//ͨ��ָ��ƫ�ƻ�ȡ��Ա����
	//Children ch(12);
	//int *q = (int *)&ch;
	//cout << (unsigned int)(*q) << endl;
	//q++;
	//cout << (unsigned int)(*q) << endl;
	system("pause");
	return 0;
}