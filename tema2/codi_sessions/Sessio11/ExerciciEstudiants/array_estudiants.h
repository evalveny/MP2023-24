#ifndef ARRAY_ESTUDIANTS_H
#define ARRAY_ESTUDIANTS_H
#include "Estudiant.h"

const int MAX_ESTUDIANTS = 10;

Estudiant* cercaEstudiant(Estudiant estudiants[], int nEstudiants, string niu);
bool afegeixNotaEstudiant(Estudiant* estudiant, float nota, float* notaMitjana);
bool afegeixNota(Estudiant estudiants[], int nEstudiants, string niu, float nota, float* notaMitjana);


#endif