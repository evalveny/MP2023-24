#include "reserves.h"
#include <iostream>
#include <fstream>
using namespace std;

bool inicialitzaReserves(int& nAules, string codis[], int capacitat[])
{
	bool correcte = false;
	ifstream fitxerInicial;
	fitxerInicial.open("dades_inicials.txt");
	if (fitxerInicial.is_open())
	{
		cout << "Comment :=>> Dades inicials de les aules (codi aula, capacitat): " << endl;
		correcte = true;
		fitxerInicial >> nAules;
		for (int i = 0; i < nAules; i++)
		{
			fitxerInicial >> codis[i] >> capacitat[i];
			cout << "Comment :=>> (" << codis[i] << ", " << capacitat[i] << ")" << endl;
		}
		cout << "Comment :=>> ---------------------------------------------------------------------------------" << endl;
	}
	return correcte;
}

DiaSetmana charToDia(char dia)
{
	DiaSetmana diaSetmana;
	switch (dia)
	{
	case 'L':
		diaSetmana = DILLUNS;
		break;
	case 'M':
		diaSetmana = DIMARTS;
		break;
	case 'X':
		diaSetmana = DIMECRES;
		break;
	case 'J':
		diaSetmana = DIJOUS;
		break;
	case 'V':
		diaSetmana = DIVENDRES;
		break;
	}
	return diaSetmana;
}

string diaToString(DiaSetmana dia)
{
	string strDia;
	switch (dia)
	{
	case DILLUNS:
		strDia = "DILLUNS";
		break;
	case DIMARTS:
		strDia = "DIMARTS";
		break;
	case DIMECRES:
		strDia = "DIMECRES";
		break;
	case DIJOUS:
		strDia = "DIJOUS";
		break;
	case DIVENDRES:
		strDia = "DIVENDRES";
		break;
	}
	return strDia;
}

string boolToResultatReserva(bool resultat)
{
	string strResultat;
	if (resultat)
		strResultat = "RESERVA POSSIBLE";
	else
		strResultat = "RESERVA NO POSSIBLE";
	return strResultat;
}

string boolToResultatAnulacio(bool resultat)
{
	string strResultat;
	if (resultat)
		strResultat = "ANULACIO CORRECTA";
	else
		strResultat = "NO ES POT ANULAR LA RESERVA. L'AULA NO EXISTEIX";
	return strResultat;
}

float processaReserva(Reserves& r, ifstream& fitxerTest)
{
	float reduccio = 0.0;
	int capacitat, nDies;
	DiaActivitat dies[MAX_DIES_ACTIVITAT];
	char resultatChr;
	bool resultat;
	string codiAula = "";
	fitxerTest >> capacitat;
	fitxerTest >> nDies;
	for (int i = 0; i < nDies; i++)
	{
		char dia;
		fitxerTest >> dia >> dies[i].hora >> dies[i].durada;
		dies[i].dia = charToDia(dia);
	}
	fitxerTest >> resultatChr;
	resultat = (resultatChr == 'T');
	if (resultat)
		fitxerTest >> codiAula;
	cout << "Comment :=>> Accio: Reserva activitat" << endl;
	cout << "Comment :=>> Nombre d'assistents: " << capacitat << endl;
	cout << "Comment :=>> Dies de l'activitat (dia, hora inicial i durada): " << endl;
	for (int i = 0; i < nDies; i++)
		cout << "Comment :=>> (" << diaToString(dies[i].dia) << "," << dies[i].hora << ", " << dies[i].durada << ")" << endl;
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Resultat esperat: " << boolToResultatReserva(resultat) << endl;
	if (resultat)
		cout << "Comment :=>> Aula reservada esperada: " << codiAula << endl;
	cout << "Comment :=>> ----------" << endl;

	string aulaReservada = r.reservaActivitat(capacitat, dies, nDies);

	bool resultatObtingut = (aulaReservada != "");
	cout << "Comment :=>> Resultat obtingut: " << boolToResultatReserva(resultatObtingut) << endl;
	if (resultatObtingut)
		cout << "Comment :=>> Aula reservada obtinguda: " << aulaReservada << endl;
	if ((resultat != resultatObtingut) || (aulaReservada != codiAula))
	{
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 2.0;
	}
	else
	{
		if (resultatObtingut)
		{
			cout << "Comment :=>> Comprovant que l'aula hagi quedat correctament reservada per totes les hores de l'activitat..." << endl;
			bool reservada = true;
			int i = 0;
			while (reservada && (i < nDies))
			{
				int j = 0;
				while (reservada && (j < dies[i].durada))
				{
					if (r.comprovaAulaDisponible(aulaReservada, dies[i].dia, dies[i].hora + j))
						reservada = false;
					else
						j++;
				}
				i++;
			}
			if (!reservada)
			{
				cout << "Comment :=>> ----------" << endl;
				cout << "Comment :=>> ERROR. Aula no reservada per algun dels dies/hores de l'activitat" << endl;
				reduccio += 2.0;
			}
			else
			{
				cout << "Comment :=>> ----------" << endl;
				cout << "Comment :=>> Aula correctament reservada per tots els dies/hores de l'activitat" << endl;
				cout << "Comment :=>> CORRECTE" << endl;
			}
		}
		else
		{
			cout << "Comment :=>> ----------" << endl;
			cout << "Comment :=>> CORRECTE" << endl;
		}
	}
	return reduccio;
}

