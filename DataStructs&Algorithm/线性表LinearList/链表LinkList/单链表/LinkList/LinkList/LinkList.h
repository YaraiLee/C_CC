#pragma once

#include "Node.h"

class LinkList
{
public:
	LinkList();
	virtual ~LinkList();
	bool isListEmpty();
	//删除所有节点(头结点除外)
	void clearList();
	int getListLength();
	//获取指定index处节点
	bool getListElem(int index, Node* ptrNode) const;
	//获取指定节点index
	int getListElemLocate(const Node& rNode) const;
	//遍历
	void traverseList() const;
	//头插
	bool insertNodeHead(const Node& rNode);
	//尾插
	bool insertNodeTail(const Node& rNode);
	//指定index插入节点
	bool insertNode(int index, const Node& rNode);
	//指定index删除节点
	bool delListNode(int index, Node* ptrNode);
	//链表倒置
	void reverseList() const;
private:
	int m_iLength;
	Node* m_pList;
};
