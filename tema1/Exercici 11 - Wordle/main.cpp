#include "wordle.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}

void mostraEstat(EstatPartida estat)
{
	switch (estat)
	{
	case ACTIVA:
		cout << "PARTIDA ACTIVA";
		break;
	case FINAL_GUANYAT:
		cout << "PARTIDA ACABADA I GUANYADA";
		break;
	case FINAL_PERDUT:
		cout << "PARTIDA ACABADA I PERDUDA";
		break;
	}
}

void descodificaJugada(string jugada, string& paraula, string& resultat)
{
	istringstream sString(jugada);
	char separador;
	char charParaula, charResultat;
	for (int i = 0; i < 5; i++)
	{
		sString >> separador >> charParaula >> separador >> charResultat >> separador;
		paraula = paraula + charParaula;
		resultat = resultat + charResultat;
	}
}

float testPartida()
{
	float reduccio = 0;

	const int N_PROVES = 3;
	const int MAX_INTENTS = 6;
	string paraulaInicial[N_PROVES] = { "ARBRE", "JUGAR", "AIGUA" };
	string lletresParaula[N_PROVES][MAX_INTENTS] =
	{
		{"TAULA", "PORTA", "PARET", "CAURE", "ARBRE"},
		{"COTXE", "PISTA", "LLUNA", "MURAL", "JUGAR"},
		{"PILOT", "COTXE", "CALMA", "TERRA", "LLUNA", "GESPA"}
	};
	string resultatParaula[N_PROVES][MAX_INTENTS] =
	{
		{"NINNI", "NNINI", "NIIIN", "NINCC", "CCCCC"},
		{"NNNNN", "NNNNI", "NNINI", "NCICN", "CCCCC"},
		{"NCNNN", "NNNNN", "NINNC", "NNNNC", "NNINC", "INNNC"}
	};
	string resultatABC[N_PROVES] =
	{
		{"CCN_C______N__NN_C_NN_____"},
		{"C_N_N_C_NC_NNNNN_CNNC__N__"},
		{"C_N_N_I_C__NNNNN_NNNI__N__"}
	};
	const int nIntents[N_PROVES] = { 5, 5, 6 };
	EstatPartida resultatIntent[N_PROVES][MAX_INTENTS] =
	{
		{ACTIVA, ACTIVA, ACTIVA, ACTIVA, FINAL_GUANYAT},
		{ACTIVA, ACTIVA, ACTIVA, ACTIVA, FINAL_GUANYAT},
		{ACTIVA, ACTIVA, ACTIVA, ACTIVA, ACTIVA, FINAL_PERDUT}
	};

	Wordle wordle;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Inicialitzant partida amb paraula : " << paraulaInicial[i] << endl;
		cout << "Comment :=>> " << endl;		
		cout << "Comment :=>> ------------------------------------------" << endl;
		wordle.inicialitza(paraulaInicial[i]);
		for (int j = 0; j < nIntents[i]; j++)
		{
			cout << "Comment :=>> Intent: " << j + 1 << endl;
			cout << "Comment :=>> Paraula Introduida: " << lletresParaula[i][j] << endl;
			EstatPartida resultat = wordle.juga(lletresParaula[i][j]);
			cout << "Comment :=>> Resultat esperat de la crida al metode juga: ";
			mostraEstat(resultatIntent[i][j]);
			cout << endl;
			cout << "Comment :=>> ------" << endl;
			cout << "Comment :=>> Resultat obtingut de la crida al metode juga: ";
			mostraEstat(resultat);
			cout << endl;
			cout << "Comment :=>> ------" << endl;
			if (resultatIntent[i][j] == resultat)
				cout << "Comment :=>> CORRECTE" << endl;
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 1.0;
			}
			cout << "Comment :=>> ------------------" << endl;
		}
		cout << "Comment :=>> " << endl;
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> Escrivint resultat de la partida a un fitxer..." << endl;
		cout << "Comment :=>> " << endl;
		const string nomFitxer = "resultat.txt";
		wordle.escriuPartida(nomFitxer);
		cout << "Comment :=>> Comprovant resultat de la partida..." << endl;
		cout << "Comment :=>> ------------------------------------------" << endl;
		ifstream fitxer;
		fitxer.open(nomFitxer);
		if (fitxer.is_open())
		{
			string paraula, resultat;
			for (int j = 0; j < nIntents[i]; j++)
			{
				string jugada, paraula, resultat;
				getline(fitxer, jugada);
				descodificaJugada(jugada, paraula, resultat);
				cout << "Comment :=>> Intent: " << j + 1 << endl;
				cout << "Comment :=>> Paraula Introduida: " << lletresParaula[i][j] << endl;
				cout << "Comment :=>> Resultat esperat: " << resultatParaula[i][j] << endl;
				cout << "Comment :=>> ------" << endl;
				cout << "Comment :=>> Paraula llegida del fitxer: " << paraula << endl;
				cout << "Comment :=>> Resultat llegit del fitxer: " << resultat << endl;
				if ((resultatParaula[i][j] == resultat) && 
					(lletresParaula[i][j] == paraula))
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 1.0;
				}
				cout << "Comment :=>> ------------------" << endl;
			}
			cout << "Comment :=>> Estat final de l'abecedari esperat: " << endl;
			string abecedariEsperat;
			for (char c = 'A', j = 0; c <= 'Z'; c++, j++)
				abecedariEsperat = abecedariEsperat + "(" + c + "," + resultatABC[i][j] + ")";
			cout << "Comment :=>> " << abecedariEsperat << endl;
			cout << "Comment :=>> ------" << endl;
			cout << "Comment :=>> Estat final de l'abecedari llegit del fitxer: " << endl;
			string abecedari;
			fitxer >> abecedari;
			cout << "Comment :=>> " << abecedari << endl;
			if (abecedari == abecedariEsperat)
				cout << "Comment :=>> CORRECTE" << endl;
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 1.0;
			}
			cout << "Comment :=>> ------------------" << endl;
			cout << "Comment :=>> " << endl;
		}
		else
		{
			cout << "Comment :=>> ERROR. No es pot obrir el fitxer amb el resultat de la partida" << endl;
			reduccio += 6.0;
		}


	}
	return reduccio;
}

int main()
{
	
	float grade = 0.0;

	cout << endl << "Grade :=>> " << grade << endl << endl;
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> Iniciant test" << endl;
	cout << "Comment :=>> =============" << endl;

	float reduccio = testPartida();
	if (reduccio > 10.0)
		reduccio = 10.0;
	grade += (10.0 - reduccio);
	cout << endl << "Grade :=>> " << grade << endl << endl;

	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;


	return 0;
}