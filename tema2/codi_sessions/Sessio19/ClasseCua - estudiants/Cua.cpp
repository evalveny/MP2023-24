
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


	// Si la cua esta buida

		// El nou element passa a ser el primer i �ltim a la vegada

	// sino

		// Enlla�ar nou element amb l��ltim. 
		// El nou element passa a ser l��ltim

}

void Cua::treu()
{
	// Si cua amb un sol element
		// Modificar apuntador a �ltim
	// Modificar apuntador a primer
	// Eliminar node 
}


