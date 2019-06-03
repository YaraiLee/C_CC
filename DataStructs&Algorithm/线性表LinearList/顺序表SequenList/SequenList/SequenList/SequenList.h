#pragma once
#include <iostream>
using namespace std;

typedef int DataType;
template <typename T>
class SequenList
{
public:
	SequenList(int size);
	virtual ~SequenList();
	void clearList();
	int getListLength()const;
	bool isListEmpty()const;
	bool getListElem(int index, T& data)const;
	int getElemLocate(const T data)const;
	bool getPreListElem(const T curData, T& preData)const;
	bool getNextListElem(const T curData, T& nextData)const;
	void traverseList()const;
	bool insertListElem(int index, const T data);
	bool delListElem(int index, T& data);
private:
	int m_iSize;
	int m_iLength;
	T* m_gList;
};

template <typename T>
SequenList<T>::SequenList(int size)
{
	m_iSize = size;
	m_iLength = 0;
	m_gList = new T[size];
}
template <typename T>
SequenList<T>::~SequenList()
{
	delete[]m_gList;
	m_gList = NULL;
}
template <typename T>
void SequenList<T>::clearList() {
	m_iLength = 0;
}
template <typename T>
int SequenList<T>::getListLength()const {
	return m_iLength;
}
template <typename T>
bool SequenList<T>::isListEmpty() const {
	return 0 == m_iLength ? true : false;
}
template <typename T>
bool SequenList<T>::getListElem(int index, T& data) const {
	if (index < 0 || index >= m_iLength) {
		return false;
	}
	data = m_gList[index];
	return true;
}
template <typename T>
int SequenList<T>::getElemLocate(const T data) const {
	for (int i = 0; i < m_iLength; i++) {
		if (data == m_gList[i]) {
			return i;
		}
	}
	return -1;
}
template <typename T>
bool SequenList<T>::getPreListElem(const T curData, T& preData) const {
	int curIndex = getElemLocate(curData);
	if (curIndex <= 0) {
		return false;
	}
	preData = m_gList[curIndex - 1];
	return true;
}
template <typename T>
bool SequenList<T>::getNextListElem(const T curData, T& nextData) const {
	int curIndex = getElemLocate(curData);
	if (-1 == curIndex || curIndex >= m_iLength - 1) {
		return false;
	}
	nextData = m_gList[curIndex + 1];
	return true;
}
template <typename T>
void SequenList<T>::traverseList() const {
	for (int i = 0; i < m_iLength; i++) {
		cout << "List[" << i << "]" << "=" << m_gList[i] << endl;
	}
}
template <typename T>
bool SequenList<T>::insertListElem(int index, const T data) {
	if (index < 0 || index > m_iLength || m_iLength >= m_iSize) {
		return false;
	}
	for (int i = m_iLength - 1; i >= index; i--) {
		m_gList[i + 1] = m_gList[i];
	}
	m_gList[index] = data;
	m_iLength++;

	return true;
}
template <typename T>
bool SequenList<T>::delListElem(int index, T& data) {
	if (index < 0 || index >= m_iLength) {
		return false;
	}
	data = m_gList[index];
	for (int i = index; i < m_iLength - 1; i++) {
		m_gList[i] = m_gList[i + 1];
	}
	m_iLength--;
	return true;
}
