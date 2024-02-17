#ifndef JUGADOR_H
#define JUGADOR_H

#include "carta.h"

const int MAX_CARTES = 40;

typedef struct
{
	Carta cartes[MAX_CARTES];
	int nCartes;
	int haPogutTirar;
} Jugador;

void afegeixCartaJugador(Jugador& jugador, Carta& carta);
bool tiraCartaJugador(Jugador& jugador, Carta& cartaActual, Carta& cartaATirar);

#endif