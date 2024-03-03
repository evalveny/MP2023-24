#pragma once
#include <string>
using namespace std;

const int MAX_ASSIGNATURES = 10;
const int MAX_NOTES = 5;

class Assignatura
{
public:
	string m_nom;
	float m_notes[MAX_NOTES];
	float m_notaFinal;
};

class Estudiant
{
public:
	string m_niu;
	string m_nom;
	int m_nAssignatures;
	Assignatura m_assignatures[MAX_ASSIGNATURES];

	void afegeixAssignatura(string nomAssignatura);
	float notaMitja();
};