#include <iostream>
#include "joc.h"
using namespace std;


void mostraCarta(int carta[2])
{
	cout << "{";
	switch (carta[0])
	{
	case VERMELL: 
		cout << "VERMELL";
		break;
	case VERD:
		cout << "VERD";
		break;
	case BLAU:
		cout << "BLAU";
		break;
	case GROC:
		cout << "GROC";
		break;
	default:
		cout << "---";
		break;
	}
	cout << ", " << carta[1];
	cout << "}";
}


void mostraMoviment(int moviment[4])
{
	cout << "Jug. " << moviment[0];
	switch (moviment[1])
	{
	case ROBA_CARTA:
		cout << " ROBA CARTA ";
		break;
	case TIRA_CARTA:
		cout << " TIRA CARTA ";
		break;
	case PASSA_TORN:
		cout << " PASSA TORN ";
		break;
	}
	mostraCarta(&moviment[2]);
}

void mostraCartesJugador(int cartes[MAX_CARTES][2], int jugador)
{
	for (int i = jugador * 7; i < (jugador + 1) * 7; i++)
	{
		mostraCarta(cartes[i]);
		cout << ",";
	}
}

bool comparaMoviment(int movimentEsperat[4], int moviment[4])
{
	bool iguals = true;
	int i = 0;
	while (iguals && (i < 4))
	{
		if (movimentEsperat[i] != moviment[i])
			iguals = false;
		else
			i++;
	}
	return iguals;
}

float comparaMoviments(int movimentsEsperats[MAX_MOVIMENTS][4], int nMovimentsEsperat,
	int moviments[MAX_MOVIMENTS][4], int nMoviments)
{
	bool iguals = true;
	float reduccio = 0.0;
	for (int i = 0; i < nMovimentsEsperat; i++)	
	{
		if (!comparaMoviment(movimentsEsperats[i], moviments[i]))
		{
			iguals = false;
			reduccio += 1.0;
		}
	}
	if (!iguals)
	{
		cout << "Comment :=>> ERROR. ELS MOVIMENTS NO SON IGUALS ALS ESPERATS" << endl;
	}
	if (nMovimentsEsperat != nMoviments)
	{
		cout << "Comment :=>> ERROR. EL NUMERO DE MOVIMENTS NO ES IGUAL AL NUMERO DE MOVIMENTS ESPERAT" << endl;
		reduccio += 4.0;
	}
	if (iguals && (nMovimentsEsperat == nMoviments))
	{
		cout << "Comment :=>> CORRECTE" << endl;
	}
	return reduccio;
}


