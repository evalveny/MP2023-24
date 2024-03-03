#ifndef JUGADA_H
#define JUGADA_H

#include <string>
#include "lletra.h"

using namespace std;

class Jugada
{
public:
    Jugada() {}
    void inicialitza(const string& paraula);
    bool comprova(char paraula[NUM_LLETRES], Lletra abecedari[NUM_LLETRES_ABC]);
    Lletra getLletra(int posicio) const { return m_paraula[posicio]; }
private:
    Lletra m_paraula[NUM_LLETRES];

    EstatLletra comprovaLletra(int posicio, char paraula[NUM_LLETRES]);
};

ofstream& operator<<(ofstream& output, const Jugada& jugada);

#endif
