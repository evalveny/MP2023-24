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
	float dx = m_x - p.m_x;
	float dy = m_y - p.m_y;
	return sqrt(dx * dx + dy * dy);
	return 0;
}

Punt Punt::suma(Punt& p)
{
	Punt pSuma;
	pSuma.m_x = m_x + p.m_x;
	pSuma.m_y = m_y + p.m_y;
	return pSuma;
}

