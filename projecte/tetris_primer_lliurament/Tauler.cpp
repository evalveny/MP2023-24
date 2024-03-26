#include "Tauler.h"
#include <iostream>
using namespace std;

Tauler::Tauler()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        m_tauler[i][0] = NO_COLOR;
        m_tauler[i][1] = NO_COLOR;
        m_tauler[i][MAX_COL + 2] = NO_COLOR;
        m_tauler[i][MAX_COL + 3] = NO_COLOR;
        for (int j = 0; j < MAX_COL; j++)
            m_tauler[i][j + 2] = COLOR_NEGRE;
    }
    for (int j = 0; j < MAX_COL + 4; j++)
    {
        m_tauler[MAX_FILA][j] = NO_COLOR;
        m_tauler[MAX_FILA + 1][j] = NO_COLOR;
    }
    for (int i = 0; i < MAX_FILA; i++)
        m_lliures[i] = MAX_COL;
}

void Tauler::inicialitza(ColorFigura taulerInicial[MAX_FILA][MAX_COL])
{
    for (int i = 0; i < MAX_FILA; i++)
        m_lliures[i] = MAX_COL;
    for (int i = 0; i < MAX_FILA; i++)
        for (int j = 0; j < MAX_COL; j++)
        {
            m_tauler[i][j + 2] = taulerInicial[i][j];
            if (taulerInicial[i][j] != COLOR_NEGRE)
                m_lliures[i]--;
        }
}

bool Tauler::colisionaFigura(const Figura& figura)
{
    bool colisionaFigura = false;
    int mascara[MAX_ALCADA][MAX_AMPLADA];

    int filaMascara = 0;
    int filaTauler = figura.getFila() - 1;
    figura.getMascara(mascara);
    do
    {
        int colMascara = 0;
        int colTauler = figura.getColumna() + 1;
        do
        {
            if ((mascara[filaMascara][colMascara] * m_tauler[filaTauler][colTauler]) != 0)
            {
                colisionaFigura = true;
            }
            colMascara++;
            colTauler++;
        } while ((!colisionaFigura) && (colMascara < figura.getAmplada()));

        filaMascara++;
        filaTauler++;
    } while ((!colisionaFigura) && (filaMascara < figura.getAlcada()));

    return colisionaFigura;

}

int Tauler::colocaFigura(const Figura& figura)
{
    int mascara[MAX_ALCADA][MAX_AMPLADA];
    int numFilesFetes = 0;

    ColorFigura color = figura.getColor();
    figura.getMascara(mascara);
    int filaTauler = figura.getFila() - 1;
    for (int filaMascara = 0; filaMascara < figura.getAlcada(); filaMascara++)
    {
        int colTauler = figura.getColumna() + 1;
        for (int colMascara = 0; colMascara < figura.getAmplada(); colMascara++)
        {
            if (mascara[filaMascara][colMascara] > 0)
            {
                m_tauler[filaTauler][colTauler] = color;
                m_lliures[filaTauler]--;
                if (m_lliures[filaTauler] == 0)
                {
                    numFilesFetes++;
                    baixaFila(filaTauler);
                }
            }
            colTauler++;
        }
        filaTauler++;
    }
    return numFilesFetes;
}


void Tauler::dibuixaFigura(const Figura& figura)
{
    int mascara[MAX_ALCADA][MAX_AMPLADA];

    ColorFigura color = figura.getColor();
    figura.getMascara(mascara);
    int filaTauler = figura.getFila() - 1;
    for (int filaMascara = 0; filaMascara < figura.getAlcada(); filaMascara++)
    {
        int colTauler = figura.getColumna() + 1;
        for (int colMascara = 0; colMascara < figura.getAmplada(); colMascara++)
        {
            if (mascara[filaMascara][colMascara] > 0)
            {
                m_tauler[filaTauler][colTauler] = color;
            }
            colTauler++;
        }
        filaTauler++;
    }
}

void Tauler::baixaFila(int fila)
{
    if (fila > 0)
    {
        for (int i = fila; i > 0; i--)
        {
            for (int j = 0; j < MAX_COL; j++)
            {
                m_tauler[i][j + 2] = m_tauler[i - 1][j + 2];
            }
            m_lliures[i] = m_lliures[i - 1];
        }
    }
    for (int i = 0; i < MAX_COL; i++)
        m_tauler[0][i + 2] = COLOR_NEGRE;
    m_lliures[0] = MAX_COL;
}

void Tauler::getValorsTauler(ColorFigura tauler[MAX_FILA][MAX_COL])
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
            tauler[i][j] = m_tauler[i][j + 2];
    }
}