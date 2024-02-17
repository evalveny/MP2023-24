#include "binari.h"
#include <math.h>

int BinariADecimal(int binari[], int longitud)
{
    int valor = 0;
    int potencia = 1;
    for (int i = 1; i < longitud; i++)
    {
        potencia *= 2;
        valor = (2 * valor) + binari[i];
    }
    if (binari[0] == 1)
        valor -= potencia;
    return valor;
}

//int BinariADecimal(int binari[], int longitud)
//{
//    int valor = 0;
//    int potencia = 1;
//    for (int i = (longitud - 1); i > 0; i--)
//    {
//        valor += binari[i] * potencia;
//        potencia *= 2;
//    }
//    if (binari[0] == 1)
//        valor -= potencia;
//    return valor;
//}

//int BinariADecimal(int binari[], int longitud)
//{
//    int valor = 0;
//    for (int i = (longitud - 1); i > 0; i--)
//        valor += binari[i] * pow(2, (longitud - 1 - i));
//    if (binari[0] == 1)
//        valor -= pow(2, longitud - 1);
//    return valor;
//}