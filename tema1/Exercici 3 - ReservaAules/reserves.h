#ifndef _RESERVES_H
#define _RESERVES_H
#include "aula.h"

const int MAX_AULES = 10;
const int MAX_DIES_ACTIVITAT = 10;

typedef struct
{
    DiaSetmana dia;
    int hora;
    int durada;
} DiaActivitat;

class Reserves
{
public:
    Reserves() : m_nAules(0) {}
    Reserves(int nAules, string codis[MAX_AULES], int capacitat[MAX_AULES]);
    string reservaActivitat(int nAssistents, DiaActivitat dies[MAX_DIES_ACTIVITAT], int nDies);
    bool anulaActivitat(const string& codiAula, DiaActivitat dies[MAX_DIES_ACTIVITAT], int nDies);
    bool comprovaAulaDisponible(const string& codiAula, DiaSetmana dia, int hora);
private:
    Aula m_aules[MAX_AULES];
    int m_nAules;

    bool comprovaDisponibilitat(const Aula& aula, DiaActivitat dies[MAX_DIES_ACTIVITAT], int nDies);
    void reservaAula(int nAula, DiaActivitat dies[MAX_DIES_ACTIVITAT], int nDies);
    void anulaReservaAula(int nAula, DiaActivitat dies[MAX_DIES_ACTIVITAT], int nDies);
};


#endif // !_RESERVES_H

