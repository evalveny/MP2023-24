#include <iostream>
#include <math.h>

using namespace std;

typedef struct
{
	float x;
	float y;
} Punt;

void llegeixPunt(Punt& p)
{
	cout << "Introdueix coordinades x i y del punt: ";
	cin >> p.x >> p.y;
}

void mostraPunt(Punt & p)
{
	cout << "(" << p.x << ", " << p.y << ")";
}

float distanciaPunts(Punt &p1, Punt &p2)
{
	float dx = p1.x - p2.x;
	float dy = p1.y - p2.y;
	return sqrt(dx*dx + dy * dy);
}


int main()
{
	Punt p1 = { 0, 0 };
	Punt p2;

	llegeixPunt(p2);

	float distancia = distanciaPunts(p1, p2);

	cout << "Primer punt: ";
	mostraPunt(p1);
	cout << endl;
	cout << "Segon punt: ";
	mostraPunt(p2);
	cout << endl;
	cout << "Distancia: " << distancia << endl;

	return 0;
}

