#include "carta.h"

bool cartesCompatibles(Carta& carta1, Carta& carta2)
{
	if ((carta1.valor == carta2.valor) || (carta1.color == carta2.color))
		return true;
	else
		return false;
}