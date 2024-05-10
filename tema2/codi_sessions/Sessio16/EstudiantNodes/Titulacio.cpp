#include "Titulacio.h"



void Titulacio::afegeixEstudiant(const string& niu, const string& nom)
{
	Estudiant estudiantAux(niu, nom);
	NodeEstudiant* nodeAux = new NodeEstudiant;
	nodeAux->setValor(estudiantAux);
	nodeAux->setNext(m_estudiants);
	m_estudiants = nodeAux;
	m_nEstudiants++;
}

void Titulacio::eliminaPrimerEstudiant()
{
	if (m_estudiants != nullptr)
	{
		NodeEstudiant* aux = m_estudiants;
		m_estudiants = m_estudiants->getNext();
		delete aux;
	}
}

bool Titulacio::eliminaEstudiant(const string& niu)
{
	bool trobat = false;
	NodeEstudiant* aux = m_estudiants;
	NodeEstudiant* anterior = nullptr;
	while ((aux != nullptr) && !trobat)
	{
		if (niu == aux->getValor().getNiu())
			trobat = true;
		else
		{
			anterior = aux;
			aux = aux->getNext();
		}
	}
	if (trobat)
	{
		if (anterior != nullptr)
			anterior->setNext(aux->getNext());
		else
			m_estudiants = aux->getNext();
		delete aux;
		m_nEstudiants--;
	}
	return trobat;
}


void Titulacio::insereixEstudiant(const string& niu, const string& nom)
{
	bool trobat = false;
	NodeEstudiant* aux = m_estudiants;
	NodeEstudiant* anterior = nullptr;
	while ((aux != nullptr) && !trobat)
	{
		if (niu < aux->getValor().getNiu())
			trobat = true;
		else
		{
			anterior = aux;
			aux = aux->getNext();
		}
	}
	Estudiant estudiantAux(niu, nom);
	NodeEstudiant* nouEstudiant = new NodeEstudiant;
	nouEstudiant->setValor(estudiantAux);
	nouEstudiant->setNext(aux);
	if (anterior != nullptr)
		anterior->setNext(nouEstudiant);
	else
		m_estudiants = nouEstudiant;
}

bool Titulacio::consultaEstudiant(const string& niu, Estudiant& e)
{
	bool trobat = false;
	NodeEstudiant *aux = m_estudiants;
	while ((aux != nullptr) && (!trobat))
	{
		e = aux->getValor();
		if (e.getNiu() == niu)
			trobat = true;
		else
			aux = aux->getNext();
	}
	return trobat;
}