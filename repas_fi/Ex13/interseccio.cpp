#include "interseccio.h"

void interseccioVectorsOrdenats(int vector1[], int mida1, int vector2[], int mida2, int vectorInterseccio[], int& midaInterseccio)
{
	int i = 0; 
	int j = 0; 
	midaInterseccio = 0; 

	while ((i < mida1) && (j < mida2))
	{
		if (vector1[i] < vector2[j])
            i++;
		else
            if (vector2[j] < vector1[i])
                j++;
            else
            {
                vectorInterseccio[midaInterseccio] = vector1[i];
                i++;
                j++;
                midaInterseccio++;
            }
	}
}


bool cercaElement(int vector[], int mida, int valor)
{
    int i = 0;
    bool trobat = false;
    while ((!trobat) && (i < mida))
    {
        if (vector[i] == valor)
            trobat = true;
        else
            i++;
    }
    return trobat;
}


void eliminaElement(int vector[], int& mida, int index) 
{
    for (int i = index; i < (mida - 1); i++)
        vector[i] = vector[i+1];
    mida--;
}

void interseccioVectors(int vector1[], int& mida1,int vector2[], int mida2)
{
    int midaInicial = mida1;
    int indexActual = 0;
    for (int i = 0; i < midaInicial; i++)
    {
        if (cercaElement(vector2, mida2, vector1[indexActual]))
            indexActual++;
        else
            eliminaElement(vector1, mida1, indexActual);
    }
}
