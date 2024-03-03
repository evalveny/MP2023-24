#ifndef LLETRA_H
#define LLETRA_H

#include <fstream>
#include "definicions.h"

using namespace std;

class Lletra
{
public:
    Lletra() : m_lletra(' '), m_estat(NO_DEFINIDA) {}
    void setLletra(char lletra) { m_lletra = lletra; }
    void setEstat(EstatLletra estat) { m_estat = estat; }
    EstatLletra getEstat() const { return m_estat; }
    char getLletra() const { return m_lletra; }
    void actualitzaEstat(EstatLletra estat);
private:
    char m_lletra;
    EstatLletra m_estat;
};

ofstream& operator<<(ofstream& output, const Lletra& lletra);

#endif

