#pragma once
#include "Node.h"

class Tree
{
public:
	Tree();
	~Tree();
	Node* searchNode(int nodeIndex);	//指定索引搜索节点
	bool AddNode(int nodeIndex, int direction, Node* pNode);	//指定索引、左右，添加节点(随处添加，不仅限添加叶子节点)
	bool DeleteNode(int index, Node* pNode);	//指定索引删除节点，包括该节点的所有子节点

	void PreorderTraverse() const;	//前序遍历
	void InorderTraverse() const;	//中序遍历
	void PostorderTraverse() const;	//后序遍历
private:
	Node* m_pRoot;
};