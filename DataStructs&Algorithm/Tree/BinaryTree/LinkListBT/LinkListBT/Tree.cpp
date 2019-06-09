#include "Tree.h"
using namespace std;

Tree::Tree() {
	m_pRoot = new Node;
}

Tree::~Tree() {
	m_pRoot->DeleteNode();
}
Node* Tree::searchNode(int nodeIndex) {
	if (NULL == m_pRoot || nodeIndex < 0) {
		return NULL;
	}
	return m_pRoot->searchNode(nodeIndex);
}
bool Tree::AddNode(int nodeIndex, int direction, Node* pNode) {
	Node* preNode = this->searchNode(nodeIndex);
	if (NULL != preNode) {
		return preNode->AddNode(direction, pNode);
	}
	return false;
}
bool Tree::DeleteNode(int nodeIndex, Node* pNode) {
	Node* preNode = this->searchNode(nodeIndex);
	if (preNode != NULL) {
		if (NULL != pNode) {
			pNode->m_data = preNode->m_data;
			pNode->m_iIndex = preNode->m_iIndex;
		}
		preNode->DeleteNode();
		return true;
	}
	return false;
}

void Tree::PreorderTraverse() const {
	m_pRoot->PreorderTraverse();
	cout << endl;
}
void Tree::InorderTraverse() const {
	m_pRoot->InorderTraverse();
	cout << endl;
}
void Tree::PostorderTraverse() const {
	m_pRoot->PostorderTraverse();
	cout << endl;
}