#ifndef MY_QUEUE_H
#define MY_QUEUE_H

typedef int DataType;

#define QUEUE_CAPACITY 10 

class MyQueue
{
private:
    DataType *m_pQueue;  //队列数组指针
    int m_iQueueLen;    //队列元素个数
    int m_iQueueCapacity;   //队列数组容量
    int m_iHead;
    int m_iTail;
public:
    MyQueue(int queueCapacity);
    virtual ~MyQueue();
    void ClearQueue();
    bool QueueEmpty() const;
    bool QueueFull() const;
    int QueueLength() const;
    bool EnQueue(DataType element);
    bool DeQueue(DataType &element);
    void QueueTraverse();
};
#endif