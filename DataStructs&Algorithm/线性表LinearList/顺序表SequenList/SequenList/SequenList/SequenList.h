#pragma once
#include <iostream>
using namespace std;

typedef int DataType;

class SequenList
{
public:
	SequenList(int size);
	virtual ~SequenList();
	void clearList();
	int getListLength()const;
	bool isListEmpty()const;
	bool getListElem(int index, DataType& data)const;
	int getElemLocate(const DataType data)const;
	bool getPreListElem(const DataType curData, DataType& preData)const;
	bool getNextListElem(const DataType curData, DataType& nextData)const;
	void traverseList()const;
	bool insertListElem(int index, const DataType data);
	bool delListElem(int index, DataType& data);
private:
	int m_iSize;
	int m_iLength;
	DataType* m_gList;
};