float testMoviments()
{
	float grade = 10.0;

/*	Carta cartesInicials[MAX_CARTES][2] =
	{
		{VERMELL, 0}, {VERMELL, 1}, {VERMELL, 2}, {VERMELL, 3}, {VERMELL, 4}, {VERMELL, 5}, {VERMELL, 6},
		{BLAU, 1}, {BLAU, 2}, {BLAU, 3}, {BLAU, 4}, {BLAU, 5}, {BLAU, 6}, {BLAU, 7},
		{VERMELL, 7}, {VERMELL, 8}, {VERMELL, 9}, {GROC, 0}, {GROC, 1}, {GROC, 2}, {GROC, 3},
		{VERD, 0}, {VERD, 1}, {VERD, 2}, {VERD, 3}, {VERD, 4}, {VERD, 5}, {BLAU, 0},
		{VERD, 7}, 
	};

	int movimentsEsperats[MAX_MOVIMENTS][4] =
	{
		{0, TIRA_CARTA, VERD, 0}, {1, ROBA_CARTA, BLAU, 8}, {1, ROBA_CARTA, BLAU, 9}, {1, ROBA_CARTA, VERD, 6}, 
		{1, ROBA_CARTA, VERD, 7}, {1, ROBA_CARTA, VERD, 8}, {1, ROBA_CARTA, VERD, 9}, {1, ROBA_CARTA, GROC, 5}, 
		{1, ROBA_CARTA, GROC, 6}, {1, ROBA_CARTA, GROC, 7}, {1, ROBA_CARTA, GROC, 8}, {1, ROBA_CARTA, GROC, 9},
		{1, PASSA_TORN, -1, -1}, {2, TIRA_CARTA, VERMELL, 9}, {3, PASSA_TORN, -1, -1}, {0, TIRA_CARTA, VERMELL, 1},
		{1, TIRA_CARTA, BLAU, 1}, {2, TIRA_CARTA, GROC, 1}, {3, TIRA_CARTA, VERD, 1}, 
	}
*/
	int cartesInicials[MAX_CARTES][2] =
	{
		{VERMELL, 0}, {VERMELL, 3}, {VERMELL, 6}, {VERMELL, 9}, {VERD, 2}, {VERD, 5}, {VERD, 8},
		{VERMELL, 1}, {VERMELL, 4}, {VERMELL, 7}, {VERD, 0}, {VERD, 3}, {VERD, 6}, {VERD, 9},
		{VERMELL, 2}, {VERMELL, 5}, {VERMELL, 8}, {VERD, 1}, {VERD, 4}, {VERD, 7}, {BLAU, 0},
		{BLAU, 1}, {BLAU, 2}, {BLAU, 3}, {BLAU, 4}, {BLAU, 5}, {BLAU, 6}, {BLAU, 7},{BLAU, 8}, {BLAU, 9},
		{GROC, 0}, {GROC, 1}, {GROC, 2}, {GROC, 3}, {GROC, 4}, {GROC, 5}, {GROC, 6}, {GROC, 7},{GROC, 8}, {GROC, 9},
	};
	int movimentsEsperats[MAX_MOVIMENTS][4] =
	{
		{0, ROBA_CARTA, BLAU, 2}, {0, TIRA_CARTA, BLAU, 2}, {1, ROBA_CARTA, BLAU, 3}, {1, TIRA_CARTA, BLAU, 3},
		{2, TIRA_CARTA, BLAU, 0}, {0, TIRA_CARTA, VERMELL, 0}, {1, TIRA_CARTA, VERMELL, 7}, {2, TIRA_CARTA, VERMELL, 8}, 
		{0, TIRA_CARTA, VERMELL, 9}, {1, TIRA_CARTA, VERMELL, 4}, {2, TIRA_CARTA, VERMELL, 5}, {0, TIRA_CARTA, VERMELL, 6},
		{1, TIRA_CARTA, VERMELL, 1}, {2, TIRA_CARTA, VERMELL, 2}, {0, TIRA_CARTA, VERMELL, 3}, {1, TIRA_CARTA, VERD, 3},
		{2, TIRA_CARTA, VERD, 7}, {0, TIRA_CARTA, VERD, 8}, {1, TIRA_CARTA, VERD, 9}, {2, TIRA_CARTA, VERD, 4},
		{0, TIRA_CARTA, VERD, 5}, {1, TIRA_CARTA, VERD, 6}, {2, TIRA_CARTA, VERD, 1}
	};
	int nJugadors = 3;
	int nMovimentsEsperat = 23;

	int moviments[MAX_MOVIMENTS][4];
	int nMoviments;
	
	cout << endl;
	cout << "Comment :=>> Execucio de la partida completa" << endl;
	cout << "Comment :=>> ===============================" << endl;
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> ......." << endl;


	jugaPartida(cartesInicials, nJugadors, moviments, nMoviments);


	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> ------------------------------------------" << endl;
	cout << "Comment :=>> Final de la partida" << endl;

	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> Comprovacio dels moviments que s'han fet a la partida" << endl;
	cout << "Comment :=>> =====================================================" << endl;

	cout << "Comment :=>> Cartes esperades pel jugador 0: " << endl;
	cout << "Comment :=>> ";
	mostraCartesJugador(cartesInicials, 0);
	cout << endl;
	cout << "Comment :=>> Cartes esperades pel jugador 1: " << endl;
	cout << "Comment :=>> ";
	mostraCartesJugador(cartesInicials, 1);
	cout << endl;
	cout << "Comment :=>> Cartes esperades pel jugador 2: " << endl;
	cout << "Comment :=>> ";
	mostraCartesJugador(cartesInicials, 2);
	cout << endl;
	cout << "Comment :=>> Carta inicial del joc: ";
	mostraCarta(cartesInicials[nJugadors * 7]);
	cout << endl;


	cout << "Comment :=>> ----------------------------" << endl;
	cout << "Comment :=>> Comparacio de moviments esperats i obtinguts:" << endl;
	for (int i = 0; i < nMovimentsEsperat; i++)
	{
		cout << "Comment :=>> Esperat: ";
		mostraMoviment(movimentsEsperats[i]);
		cout << " --- Obtingut: ";
		mostraMoviment(moviments[i]);
		cout << endl;
	}
	
	float reduccio = comparaMoviments(movimentsEsperats, nMovimentsEsperat, moviments, nMoviments);

	return reduccio;
}


int main()
{
	cout << endl;
	cout << "Comment :=>> ==============" << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> ==============" << endl;
	
	float grade = 0.0;
	cout << "Grade :=>> " << grade << endl;

	float reduccio = testMoviments();
	grade += (10 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}