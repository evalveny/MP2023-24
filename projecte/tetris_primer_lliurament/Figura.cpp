#include "Figura.h"

void::Figura::resetForma()
{
	for (int i = 0; i < m_alcada; i++)
		for (int j = 0; j < m_amplada; j++)
			m_mascara[i][j] = 0;
}

void Figura::inicialitzaForma(TipusFigura tipus)
{
	switch (tipus)
	{
	case FIGURA_J:
		m_amplada = 3;
		m_alcada = 3;
		resetForma();
		m_mascara[0][0] = 1;
		m_mascara[1][0] = 1;
		m_mascara[1][1] = 1;
		m_mascara[1][2] = 1;
		m_color = COLOR_BLAUFOSC;
		break;
	case FIGURA_L:
		m_amplada = 3;
		m_alcada = 3;
		resetForma();
		m_mascara[0][2] = 1;
		m_mascara[1][0] = 1;
		m_mascara[1][1] = 1;
		m_mascara[1][2] = 1;
		m_color = COLOR_TARONJA;
		break;
	case FIGURA_S:
		m_amplada = 3;
		m_alcada = 3;
		resetForma();
		m_mascara[0][1] = 1;
		m_mascara[0][2] = 1;
		m_mascara[1][0] = 1;
		m_mascara[1][1] = 1;
		m_color = COLOR_VERD;
		break;
	case FIGURA_Z:
		m_amplada = 3;
		m_alcada = 3;
		resetForma();
		m_mascara[0][0] = 1;
		m_mascara[0][1] = 1;
		m_mascara[1][1] = 1;
		m_mascara[1][2] = 1;
		m_color = COLOR_VERMELL;
		break;
	case FIGURA_T:
		m_amplada = 3;
		m_alcada = 3;
		resetForma();
		m_mascara[0][1] = 1;
		m_mascara[1][0] = 1;
		m_mascara[1][1] = 1;
		m_mascara[1][2] = 1;
		m_color = COLOR_MAGENTA;
		break;
	case FIGURA_I:
		m_amplada = 4;
		m_alcada = 4;
		resetForma();
		m_mascara[1][0] = 1;
		m_mascara[1][1] = 1;
		m_mascara[1][2] = 1;
		m_mascara[1][3] = 1;
		m_color = COLOR_BLAUCEL;
		break;
	case FIGURA_O:
		m_amplada = 2;
		m_alcada = 2;
		m_mascara[0][0] = 1;
		m_mascara[0][1] = 1;
		m_mascara[1][0] = 1;
		m_mascara[1][1] = 1;
		m_color = COLOR_GROC;
		break;
	}
}

void Figura::inicialitza(TipusFigura tipus, int fila, int columna)
{
	m_tipus = tipus;
	m_fila = fila;
	m_columna = columna;
	m_gir = 0;
	inicialitzaForma(tipus);
}

void Figura::getMascara(int mascara[MAX_ALCADA][MAX_AMPLADA]) const
{
	for (int i = 0; i < m_alcada; i++)
		for (int j = 0; j < m_amplada; j++)
			mascara[i][j] = m_mascara[i][j];
}

void Figura::mou(int dirX)
{
	m_columna += dirX;
}

void Figura::baixa()
{
	m_fila += 1;
}

void Figura::puja()
{
	m_fila -= 1;
}

void Figura::gira(DireccioGir direccio)
{
	transposaMascara();
	if (direccio == GIR_HORARI)
	{
		inverteixMascaraVertical();
		m_gir = (m_gir + 1) % 4;
	}
	else
	{
		inverteixMascaraHorizontal();
		m_gir = (m_gir - 1) % 4;
	}
		
}


void Figura::transposaMascara()
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

void Figura::inverteixMascaraVertical()
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

void Figura::inverteixMascaraHorizontal()
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
