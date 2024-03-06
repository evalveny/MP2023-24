#include "aula.h"

void Aula::inicialitzaOcupacio()
{
	for (int i = 0; i < MAX_DIES; i++)
		for (int j = 0; j < MAX_HORES; j++)
			m_ocupacio[i][j] = false;
}

bool Aula::estaDisponible(DiaSetmana dia, int hora, int durada) const
{
	bool disponible = false;
	if ((dia >= 0) && (dia < MAX_DIES) && (hora >= HORA_INICIAL) && ((hora + durada) <= HORA_FINAL))
	{
		disponible = true;
		int i = 0;
		while (disponible && (i < durada))
		{
			if (m_ocupacio[dia][hora + i - HORA_INICIAL])
				disponible = false;
			else
				i++;
		}
	}
	return disponible;
}

bool Aula::reserva(DiaSetmana dia, int hora, int durada)
{
	bool correcte = false;
	if ((dia >= 0) && (dia < MAX_DIES) && (hora >= HORA_INICIAL) && ((hora + durada) <= HORA_FINAL))
	{
		for (int i = 0; i < durada; i++)
			m_ocupacio[dia][hora + i - HORA_INICIAL] = true;
		correcte = true;
	}
	return correcte;
}

bool Aula::anulaReserva(DiaSetmana dia, int hora, int durada)
{
	bool correcte = false;
	if ((dia >= 0) && (dia < MAX_DIES) && (hora >= HORA_INICIAL) && ((hora + durada) <= HORA_FINAL))
	{
		for (int i = 0; i < durada; i++)
			m_ocupacio[dia][hora + i - HORA_INICIAL] = false;
		correcte = true;
	}
	return correcte;
}
