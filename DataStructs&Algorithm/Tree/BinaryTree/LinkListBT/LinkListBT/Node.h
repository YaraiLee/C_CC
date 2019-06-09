#pragma once
#include <iostream>

typedef int NodeDataType;
class Node
{
public:
	Node();
	Node(NodeDataType data, int index);
	Node* searchNode(int nodeIndex);
	bool AddNode(int direction, Node* pNode);
	void DeleteNode();
	void PreorderTraverse() const;
	void InorderTraverse() const;
	void PostorderTraverse() const;


	const static int LEFT_CHILD = 0;
	const static int RIGHT_CHILD = 1;
	int m_iIndex;
	NodeDataType m_data;
	Node* m_pLChild;
	Node* m_pRChild;
	Node* m_pParent;
};