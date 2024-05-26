#include "Jugador.h"

void Jugador::afegeixCarta(const Carta& carta)
{

	// afegeix una carta al conjunt de cartes del jugador

}



bool Jugador::tiraCarta(const Carta& cartaTirada, Carta& cartaATirar)
{

	// Aquest m�tode ha de seleccionar una de les cartes de les que t� el jugador per poder tirar en el seu torn.
	// En el par�metre cartaTirada  rep la carta que ha tirat el jugador anterior i que est� a dalt de tot 
	// de les cartes jugades.
	// Si t� alguna carta que es pugui tirar segons les regles del joc, 
	// la retornar� al par�metre per refer�ncia cartaATirar i retornar� true com a resultat de la funci�.
	// Si no t� cap carta per tirar retornar� false.
	// En qualsevol dels dos casos s�ha d�actualitzar l�atribut que indica si el jugador ha pogut tirar o no en el seu torn.
	// Si el jugador t� m�s d�una carta que es pot tirar, la carta a tirar es seleccionar� seguint aquest ordre de prioritat:
		// Carta especial de robar 2 del color de l��ltima carta tirada.
		// Carta especial de canvi de torn del color de l��ltima carta tirada.
		// Carta especial de saltar torn del color de l��ltima carta tirada.
		// Una carta normal del mateix color de l��ltima carta tirada.Si en tenim m�s d�una, 
		// tirarem la que tingui el valor m�s petit.
		// Una carta normal del mateix valor de l��ltima carta tirada, per� de diferent color.
		// Si en tenim m�s d�una tirarem la que tingui el codi de color m�s petit segons les 
		// constants de color declarades al fitxer �Carta.h�.



}