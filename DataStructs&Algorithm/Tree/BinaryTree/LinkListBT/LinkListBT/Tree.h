#pragma once
#include "Node.h"

class Tree
{
public:
	Tree();
	~Tree();
	Node* searchNode(int nodeIndex);	//ָ�����������ڵ�
	bool AddNode(int nodeIndex, int direction, Node* pNode);	//ָ�����������ң���ӽڵ�(�洦��ӣ����������Ҷ�ӽڵ�)
	bool DeleteNode(int index, Node* pNode);	//ָ������ɾ���ڵ㣬�����ýڵ�������ӽڵ�

	void PreorderTraverse() const;	//ǰ�����
	void InorderTraverse() const;	//�������
	void PostorderTraverse() const;	//�������
private:
	Node* m_pRoot;
};