#include <iostream>
using namespace std;

const int MAX = 5;

void sumaVectors(int* p1, int* p2, int* pSuma, int nElements)
{
	for (int i = 0; i < nElements; i++)
		pSuma[i] = p1[i] + p2[i];
}

void llegeixVector(int* v, int nElements)
{
	for (int i = 0; i < nElements; i++)
	{
		cout << "Introdueix valor " <<
			i + 1 << " del vector: ";
		cin >> v[i];
	}
}


void mostraVector(int* v, int nElements)
{
	for (int i = 0; i < nElements; i++)
		cout << v[i] << " ";
	cout << endl;
}


    int main()
    {
        int *v1, *v2, *vSuma;
        int nElements;

        cout << "Quants elements han de tenir els vectors ? ";
        cin >> nElements;

        // CREAR ELS 3 ARRAYS DINAMICS v1, v2 i vSuma



        // LLEGIR ELS ELEMENTES DE v1 i v2 CRIDANT A llegeixVector
        llegeixVector(                   );
        llegeixVector(	                  );


        // SUMAR v1 i v2 GUARDANT EL RESULTAT A vSuma CRIDANT A sumaVectors
        sumaVectors(                      );

        cout << "Suma dels vectors: ";
        // MOSTRAR EL RESULTAT DE vSuma CRIDANT A mostraVector
        mostraVector(                  );

        // ALLIBERAR ELS 3 ARRAYS DIN�MICS





        return 0;
    }

