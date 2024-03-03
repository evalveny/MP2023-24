#pragma once
#include "llibre.h"

const int MAX_LLIBRES = 100;

class Biblioteca
{
public:
	Biblioteca() : m_nLlibres(0) {}
	int prestaLlibre(const string& titol, int& codiExemplar);
	int retornaLlibre(const string& titol, int codiExemplar);
	void afegeixLlibre(const Llibre& llibre);
private:
	Llibre m_llibres[MAX_LLIBRES];
	int m_nLlibres;

	int cercaLlibre(const string& titol);
};
