#ifndef TAULER_H
#define TAULER_H
#include "FormaFigura.h"

const int MAX_FILA = 24;
const int MAX_COL = 17;

class Tauler
{
public:
    Tauler();

    bool colisionaFigura(int fila, int col, int mascara[MAX_ALCADA][MAX_AMPLADA], int midaMascara);
    int colocaFigura(int fila, int col, int mascara[MAX_ALCADA][MAX_AMPLADA], int midaMascara, int color);
    void mostra();

private:
    int m_tauler[MAX_FILA][MAX_COL];
    int m_lliures[MAX_FILA];

    void baixaFila(int fila);
};
#endif