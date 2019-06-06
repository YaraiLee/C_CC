#ifndef VERTEX_NODE_H
#define VERTEX_NODE_H

//顶点结点类定义
typedef char VertexType;	//顶点数据类型

class VertexNode
{
public:
	VertexNode(VertexType data = 0, bool isVisited = false);
	VertexType m_data;
	bool m_bIsVisited;
};

#endif