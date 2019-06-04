#pragma once

typedef int DataType;
//template <typename T>
class Node
{
public:
	Node* next;
	DataType data;
	Node();
	virtual ~Node();
	Node(DataType data);
	void printNode();
};