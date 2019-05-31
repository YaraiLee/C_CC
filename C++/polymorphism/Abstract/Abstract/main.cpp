#include "DustMan.h"

int main(void) {
	Person* ptrPerson = new DustMan("Lee", "001");
	ptrPerson->printInfo();
	//ptrPerson->work();	//Worker类型或者该类子类指针

	delete ptrPerson;
	ptrPerson = NULL;

	system("pause");
	return 0;
}