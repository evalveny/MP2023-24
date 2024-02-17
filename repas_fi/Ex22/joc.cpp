#include "joc.h"
#include <fstream>
using namespace std;


bool agafaCarta(Joc& joc, int nJugador)
{
	bool correcte = false;
	if (joc.cartaActualBaralla < MAX_CARTES)
	{
		afegeixCartaJugador(joc.jugadors[nJugador], joc.cartesBaralla[joc.cartaActualBaralla]);
		joc.cartaActualBaralla++;
		correcte = true;
	}
	return correcte;
}

void inicialitza(Joc& joc, int cartesInicials[MAX_CARTES][2], int nJugadors)
{
	for (int i = 0; i < MAX_CARTES; i++)
	{
		joc.cartesBaralla[i].color = cartesInicials[i][0];
		joc.cartesBaralla[i].valor = cartesInicials[i][1];
	}
	joc.cartaActualBaralla = 0;
	for (int i = 0; i < nJugadors; i++)
	{
		joc.jugadors[i].nCartes = 0;
		joc.jugadors[i].haPogutTirar = true;
		for (int j = 0; j < N_CARTES_JUGADOR; j++)
		{	
			bool correcte = agafaCarta(joc, i);
		}
	}
	joc.nJugadors = nJugadors;
	joc.cartaActualJoc = joc.cartesBaralla[joc.cartaActualBaralla];
	joc.cartaActualBaralla++;
	joc.jugadorActual = 0;
}


void tiraCarta(Joc& joc, int moviments[MAX_MOVIMENTS][4], int& nMoviments)
{
	bool potRobar = true;
	bool potTirar = false;
	Carta cartaATirar;
	do
	{
		potTirar = tiraCartaJugador(joc.jugadors[joc.jugadorActual], joc.cartaActualJoc, cartaATirar);
		if (!potTirar)
		{
			moviments[nMoviments][0] = joc.jugadorActual;
			moviments[nMoviments][1] = ROBA_CARTA;
			moviments[nMoviments][2] = joc.cartesBaralla[joc.cartaActualBaralla].color;
			moviments[nMoviments][3] = joc.cartesBaralla[joc.cartaActualBaralla].valor;
			nMoviments++;
			potRobar = agafaCarta(joc, joc.jugadorActual);
		}
	} while ((!potTirar) && (potRobar));
	if (potTirar)
	{
		joc.cartaActualJoc = cartaATirar;
		moviments[nMoviments][0] = joc.jugadorActual;
		moviments[nMoviments][1] = TIRA_CARTA;
		moviments[nMoviments][2] = cartaATirar.color;
		moviments[nMoviments][3] = cartaATirar.valor;
		nMoviments++;
	}
	else
	{
		moviments[nMoviments][0] = joc.jugadorActual;
		moviments[nMoviments][1] = PASSA_TORN;
		moviments[nMoviments][2] = -1;
		moviments[nMoviments][3] = -1;
		nMoviments++;
	}
}

bool final(Joc& joc)
{
	bool finalPartida = false;
	int i = 0;
	while (!finalPartida && (i < joc.nJugadors))
	{
		if (joc.jugadors[i].nCartes == 0)
			finalPartida = true;
		else
			i++;
	}
	if (!finalPartida)
	{
		finalPartida = true;
		i = 0;
		while (finalPartida && (i < joc.nJugadors))
		{
			if (joc.jugadors[i].haPogutTirar)
				finalPartida = false;
			else
				i++;
		}
	}
	return finalPartida;
}


void jugaPartida(int cartesInicials[MAX_CARTES][2], int nJugadors, int moviments[MAX_MOVIMENTS][4], int& nMoviments)
{
	Joc joc;
	nMoviments = 0;

	inicialitza(joc, cartesInicials, nJugadors);
	while (!final(joc))
	{
		tiraCarta(joc, moviments, nMoviments);
		joc.jugadorActual = (joc.jugadorActual + 1) % nJugadors;
	}
}