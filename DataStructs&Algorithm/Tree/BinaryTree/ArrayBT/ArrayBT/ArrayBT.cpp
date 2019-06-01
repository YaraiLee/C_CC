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
//������pos�����/���ֽڵ㣬��������=pos*2+1 �ҽڵ�����=pos*2+2
bool ArrayBT::addNode(int pos, const int direct, int value) {
	if (pos < 0 || pos >= m_iSize) {
		return false;
	}
	if (0 == m_pArray[pos]) {
		return false;
	}
	if (NODE_LEFT == direct) {	//����
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
	//ɾ�����û�п��Ǹýڵ��Ƿ����ӽڵ㣬ֱ����0ɾ��
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