#pragma once
//数组实现二叉树
#include <iostream>
using namespace std;

class ArrayBT
{
public:
	const static int NODE_LEFT = 0;
	const static int NODE_RIGHT = 1;

	ArrayBT(int size, int root);
	virtual ~ArrayBT();
	bool addNode(int pos, int direct, int value);
	bool delNode(int pos, int& value);
	void traverseTree();
	int* searchNode(int pos);
private:
	int m_iSize;
	int* m_pArray;
};
