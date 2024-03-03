#include "wordle.h"
#include <fstream>

using namespace std;

Wordle::Wordle()
{
	for (int i = 0; i < NUM_LLETRES_ABC; i++)
		m_abecedari[i].setLletra('A' + i);
	m_nIntents = 0;
}

void Wordle::inicialitza(const string& paraula)
{
	m_nIntents = 0;
	for (int i = 0; i < NUM_LLETRES; i++)
		m_paraula[i] = paraula[i];
	for (int i = 0; i < NUM_LLETRES_ABC; i++)
	{
		m_abecedari[i].setLletra('A' + i);
		m_abecedari[i].setEstat(NO_DEFINIDA);
	}
}

EstatPartida Wordle::juga(const string& paraula)
{
	EstatPartida estat = ACTIVA;
	m_jugades[m_nIntents].inicialitza(paraula);
	bool final = m_jugades[m_nIntents].comprova(m_paraula, m_abecedari);
	m_nIntents++;
	if (final)
		estat = FINAL_GUANYAT;
	else
		if (m_nIntents == MAX_INTENTS)
			estat = FINAL_PERDUT;
	return estat;
}

void Wordle::escriuPartida(const string& nomFitxer)
{
	ofstream fitxer;

	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		for (int i = 0; i < m_nIntents; i++)
			fitxer << m_jugades[i];
		for (int i = 0; i < NUM_LLETRES_ABC; i++)
			fitxer << m_abecedari[i];
	}
}