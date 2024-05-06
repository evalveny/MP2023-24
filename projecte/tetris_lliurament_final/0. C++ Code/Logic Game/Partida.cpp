#include "Partida.h"

void Partida::inicialitza(const string& nomFitxer)
{
	m_joc.inicialitza(nomFitxer);
}

void Partida::actualitza(TipusTecla tecla, float deltaTime)
{
	m_joc.dibuixa();
}