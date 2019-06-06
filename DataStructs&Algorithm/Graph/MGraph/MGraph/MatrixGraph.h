#pragma once
//ͼ���ڽӾ���洢�ඨ��
#include "VertexNode.h"
#include <iostream>
#include <vector>
using namespace std;

typedef int EdgeType;	//�ߵ�Ȩֵ����

class MatrixGraph
{
public:
	MatrixGraph(int capacity);
	~MatrixGraph();
	bool addVertexNode(VertexNode* node);	//��Ӷ���
	void resetVertex();	//��������Ϊδ���ʹ�
	bool setValueDiMatrix(int row, int col, const EdgeType value = edgeValid);	//����ͼ�ڽӾ������ñߵ�Ȩֵ Ĭ��edgeValid
	bool setValueUnDiMatrix(int row, int col, const EdgeType value = edgeValid);	//����ͼ�ڽӾ������ñߵ�Ȩֵ Ĭ��edgeValid
	bool getValueFromMatrix(int row, int col, EdgeType& value) const;	//��ȡָ�������ֵ
	void printMatrix() const;	//��ӡ�ڽӾ���
	void DFSTraverseMatrix(int nodeIndex = 0) const;	//����������������ڽӾ���(�ݹ�棩Ĭ�ϴӵ�һ�����㿪ʼ
	void BFSTraverseMatrix(int nodeIndex = 0) const;	//����������������ڽӾ���(�ݹ�棩Ĭ�ϴӵ�һ�����㿪ʼ
	void BFSTraverseMatrixImpl(vector<EdgeType> preVec) const;	//�����������ʵ�ֱ����ڽӾ���(�ݹ�棩
	void DFSTraverseMatrixStack() const;
	void BFSTraverseMatrixQueue() const;
private:
	int m_iCapacity;	//ͼ���������ɵĶ�����
	int m_iVertexCount;	//�Ѿ���ӵĶ�����
	VertexNode* m_pNodeArr;	//����洢����,�����
	EdgeType* m_pMatrix;	//�ڽӾ��󣬼��߱�
	const static EdgeType edgeValid = 1;	//�ߵ�Ȩֵ Ĭ�ϺϷ�ֵ
};

