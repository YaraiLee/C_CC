#include "ArrayBT.h"

int main(void) {

	int size = 10;
	int root = 3;

	ArrayBT* pArrayBT = new ArrayBT(size,root);
	pArrayBT->traverseTree();
	//������
	int node1 = 5;
	int node2 = 8;
	pArrayBT->addNode(0, ArrayBT::NODE_LEFT, node1);
	pArrayBT->addNode(0, ArrayBT::NODE_RIGHT, node2);
	int node3 = 2;
	int node4 = 6;
	pArrayBT->addNode(1, ArrayBT::NODE_LEFT, node3);
	pArrayBT->addNode(1, ArrayBT::NODE_RIGHT, node4);
	int node5 = 9;
	int node6 = 7;
	pArrayBT->addNode(2, ArrayBT::NODE_LEFT, node5);
	pArrayBT->addNode(2, ArrayBT::NODE_RIGHT, node6);
	pArrayBT->traverseTree();
	//ɾ���ڵ�
	int delNode;
	if (pArrayBT->delNode(1, delNode)) {
		cout << "del node=" << delNode << endl;
		pArrayBT->traverseTree();
	}
	else {
		cerr << "del error" << endl;
	}
	//���ҽ��
	int *pDstNode = pArrayBT->searchNode(1);
	if (NULL != pDstNode) {
		cout << *pDstNode << endl;
	}
	else {
		cout << "node not exist!" << endl;
	}
	delete pArrayBT;
	pArrayBT = NULL;
	system("pause");
	return 0;
}