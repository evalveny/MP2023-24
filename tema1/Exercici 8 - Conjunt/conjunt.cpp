#include "Conjunt.h"

Conjunt::Conjunt(const Estudiant v[], int mida)
{
	if (mida <= MAX_ELEMENTS)
	{
		for (int i = 0; i < mida; i++)
		{
			m_elements[i] = v[i];
		}
		m_nElements = mida;
	}
}

bool Conjunt::pertany(const Estudiant& element) const
{
	bool trobat = false;
	int i = 0;
	while (!trobat && (i < m_nElements))
	{
		if (m_elements[i] == element)
			trobat = true;
		else
			i++;
	}
	return trobat;
}

bool Conjunt::recuperaElement(Estudiant& element) const
{
	bool trobat = false;
	int i = 0;
	while (!trobat && (i < m_nElements))
	{
		if (m_elements[i] == element)
		{
			trobat = true;
			element = m_elements[i];
		}
		else
			i++;
	}
	return trobat;

}

void Conjunt::operator+=(const Estudiant& element)
{
	if ((m_nElements < MAX_ELEMENTS) && (!pertany(element)))
	{
		m_elements[m_nElements] = element;
		m_nElements++;
	}
}

void Conjunt::operator-=(const Estudiant& element)
{
	bool trobat = false;
	int posicio = 0;
	while (!trobat && (posicio < m_nElements))
	{
		if (m_elements[posicio] == element)
			trobat = true;
		else
			posicio++;
	}
	if (trobat)
	{
		for (int i = posicio; i < (m_nElements - 1); i++)
		{
			m_elements[i] = m_elements[i + 1];
		}
		m_nElements--;
	}
}


Conjunt Conjunt::operator+(const Conjunt& conjunt) const
{
	Conjunt resultat;
	for (int i = 0; i < m_nElements; i++)
		resultat.m_elements[i] = m_elements[i];
	resultat.m_nElements = m_nElements;
	for (int i = 0; i < conjunt.m_nElements; i++)
		resultat += conjunt.m_elements[i];
	return resultat;
}


Conjunt Conjunt::operator*(const Conjunt& conjunt) const
{
	Conjunt resultat;
	for (int i = 0; i < m_nElements; i++)
	{
		if (conjunt.pertany(m_elements[i]))
			resultat += m_elements[i];
	}
	return resultat;
}

void Conjunt::arrayToConjunt(const Estudiant v[], int mida)
{
	if (mida <= MAX_ELEMENTS)
	{
		for (int i = 0; i < mida; i++)
		{
			m_elements[i] = v[i];
		}
		m_nElements = mida;
	}
}

void Conjunt::conjuntToArray(Estudiant v[], int& mida) const
{
	for (int i = 0; i < m_nElements; i++)
	{
		v[i] = m_elements[i];
	}
	mida = m_nElements;
}

ostream& operator<<(ostream& output, const Conjunt& conjunt)
{
	Estudiant array[MAX_ELEMENTS];
	int nElements;
	conjunt.conjuntToArray(array, nElements);
	for (int i = 0; i < nElements; i++)
		output << array[i] << endl;
	return output;
}

ofstream& operator<<(ofstream& output, const Conjunt& conjunt)
{
	Estudiant array[MAX_ELEMENTS];
	int nElements;
	conjunt.conjuntToArray(array, nElements);
	for (int i = 0; i < nElements; i++)
		output << array[i] << endl;
	return output;
}

ifstream& operator>>(ifstream& input, Conjunt& conjunt)
{
	Estudiant estudiant;
	input >> estudiant;
	while (!input.eof())
	{
		conjunt += estudiant;
		input >> estudiant;
	}
	return input;
}
