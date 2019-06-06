#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int capacity)
{
	m_iCapacity = capacity;
	m_iVertexCount = 0;
	m_pNodeArr = new VertexNode[capacity];
	m_pMatrix = new EdgeType[capacity * capacity];
	memset(m_pMatrix, 0, capacity * capacity * sizeof(EdgeType));
}

MatrixGraph::~MatrixGraph()
{
	delete[]m_pMatrix;
	m_pMatrix = NULL;
	delete[]m_pNodeArr;
	m_pNodeArr = NULL;
}

bool MatrixGraph::addVertexNode(VertexNode* node) {
	if (NULL == node || m_iVertexCount >= m_iCapacity) {
		return false;
	}
	m_pNodeArr[m_iVertexCount].m_data = node->m_data;
	m_pNodeArr[m_iVertexCount].m_bIsVisited = node->m_bIsVisited;
	m_iVertexCount++;
	return true;
}

void MatrixGraph::resetVertex() {
	for (int i = 0; i < m_iVertexCount; i++) {
		m_pNodeArr[i].m_bIsVisited = false;
	}
}

bool MatrixGraph::setValueDiMatrix(int row, int col, const EdgeType value) {
	if (row < 0 || row >= m_iCapacity
		|| col < 0 || col >= m_iCapacity) {
		return false;
	}
	m_pMatrix[row * m_iCapacity + col] = value;
	return true;
}

bool MatrixGraph::setValueUnDiMatrix(int row, int col, const EdgeType value) {
	if (row < 0 || row >= m_iCapacity
		|| col < 0 || col >= m_iCapacity) {
		return false;
	}
	//无向图矩阵对角线数据相同
	m_pMatrix[row * m_iCapacity + col] = value;
	m_pMatrix[col * m_iCapacity + row] = value;
	return true;
}

bool MatrixGraph::getValueFromMatrix(int row, int col, EdgeType& value) const {
	if (row < 0 || row >= m_iCapacity
		|| col < 0 || col >= m_iCapacity) {
		return false;
	}
	value = m_pMatrix[row * m_iCapacity + col];
	return true;
}

void MatrixGraph::printMatrix() const {
	for (int i = 0; i < m_iCapacity; i++) {
		for (int j = 0; j < m_iCapacity; j++) {
			cout << m_pMatrix[i * m_iCapacity + j] << " ";
		}
		cout << endl;
	}
}

void MatrixGraph::DFSTraverseMatrix(int nodeIndex) const {
	if (nodeIndex > m_iVertexCount || m_pNodeArr[nodeIndex].m_bIsVisited) {
		return;
	}

	m_pNodeArr[nodeIndex].m_bIsVisited = true;
	cout << m_pNodeArr[nodeIndex].m_data << " ";
	for (int i = 0; i < m_iCapacity; i++) {
		EdgeType value;
		if (!getValueFromMatrix(nodeIndex, i, value)) {
			return;
		}
		if (value == edgeValid) {	
			if (m_pNodeArr[i].m_bIsVisited) { //已经遍历过，则跳过
				continue;
			}
			else {
				DFSTraverseMatrix(i);
			}
		}
		else {
			continue;
		}
	}
}

void MatrixGraph::BFSTraverseMatrix(int nodeIndex) const {
	if (nodeIndex > m_iVertexCount || m_pNodeArr[nodeIndex].m_bIsVisited) {
		return;
	}
	cout << m_pNodeArr[nodeIndex].m_data << " ";
	m_pNodeArr[nodeIndex].m_bIsVisited = true;
	vector<int> vec;
	vec.push_back(nodeIndex);
	BFSTraverseMatrixImpl(vec);
}

void MatrixGraph::BFSTraverseMatrixImpl(vector<int> preVec) const {
	if (preVec.empty()) {
		return;
	}
	vector<int> curVec;
	for (int i = 0; i < (int)preVec.size(); i++) {
		for (int j = 0; j < m_iCapacity; j++) {
			EdgeType value;
			if (!getValueFromMatrix(preVec[i], j, value)) {
				return;
			}
			if (value == edgeValid) {
				if (m_pNodeArr[j].m_bIsVisited) {
					continue;
				}
				else {	//没访问过，需要改变访问状态
					cout << m_pNodeArr[j].m_data << " ";
					m_pNodeArr[j].m_bIsVisited = true;
					curVec.push_back(j);
				}
			}
			else {
				continue;
			}
		}
	}
	if (curVec.empty()) {
		return;
	}
	BFSTraverseMatrixImpl(curVec);
}

void MatrixGraph::DFSTraverseMatrixStack() const {

}

void MatrixGraph::BFSTraverseMatrixQueue() const {
}