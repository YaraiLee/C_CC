#include "Node.h"
using namespace std;

Node::Node() {
	m_data = 0;
	m_iIndex = 0;
	m_pLChild = NULL;
	m_pRChild = NULL;
	m_pParent = NULL;
}

Node::Node(NodeDataType data, int index) {
	m_data = data;
	m_iIndex = index;
	m_pParent = NULL;
	m_pRChild = NULL;
	m_pLChild = NULL;
}

Node* Node::searchNode(int nodeIndex) {
	if (NULL == this || nodeIndex < 0) {
		return NULL;
	}

	if (this->m_iIndex == nodeIndex) {
		return this;
	}
	Node* node = NULL;
	if (NULL != this->m_pLChild) {
		node = this->m_pLChild->searchNode(nodeIndex);
		if (NULL != node) {
			return node;
		}
	}

	if (NULL != this->m_pRChild) {
		node = this->m_pRChild->searchNode(nodeIndex);
		if (NULL != node) {
			return node;
		}
	}
	return NULL;
}

bool Node::AddNode(int direction, Node* pNode) {
	if (NULL == pNode || (direction != LEFT_CHILD && direction != RIGHT_CHILD)) {
		return false;
	}

	Node* node = new Node;
	node->m_iIndex = pNode->m_iIndex;
	node->m_data = pNode->m_data;
	node->m_pParent = this;	//节点父指针

	if (direction == LEFT_CHILD) {
		node->m_pLChild = this->m_pLChild;
		if (NULL != this->m_pLChild) {	//如果this不是叶子节点
			this->m_pLChild->m_pParent = node;
		}
		this->m_pLChild = node;
	}
	else if (direction == RIGHT_CHILD) {
		node->m_pRChild = this->m_pRChild;
		if (NULL != this->m_pRChild) {
			this->m_pRChild->m_pParent = node;
		}
		this->m_pRChild = node;
	}
	else {
		return false;
	}
	return true;
}

void Node::DeleteNode() {
	if (NULL == this) {
		return;
	}

	if (NULL != this->m_pLChild) {
		this->m_pLChild->DeleteNode();
	}

	if (NULL != this->m_pRChild) {
		this->m_pRChild->DeleteNode();
	}

	if (this == this->m_pParent->m_pLChild) {
		this->m_pParent->m_pLChild = NULL;
	}

	if (this == this->m_pParent->m_pRChild) {
		this->m_pParent->m_pRChild = NULL;
	}

	delete this;
}

void Node::PreorderTraverse() const {
	cout << this->m_iIndex << " " << this->m_data << endl;
	if (NULL != this->m_pLChild) {
		this->m_pLChild->PreorderTraverse();
	}

	if (NULL != m_pRChild) {
		this->m_pRChild->PreorderTraverse();
	}
}
void Node::InorderTraverse() const {
	if (NULL != this->m_pLChild) {
		this->m_pLChild->InorderTraverse();
	}

	cout << this->m_iIndex << " " << this->m_data << endl;

	if (NULL != m_pRChild) {
		this->m_pRChild->InorderTraverse();
	}
}
void Node::PostorderTraverse() const {
	if (NULL != this->m_pLChild) {
		this->m_pLChild->PostorderTraverse();
	}

	if (NULL != m_pRChild) {
		this->m_pRChild->PostorderTraverse();
	}

	cout << this->m_iIndex << " " << this->m_data << endl;
}