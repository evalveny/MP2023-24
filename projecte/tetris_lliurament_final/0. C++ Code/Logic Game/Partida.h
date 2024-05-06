#ifndef PARTIDA
#define PARTIDA

#include "./Joc.h"
#include "./InfoJoc.h"

class Partida
{
public:
	void inicialitza(const string& nomFitxer);
	void actualitza(TipusTecla tecla, float deltaTime);
private:
	Joc m_joc;
};
#endif
