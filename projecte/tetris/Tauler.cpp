#include "Tauler.h"
#include <iostream>
using namespace std;

bool Tauler::colisionaFigura(int fila, int col, int mascara[MAX_ALCADA][MAX_AMPLADA], int midaMascara)
{
    bool colisionaFigura = false;

    int filaMascara = 0;
    int filaTauler = fila;
    do
    {
        int colMascara = 0;
        int colTauler = col;
        do
        {
            if ((mascara[filaMascara][colMascara] * m_tauler[filaTauler][colTauler]) != 0)
            {
                colisionaFigura = true;
            }
            colMascara++;
            colTauler++;
        } while ((!colisionaFigura) && (colMascara < midaMascara));

        filaMascara++;
        filaTauler++;
    } while ((!colisionaFigura) && (filaMascara < midaMascara));

    return colisionaFigura;

}

int Tauler::colocaFigura(int fila, int col, int mascara[MAX_ALCADA][MAX_AMPLADA], int midaMascara, int color)
{
    int numFilesFetes = 0;

    int filaTauler = fila;
    for (int filaMascara = 0; filaMascara < midaMascara; filaMascara++)
    {
        int colTauler = col;
        for (int colMascara = 0; colMascara < midaMascara; colMascara++)
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

void Tauler::mostra()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
            cout << m_tauler[i][j];
        cout << endl;
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
                m_tauler[fila][j] = m_tauler[fila - 1][j];
            }
            m_lliures[fila] = m_lliures[fila - 1];
        }
    }
    for (int i = 0; i < MAX_COL; i++)
        m_tauler[0][i] = 0;
    m_lliures[0] = MAX_COL;
}

}