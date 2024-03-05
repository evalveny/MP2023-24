#include <iostream>
#include <math.h>
#include "assignatura.h"

using namespace std;

void mostraBool(bool resultat)
{
	if (resultat)
		cout << "CERT";
	else
		cout << "FALS";
}


float testAfegeixNota(Assignatura& assignatura)
{
	float reduccio = 0.0;
	const int N_PROVES = 9;
	string niu[N_PROVES] = { "NIU_1", "NIU_2", "NIU_3", "NIU_5", "NIU_2", "NIU_2", "NIU_2", "NIU_2", "NIU_2" };
	float nota[N_PROVES] = { 5.0, 4.5, 6.5, 7.5, 5, 5.5, 7.0, 8.0, 6.0 };
	bool resultatEsperat[N_PROVES] = { true, true, true, false, true, true, true, true, false };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << "Comment :=>> Test del mètode afegeixNota " << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		bool resultat;

		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Niu estudiant: " << niu[i] << endl;
		cout << "Comment :=>> Nota introduida: " << nota[i] << endl;
		cout << "Comment :=>> ----------" << endl;

		resultat = assignatura.afegeixNota(niu[i], nota[i]);
		cout << "Comment :=>> Resultat esperat: ";
		mostraBool(resultatEsperat[i]);
		cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: ";
		mostraBool(resultat);
		cout << endl;
		cout << "Comment :=>> ----------" << endl;
		if (resultatEsperat[i] == resultat)
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 2;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	return reduccio;
}


float testCalculaNotaMitjana(Assignatura& assignatura)
{
	float reduccio = 0.0;
	const int N_PROVES = 4;
	string niu[N_PROVES] = { "NIU_1", "NIU_2", "NIU_4", "NIU_5"};
	float mitjanaEsperada[N_PROVES] = { 5.0, 6.0, -1.0, -1.0 };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << "Comment :=>> Test del mètode calculaNotaMitjana " << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		float resultat;

		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Niu estudiant: " << niu[i] << endl;
		cout << "Comment :=>> ----------" << endl;

		resultat = assignatura.calculaNotaMitjana(niu[i]);
		cout << "Comment :=>> Resultat esperat: " << mitjanaEsperada[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: " << resultat << endl;
		cout << "Comment :=>> ----------" << endl;
		if (fabs(mitjanaEsperada[i] - resultat) < 0.001)
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 2;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
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

	cout << "Comment :=>> Inicialitzem l'assignatura amb els estudiants següents...." << endl;
	cout << "Comment :=>> NIU_1, NOM_1" << endl;
	cout << "Comment :=>> NIU_2, NOM_2" << endl;
	cout << "Comment :=>> NIU_3, NOM_3" << endl;
	cout << "Comment :=>> NIU_4, NOM_4" << endl;
	cout << "Comment :=>> ----------------------------------" << endl;

	const int nEstudiants = 4;
	string estudiants[MAX_ESTUDIANTS][2] =
	{
		{"NIU_1", "NOM_1"},
		{"NIU_2", "NOM_2"},
		{"NIU_3", "NOM_3"},
		{"NIU_4", "NOM_4"}
	};
	Assignatura assignatura("ASSIG_1", nEstudiants, estudiants);

	float reduccio = testAfegeixNota(assignatura);
	grade = grade + (5 - reduccio);
	if (grade < 0)
		grade = 0.0;
	reduccio = testCalculaNotaMitjana(assignatura);
	grade = grade + (5 - reduccio);
	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}
