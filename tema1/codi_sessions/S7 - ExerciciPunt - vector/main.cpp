#include "Punt.h"
#include <iostream>
using namespace std;

int main()
{
	Punt p1;
	p1.setX(0.0);
	p1.setY(0.0);

	Punt p2;
	p2.llegeix();
	if ((p2.getX() != 0) && (p2.getY() != 0))
	{
		float distancia = p1.distancia(p2);

		cout << "Primer punt: ";
		p1.mostra();
		cout << endl;
		cout << "Segon punt: ";
		p2.mostra();
		cout << endl;
		cout << "Distancia: " << distancia << endl;
	}

	return 0;

}
