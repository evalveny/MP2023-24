#include "complex.h"
#include <iostream>
using namespace std;

void Complex::setReal(float pReal)
{
	m_real=pReal;
}

void Complex::setImg(float pImg)
{
	m_img=pImg;
}

float Complex::getReal()
{
	return m_real;
}

float Complex::getImg()
{
	return m_img;
}

void Complex::mostra() 
{
	cout << m_real << "+" << m_img << "i";
}


Complex Complex::suma(Complex &c)
{
	Complex resultat;

	resultat.m_real = m_real + c.m_real;
	resultat.m_img = m_img + c.m_img;
	return resultat;
}

Complex Complex::resta(Complex &c)
{
	Complex resultat;

	resultat.m_real = m_real - c.m_real;
	resultat.m_img = m_img - c.m_img;
	return resultat;
}

Complex Complex::multiplica(Complex &c)
{
	Complex resultat;

	resultat.m_real = (m_real*c.m_real) - (m_img*c.m_img);
	resultat.m_img = (m_real*c.m_img) + (m_img*c.m_real);
	return resultat;
}

Complex avaluaOperacio(const char operacio, Complex& c1, Complex& c2)
{
	Complex resultat;

	switch (operacio)
	{
	case '1':
		resultat = c1.suma(c2);
		break;
	case '2':
		resultat = c1.resta(c2);
		break;
	case '3':
		resultat = c1.multiplica(c2);
		break;
	}
	return resultat;
};
