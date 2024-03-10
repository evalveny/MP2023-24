#include "FormaFigura.h"


void FormaFigura::gira(DireccioGir direccio)
{
	transposaMascara();
	if (direccio == GIR_HORARI)
		inverteixMascaraHorizontal();
	else
		inverteixMascaraVertical();
}


void FormaFigura::transposaMascara()
{
	int aux;
	for (int i = 1; i < m_alcada; i++)
		for (int j = 0; j < i; j++)
		{
			aux = m_mascara[i][j];
			m_mascara[i][j] = m_mascara[j][i];
			m_mascara[j][i] = aux;
		}
}

void FormaFigura::inverteixMascaraVertical()
{
	int columna1, columna2;
	if (m_amplada != 2)
	{
		if (m_amplada == 3)
		{
			columna1 = 0;
			columna2 = 2;
		}
		else
		{
			columna1 = 1;
			columna2 = 2;
		}
		int aux;
		for (int i = 0; i < m_alcada; i++)
		{
			aux = m_mascara[i][columna1];
			m_mascara[i][columna1] = m_mascara[i][columna2];
			m_mascara[i][columna2] = aux;
		}
	}
}

void FormaFigura::inverteixMascaraHorizontal()
{
	int fila1, fila2;
	if (m_alcada != 2)
	{
		if (m_alcada == 3)
		{
			fila1 = 0;
			fila2 = 2;
		}
		else
		{
			fila1 = 1;
			fila2 = 2;
		}
		int aux;
		for (int i = 0; i < m_amplada; i++)
		{
			aux = m_mascara[fila1][i];
			m_mascara[fila1][i] = m_mascara[fila2][i];
			m_mascara[fila2][i] = aux;
		}
	}

}
