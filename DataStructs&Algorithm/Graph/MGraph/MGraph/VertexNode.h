#ifndef VERTEX_NODE_H
#define VERTEX_NODE_H

//�������ඨ��
typedef char VertexType;	//������������

class VertexNode
{
public:
	VertexNode(VertexType data = 0, bool isVisited = false);
	VertexType m_data;
	bool m_bIsVisited;
};

#endif