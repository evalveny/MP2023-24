#ifndef CONJUNT_H
#define CONJUNT_H

#include "estudiant.h"
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_ELEMENTS = 100;

class Conjunt	
{
public:
	Conjunt() : m_nElements(0) {}
	Conjunt(const Estudiant v[], int mida);

	int getNumElements() const { return m_nElements; }
	bool pertany(const Estudiant& element) const;
	bool recuperaElement(Estudiant& element) const;
	void operator+=(const Estudiant& element);
	void operator-=(const Estudiant& element);
	Conjunt operator+(const Conjunt& conjunt) const;
	Conjunt operator*(const Conjunt& conjunt) const;
	void arrayToConjunt(const Estudiant v[], int mida);
	void conjuntToArray(Estudiant v[], int& mida) const;
private:
	Estudiant m_elements[MAX_ELEMENTS];
	int m_nElements;
};


ostream& operator<<(ostream& output, const Conjunt& conjunt);
ofstream& operator<<(ofstream& output, const Conjunt& conjunt);
ifstream& operator>>(ifstream& input, Conjunt& conjunt);

#endif