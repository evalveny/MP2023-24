#ifndef ASSIGNATURA_H
#define ASSIGNATURA_H
#include "estudiant.h"

const int MAX_ESTUDIANTS = 50;

class Assignatura
{
public:
	Assignatura() : m_nom(""), m_nEstudiants(0) {}
	Assignatura(string nom) : m_nom(nom), m_nEstudiants(0) {}
	Assignatura(string nom, int nEstudiants, string estudiants[MAX_ESTUDIANTS][2]);

	bool afegeixNota(string niu, float nota);
	float calculaNotaMitjana(string niu);
private:
	string m_nom;
	Estudiant m_estudiants[MAX_ESTUDIANTS];
	int m_nEstudiants;

	int cercaEstudiant(string niu);
};

#endif