#include "Gun.h"

void shoot(CanShoot* p) {
	p->aim();
	p->reload();
}

int main(void) {
	CanShoot* pCanShoot = new Gun;
	shoot(pCanShoot);
	cout << pCanShoot->START << endl;
	cout << pCanShoot->TUESDAY << endl;
	delete pCanShoot;
	pCanShoot = NULL;
	system("pause");
	return 0;
}