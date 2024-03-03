#include "biblioteca.h"

void Biblioteca::afegeixLlibre(const Llibre& llibre)
{
	m_llibres[m_nLlibres] = llibre;
	m_nLlibres++;
}

int Biblioteca::cercaLlibre(const string &titol)
{
	bool trobat = false;
	int i = 0;
	while (!trobat && (i < m_nLlibres))
	{
		if (titol == m_llibres[i].getTitol())
			trobat = true;
		else
			i++;
	}
	if (trobat)
		return i;
	else 
		return -1;
}


int Biblioteca::prestaLlibre(const string &titol, int &codiExemplar)
{
	int resultat;
	int posLlibre = cercaLlibre(titol);
	if (posLlibre == -1)
		resultat = -2;
	else
		if (m_llibres[posLlibre].presta(codiExemplar))
			resultat = 0;
		else
			resultat = -1;
	return resultat;
}

int Biblioteca::retornaLlibre(const string &titol, int codiExemplar)
{
	int resultat;
	int posLlibre = cercaLlibre(titol);
	if (posLlibre == -1)
		resultat = -2;
	else
		if (m_llibres[posLlibre].retorna(codiExemplar))
			resultat = 0;
		else
			resultat = -1;
	return resultat;
}