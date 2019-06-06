#include "MatrixGraph.h"

/************************************************************************/
/*ͼ���£�				
				A				
			  /	  \
			 B	   D			
			/ \	  / \
		   C   F G - H
		   \   /
		     E

�������: A B C E F D G H
�������: A B D C F G H E

�ڽӾ���
	0 1 2 3 4 5 6 7
	A B C D E F G H
A     1	  1
B   1	1     1
C     1     1
D   1			1 1
E		1	  1
F	  1		1	
G		  1		  1
H		  1		1

/************************************************************************/
int main(void) {
	MatrixGraph* pMatrix = new MatrixGraph(8);
	//��������
	VertexNode node1('A');
	VertexNode node2('B');
	VertexNode node3('C');
	VertexNode node4('D');
	VertexNode node5('E');
	VertexNode node6('F'); 
	VertexNode node7('G');
	VertexNode node8('H');
	//��Ӷ���
	pMatrix->addVertexNode(&node1);
	pMatrix->addVertexNode(&node2);
	pMatrix->addVertexNode(&node3);
	pMatrix->addVertexNode(&node4);
	pMatrix->addVertexNode(&node5);
	pMatrix->addVertexNode(&node6);
	pMatrix->addVertexNode(&node7);
	pMatrix->addVertexNode(&node8);
	//���ñ�/��
	pMatrix->setValueUnDiMatrix(0, 1);
	pMatrix->setValueUnDiMatrix(0, 3);
	pMatrix->setValueUnDiMatrix(1, 2);
	pMatrix->setValueUnDiMatrix(1, 5);
	pMatrix->setValueUnDiMatrix(2, 4);
	pMatrix->setValueUnDiMatrix(3, 6);
	pMatrix->setValueUnDiMatrix(3, 7);
	pMatrix->setValueUnDiMatrix(4, 5);
	pMatrix->setValueUnDiMatrix(6, 7);

	pMatrix->printMatrix();

	//EdgeType val;
	//cout << boolalpha << pMatrix->getValueFromMatrix(0, 1, val) << endl;
	//cout << val << endl;
	
	cout << "DFS" << endl;
	pMatrix->DFSTraverseMatrix();
	cout << endl;
	//���ö���Ϊδ����״̬
	pMatrix->resetVertex();

	cout << "BFS" << endl;
	pMatrix->BFSTraverseMatrix();
	cout << endl;

	system("pause");
	return 0;
}