#include "notes.hpp"

void converteixNotes(float notesNumeriques[MAX_NOTES], int nEstudiants, char notesActa[MAX_NOTES], 
    float& notaMinima, float& notaMaxima, float& notaMitja)
{
    notaMinima = 10.0;
    notaMaxima = 0.0;
    notaMitja = 0.0;
    int nPresentats = 0;
    for (int i = 0; i < nEstudiants; i ++)
    {
        if (notesNumeriques[i] == -1)
            notesActa[i] = 'P';
        else
        {
            nPresentats++;
            notaMitja += notesNumeriques[i];
            if (notesNumeriques[i] > notaMaxima)
                notaMaxima = notesNumeriques[i];
            if (notesNumeriques[i] < notaMinima)
                notaMinima = notesNumeriques[i];
            if (notesNumeriques[i] < 5)
                notesActa[i] = 'S';
            else 
                if (notesNumeriques[i] < 7)
                    notesActa[i] = 'A';
                else 
                    if (notesNumeriques[i] < 9)
                        notesActa[i] = 'N';
                    else 
                        if (notesNumeriques[i] < 10)
                            notesActa[i] = 'E';
                        else
                            notesActa[i] = 'M';

        }
	}
    if (nPresentats > 0)
        notaMitja /= nPresentats;
    else
    {
        notaMinima = -1;
        notaMaxima = -1;
        notaMitja = -1;
    }
}