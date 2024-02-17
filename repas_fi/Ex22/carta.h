#ifndef CARTA_H
#define CARTA_H


const int VERMELL = 0;
const int VERD = 1;
const int BLAU = 2;
const int GROC = 3;

typedef struct
{
	int valor;
	int color;
} Carta;


bool cartesCompatibles(Carta& carta1, Carta& carta2);

#endif
