#ifndef FIGURA_H
#define FIGURA_H
#include "InfoJoc.h"


const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;



class Figura
{
public:
    Figura() : m_tipus(NO_FIGURA), m_color(NO_COLOR), m_amplada(MAX_AMPLADA),
                m_alcada(MAX_ALCADA), m_fila(0), m_columna(0), m_gir(0) 
                { resetForma(); }
    void inicialitza(TipusFigura tipus, int fila, int columna);
    void gira(DireccioGir direccio);
    void mou(int dirX);
    void baixa();
    void puja();
    void dibuixa();

    int getFila() const{ return m_fila; }
    int getColumna() const { return m_columna; }
    ColorFigura getColor() const { return m_color; }
    int getAlcada() const{ return m_alcada; }
    int getAmplada() const { return m_amplada; }
    void getMascara(int mascara[MAX_ALCADA][MAX_AMPLADA]) const;
    TipusFigura getTipus() const { return m_tipus; }
private:
    TipusFigura m_tipus;
    ColorFigura m_color;
    int m_amplada;
    int m_alcada;
    int m_mascara[MAX_ALCADA][MAX_AMPLADA];
    int m_fila;
    int m_columna;
    int m_gir;

    void resetForma();
    void inicialitzaForma(TipusFigura tipus);
    void transposaMascara();
    void inverteixMascaraHorizontal();
    void inverteixMascaraVertical();
};


#endif
