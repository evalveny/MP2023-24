#include "Partida.h"
#include "GraphicManager.h"

void Partida::inicialitza(const string& nomFitxer)
{
	m_joc.inicialitza(nomFitxer);
}

void Partida::actualitza(TipusTecla tecla, float deltaTime)
{
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	m_joc.dibuixa();
}