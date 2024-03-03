#include "jugada.h"

void Jugada::inicialitza(const string& paraula)
{
	for (int i = 0; i < NUM_LLETRES; i++)
	{
		m_paraula[i].setLletra(paraula[i]);
	}
}

bool Jugada::comprova(char paraula[NUM_LLETRES], Lletra abecedari[NUM_LLETRES_ABC])
{
	bool correcta = true;
	for (int i = 0; i < NUM_LLETRES; i++)
	{
		EstatLletra estat = comprovaLletra(i, paraula);
		m_paraula[i].setEstat(estat);
		if (estat != POSICIO_CORRECTA)
			correcta = false;
		abecedari[m_paraula[i].getLletra() - 'A'].actualitzaEstat(estat);
	}
	return correcta;
}

EstatLletra Jugada::comprovaLletra(int posicio, char paraula[NUM_LLETRES])
{
	EstatLletra estat = NO_EXISTEIX;
	int posLletra = -1;
	for (int i = 0; i < NUM_LLETRES; i++)
	{
		if (m_paraula[posicio].getLletra() == paraula[i])
		{
			if (posLletra == -1)
				posLletra = i;
			else
				if (i == posicio)
					posLletra = i;
		}			
	}
	if (posLletra != -1)
		if (posLletra == posicio)
			estat = POSICIO_CORRECTA;
		else
			estat = POSICIO_INCORRECTA;
	return estat;
}

ofstream& operator<<(ofstream& output, const Jugada& jugada)
{
	for (int i = 0; i < NUM_LLETRES; i++)
		output << jugada.getLletra(i);
	output << endl;
	return output;
}

