#include "LinkList.h"
#include <iostream>
using namespace std;

int main(void) {

	LinkList* list = new LinkList;
	Node node1(1);
	Node node2(2);
	Node node3(3);
	//ͷ��
	list->insertNodeHead(node1);
	list->insertNodeHead(node2);
	cout << "after insertNodeHead" << endl;
	list->traverseList();

	//β��
	list->insertNodeTail(node3);
	cout << "after insertNodeTail" << endl;
	list->traverseList();

	//������
	list->reverseList();
	cout << "after reverseList" << endl;
	list->traverseList();

	//ָ��λ�ò���
	Node node4(4);
	list->insertNode(4, node4);
	cout << "after insertNode" << endl;
	cout << "list len = " << list->getListLength() << endl;
	list->traverseList();
	//ָ��λ��ɾ��
	Node tmpNode;
	list->delListNode(4, &tmpNode);
	cout << "after delListNode" << endl;
	cout << "del node data=" << tmpNode.data << endl;
	list->traverseList();

	//��ȡ������
	cout << "list len = " << list->getListLength() << endl;
	//��ȡָ��index�ڵ�
	int index = 3;
	Node node;
	cout << "getListElem " << boolalpha << list->getListElem(index, &node) << endl;
	cout << "index=" << index << " data=" << node.data << endl;
	//��ȡ�ڵ�����
	index = list->getListElemLocate(node3);
	cout << "node data=" << node3.data << " index=" << index << endl;

	list->clearList();
	cout << boolalpha << list->isListEmpty() << endl;
	delete list;
	list = NULL;
	
	system("pause");
	return 0;
}