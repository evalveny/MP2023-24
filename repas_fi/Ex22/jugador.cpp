#include "jugador.h"

void afegeixCartaJugador(Jugador& jugador, Carta& carta)
{
	jugador.cartes[jugador.nCartes] = carta;
	jugador.nCartes++;
}

bool tiraCartaJugador(Jugador& jugador, Carta& cartaActual, Carta& cartaATirar)
{
    cartaATirar.valor = -1;
    cartaATirar.color = cartaActual.color;
    int cartaSeleccionada = -1;
    jugador.haPogutTirar = false;
    for (int i = 0; i < jugador.nCartes; i++)
    {
        if (cartesCompatibles(cartaActual, jugador.cartes[i]))
        {
            jugador.haPogutTirar = true;
            if (jugador.cartes[i].color == cartaActual.color)
            {
                if ((jugador.cartes[i].valor > cartaATirar.valor) || (cartaATirar.color != cartaActual.color))
                {
                    cartaATirar = jugador.cartes[i];
                    cartaSeleccionada = i;
                }
            }
            else
            {
                if (cartaATirar.valor == -1)
                {
                    cartaATirar = jugador.cartes[i];
                    cartaSeleccionada = i;
                }
                    
            }
        }
    }
    if (jugador.haPogutTirar)
    {
        for (int i = cartaSeleccionada; i < (jugador.nCartes - 1); i++)
            jugador.cartes[i] = jugador.cartes[i + 1];
        jugador.nCartes--;
    }

    return jugador.haPogutTirar;
}