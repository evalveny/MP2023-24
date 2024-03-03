#include "complex.h"
#include <iostream>

using namespace std;

void calcula(const Complex& c1, const Complex& c2, char operacio)
{
    Complex c3;
    if (operacio == '+')
        c3 = c1.suma(c2);
    else
        if (operacio == '-')
            c3 = c1.resta(c2);
        else
            c3 = c1.multiplica(c2);
    c3.mostra();
}

int main()
{
	Complex a, b;
	char operacio;

	a.llegeix();
	b.llegeix();
	cin >> operacio;
	calcula(a, b, operacio);
	return 0;
}

