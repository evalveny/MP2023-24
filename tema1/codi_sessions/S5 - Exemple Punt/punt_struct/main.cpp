#include "Punt.h"
#include "Poligon.h"
#include <iostream>
using namespace std;

int main()
{
	Punt p1 = { 0, 0 };
	Punt p2;

	p2.llegeix();

	float distancia = p1.distancia(p2);

	cout << "Primer punt: ";
	p1.mostra();
	cout << endl;
	cout << "Segon punt: ";
	p2.mostra();
	cout << endl;
	cout << "Distancia: " << distancia << endl;

	return 0;
}

