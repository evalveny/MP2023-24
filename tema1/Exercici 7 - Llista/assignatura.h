#ifndef ASSIGNATURA_H
#define ASSIGNATURA_H
#include "estudiant.h"
#include "llista.h"

const int MAX_ESTUDIANTS = 50;

class Assignatura
{
public:
	Assignatura() : m_nom("") {}
	Assignatura(string nom) : m_nom(nom) {}
	Assignatura(string nom, int nEstudiants, string estudiants[MAX_ESTUDIANTS][2]);

	bool afegeixNota(string niu, float nota);
	float calculaNotaMitjana(string niu);
private:
	string m_nom;
	Llista m_estudiants;

};

#endif