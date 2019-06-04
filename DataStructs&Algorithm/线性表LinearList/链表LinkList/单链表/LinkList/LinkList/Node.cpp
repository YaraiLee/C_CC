#include "Node.h"
#include <iostream>
using namespace std;

Node::Node() {

}

Node::~Node() {
}
Node::Node(DataType data) {
	this->data = data;
	next = NULL;
}
void Node::printNode() {
	cout << data << endl;
}