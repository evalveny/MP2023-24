#include <iostream>
#include <math.h>
#include "Punt.h"

using namespace std;


void Punt::llegeix()
{
	cout << "Introdueix coordinades x i y del punt: ";
	cin >> m_x >> m_y;
}

void Punt::mostra()
{
	cout << "(" << m_x << ", " << m_y << ")";
}

float Punt::distancia(Punt& p)
{
	return 0;
}



