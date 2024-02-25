#pragma once

class Complex
{
public:
	Complex() { m_real = 0; m_img = 0; }
	float getReal(); //TO VALIDATE TEST
	float getImg(); //TO VALIDATE TEST
	void setReal(float pReal); //TO VALIDATE TEST
	void setImg(float PImg); //TO VALIDATE TEST
	void mostra();
	Complex suma(Complex &c);
	Complex resta(Complex &c);
	Complex multiplica(Complex &c);
	
	float m_real, m_img;
};

Complex avaluaOperacio(const char operacio, Complex& c1, Complex& c2);
