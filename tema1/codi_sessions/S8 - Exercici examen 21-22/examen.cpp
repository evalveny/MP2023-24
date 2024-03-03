#include <iostream>
#include "examen.h"

using namespace std;

void Estudiant::afegeixAssignatura(string nomAssignatura)
{
	m_assignatures[m_nAssignatures].m_nom = nomAssignatura;
	m_nAssignatures++;
}

float Estudiant::notaMitja()
{
	float nota = 0;
	for (int i = 0; i < m_nAssignatures; i++)
		nota += m_assignatures[i].m_notaFinal;
	nota /= m_nAssignatures;
	return nota;
}

void llegeixAssignatures(Estudiant& estudiant)
{
	string nomAssig;

	cin >> nomAssig;
	while (nomAssig != "")
	{
		estudiant.afegeixAssignatura(nomAssig);
		cin >> nomAssig;
	}
}

void mostraEstudiant(Estudiant estudiant)
{
	cout << estudiant.m_nom;
	cout << estudiant.m_niu;
	float nota = estudiant.notaMitja();
	cout << nota;
}

int main()
{
	Estudiant estudiant;
	cin >> estudiant.m_nom;
	cin >> estudiant.m_niu;
	llegeixAssignatures(estudiant);
	mostraEstudiant(estudiant);
	return 0;
}