#include <iostream>
#include "MyQueue.h"

MyQueue::MyQueue(int queueCapacity) {
    m_iQueueCapacity = queueCapacity;
    m_pQueue = new DataType[m_iQueueCapacity];
    ClearQueue();
}
MyQueue::~MyQueue() {
    delete []m_pQueue;
    m_pQueue = NULL;
}
void MyQueue::ClearQueue() {
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
}
bool MyQueue::QueueEmpty() const {
    return m_iQueueLen == 0 ? true : false;
}
bool MyQueue::QueueFull() const {
    return m_iQueueCapacity == m_iQueueLen ? true : false;
}
int MyQueue::QueueLength() const {
	return m_iQueueLen;
}
bool MyQueue::EnQueue(DataType element) {
	if (QueueFull()) {
		return false;
	}
	m_pQueue[m_iTail] = element;
	m_iTail = ++m_iTail % m_iQueueCapacity;
	m_iQueueLen++;
	return true;
}
bool MyQueue::DeQueue(DataType &element) {
	if (QueueEmpty()) {
		return false;
	}
	element = m_pQueue[m_iHead];
	m_iHead = ++m_iHead % m_iQueueCapacity;
	m_iQueueLen--;
	return true; 
}
void MyQueue::QueueTraverse() {	
	for (int i = 0; i < m_iQueueLen; i++) {
		std::cout << m_pQueue[(m_iHead + i) % m_iQueueCapacity] << std::endl;
	}
}
