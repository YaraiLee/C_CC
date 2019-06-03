#include "SequenList.h"

int main(void) {
	SequenList<int>* ptrList = new SequenList<int>(4);
	DataType e1 = 3;
	ptrList->insertListElem(0, e1);
	DataType e2 = 5;
	ptrList->insertListElem(1, e2);
	DataType e3 = 7;
	ptrList->insertListElem(2, e3);

	ptrList->traverseList();

	int curIndex = ptrList->getElemLocate(e3);
	cout << curIndex << endl;

	DataType preData;
	cout << boolalpha << ptrList->getPreListElem(e2, preData) << endl;
	cout << "curData: " << e2 << " preData: " << preData << endl;
	DataType nextData;
	cout << boolalpha << ptrList->getNextListElem(e2, nextData) << endl;

	cout << "curData: " << e2 << " nextData: " << nextData << endl;
	DataType delData;
	ptrList->delListElem(0, delData);
	cout << "Del delData=" << delData << endl;
	ptrList->traverseList();

	ptrList->insertListElem(0, delData);
	ptrList->traverseList();

	DataType e4 = 8;
	cout << boolalpha << ptrList->insertListElem(0, e4) << endl;
	ptrList->traverseList();


	cout << boolalpha << ptrList->delListElem(0, e4) << endl;
	ptrList->traverseList();

	cout << boolalpha << ptrList->delListElem(0, e4) << endl;
	ptrList->traverseList();

	cout << boolalpha << ptrList->delListElem(2, e4) << endl;
	ptrList->traverseList();

	cout << boolalpha << ptrList->delListElem(0, e4) << endl;
	ptrList->traverseList();

	cout << "clear" << endl;
	ptrList->clearList();
	cout << boolalpha << ptrList->isListEmpty() << endl;
	ptrList->traverseList();

	cout << boolalpha << ptrList->delListElem(0, e4) << endl;
	ptrList->traverseList();


	delete[]ptrList;
	ptrList = NULL;

	system("pause");
	return 0;
}