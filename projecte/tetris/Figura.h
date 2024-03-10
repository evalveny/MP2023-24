#ifndef FIGURA_H
#define FIGURA_H
#include "FormaFigura.h"

const int N_TIPUS_FIGURES = 7;

typedef enum
{
    COLOR_BLAUCEL = 0,
    COLOR_GROC,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERD,
    COLOR_VERMELL
} ColorFigura;


typedef enum
{
    FIGURA_O = 0,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S
} TipusFigura;


class Figura
{
public:
    Figura();
    void gira();
    void mou(int dirX);
    void baixa();
private:
    TipusFigura m_tipus;
    ColorFigura m_color;
    FormaFigura m_forma;
    int m_posX;
    int m_posY;
};


#endif
