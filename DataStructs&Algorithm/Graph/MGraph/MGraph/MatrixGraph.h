#pragma once
//图的邻接矩阵存储类定义
#include "VertexNode.h"
#include <iostream>
#include <vector>
using namespace std;

typedef int EdgeType;	//边的权值类型

class MatrixGraph
{
public:
	MatrixGraph(int capacity);
	~MatrixGraph();
	bool addVertexNode(VertexNode* node);	//添加顶点
	void resetVertex();	//顶点重置为未访问过
	bool setValueDiMatrix(int row, int col, const EdgeType value = edgeValid);	//有向图邻接矩阵设置边的权值 默认edgeValid
	bool setValueUnDiMatrix(int row, int col, const EdgeType value = edgeValid);	//无向图邻接矩阵设置边的权值 默认edgeValid
	bool getValueFromMatrix(int row, int col, EdgeType& value) const;	//获取指定坐标的值
	void printMatrix() const;	//打印邻接矩阵
	void DFSTraverseMatrix(int nodeIndex = 0) const;	//深度优先搜索遍历邻接矩阵(递归版）默认从第一个顶点开始
	void BFSTraverseMatrix(int nodeIndex = 0) const;	//广度优先搜索遍历邻接矩阵(递归版）默认从第一个顶点开始
	void BFSTraverseMatrixImpl(vector<EdgeType> preVec) const;	//广度优先搜索实现遍历邻接矩阵(递归版）
	void DFSTraverseMatrixStack() const;
	void BFSTraverseMatrixQueue() const;
private:
	int m_iCapacity;	//图中最多可容纳的顶点数
	int m_iVertexCount;	//已经添加的顶点数
	VertexNode* m_pNodeArr;	//顶点存储数组,顶点表
	EdgeType* m_pMatrix;	//邻接矩阵，即边表
	const static EdgeType edgeValid = 1;	//边的权值 默认合法值
};

