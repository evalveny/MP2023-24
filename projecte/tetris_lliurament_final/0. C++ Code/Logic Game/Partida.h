#ifndef PARTIDA
#define PARTIDA

#include "./Joc.h"
#include "./InfoJoc.h"
#include "LlistaFigura.h"
#include "LlistaMoviment.h"
#include <ctime>

const int PUNTS_FIGURA = 10;
const int PUNTS_FILA = 100;
const int DOBLE_FILA = 50;
const int TRIPLE_FILA = 75;
const int QUADRUPLE_FILA = 100;

const int CANVI_NIVELL = 200;
const double VELOCITAT_INICIAL = 1.0;
const double CANVI_VELOCITAT = 0.75;

typedef enum
{
	MODE_NORMAL,
	MODE_TEST
} ModeJoc;

class Partida
{
public:
	Partida() : m_mode(MODE_NORMAL), m_temps(0.0), m_punts(0), m_nivell(1), m_velocitat(VELOCITAT_INICIAL), m_finalJoc(false)
	{
		srand(time(0));
	}
	Partida(ModeJoc mode) : m_mode(mode), m_temps(0.0), m_punts(0), m_nivell(1), m_velocitat(VELOCITAT_INICIAL), m_finalJoc(false)
	{
		srand(time(0));
	}
	void inicialitza(const string& nomFitxerInicial, const string& nomFitxerFigures, const string& nomFitxerMoviments);		
	void actualitza(float deltaTime);
	int getPuntuacio() const { return m_punts; }
private:
	Joc m_joc;
	ModeJoc m_mode;
	double m_temps;
	int m_punts;
	int m_nivell;
	double m_velocitat;
	bool m_finalJoc;
	LlistaFigura m_figures;
	LlistaMoviment m_moviments;

	void actualitzaPunts(int nFilesEliminades);
	void inicialitzaFigures(const string& nomFitxer);
	void inicialitzaMoviments(const string& nomFitxer);
	void actualitzaNormal(float deltaTime);
	void actualitzaTest(float deltaTime);

};
#endif
