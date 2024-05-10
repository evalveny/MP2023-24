#ifndef INFO_JOC_H
#define INFO_JOC_H

const int N_TIPUS_FIGURES = 7;

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;

typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S
} TipusFigura;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

typedef struct
{
    TipusFigura tipus;
    int fila;
    int columna;
    int gir;
} InfoFigura;

typedef enum
{
    MOVIMENT_ESQUERRA = 0,
    MOVIMENT_DRETA = 1,
    MOVIMENT_GIR_HORARI = 2,
    MOVIMENT_GIR_ANTI_HORARI = 3,
    MOVIMENT_BAIXA = 4,
    MOVIMENT_BAIXA_FINAL = 5,
} TipusMoviment;


const int SCREEN_SIZE_X = 600;
const int SCREEN_SIZE_Y = 700;

const int MIDA_QUADRAT = 26;

const int N_FILES_TAULER = 21;
const int N_COL_TAULER = 11;

const int POS_X_TAULER = 120;
const int POS_Y_TAULER = 100;

const int POS_X_PUNTUACIO = 120;
const int POS_Y_PUNTUACIO = 50;

const int POS_X_NIVELL = 300;
const int POS_Y_NIVELL = 50;

const int POS_X_FINAL_JOC = 120;
const int POS_Y_FINAL_JOC = 300;


void dibuixaQuadrat(ColorFigura color, int posX, int posY);

#endif