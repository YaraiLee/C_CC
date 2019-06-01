#pragma once
//数组实现二叉树
#include <iostream>
using namespace std;

const int NODE_LEFT = 0;
const int NODE_RIGHT = 1;

class ArrayBT
{
public:
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
