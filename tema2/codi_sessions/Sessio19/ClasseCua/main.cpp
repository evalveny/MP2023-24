#include "Cua.h"
#include <iostream>
using namespace std;



int main()
{
	Cua c;

	for (int i = 0; i < 10; i++)
		c.afegeix(i);
	c.treu();
	c.treu();
	c.treu();

	int primer = c.getPrimer();
	int ultim = c.getUltim();

	cout << "Primer valor: " << primer << ", Ultim valor: " << ultim << endl;
	return 0;
}