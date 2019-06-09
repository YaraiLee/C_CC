#include "Tree.h"
using namespace std;
/************************************************************************/
/*				(0)
		5(1)			8(2)
	2(3)	6(4)	9(5)	7(6)

按照索引：
	前序遍历: 0 1 3 4 2 5 6
	中序遍历: 3 1 4 0 5 2 6
	后序遍历: 2 4 1 5 6 2 0
按数据：
	前序遍历: 0 5 2 6 8 9 7
	中序遍历: 2 5 6 0 9 8 7
	后序遍历: 2 6 5 9 7 8 0
/************************************************************************/

int main(void) {

	Tree* pTree = new Tree;
	Node node1(5, 1), node2(8, 2), node3(2,3), node4(6,4), node5(9,5), node6(7,6), node7(1, 7);

	pTree->AddNode(0, Node::LEFT_CHILD, &node1);
	pTree->AddNode(0, Node::RIGHT_CHILD, &node2);
	pTree->AddNode(1, Node::LEFT_CHILD, &node3);
	pTree->AddNode(1, Node::RIGHT_CHILD, &node4);
	pTree->AddNode(2, Node::LEFT_CHILD, &node5);
	pTree->AddNode(2, Node::RIGHT_CHILD, &node6);
	//pTree->AddNode(0, Node::LEFT_CHILD, &node7);	//node7添加位置不是叶子节点位置
	
	pTree->PreorderTraverse();

	pTree->DeleteNode(node1.m_iIndex, NULL);

	pTree->PreorderTraverse();
	pTree->InorderTraverse();
	pTree->PostorderTraverse();

	system("pause");
	return 0;
}