#include <stdio.h>
#include <iostream>
#include "interseccio.h"

using namespace std;

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

bool comparaVector(int v1[], int longitud1, int v2[], int longitud2)
{
	bool iguals = (longitud1 == longitud2);
	int i = 0;
	while ((iguals) && (i < longitud1))
	{
		if (v1[i] != v2[i])
			iguals = false;
		i++;
	}
	return iguals;
}

float testInterseccioOrdenats()
{
	float reduccio = 0.0;

	const int N_PROVES = 5;
	const int MAX_ELEMENTS = 10;

	int vector1[N_PROVES][MAX_ELEMENTS] = { { 1, 3, 5, 6, 9 },{ 1, 2, 3, 4, 5 },{ 6, 7, 8, 9 },{ 2, 4, 6, 8 },{1, 3, 5, 7, 9} };
	int vector2[N_PROVES][MAX_ELEMENTS] = { { 2, 4, 6, 7, 8, 13 },{ 3, 4, 5, 6, 7, 8, 9 },{ 3, 5, 6, 7, 8, 9 },{ 2, 4, 6, 8, 10, 12 },{2, 4, 6, 8, 10} };
	int vectorInterseccioEsperat[N_PROVES][MAX_ELEMENTS] = {
		{ 6 },
		{ 3, 4, 5 },
		{ 6, 7, 8, 9 },
		{ 2, 4, 6, 8 },
		{  } };
	int midaVector1[N_PROVES] = { 5, 5, 4, 4, 5 };
	int midaVector2[N_PROVES] = { 6, 7, 6, 6, 5 };
	int midaVectorInterseccioEsperat[N_PROVES] = { 1, 3, 4, 4, 0 };
	int vectorInterseccio[MAX_ELEMENTS];
	int midaVectorInterseccio = 0;


	cout << endl << endl;
	cout << "Comment :=>> Iniciant test Interseccio Vectors Ordenats" << endl;
	cout << "Comment :=>> ==========================================" << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Vector1: ";
		mostraArray(vector1[i], midaVector1[i]);
		cout << endl;
		cout << "Comment :=>> Vector2: ";
		mostraArray(vector2[i], midaVector2[i]);
		cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat:";
		mostraArray(vectorInterseccioEsperat[i], midaVectorInterseccioEsperat[i]);
		cout << endl;
		interseccioVectorsOrdenats(vector1[i], midaVector1[i], vector2[i], midaVector2[i], vectorInterseccio, midaVectorInterseccio);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut:";
		mostraArray(vectorInterseccio, midaVectorInterseccio);
		cout << endl;
		if (comparaVector(vectorInterseccio, midaVectorInterseccio, vectorInterseccioEsperat[i], midaVectorInterseccioEsperat[i]))
		{
			cout << "Comment :=>> CORRECTE" << endl;
		}
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 2;
		}	
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	return reduccio;
}

float testInterseccio()
{
	float reduccio = 0.0;

	const int N_PROVES = 5;
	const int MAX_ELEMENTS = 10;

	int vector1[N_PROVES][MAX_ELEMENTS] = { { 1, 6, 5, 3, 9 },{ 5, 2, 1, 4, 3 },{ 6, 7, 8, 9 },{ 2, 4, 6, 8, 10, 12 },{1, 3, 5, 7, 9} };
	int vector2[N_PROVES][MAX_ELEMENTS] = { { 4, 2, 8, 7, 6, 13 },{ 9, 8, 7, 6, 5, 4, 3 },{ 9, 8, 7, 6, 5, 3 },{ 6, 8, 10, 12 },{2, 4, 6, 8, 10} };
	int vector1Esperat[N_PROVES][MAX_ELEMENTS] = {
		{ 6 },
		{ 5, 4, 3 },
		{ 6, 7, 8, 9 },
		{ 6, 8, 10, 12 },
		{  } };
	int midaVector1[N_PROVES] = { 5, 5, 4, 6, 5 };
	int midaVector2[N_PROVES] = { 6, 7, 6, 4, 5 };
	int midaVector1Esperat[N_PROVES] = { 1, 3, 4, 4, 0 };
	

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test Interseccio Vectors No Ordenats" << endl;
	cout << "Comment :=>> =============================================" << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Vector1: ";
		mostraArray(vector1[i], midaVector1[i]);
		cout << endl;
		cout << "Comment :=>> Vector2: ";
		mostraArray(vector2[i], midaVector2[i]);
		cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat:";
		mostraArray(vector1Esperat[i], midaVector1Esperat[i]);
		cout << endl;
		interseccioVectors(vector1[i], midaVector1[i], vector2[i], midaVector2[i]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut:";
		mostraArray(vector1[i], midaVector1[i]);
		cout << endl;
		if (comparaVector(vector1[i], midaVector1[i], vector1Esperat[i], midaVector1Esperat[i]))
		{
			cout << "Comment :=>> CORRECTE" << endl;
		}
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
	float reduccio = testInterseccio();
	if (reduccio > 6.0)
		reduccio = 6.0;
	grade = grade + (5 - reduccio);
	cout << "Grade :=>> " << grade << endl;
	reduccio = testInterseccioOrdenats();
	if (reduccio > 6.0)
		reduccio = 6.0;
	grade = grade + (5 - reduccio);
	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}