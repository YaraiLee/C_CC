#pragma once

#include "Node.h"

class LinkList
{
public:
	LinkList();
	virtual ~LinkList();
	bool isListEmpty();
	//ɾ�����нڵ�(ͷ������)
	void clearList();
	int getListLength();
	//��ȡָ��index���ڵ�
	bool getListElem(int index, Node* ptrNode) const;
	//��ȡָ���ڵ�index
	int getListElemLocate(const Node& rNode) const;
	//����
	void traverseList() const;
	//ͷ��
	bool insertNodeHead(const Node& rNode);
	//β��
	bool insertNodeTail(const Node& rNode);
	//ָ��index����ڵ�
	bool insertNode(int index, const Node& rNode);
	//ָ��indexɾ���ڵ�
	bool delListNode(int index, Node* ptrNode);
	//������
	void reverseList() const;
private:
	int m_iLength;
	Node* m_pList;
};
