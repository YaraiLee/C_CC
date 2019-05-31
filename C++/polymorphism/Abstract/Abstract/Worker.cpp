#include "Worker.h"


Worker::Worker(string name, string code) :Person(name), m_strCode(code)
{
	cout << "Worker(string name, string code)" << endl;
}

Worker::~Worker()
{
	cout << "~Worker()" << endl;
}

void Worker::work() {
	cout << "Worker::work()" << endl;
}