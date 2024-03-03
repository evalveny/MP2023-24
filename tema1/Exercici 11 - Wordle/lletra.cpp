#include "lletra.h"

void Lletra::actualitzaEstat(EstatLletra estat)
{
	if (m_estat != estat)
	{
		if (m_estat == NO_DEFINIDA)
			m_estat = estat;
		else
			if ((m_estat == POSICIO_INCORRECTA) && (estat == POSICIO_CORRECTA))
				m_estat = estat;
	}
}

ofstream& operator<<(ofstream& output, const Lletra& lletra)
{
	char estat;
	switch (lletra.getEstat())
	{
	case NO_DEFINIDA:
		estat = '_';
		break;
	case NO_EXISTEIX:
		estat = 'N';
		break;
	case POSICIO_INCORRECTA:
		estat = 'I';
		break;
	case POSICIO_CORRECTA:
		estat = 'C';
		break;
	}
	output << "(" << lletra.getLletra() << "," << estat << ")";
	return output;
}