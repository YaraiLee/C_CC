#include "DustMan.h"

int main(void) {
	Person* ptrPerson = new DustMan("Lee", "001");
	ptrPerson->printInfo();
	//ptrPerson->work();	//Worker���ͻ��߸�������ָ��

	delete ptrPerson;
	ptrPerson = NULL;

	system("pause");
	return 0;
}