#include "SequenList.h"

SequenList::SequenList(int size)
{
	m_iSize = size;
	m_iLength = 0;
	m_gList = new DataType[size];
}

SequenList::~SequenList()
{
	delete[]m_gList;
	m_gList = NULL;
}

void SequenList::clearList() {
	m_iLength = 0;
}

int SequenList::getListLength()const {
	return m_iLength;
}

bool SequenList::isListEmpty() const {
	return 0 == m_iLength ? true : false;
}

bool SequenList::getListElem(int index, DataType& data) const {
	if (index < 0 || index >= m_iLength) {
		return false;
	}
	data = m_gList[index];
	return true;
}

int SequenList::getElemLocate(const DataType data) const {
	for (int i = 0; i < m_iLength; i++) {
		if (data == m_gList[i]) {
			return i;
		}
	}
	return -1;
}
bool SequenList::getPreListElem(const DataType curData, DataType& preData) const {
	int curIndex = getElemLocate(curData);
	if (curIndex <= 0) {
		return false;
	}
	preData = m_gList[curIndex - 1];
	return true;
}

bool SequenList::getNextListElem(const DataType curData, DataType& nextData) const {
	int curIndex = getElemLocate(curData);
	if (-1 == curIndex || curIndex >= m_iLength - 1) {
		return false;
	}
	nextData = m_gList[curIndex + 1];
	return true;
}
void SequenList::traverseList() const {
	for (int i = 0; i < m_iLength; i++) {
		cout << "List[" << i << "]" << "=" << m_gList[i] << endl;
	}
}

bool SequenList::insertListElem(int index, const DataType data) {
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
bool SequenList::delListElem(int index, DataType& data) {
	if (index < 0 || index >= m_iLength) {
		return false;
	}
	data = m_gList[index];
	for (int i = index; i < m_iLength-1; i++) {
		m_gList[i] = m_gList[i + 1];
	}
	m_iLength--;
	return true;
}
