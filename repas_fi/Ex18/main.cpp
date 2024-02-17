#include <fstream>
#include <iostream>
#include <string.h>
#include "paraulogic.h"

using namespace std;

char diccionari[N_PARAULES][MAX_PARAULA];


void mostraBool(bool resultat)
{
	if (resultat)
		cout << "VALIDA";
	else
		cout << "NO VALIDA";
}

void mostraTutti(bool resultat)
{
	if (resultat)
		cout << "TUTTI";
	else
		cout << "NO TUTTI";
}




bool llegeixDiccionari()
{
	bool correcte = false;
	const string nomFitxerDiccionari = "diccionari_catala_reduit.txt";
	ifstream fitxer;
	fitxer.open(nomFitxerDiccionari);
	if (fitxer.is_open())
	{
		correcte = true;
		char paraula[MAX_PARAULA];
		int i = 0;
		fitxer >> paraula;
		while (!fitxer.eof())
		{
			strcpy_s(diccionari[i], paraula);
			i++;
			fitxer >> paraula;
		}
	}
	return correcte;
}

float testIntrodueixParaula()
{
	float reduccio = 0.0;
	const int N_PROVES = 9;
	char lletres[N_LLETRES + 1] = {'b', 'a', 'i', 'x', 'd', 'o', 'r', '\0'};
	char paraules[N_PROVES][MAX_PARAULA] =
	{
		"abaixat",
		"dia",
		"baixadora",
		"bo",
		"bar",
		"baix",
		"barri",
		"baixada",
		"abaixador"
	};
	bool resultatEsperat[N_PROVES] = { false, false, false, true, true, true, true, true, true };
	bool tuttiEsperat[N_PROVES] = { false, false, false, false, false, false, false, false, true };
	int puntuacioEsperada[N_PROVES] = { 0, 0, 0, 0, 1, 2, 5, 7, 18 };
	
	if (!llegeixDiccionari())
	{
		cout << "Comment :=>> ERROR. No es pot llegir el fitxer amb el diccionari" << endl;
		reduccio = 10.0;
	}
	else
	{
		for (int i = 0; i < N_PROVES; i++)
		{
			bool resultat, tutti;
			int puntuacio;

			cout << "Comment :=>>" << endl;
			cout << "Comment :=>> -----------------------------------------------" << endl;
			cout << "Comment :=>> TEST " << i + 1 << endl;
			cout << "Comment :=>> -----------------------------------------------" << endl;

			cout << "Comment :=>> Lletres disponibles: " << lletres << endl;
			cout << "Comment :=>> Paraula introduida: " << paraules[i] << endl;
			cout << "Comment :=>> ----------" << endl;

			resultat = introdueixParaula(paraules[i], lletres, diccionari, tutti, puntuacio);
			cout << "Comment :=>> Resultat esperat: ";
			mostraBool(resultatEsperat[i]);
			cout << endl;
			cout << "Comment :=>> Tutti esperat: ";
			mostraTutti(tuttiEsperat[i]);
			cout << endl;
			cout << "Comment :=>> Puntuacio esperada: " << puntuacioEsperada[i] << endl;
			cout << "Comment :=>> ----------" << endl;
			cout << "Comment :=>> Resultat obtingut: ";
			mostraBool(resultat);
			cout << endl;
			cout << "Comment :=>> Tutti obtingut: ";
			mostraTutti(tutti);
			cout << endl;
			cout << "Comment :=>> Puntuacio obtinguda: " << puntuacio << endl;
			cout << "Comment :=>> ----------" << endl;
			if ((resultatEsperat[i] == resultat) && (tuttiEsperat[i] == tutti) && (puntuacioEsperada[i] == puntuacio))
				cout << "Comment :=>> CORRECTE" << endl;
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 2;
			}
			cout << "Comment :=>> -----------------------------------------------" << endl;

		}

	}

	return reduccio;
}


int main()
{
	float grade = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;

	cout << "Grade :=>> " << grade << endl;
	float reduccio = testIntrodueixParaula();
	grade = grade + (10 - reduccio);
	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}

