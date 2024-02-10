#include "Unir.h"

void uneixVectorsOrdenats(int vector1[], int mida1, int vector2[], int mida2, int vectorUnio[], int& midaUnio)
{
	int i = 0; // index llista 1
	int j = 0; // index llista 2
	midaUnio = 0; // index llista unió

	while (i < mida1 && j < mida2)
	{
		if (vector1[i] < vector2[j])
		{
			vectorUnio[midaUnio] = vector1[i];
			i++;
            midaUnio++;
		}
		else
            if (vector2[j] < vector1[i])
		    {
			    vectorUnio[midaUnio] = vector2[j];
			    j++;
                midaUnio++;
		    }
            else
            {
                vectorUnio[midaUnio] = vector1[i];
                i++;
                j++;
                midaUnio++;
            }
	}

	for (int x = i; x < mida1; x++)
	{
		vectorUnio[midaUnio] = vector1[x];
        midaUnio++;
	}

	for (int x = j; x < mida2; x++)
	{
		vectorUnio[midaUnio] = vector2[x];
        midaUnio++;
	}
}

bool cercaElement(int vector[], int mida, int valor) 
{
    int i = 0;
    bool trobat = false;
    while (i < mida && !trobat)
    {
        if (vector[i] == valor)
            trobat = true;
        else
            i++;
    }
    return trobat;
}

int cercaPosicio(int vector[], int mida, int valor)
{
    int i = 0;
    bool trobat = false;
    while (i < mida && !trobat)
    {
        if (vector[i] > valor)
            trobat = true;
        else
            i++;
    }
    return i;
}

void afegeixOrdenadament(int vector[], int& mida, int valor)
{
    int posicio = cercaPosicio(vector, mida, valor);
    for (int i = mida; i >= posicio + 1; i--)
        vector[i] = vector[i - 1];
    vector[posicio] = valor;
    mida++;
}

void uneixVectors(int vector1[], int mida1, int vector2[], int mida2, int vectorUnio[], int& midaUnio)
{
    midaUnio = 0;
    // copiem el vector ordenat (vector1) al vector d'unió (vectorUnio)
    for (int i = 0; i < mida1; i++)
    {
        afegeixOrdenadament(vectorUnio, midaUnio, vector1[i]);
    }
    midaUnio = mida1;

    // afegir al vector d'unió cada valor del vector 2
    for (int j = 0; j < mida2; j++)
    {
        if (!cercaElement(vectorUnio, midaUnio, vector2[j]))
            afegeixOrdenadament(vectorUnio, midaUnio, vector2[j]);
    }
}
