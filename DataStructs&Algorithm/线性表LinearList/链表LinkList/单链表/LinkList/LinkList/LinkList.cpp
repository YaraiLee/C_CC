#include "LinkList.h"
#include <iostream>

LinkList::LinkList()
{
	m_iLength = 0;
	m_pList = new Node;
	m_pList->next = NULL;
}

LinkList::~LinkList()
{
	clearList();
	delete m_pList;
	m_pList = NULL;
}

bool LinkList::isListEmpty() {
	return m_iLength == 0 ? true : false;
}

void LinkList::clearList() {
	Node* node = m_pList->next;
	Node* tmpNode = NULL;
	while (NULL != node) {
		tmpNode = node;
		node = node->next;
		tmpNode->next = NULL;
		delete tmpNode;
		m_iLength--;
	}
	tmpNode = NULL;
	m_pList->next = NULL;
}

int LinkList::getListLength() {
	return m_iLength;
}

bool LinkList::getListElem(int index, Node* ptrNode) const {
	if (index <= 0 || index > m_iLength) {
		return false;
	}
	Node* node = m_pList;
	for (int i = 0; i < index; i++) {
		node = node->next;
	}
	ptrNode->data = node->data;
	ptrNode->next = node->next;
	return true;
}

int LinkList::getListElemLocate(const Node& rNode) const {
	Node* node = m_pList->next;
	int index = 0;
	while (NULL != node) {
		index++;
		if (node->data == rNode.data) {
			return index;
		}
		node = node->next;
	}
	return -1;
}

void LinkList::traverseList() const {
	Node* node = m_pList->next;
	while (NULL != node) {
		node->printNode();
		node = node->next;
	}
}

bool LinkList::insertNodeHead(const Node& rNode) {
	Node* newNode = new Node;
	if (NULL == newNode) {
		return false;
	}
	newNode->data = rNode.data;
	newNode->next = m_pList->next;
	m_pList->next = newNode;
	
	m_iLength++;
	return true;
}

bool LinkList::insertNodeTail(const Node& rNode) {
	Node* newNode = new Node;
	if (NULL == newNode) {
		return false;
	}
	newNode->data = rNode.data;
	newNode->next = NULL;

	Node* node = m_pList;
	while (NULL != node->next) {
		node = node->next;
	}
	node->next = newNode;

	m_iLength++;
	return true;
}

bool LinkList::insertNode(int index, const Node& rNode) {
	if (index <= 0 || index > m_iLength+1) {
		return false;
	}
	Node* ptrNewNode = new Node;
	if (NULL == ptrNewNode) {
		return false;
	}

	Node* node = m_pList;
	for (int i = 0; i < index-1; i++) {
		node = node->next;
	}
	ptrNewNode->data = rNode.data;
	ptrNewNode->next = node->next;
	node->next = ptrNewNode;

	m_iLength++;
	return true;
}
bool LinkList::delListNode(int index, Node* ptrNode) {
	if (index <= 0 || index > m_iLength) {
		return false;
	}

	Node* node = m_pList;
	Node* preNode = NULL;
	for (int i = 0; i < index; i++) {
		preNode = node;
		node = node->next;
	}
	preNode->next = node->next;
	node->next = NULL;

	ptrNode->data = node->data;
	ptrNode->next = NULL;
	delete node;
	node = NULL;

	m_iLength--;
	return true;
}