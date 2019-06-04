#pragma once

#include "Node.h"

class LinkList
{
public:
	LinkList();
	virtual ~LinkList();
	bool isListEmpty();
	void clearList();
	int getListLength();

	bool getListElem(int index, Node* ptrNode) const;
	int getListElemLocate(const Node& rNode) const;
	void traverseList() const;

	bool insertNodeHead(const Node& rNode);
	bool insertNodeTail(const Node& rNode);

	bool insertNode(int index, const Node& rNode);
	bool delListNode(int index, Node* ptrNode);

	void reverseList() const;
private:
	int m_iLength;
	Node* m_pList;
};
