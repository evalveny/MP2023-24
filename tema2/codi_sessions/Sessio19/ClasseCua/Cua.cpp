
#include "Cua.h"

Cua::Cua()
{
     m_primer = nullptr;
	 m_ultim = nullptr;
}

Cua::~Cua()
{
	while (m_primer != nullptr)
		treu();
}

bool Cua::esBuida() const
{
    return (m_primer == nullptr);
}

int Cua::getPrimer() const
{
	if (m_primer != nullptr)
		return m_primer->getValor();
}

int Cua::getUltim() const
{
	if (m_ultim != nullptr)
		return m_ultim->getValor();
}


void Cua::afegeix(const int& valor)
{
	// Creaci� din�mica del nou node
	Node* aux = new Node;
	aux->setValor(valor);
	aux->setNext(nullptr);

	// Si la cua esta buida
	if (m_primer == nullptr)
	{
		// El nou element passa a ser el primer i �ltim a la vegada
		m_primer = aux;
		m_ultim = aux;
	}
	// sino
	else
	{
		// Enlla�ar nou element amb l��ltim. 
		// El nou element passa a ser l��ltim
		m_ultim->setNext(aux);
		m_ultim = aux;
	}

}

void Cua::treu()
{
	if (m_primer != nullptr)
	{
		Node* aux = m_primer;
		// Si cua amb un sol element
		if (m_primer == m_ultim)
			// Modificar apuntador a �ltim
			m_ultim = nullptr;
		// Modificar apuntador a primer
		m_primer = aux->getNext();
		// Eliminar node 
		delete aux;
	}
}


