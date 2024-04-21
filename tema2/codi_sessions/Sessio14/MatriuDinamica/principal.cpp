#include "matriu.h"
#include <iostream>
using namespace std;

#include <signal.h>
typedef void(*SignalHandlerPointer)(int);
void SignalHandler(int signal)
{
	if (signal == SIGSEGV) {
		throw "Segmentation fault";
	}
	else {
		throw "Other Error";
	}
}
SignalHandlerPointer previousHandler;

void mostraMatriuEstatica(int matriu[][4], int nFiles, int nColumnes)
{
	for (int i = 0; i < nFiles; i++)
	{
		cout << "Comment :=>>";
		for (int j = 0; j < nColumnes; j++)
			cout << matriu[i][j] << " ";
		cout << "\n";
	}
}


void mostraMatriuDinamica(int** matriu, int nFiles, int nColumnes)
{
	for (int i = 0; i < nFiles; i++)
	{
		cout << "Comment :=>>";
		for (int j = 0; j < nColumnes; j++)
			cout << matriu[i][j] << " ";
		cout << "\n";
	}
}

bool igualMatrius(int resultat[][4], int** matriu, int nFiles, int nColumnes)
{
	bool iguals = true;
	int i = 0;
	while (iguals && (i < nFiles))
	{
		int j = 0;
		while (iguals && (j < nColumnes))
		{
			if (resultat[i][j] != matriu[i][j])
				iguals = false;
			else
				j++;
		}
		i++;
	}
	return iguals;
}

int main()
{
	int **m1, **m2, **suma;
	const int nFiles = 5;
	const int nColumnes = 4;

	int matriu1[nFiles][nColumnes] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
		{17, 18, 19, 20}
	};

	int matriu2[nFiles][nColumnes] =
	{
		{1, 1, 1, 1},
		{2, 2, 2, 2},
		{3, 3, 3, 3},
		{4, 4, 4, 4},
		{5, 5, 5, 5}
	};

	int matriuResultat[nFiles][nColumnes] =
	{
		{2, 3, 4, 5},
		{7, 8, 9, 10},
		{12, 13, 14, 15},
		{17, 18, 19, 20},
		{22, 23, 24, 25}
	};


	float grade = 0.0;
	cout << "Grade :=>> " << grade << endl;

	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;

	cout << "Comment :=>> Creant les matrius amb 5 files i 4 columnes..." << endl;

	m1 = creaMatriu(nFiles, nColumnes);
	m2 = creaMatriu(nFiles, nColumnes);
	suma = creaMatriu(nFiles, nColumnes);
	
	cout << "Comment :=>> Llegint matriu m1 amb valors..." << endl;
	mostraMatriuEstatica(matriu1, nFiles, nColumnes);
	llegeixMatriu(m1, nFiles, nColumnes, "matriu1.txt");
	cout << "Comment :=>> Llegint matriu m1 amb valors..." << endl;
	mostraMatriuEstatica(matriu2, nFiles, nColumnes);
	llegeixMatriu(m2, nFiles, nColumnes, "matriu2.txt");

	cout << "Comment :=>> Calculant la suma de m1 + m2..." << endl;
	sumaMatrius(m1, m2, suma, nFiles, nColumnes);
	cout << "Comment :=>> ----------------------------" << endl;
	cout << "Comment :=>> Resultat esperat: " << endl;
	mostraMatriuEstatica(matriuResultat, nFiles, nColumnes);
	cout << "Comment :=>> ------------" << endl;
	cout << "Comment :=>> Resultat obtingut: " << endl;
	mostraMatriuDinamica(suma, nFiles, nColumnes);

	if (igualMatrius(matriuResultat, suma, nFiles, nColumnes))
	{
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 8;
	}	
	else
	{
		cout << "Comment :=>> ERROR" << endl;
	}
	cout << "Comment :=>> -----------------------------------------" << endl;
	cout << "Grade :=>> " << grade << endl;
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> Alliberant totes les matrius..." << endl;


	destrueixMatriu(m1, nFiles);
	destrueixMatriu(m2, nFiles);
	destrueixMatriu(suma, nFiles);

	grade += 2;
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> -----------------------------------------" << endl;
	cout << "Comment :=>> " << endl;

	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;

}
