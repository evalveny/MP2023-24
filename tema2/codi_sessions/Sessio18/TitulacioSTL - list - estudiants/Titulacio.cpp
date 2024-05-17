#include "Titulacio.h"
#include <fstream>
#include <iostream>
using namespace std;

void Titulacio::afegeixEstudiant(const string& niu, const string& nom, int anyInici)
{
}

bool Titulacio::eliminaEstudiant(const string& niu)
{
	bool trobat = false;
	// Recuperar iterador a l'estudiant que volem eliminar
	// Aplicar esquema de cerca per recuperar estudiant




	// Eliminar l’estudiant utilitzant l’iterador a l’element
	return trobat;
}

bool Titulacio::consultaEstudiant(const string& niu, Estudiant& e)
{
	bool trobat = false;
	std::list<Estudiant>::iterator aux = m_estudiants.begin();
	while ((aux != m_estudiants.end()) && (!trobat))
	{
		e = *aux;
		if (e.getNiu() == niu)
			trobat = true;
		else
			aux++;
	}
	return trobat;
}

void Titulacio::llegeixEstudiants(const string& nomFitxer)
{

}

void Titulacio::mostraEstudiants()
{

}

void Titulacio::eliminaEstudiantsAny(int any)
{

}