float processaAnulacio(Reserves& r, ifstream& fitxerTest)
{
	float reduccio = 0.0;
	int nDies;
	DiaActivitat dies[MAX_DIES_ACTIVITAT];
	char resultatChr;
	bool resultat;
	string codiAula = "";
	fitxerTest >> codiAula;
	fitxerTest >> nDies;
	for (int i = 0; i < nDies; i++)
	{
		char dia;
		fitxerTest >> dia >> dies[i].hora >> dies[i].durada;
		dies[i].dia = charToDia(dia);
	}
	fitxerTest >> resultatChr;
	resultat = (resultatChr == 'T');
	cout << "Comment :=>> Accio: Anulacio activitat" << endl;
	cout << "Comment :=>> Codi Aula: " << codiAula << endl;
	cout << "Comment :=>> Dies de l'activitat anulada (dia, hora inicial i durada): " << endl;
	for (int i = 0; i < nDies; i++)
		cout << "Comment :=>> (" << diaToString(dies[i].dia) << "," << dies[i].hora << ", " << dies[i].durada << ")" << endl;
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Resultat esperat: " << boolToResultatAnulacio(resultat) << endl;
	cout << "Comment :=>> ----------" << endl;

	bool resultatObtingut = r.anulaActivitat(codiAula, dies, nDies);

	cout << "Comment :=>> Resultat obtingut: " << boolToResultatAnulacio(resultatObtingut) << endl;
	if (resultat != resultatObtingut)
	{
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 2.0;
	}
	else
	{
		if (resultat)
		{
			cout << "Comment :=>> Comprovant que l'aula hagi quedat correctament alliberada per totes les hores de l'activitat..." << endl;
			bool reservada = false;
			int i = 0;
			while (!reservada && (i < nDies))
			{
				int j = 0;
				while (!reservada && (j < dies[i].durada))
				{
					if (!r.comprovaAulaDisponible(codiAula, dies[i].dia, dies[i].hora + j))
						reservada = true;
					else
						j++;
				}
				i++;
			}
			if (reservada)
			{
				cout << "Comment :=>> ----------" << endl;
				cout << "Comment :=>> ERROR. Aula encara reservada per algun dels dies/hores de l'activitat" << endl;
				reduccio += 2.0;
			}
			else
			{
				cout << "Comment :=>> ----------" << endl;
				cout << "Comment :=>> Aula correctament alliberada per tots els dies/hores de l'activitat" << endl;
				cout << "Comment :=>> CORRECTE" << endl;
			}
		}
		else
		{
			cout << "Comment :=>> ----------" << endl;
			cout << "Comment :=>> CORRECTE" << endl;
		}
	}
	return reduccio;
}

float processaAccio(Reserves& r, ifstream& fitxerTest)
{
	float reduccio = 0.0;
	char tipusAccio;
	fitxerTest >> tipusAccio;
	if (tipusAccio == 'R')
		reduccio = processaReserva(r, fitxerTest);
	else
		reduccio = processaAnulacio(r, fitxerTest);
	return reduccio;
}

bool processaReserves(Reserves& r, float& reduccio)
{
	bool correcte = false;
	reduccio = 0.0;
	ifstream fitxerTest;
	fitxerTest.open("test.txt");
	if (fitxerTest.is_open())
	{
		correcte = true;
		int nProves;
		fitxerTest >> nProves;
		for (int i = 0; i < nProves; i++)
		{
			cout << "Comment :=>> TEST " << i + 1 << endl;
			cout << "Comment :=>> -------" << endl;
			reduccio += processaAccio(r, fitxerTest);
			cout << "Comment :=>> ---------------------------------------------------------------------------------" << endl;
		}
	}
	return correcte;
}

float testReserves()
{
	float reduccio = 0.0;
	string codiAules[MAX_AULES];
	int capacitatAules[MAX_AULES];
	int nAules = 0;
	bool correcte = inicialitzaReserves(nAules, codiAules, capacitatAules);
	if (!correcte)
	{
		cout << "Comment :=>> No es pot llegir el fitxer de test" << endl;
		cout << "Comment :=>>" << endl;
		reduccio = 10.0;
	}
	else
	{
		Reserves r(nAules, codiAules, capacitatAules);
		correcte = processaReserves(r, reduccio);
		if (!correcte)
		{
			cout << "Comment :=>> No es pot llegir el fitxer de test" << endl;
			cout << "Comment :=>>" << endl;
			reduccio = 10.0;
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
	cout << "Comment :=>> Totes les accions depenen del funcionament correcte de les accions anteriors" << endl;
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> ---------------------------------------------------------------------------------" << endl;

	cout << "Grade :=>> " << grade << endl;

	float reduccio = testReserves();
	grade = grade + (10 - reduccio);
	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}