#include "assignatura.h"

Assignatura::Assignatura(string nom, int nEstudiants, string estudiants[MAX_ESTUDIANTS][2])
{
    m_nom = nom;
    for (int i = 0; i < nEstudiants; i++)
    {
        Estudiant e(estudiants[i][1], estudiants[i][0]);
        m_estudiants + e;
    }
}


bool Assignatura::afegeixNota(string niu, float nota)
{
    bool correcte;
    int pos = m_estudiants.cerca(niu);
    if (pos != -1)
    {
        Estudiant e = m_estudiants.getElement(pos);
        correcte = e.afegeixNota(nota);
        m_estudiants.setElement(pos, e);
    }
    else
        correcte = false;
    return correcte;
}

float Assignatura::calculaNotaMitjana(string niu)
{
    float mitjana;
    int pos = m_estudiants.cerca(niu);
    if (pos != -1)
    {
        Estudiant e = m_estudiants.getElement(pos);
        mitjana = e.calculaNotaMitjana();
    }       
    else
        mitjana = -1.0;
    return mitjana;
}
