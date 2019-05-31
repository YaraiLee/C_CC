#pragma once

#include "Worker.h"

class DustMan : public Worker
{
public:
	DustMan(string name, string code);
	virtual ~DustMan();
	void printInfo();
private:

};
