#ifndef DEFINICIONS_H
#define DEFINICIONS_H

typedef enum
{
    NO_DEFINIDA,
    NO_EXISTEIX,
    POSICIO_INCORRECTA,
    POSICIO_CORRECTA
} EstatLletra;

typedef enum
{
    ACTIVA,
    FINAL_GUANYAT,
    FINAL_PERDUT
} EstatPartida;

const int NUM_LLETRES = 5;
const int NUM_LLETRES_ABC = 26;
const int MAX_INTENTS = 6;

#endif
