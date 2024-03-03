#ifndef WORDLE_H
#define WORDLE_H

#include "jugada.h"

class Wordle
{
public:
    Wordle();
    void inicialitza(const string& paraula);
    EstatPartida juga(const string& paraula);
    void escriuPartida(const string& nomFitxer);
private:
    Lletra m_abecedari[NUM_LLETRES_ABC];
    Jugada m_jugades[MAX_INTENTS];
    char m_paraula[NUM_LLETRES];
    int m_nIntents;
};



#endif
