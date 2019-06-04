#include "LinkList.h"
#include <iostream>
using namespace std;

int main(void) {

	LinkList* list = new LinkList;
	Node node1(1);
	Node node2(2);
	Node node3(3);
	//头插
	list->insertNodeHead(node1);
	list->insertNodeHead(node2);
	cout << "after insertNodeHead" << endl;
	list->traverseList();

	//尾插
	list->insertNodeTail(node3);
	cout << "after insertNodeTail" << endl;
	list->traverseList();

	//链表倒置
	list->reverseList();
	cout << "after reverseList" << endl;
	list->traverseList();

	//指定位置插入
	Node node4(4);
	list->insertNode(4, node4);
	cout << "after insertNode" << endl;
	cout << "list len = " << list->getListLength() << endl;
	list->traverseList();
	//指定位置删除
	Node tmpNode;
	list->delListNode(4, &tmpNode);
	cout << "after delListNode" << endl;
	cout << "del node data=" << tmpNode.data << endl;
	list->traverseList();

	//获取链表长度
	cout << "list len = " << list->getListLength() << endl;
	//获取指定index节点
	int index = 3;
	Node node;
	cout << "getListElem " << boolalpha << list->getListElem(index, &node) << endl;
	cout << "index=" << index << " data=" << node.data << endl;
	//获取节点索引
	index = list->getListElemLocate(node3);
	cout << "node data=" << node3.data << " index=" << index << endl;

	list->clearList();
	cout << boolalpha << list->isListEmpty() << endl;
	delete list;
	list = NULL;
	
	system("pause");
	return 0;
}