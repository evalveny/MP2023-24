#include "Figura.h"

void Figura::gira()
{
	m_forma.gira();
}

void Figura::mou(int dirX)
{
	m_posX += dirX;
}

void Figura::baixa()
{
	m_posY += 1;
}