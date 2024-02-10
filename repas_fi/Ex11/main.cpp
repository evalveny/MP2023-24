#include <iostream>
using namespace std;

#include<math.h>
#include "notes.hpp"

template<typename T>
void mostraArray(T v[], int longitud)
{
	cout << "[";
	for (int i = 0; i < longitud - 1; i++)
		cout << v[i] << ", ";
	if (longitud > 0)
		cout << v[longitud - 1];
	cout << "]";
}

template<typename T>
bool igualsArray(T v1[], T v2[], int longitud)
{
	bool iguals = true;
	int i = 0;
	while (iguals && (i < longitud))
	{
		if (v1[i] != v2[i])
			iguals = false;
		else
			i++;
	}
	return iguals;
}

float testCalculNotes()
{
	const int N_PROVES = 2;
	const int MAX_ESTUDIANTS = 10;
	float notaNumerica[N_PROVES][MAX_ESTUDIANTS] = 
	{
		{ 2.8, 5, 7.2, 9.1, 10, -1, 7.0, -1, 7.9, -1 },
		{ -1, -1, -1}
	};
	char notaActaEsperada[N_PROVES][MAX_ESTUDIANTS] = 
	{
		{ 'S', 'A', 'N', 'E', 'M', 'P', 'N', 'P', 'N', 'P' },
		{ 'P', 'P', 'P'}
	};
	int nEstudiants[N_PROVES] = {10, 3};
	float notaMinimaEsperada[N_PROVES] = {2.8, -1};
	float notaMaximaEsperada[N_PROVES] = {10, -1};
	float notaMitjaEsperada[N_PROVES] = {7.0, -1};

	char notesActa[MAX_ESTUDIANTS];
	float reduccio = 0.0;
	float notaMinima, notaMaxima, notaMitja;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Notes numeriques: ";
		mostraArray(notaNumerica[i], nEstudiants[i]);
		cout << endl;
		cout << "Comment :=>> ----------" << endl;		
		converteixNotes(notaNumerica[i], nEstudiants[i], notesActa, notaMinima, notaMaxima, notaMitja);
		cout << "Comment :=>> Notes acta esperades: ";
		mostraArray(notaActaEsperada[i], nEstudiants[i]);
		cout << endl;
		cout << "Comment :=>> Nota minima esperada: " << notaMinimaEsperada[i] << endl;
		cout << "Comment :=>> Nota maxima esperada: " << notaMaximaEsperada[i] << endl;
		cout << "Comment :=>> Nota mitja esperada: " << notaMitjaEsperada[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Notes acta obtingudes: ";
		mostraArray(notesActa, nEstudiants[i]);
		cout << endl;
		cout << "Comment :=>> Nota minima obtinguda: " << notaMinima << endl;
		cout << "Comment :=>> Nota maxima obtinguda: " << notaMaxima << endl;
		cout << "Comment :=>> Nota mitja obtinguda: " << notaMitja << endl;
		cout << "Comment :=>> ----------" << endl;
		if ((notaMinimaEsperada[i] == notaMinima) && (notaMaximaEsperada[i] == notaMaxima) &&
			(fabs(notaMitjaEsperada[i] - notaMitja) < 0.001) && (igualsArray(notaActaEsperada[i], notesActa, nEstudiants[i])))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			if (notaMinimaEsperada[i] != notaMinima)
				reduccio += 2;
			if (notaMaximaEsperada[i] != notaMaxima)
				reduccio += 2;
			if (fabs(notaMitjaEsperada[i] - notaMitja) >= 0.001)
				reduccio += 2;
			if (!igualsArray(notaActaEsperada[i], notesActa, nEstudiants[i]))
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
	float reduccio = testCalculNotes();
	grade = grade + (10 - reduccio);
	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}