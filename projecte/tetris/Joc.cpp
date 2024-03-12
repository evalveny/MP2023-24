#include "Joc.h"
#include <fstream>
using namespace std;

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
	return true;
}

bool Joc::mouFigura(int dirX)
{
	return true;
}

int Joc::baixaFigura()
{
	return 0;
}

void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		m_tauler.colocaFigura(m_figuraActual);
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
