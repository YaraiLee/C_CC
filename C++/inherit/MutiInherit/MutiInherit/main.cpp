/************************************************************************/
/* ÁâÐÎ¼Ì³Ð
/************************************************************************/
#include "ChildLabourer.h"

int main(void) {
	ChildLabourer* p = new ChildLabourer("lee", 10);
	p->eat();
	p->work();
	p->play();

	delete p;
	p = NULL;

	system("pause");
	return 0;
}