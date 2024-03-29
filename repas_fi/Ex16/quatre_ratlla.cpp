#include <iostream>
#include "quatre_ratlla.h"

using namespace std;

// DESCRIPTION: 
// Afegeix una fitxa del color del jugador que es passa com a par�metre a una
// columna del taular 
// PARAMETERS:
// tauler: matriu que cont� l'estat actual del joc
// columna: columna on es vol posar la fitxa (entre 0 i N_COLUMNES - 1)
// jugador: indica quin jugador est� posant la fitxa. Pot tenir els valors 1 � 2
// RETURN:
// - Si la fitxa no es pot posar perqu� la columna ja est� plena retorna -1
// - Si la fitxa s� que es pot posar retorna la fila on queda col�locada (suposant
//   que la fila superior �s la fila 0. 
int posaFitxa(int tauler[N_FILES][N_COLUMNES], int columna, int jugador)
{
    int i = 0;
    bool trobat = false;
    while ((i < N_FILES) && !trobat)
    {
        if (tauler[i][columna] != 0)
            trobat = true;
        else i++;
    }
    if (i > 0)
        tauler[i - 1][columna] = jugador;
    return i-1;
}

bool quatreRatllaDireccio(int tauler[N_FILES][N_COLUMNES], int fila, int columna, int dirF, int dirC)
{
	bool iguals = true;
	bool ratlla = false;
	int nIguals = 1;
	int posCol = columna;
	int posFil = fila;
	int limitF, limitC;
	if (tauler[fila][columna] != 0)
	{
		if (dirF > 0)
			limitF = N_FILES - 1;
		else
			if (dirF < 0)
				limitF = 0;
			else
				limitF = -1;
		if (dirC > 0)
			limitC = N_COLUMNES - 1;
		else
			if (dirC < 0)
				limitC = 0;
			else
				limitC = -1;

		while ((nIguals < 4) && (posCol != limitC) && (posFil != limitF) && iguals)
		{
			if (tauler[posFil][posCol] != tauler[posFil + dirF][posCol + dirC])
				iguals = false;
			else
			{
				nIguals++;
				posFil += dirF;
				posCol += dirC;
			}
		}
		iguals = true;
		int posCol = columna;
		int posFil = fila;
		dirF = -dirF;
		dirC = -dirC;
		limitC = (N_COLUMNES - 1) - limitC;
		limitF = (N_FILES - 1) - limitF;
		while ((nIguals < 4) && (posCol != limitC) && (posFil != limitF) && iguals)
		{
			if (tauler[posFil][posCol] != tauler[posFil + dirF][posCol + dirC])
				iguals = false;
			else
			{
				nIguals++;
				posFil += dirF;
				posCol += dirC;
			}
		}
	}
	if (nIguals == 4)
		ratlla = true;
	else
		ratlla = false;
	return ratlla;
}

// DESCRIPTION: 
// Comprova si hi ha alguna combinaci� de fitxes (en qualsevol de les 4 direccions 
// possibles) que formi quatre en ratlla i que passi per la fila i columna que 
// s'indiquen com a par�metre
// PARAMETERS:
// tauler: matriu que cont� l'estat actual del joc
// fila: fila de la posici� per la que es vol comprovar si forma 4 en ratlla
// columna: columna de la posici� per la que es vol comprovar si forma 4 en ratlla
// RETURN:
// Si hi ha quatre en ratlla que passi per la fila i columna (true) o no (false)
bool quatreRatlla(int tauler[N_FILES][N_COLUMNES], int fila, int columna)
{
	bool ratlla = quatreRatllaDireccio(tauler, fila, columna, 1, 0);
	if (!ratlla)
		ratlla = quatreRatllaDireccio(tauler, fila, columna, 0, 1);
		if (!ratlla)
			ratlla = quatreRatllaDireccio(tauler, fila, columna, 1, 1);
			if (!ratlla)
				ratlla = quatreRatllaDireccio(tauler, fila, columna, -1, 1);
	return ratlla;
}

void mostraTauler(int tauler[N_FILES][N_COLUMNES])
{
	for (int i = 0; i < N_FILES; i++)
	{
		cout << "|";
		for (int j = 0; j < N_COLUMNES; j++)
			cout << tauler[i][j] << "|";
		cout << endl;
	}
}

int jugaQuatreRatlla(int tauler[N_FILES][N_COLUMNES])
{
    int jugador = 1;
    int nLliures = N_FILES * N_COLUMNES;
    bool final = false;
    int guanyador = -1;
    int fila, columna;
    while ((!final) && (nLliures > 0))
    {
        mostraTauler(tauler);
        cout << "Torn del jugador: " << jugador;
        do
        {
            cout << "A quina columna vols posar la fitxa? ";
            cin >> columna;
            fila = posaFitxa(tauler, columna, jugador);
            if (fila == -1)
                cout << "Aquesta columna esta plena. Torna a provar" << endl;
        }
        while (fila == -1);
        nLliures--;
        final = quatreRatlla(tauler, fila, columna);
        if (final)
            guanyador = jugador;
        else
            jugador = 3 - jugador;
    }
    return guanyador;
}