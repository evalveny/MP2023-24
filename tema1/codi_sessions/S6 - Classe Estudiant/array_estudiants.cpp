#include "Estudiant.h"

void afegeixEstudiant(Estudiant estudiants[], int nEstudiants, string nom, string niu)
{
    estudiants[nEstudiants].inicialitza(nom, niu);
}

int cercaEstudiant(Estudiant estudiants[], int nEstudiants, string niu)
{
    bool trobat = false;
    int i = 0;
    while (!trobat && (i < nEstudiants))
    {
        if (estudiants[i].getNiu() == niu)
            trobat = true;
        else
            i++;
    }
    if (trobat)
        return i;
    else
        return -1;
}

bool afegeixNota(Estudiant estudiants[], int nEstudiants, string niu, float nota)
{
    bool correcte;
    int pos = cercaEstudiant(estudiants, nEstudiants, niu);
    if (pos != -1)
        correcte = estudiants[pos].afegeixNota(nota);
    else
        correcte = false;
    return correcte;
}

float calculaNotaMitjana(Estudiant estudiants[], int nEstudiants, string niu)
{
    float mitjana;
    int pos = cercaEstudiant(estudiants, nEstudiants, niu);
    if (pos != -1)
        mitjana = estudiants[pos].calculaNotaMitjana();
    else
        mitjana = -1.0;
    return mitjana;
}
