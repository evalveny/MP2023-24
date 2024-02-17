#include <string.h>
#include "paraulogic.h"

bool comprovaTutti(bool lletres[N_LLETRES])
{
	int i = 0;
	bool tutti = true;
	while (tutti && (i < N_LLETRES))
	{
		if (lletres[i] == false)
			tutti = false;
		else
			i++;
	}
	return tutti;
}

int lletraValida(char lletra, char lletres[N_LLETRES])
{
	int i = 0;
	bool trobat = false;
	int posLletra = -1;
	while (!trobat && (i < N_LLETRES))
	{
		if (lletres[i] == lletra)
		{
			trobat = true;
			posLletra = i;
		}
		else
			i++;
	}
	return posLletra;
}


bool comprovaLletres(char paraula[MAX_PARAULA], char lletres[N_LLETRES], bool& tutti)
{
	bool correcte = true;
	bool existeixLletra[N_LLETRES];
	for (int i = 0; i < N_LLETRES; i++)
		existeixLletra[i] = false;
	int i = 0;
	bool finalParaula = false;
	while (correcte && (i < MAX_PARAULA) && !finalParaula)
	{
		if (paraula[i] == '\0')
			finalParaula = true;
		else
		{
			int posLletra = lletraValida(paraula[i], lletres);
			if (posLletra != -1)
			{
				existeixLletra[posLletra] = true;
				i++;
			}
			else
				correcte = false;
		}
	}
	correcte = correcte && (existeixLletra[0] == true);
	if (correcte)
		tutti = comprovaTutti(existeixLletra);
	else
		tutti = false;
	return correcte;
}

bool comprovaDiccionari(char paraula[MAX_PARAULA], char diccionari[N_PARAULES][MAX_PARAULA])
{
	int i = 0;
	bool trobat = false;
	while (!trobat && (i < N_PARAULES))
	{
		if (strcmp(paraula, diccionari[i]) == 0)
		{
			trobat = true;
		}
		else
			i++;
	}
	return trobat;
}


int calculaPuntuacio(char paraula[MAX_PARAULA], bool tutti)
{
	int puntuacio = 0;
	int longitud = strlen(paraula);
	if (longitud >= 3)
	{
		switch (longitud)
		{
		case 3: puntuacio = 1;
			break;
		case 4:
			puntuacio = 2;
			break;
		default:
			puntuacio = longitud;
			break;
		}
		if (tutti)
			puntuacio *= 2;
	}
	return puntuacio;
}

bool introdueixParaula(char paraula[MAX_PARAULA], char lletres[N_LLETRES],
    char diccionari[N_PARAULES][MAX_PARAULA], bool& tutti, int& puntuacio)
{
    bool correcte;
    bool possibleTutti = false;
    tutti = false;

    puntuacio = 0;
    correcte = comprovaLletres(paraula, lletres, possibleTutti);
    if (correcte)
    {
        correcte = comprovaDiccionari(paraula, diccionari);
        if (correcte)
        {
            tutti = possibleTutti;
            puntuacio = calculaPuntuacio(paraula, tutti);
        }
    }
    return correcte;
}