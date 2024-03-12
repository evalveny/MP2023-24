#include "Joc.h"

int main()
{
	Joc joc;

	joc.inicialitza("joc_inicial.txt");
	joc.escriuTauler("joc_final.txt");
	return 0;
}