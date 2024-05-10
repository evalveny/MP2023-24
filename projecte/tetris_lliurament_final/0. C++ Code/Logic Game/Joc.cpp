#include "Joc.h"
#include <fstream>
using namespace std;

bool Joc::novaFigura()
{
	TipusFigura tipus = TipusFigura((rand() % N_TIPUS_FIGURES) + 1);
	int colMaxima = N_COL_TAULER - 2;
	if (tipus == FIGURA_O)
		colMaxima = N_COL_TAULER - 1;
	else
		if (tipus == FIGURA_I)
			colMaxima = N_COL_TAULER - 3;
	int columna = (rand() % colMaxima) + 1;
	int nGir = (rand() % 4);
	m_figuraActual.inicialitza(tipus, 1, columna);
	for (int i = 0; i < nGir; i++)
		m_figuraActual.gira(GIR_HORARI);
	bool colisiona = m_tauler.colisionaFigura(m_figuraActual);
	return colisiona;
}

void Joc::novaFigura(InfoFigura figura)
{
	m_figuraActual.inicialitza(figura.tipus, figura.fila, figura.columna);
	for (int i = 0; i < figura.gir; i++)
		m_figuraActual.gira(GIR_HORARI);
}

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		int tipus, fila, columna, gir;
		fitxer >> tipus >> fila >> columna >> gir;
		m_figuraActual.inicialitza(TipusFigura(tipus), fila, columna);
		for (int i = 0; i < gir; i++)
			m_figuraActual.gira(GIR_HORARI);

		ColorFigura taulerInicial[MAX_FILA][MAX_COL];
		int color;
		for (int i = 0; i < MAX_FILA; i++)
			for (int j = 0; j < MAX_COL; j++)
			{
				fitxer >> color;
				taulerInicial[i][j] = ColorFigura(color);
			}
		m_tauler.inicialitza(taulerInicial);
		fitxer.close();
	}
}

bool Joc::giraFigura(DireccioGir direccio)
{
	m_figuraActual.gira(direccio);
	bool colisiona = m_tauler.colisionaFigura(m_figuraActual);
	if (colisiona)
	{
		if (direccio == GIR_HORARI)
			direccio = GIR_ANTI_HORARI;
		else
			direccio = GIR_HORARI;
		m_figuraActual.gira(direccio);
	}
	return !colisiona;
}

bool Joc::mouFigura(int dirX)
{
	m_figuraActual.mou(dirX);
	bool colisiona = m_tauler.colisionaFigura(m_figuraActual);
	if (colisiona)
		m_figuraActual.mou(-dirX);
	return !colisiona;
}

int Joc::baixaFigura()
{
	int nFiles = -1;
	m_figuraActual.baixa();
	if (m_tauler.colisionaFigura(m_figuraActual))
	{
		nFiles = 0;
		m_figuraActual.puja();
		nFiles = m_tauler.colocaFigura(m_figuraActual);
	}
	return nFiles;
}

int Joc::colocaFigura()
{
	int nFiles;
	do 
	{
		nFiles = baixaFigura();
	} while (nFiles == -1);
	return nFiles;
}

void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		if (m_figuraActual.getTipus() != NO_FIGURA)
			m_tauler.dibuixaFigura(m_figuraActual);
		ColorFigura tauler[MAX_FILA][MAX_COL];
		m_tauler.getValorsTauler(tauler);
		for (int i = 0; i < MAX_FILA; i++)
		{
			for (int j = 0; j < MAX_COL; j++)
			{
				fitxer << int(tauler[i][j]) << " ";
			}
			fitxer << endl;
		}

		fitxer.close();
	}
}

void Joc::dibuixa()
{
	m_tauler.dibuixa();
	m_figuraActual.dibuixa();
}