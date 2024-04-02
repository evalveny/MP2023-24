#include "Estudiant.h"
#include "array_estudiants.h"

Estudiant* cercaEstudiant(Estudiant estudiants[], int nEstudiants, string niu)
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
        return &estudiants[i];
    else
        return nullptr;
}

bool afegeixNotaEstudiant(Estudiant* estudiant, float nota, float* notaMitjana)
{
    bool correcte = estudiant->afegeixNota(nota);
    *notaMitjana = estudiant->calculaNotaMitjana();
    return correcte;
}


bool afegeixNota(Estudiant estudiants[], int nEstudiants, string niu, float nota, float* notaMitjana)
{
    bool correcte = false;
    Estudiant* estudiant = cercaEstudiant(estudiants, nEstudiants, niu);
    if (estudiant != nullptr)
    {
        correcte = true;
        afegeixNotaEstudiant(estudiant, nota, notaMitjana);
    }
    return correcte;
}

