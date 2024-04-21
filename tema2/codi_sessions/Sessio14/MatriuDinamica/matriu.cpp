#include "matriu.h"
#include <fstream>
using namespace std;

int** creaMatriu(int nFiles, int nColumnes)
{
	int** m;

	m = new int* [nFiles];
	for (int i = 0; i < nFiles; i++)
		m[i] = new int[nColumnes];
	return m;
}

void destrueixMatriu(int** m, int nFiles)
{
	for (int i = 0; i < nFiles; i++)
		delete[] m[i];
	delete[] m;
}

void llegeixMatriu(int** m, int nFiles, int nColumnes, const string& nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{ 
		for (int i = 0; i < nFiles; i++)
			for (int j = 0; j < nColumnes; j++)
			{
				fitxer >> m[i][j];
			}
		fitxer.close();
	}
}

void sumaMatrius(int** m1, int** m2, int** suma, int nFiles, int nColumnes)
{
	for (int i = 0; i < nFiles; i++)
		for (int j = 0; j < nColumnes; j++)
			suma[i][j] = m1[i][j] + m2[i][j];
}
