#include "reserves.h"

Reserves::Reserves(int nAules, string codis[MAX_AULES], int capacitat[MAX_AULES])
{
	m_nAules = nAules;
	for (int i = 0; i < nAules; i++)
	{
		m_aules[i].setCodi(codis[i]);
		m_aules[i].setCapacitat(capacitat[i]);
	}
}

bool Reserves::comprovaAulaDisponible(const string& codiAula, DiaSetmana dia, int hora)
{
	bool trobat = false;
	int i = 0;
	while (!trobat && (i < m_nAules))
	{
		if (m_aules[i].getCodi() == codiAula)
			trobat = true;
		else
			i++;
	}
	if (trobat)
		trobat = m_aules[i].estaDisponible(dia, hora, 1);
	return trobat;
}

string Reserves::reservaActivitat(int nAssistents, DiaActivitat dies[MAX_DIES_ACTIVITAT], int nDies)
{
	string codiAula = "";
	int minCapacitat = MAX_CAPACITAT_AULA;
	int nAula = 0;
	for (int i = 0; i < m_nAules; i++)
	{
		int capacitatAula = m_aules[i].getCapacitat();
		if ((capacitatAula >= nAssistents) && (capacitatAula < minCapacitat))
			if (comprovaDisponibilitat(m_aules[i], dies, nDies))
			{
				codiAula = m_aules[i].getCodi();
				minCapacitat = capacitatAula;
				nAula = i;
			}
	}
	if (codiAula != "")
		reservaAula(nAula, dies, nDies);
	return codiAula;
}

bool Reserves::anulaActivitat(const string& codiAula, DiaActivitat dies[MAX_DIES_ACTIVITAT], int nDies)
{
	bool trobat = false;
	int i = 0;
	while (!trobat && (i < m_nAules))
	{
		if (m_aules[i].getCodi() == codiAula)
			trobat = true;
		else
			i++;
	}
	if (trobat)
		anulaReservaAula(i, dies, nDies);
	return trobat;

}

bool Reserves::comprovaDisponibilitat(const Aula& aula, DiaActivitat dies[MAX_DIES_ACTIVITAT], int nDies)
{
	bool disponible = true;
	int i = 0;
	while (disponible && (i < nDies))
	{
		if (!aula.estaDisponible(dies[i].dia, dies[i].hora, dies[i].durada))
			disponible = false;
		else
			i++;
	}
	return disponible;
}

void Reserves::reservaAula(int nAula, DiaActivitat dies[MAX_DIES_ACTIVITAT], int nDies)
{
	for (int i = 0; i < nDies ; i++)
		m_aules[nAula].reserva(dies[i].dia, dies[i].hora, dies[i].durada);
}

void Reserves::anulaReservaAula(int nAula, DiaActivitat dies[MAX_DIES_ACTIVITAT], int nDies)
{
	for (int i = 0; i < nDies; i++)
		m_aules[nAula].anulaReserva(dies[i].dia, dies[i].hora, dies[i].durada);
}