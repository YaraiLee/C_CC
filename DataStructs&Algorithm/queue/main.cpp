#include "MyQueue.h"
#include <stdlib.h> 
#include <iostream>
using namespace std;

int main(void) 
{
	int ele;
	MyQueue queue = MyQueue(QUEUE_CAPACITY);
	queue.EnQueue(1);
	queue.EnQueue(2);
	queue.EnQueue(4);
	queue.DeQueue(ele);
	cout << "DeQueue:" << ele << endl;
	queue.EnQueue(5);
//	cout << queue.QueueLength() << endl;
	queue.QueueTraverse();
//	delete queue;
//	queue = NULL;
	system("pause");
	return 0;
}
