#pragma once

#include "CanShoot.h"
#include <iostream>

using namespace std;

class Gun : public CanShoot
{
public:
	Gun();
	virtual ~Gun();
	void aim();
	void reload();
private:
	int* m_pInt;
};