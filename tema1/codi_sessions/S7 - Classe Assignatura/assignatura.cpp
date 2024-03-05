#include "assignatura.h"

Assignatura::Assignatura(string nom, int nEstudiants, string estudiants[MAX_ESTUDIANTS][2])
{
    m_nom = nom;
    for (int i = 0; i < nEstudiants; i++)
    {
        m_estudiants[i].setNiu(estudiants[i][0]);
        m_estudiants[i].setNom(estudiants[i][1]);
    }
    m_nEstudiants = nEstudiants;
}

int Assignatura::cercaEstudiant(string niu)
{
    bool trobat = false;
    int i = 0;
    while (!trobat && (i < m_nEstudiants))
    {
        if (m_estudiants[i].getNiu() == niu)
            trobat = true;
        else
            i++;
    }
    if (trobat)
        return i;
    else
        return -1;
}

bool Assignatura::afegeixNota(string niu, float nota)
{
    bool correcte;
    int pos = cercaEstudiant(niu);
    if (pos != -1)
        correcte = m_estudiants[pos].afegeixNota(nota);
    else
        correcte = false;
    return correcte;
}

float Assignatura::calculaNotaMitjana(string niu)
{
    float mitjana;
    int pos = cercaEstudiant(niu);
    if (pos != -1)
        mitjana = m_estudiants[pos].calculaNotaMitjana();
    else
        mitjana = -1.0;
    return mitjana;
}
