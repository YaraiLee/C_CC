#include "ArrayBT.h"

ArrayBT::ArrayBT(int size, int root)
{
	m_iSize = size;
	m_pArray = new int[m_iSize];
	for (int i = 0; i < m_iSize; i++) {
		m_pArray[i] = 0;
	}
	m_pArray[0] = root;
}

ArrayBT::~ArrayBT()
{
	delete[]m_pArray;
	m_pArray = NULL;
}
//给索引pos添加左/右字节点，左结点索引=pos*2+1 右节点索引=pos*2+2
bool ArrayBT::addNode(int pos, const int direct, int value) {
	if (pos < 0 || pos >= m_iSize) {
		return false;
	}
	if (0 == m_pArray[pos]) {
		return false;
	}
	if (NODE_LEFT == direct) {	//左结点
		if (pos * 2 + 1 < m_iSize && 0 == m_pArray[pos * 2 + 1]) {
			m_pArray[pos * 2 + 1] = value;
			return true;
		}
		else {
			return false;
		}
		
	}
	else if (NODE_RIGHT == direct) {
		if (pos * 2 + 2 < m_iSize && 0 == m_pArray[pos * 2 + 2]) {
			m_pArray[pos * 2 + 2] = value;
			return true;
		}
		else {
			return false;
		}	
	}
	else {
		return false;
	}
}

bool ArrayBT::delNode(int pos, int& value) {
	if (pos < 0 || pos >= m_iSize || 0 == m_pArray[pos]) {
		return false;
	}
	//删除结点没有考虑该节点是否有子节点，直接置0删除
	//int leftPos = pos * 2 + 1;
	//int rightPos = pos * 2 + 1;
	//if ((leftPos < m_iSize && m_pArray[leftPos] != 0)
	//	|| (rightPos < m_iSize && m_pArray[rightPos] != 0)) {
	//	return false;
	//}
	value = m_pArray[pos];
	m_pArray[pos] = 0;
	return true;
}

void ArrayBT::traverseTree() {
	for (int i = 0; i < m_iSize; i++) {
		cout << m_pArray[i] << " ";
	}
	cout << endl;
}
int* ArrayBT::searchNode(int pos) {
	if (pos < 0 || pos >= m_iSize || 0 == m_pArray[pos]) {
		return NULL;
	}
	return &m_pArray[pos];
}