#ifndef FORMA_FIGURA_H
#define FORMA_FIGURA_H

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class FormaFigura
{
public:
	FormaFigura();
    void gira(DireccioGir direccio);
private:
    int m_amplada;
    int m_alcada;
    int m_mascara[MAX_ALCADA][MAX_AMPLADA];

    void transposaMascara();
    void inverteixMascaraHorizontal();
    void inverteixMascaraVertical();
};

#endif
