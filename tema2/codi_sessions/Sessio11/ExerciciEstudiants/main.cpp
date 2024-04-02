#include <iostream>
#include <math.h>
#include "array_estudiants.h"

using namespace std;


void mostraBool(bool resultat)
{
	if (resultat)
		cout << "CERT";
	else
		cout << "FALS";
}




float testAfegeixNota(Estudiant estudiants[], int& nEstudiants)
{
	float reduccio = 0.0;
	const int N_PROVES = 8;
	string niu[N_PROVES] = { "NIU_1", "NIU_2", "NIU_3", "NIU_5", "NIU_2", "NIU_2", "NIU_2", "NIU_2"};
	float nota[N_PROVES] = { 5.0, 4.0, 6.5, 7.5, 5, 6.0, 7.0, 8.0};
	bool resultatEsperat[N_PROVES] = { true, true, true, false, true, true, true, true};
	float notaMitjanaEsperada[N_PROVES] = { 5.0, 4.0, 6.5, -1, 4.5, 5.0, 5.5, 6.0 };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << "Comment :=>> Test de la funcio afegeixNota " << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		bool resultat;
		float notaMitjana;

		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Niu estudiant: " << niu[i] << endl;
		cout << "Comment :=>> Nota introduida: " << nota[i] << endl;
		cout << "Comment :=>> ----------" << endl;

		resultat = afegeixNota(estudiants, nEstudiants, niu[i], nota[i], &notaMitjana);
		cout << "Comment :=>> Resultat esperat: ";
		mostraBool(resultatEsperat[i]);
		cout << endl;
		if (resultatEsperat[i])
			cout << "Comment :=>> Nota mitjana esperada: " << notaMitjanaEsperada[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: ";
		mostraBool(resultat);
		cout << endl;
		if (resultat)
			cout << "Comment :=>> Nota mitjana obtinguda: " << notaMitjana << endl;;
		cout << "Comment :=>> ----------" << endl;
		if (resultatEsperat[i] == resultat)
			if (resultat)
				if (notaMitjanaEsperada[i] == notaMitjana)
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 2;
				}
			else
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

float testAfegeixNotaEstudiant()
{
	float reduccio = 0.0;
	const int N_PROVES = 2;
	float nota[N_PROVES] = { 4.0, 8.0 };
	float notaEsperada[N_PROVES] = { 4.0, 6.0 };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << "Comment :=>> Test de la funcio afegeixNotaEstudiant " << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << "Comment :=>> Inicialitzem un estudiant amb NIU_1 i NOM_1 ..." << endl;
	Estudiant e("NOM_1", "NIU_1");

	for (int i = 0; i < N_PROVES; i++)
	{
		bool resultat;
		float notaMitjana;

		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Nota afegida: " << nota[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		resultat = afegeixNotaEstudiant(&e, nota[i], &notaMitjana);
		cout << "Comment :=>> Nota mitjana esperada: " << notaEsperada[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Nota mitjana obtinguda: " << notaMitjana << endl;
		if (notaEsperada[i] == notaMitjana)
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


float testCercaEstudiant(Estudiant estudiants[], int& nEstudiants)
{
	float reduccio = 0.0;
	const int N_PROVES = 4;
	string niu[N_PROVES] = { "NIU_1", "NIU_2", "NIU_4", "NIU_5"};
	string nomEsperat[N_PROVES] = { "NOM_1", "NOM_2", "NOM_4", "" };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << "Comment :=>> Test de la funcio cercaEstudiant " << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		Estudiant* resultat;

		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Niu estudiant: " << niu[i] << endl;
		cout << "Comment :=>> ----------" << endl;

		resultat = cercaEstudiant(estudiants, nEstudiants, niu[i]);
		cout << "Comment :=>> Resultat esperat: ";
		if (nomEsperat[i] != "")
			cout << "Estudiant amb nom " << nomEsperat[i] << endl;
		else 
			cout << "Estudiant no existeix" << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: ";
		if (resultat != nullptr)
			cout << "Estudiant amb nom " << resultat->getNom() << endl;
		else
			cout << "Estudiant no existeix" << endl;
		cout << "Comment :=>> ----------" << endl;
		if (nomEsperat[i] != "")
			if (resultat != nullptr)
				if (resultat->getNom() == nomEsperat[i])
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 2;
				}
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 2;
			}
		else
			if (resultat == nullptr)
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


void inicialitzaTest(Estudiant estudiants[], int& nEstudiants)
{
	cout << "Comment :=>> Inicialitzem l'array d'estudiants...." << endl;
	cout << "Comment :=>> Afegim estudiant amb nom i niu: " << "NOM_1, NIU_1" << endl;
	estudiants[nEstudiants] = Estudiant("NOM_1", "NIU_1");
	nEstudiants++;
	cout << "Comment :=>> Afegim estudiant amb nom i niu: " << "NOM_2, NIU_2" << endl;
	estudiants[nEstudiants] = Estudiant("NOM_2", "NIU_2");
	nEstudiants++;
	cout << "Comment :=>> Afegim estudiant amb nom i niu: " << "NOM_3, NIU_3" << endl;
	estudiants[nEstudiants] = Estudiant("NOM_3", "NIU_3");
	nEstudiants++;
	cout << "Comment :=>> Afegim estudiant amb nom i niu: " << "NOM_4, NIU_4" << endl;
	estudiants[nEstudiants] = Estudiant("NOM_4", "NIU_4");
	nEstudiants++;
	cout << "Comment :=>> ----------------------------------" << endl;
}

int main()
{
	float grade = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;

	cout << "Grade :=>> " << grade << endl;

	Estudiant estudiants[MAX_ESTUDIANTS];
	int nEstudiants = 0;

	inicialitzaTest(estudiants, nEstudiants);

	float reduccio = testCercaEstudiant(estudiants, nEstudiants);
	grade = grade + (4 - reduccio);
	cout << "Grade :=>> " << grade << endl;
	reduccio = testAfegeixNotaEstudiant();
	grade = grade + (2 - reduccio);
	cout << "Grade :=>> " << grade << endl;
	reduccio = testAfegeixNota(estudiants, nEstudiants);
	grade = grade + (4 - reduccio);
	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}
