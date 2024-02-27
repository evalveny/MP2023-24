#pragma once
#include "Punt.h"
#include <cmath>
#include <iostream>
using namespace std;

void Punt::llegeix()
{
    cout << "Introdueix les " << m_nDimensions << " coordenades del punt : ";
    for (int i = 0; i < m_nDimensions; i++)
        cin >> m_coordenades[i];
}

void Punt::mostra()
{
    cout << "(";
    for (int i = 0; i < (m_nDimensions - 1); i++)
        cout << m_coordenades[i] << ", ";
    cout << m_coordenades[m_nDimensions - 1] << ")";
}

float Punt::distancia(Punt &p)
{
    float distancia = 0;
    for (int i = 0; i < m_nDimensions; i++)
    {
        float diferencia = p.m_coordenades[i] - m_coordenades[i];
        distancia += (diferencia * diferencia);
    }
    return sqrt(distancia);
}

