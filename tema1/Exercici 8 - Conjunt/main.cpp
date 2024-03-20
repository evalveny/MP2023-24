#include "Conjunt.h"
#include <iostream>
#include <sstream>
#include <streambuf>
#include <string>
#include <math.h>
using namespace std;

void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}

bool comparaConjuntArray(Conjunt& c, Estudiant* resultat, int longitud)
{
	bool iguals = (longitud == c.getNumElements());
	if (iguals)
	{
		int i = 0;
		while ((i < longitud) && iguals)
		{
			Estudiant estudiant(resultat[i].getNom(), resultat[i].getNiu());
			iguals = c.recuperaElement(estudiant);
			if (iguals && !((resultat[i].getNom() == estudiant.getNom()) && 
				(resultat[i].getNiu() == estudiant.getNiu()) &&
				(resultat[i].calculaNotaMitjana() == estudiant.calculaNotaMitjana())))
				iguals = false;
			else
				i++;
		}
	}
	return iguals;
}

void mostraVector(Estudiant v[], int mida)
{
	cout << "[";
	for (int i = 0; i < mida - 1; i++)
	{
		cout << "[" << v[i].getNom() << "," << v[i].getNiu() << "," << v[i].calculaNotaMitjana() << "]" << ", ";
	}
	if (mida > 0)
		cout << "[" << v[mida - 1].getNom() << "," << v[mida - 1].getNiu() << "," << v[mida - 1].calculaNotaMitjana() << "]";
	cout << "]";
}

void mostraConjunt(Conjunt& c)
{
	Estudiant array[MAX_ELEMENTS];
	int nElements = c.getNumElements();
	c.conjuntToArray(array, nElements);
	mostraVector(array, nElements);
}

void mostraBuffer(stringstream& buffer)
{
	string stringData;
	getline(buffer, stringData);
	while (stringData != "")
	{
		cout << "Comment :=>> " << stringData << endl;
		getline(buffer, stringData);
	}
}

float testInicialitzacioConjunt()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de la inicialitzacio de la classe Conjunt" << endl;
	cout << "Comment :=>> ======================================================" << endl;
	const int N_ELEMENTS = 5;
	Estudiant estudiantTest[N_ELEMENTS] =
	{
		{ "NOM_1", "NIU_1"},
		{ "NOM_2", "NIU_2"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_4", "NIU_4"},
		{ "NOM_5", "NIU_5"}
	};
	float notesTest[N_ELEMENTS] = { 5, 6, 7, 8, 9 };
	for (int i = 0; i < N_ELEMENTS; i++)
		estudiantTest[i].afegeixNota(notesTest[i]);

	cout << "Comment :=>> Inicialitzant el conjunt amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(estudiantTest, N_ELEMENTS); cout << endl;
	Conjunt c(estudiantTest, N_ELEMENTS);
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Contingut del conjunt despres d'inicialitzar (fa servir metodes conjuntToArray i getNumElements): " << endl;

	cout << "Comment :=>> ";  mostraConjunt(c); cout << endl;

	cout << "Comment :=>> ----------" << endl;
	bool iguals = comparaConjuntArray(c, estudiantTest, N_ELEMENTS);
	cout << "Comment :=>> Comprovant si contingut correcte (fa servir metodes recuperaElement i getNumElements)... " << endl;
	if (!iguals)
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 1.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;

	return reduccio;
}

float testPertany()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode pertany" << endl;
	cout << "Comment :=>> ================================" << endl;
	const int N_ELEMENTS = 5;
	Estudiant estudiantTest[N_ELEMENTS] =
	{
		{ "NOM_1", "NIU_1"},
		{ "NOM_2", "NIU_2"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_4", "NIU_4"},
		{ "NOM_5", "NIU_5"}
	};
	float notesTest[N_ELEMENTS] = { 5, 6, 7, 8, 9 };
	for (int i = 0; i < N_ELEMENTS; i++)
		estudiantTest[i].afegeixNota(notesTest[i]);

	const int N_PROVES = 5;
	Estudiant estudiantTestPertany[N_PROVES] =
	{
		{ "NOM_1", "NIU_1"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_5", "NIU_5"},
		{ "NOM_1", "NIU_5"},
		{ "NOM_5", "NIU_1"}
	};
	bool resultatEsperat[N_PROVES] = { true, true, true, false, false };

	cout << "Comment :=>> Inicialitzant el conjunt amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(estudiantTest, N_ELEMENTS); cout << endl;
	Conjunt c(estudiantTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Estudiant a buscar dins del conjunt: " << estudiantTestPertany[i].getNom() << ", " << estudiantTestPertany[i].getNiu() << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valor retorn esperat: " ; mostraBool(resultatEsperat[i]); cout <<  endl;
		cout << "Comment :=>> ---" << endl;
		bool resultat = c.pertany(estudiantTestPertany[i]);
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
		if (resultat == resultatEsperat[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}


float testRecuperaElement()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode recuperaElement" << endl;
	cout << "Comment :=>> ========================================" << endl;
	const int N_ELEMENTS = 5;
	Estudiant estudiantTest[N_ELEMENTS] =
	{
		{ "NOM_1", "NIU_1"},
		{ "NOM_2", "NIU_2"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_4", "NIU_4"},
		{ "NOM_5", "NIU_5"}
	};
	float notesTest[N_ELEMENTS] = { 5, 6, 7, 8, 9 };
	for (int i = 0; i < N_ELEMENTS; i++)
		estudiantTest[i].afegeixNota(notesTest[i]);

	const int N_PROVES = 5;
	Estudiant elementsCerca[N_PROVES] = 
	{
		{ "NOM_1", "NIU_1"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_5", "NIU_5"},
		{ "NOM_2", "NIU_1"},
		{ "NOM_1", "NIU_6"}
	};

	Estudiant estudiantEsperat[N_PROVES] = 
	{
		{ "NOM_1", "NIU_1"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_5", "NIU_5"},
		{ "", ""},
		{ "", ""}
	};
	bool resultatEsperat[N_PROVES] = { true, true, true, false, false };
	float notaEsperada[N_PROVES] = { 5, 7, 9, -1, -1 };
	cout << "Comment :=>> Inicialitzant el conjunt amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(estudiantTest, N_ELEMENTS); cout << endl;
	Conjunt c(estudiantTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Valors a recuperar: " << elementsCerca[i].getNom() << ", " << elementsCerca[i].getNiu() << endl;
		cout << "Comment :=>> ---" << endl;
		if (resultatEsperat[i])
			cout << "Comment :=>> Estudiant esperat: " << estudiantEsperat[i].getNom() << ", " << estudiantEsperat[i].getNiu() << ", " << estudiantEsperat[i].calculaNotaMitjana() << endl;
		cout << "Comment :=>> Valor retorn esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
		cout << "Comment :=>> ---" << endl;
		bool resultat = c.recuperaElement(elementsCerca[i]);
		if (resultat)
			cout << "Comment :=>> Estudiant obtingut: " << elementsCerca[i].getNom() << ", " << elementsCerca[i].getNiu() << ", " << elementsCerca[i].calculaNotaMitjana() << endl;
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
		if (resultat == resultatEsperat[i])
			if (resultat)
				if ((elementsCerca[i].getNom() == estudiantEsperat[i].getNom()) &&
					(elementsCerca[i].getNiu() == estudiantEsperat[i].getNiu()) &&
					(elementsCerca[i].calculaNotaMitjana() == notaEsperada[i]))
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 1.0;
				}
			else
				cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}


float testOperadorSumaIgual()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test operador += (afegir un element)" << endl;
	cout << "Comment :=>> =============================================" << endl;
	cout << "Comment :=>> Inicialitzant el conjunt buit (amb el constructor per defecte): " << endl;
	Conjunt c;

	const int N_PROVES = 5;
	const int N_ELEMENTS = 5;
	Estudiant estudiantTest[N_PROVES] =
	{
		{ "NOM_1", "NIU_1"},
		{ "NOM_2", "NIU_2"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_4", "NIU_4"},
		{ "NOM_4", "NIU_4"},
	};
	Estudiant resultatEsperat[N_PROVES][N_ELEMENTS] =
	{
		{
			{ "NOM_1", "NIU_1"}
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_2", "NIU_2"}
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_2", "NIU_2"},
			{ "NOM_3", "NIU_3"}
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_2", "NIU_2"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"}
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_2", "NIU_2"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"}
		}
	};
	int nElementsEsperats[N_PROVES] = { 1, 2, 3, 4, 4 };
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Estudiant a afegir: " << estudiantTest[i].getNom() << ", " << estudiantTest[i].getNiu() << endl;
		cout << "Comment :=>> ---" << endl;
		c += estudiantTest[i];
		cout << "Comment :=>> Conjunt resultat esperat: " << endl;
		cout << "Comment :=>> "; mostraVector(resultatEsperat[i], nElementsEsperats[i]); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Conjunt resultat obtingut: " << endl;
			cout << "Comment :=>> ";  mostraConjunt(c); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		bool iguals = comparaConjuntArray(c, resultatEsperat[i], nElementsEsperats[i]);
		cout << "Comment :=>> Comprovant si contingut correcte ... " << endl;
		if (iguals)
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}

	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}

float testOperadorRestaIgual()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test operador -= (eliminar un element)" << endl;
	cout << "Comment :=>> ===============================================" << endl;

	const int N_PROVES = 7;
	const int N_ELEMENTS = 4;

	Estudiant estudiantTest[N_ELEMENTS] =
	{
		{ "NOM_1", "NIU_1"},
		{ "NOM_2", "NIU_2"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_4", "NIU_4"}
	};
	Estudiant estudiantEliminar[N_PROVES] = 
	{
		{ "NOM_5", "NIU_5"}, 
		{ "NOM_2", "NIU_2"},
		{ "NOM_1", "NIU_1"},
		{ "NOM_1", "NIU_1"},
		{ "NOM_4", "NIU_4"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_3", "NIU_3"}
	};
	Estudiant resultatEsperat[N_PROVES][N_ELEMENTS] =
	{
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_2", "NIU_2"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"}		
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"}
		},
		{
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"}
		},
		{
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"}
		},
		{
			{ "NOM_3", "NIU_3"},
		},
		{
		},
		{
		}
	};
	int nElementsEsperats[N_PROVES] = { 4, 3, 2, 2, 1, 0, 0 };
	cout << "Comment :=>> Inicialitzant el conjunt amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(estudiantTest, N_ELEMENTS); cout << endl;
	Conjunt c(estudiantTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Estudiant a eliminar: " << estudiantEliminar[i].getNom() << ", " << estudiantEliminar[i].getNiu() << endl;
		cout << "Comment :=>> ----------" << endl;
		c -= estudiantEliminar[i];
		cout << "Comment :=>> Conjunt resultat esperat: " << endl;
		cout << "Comment :=>> "; mostraVector(resultatEsperat[i], nElementsEsperats[i]); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Conjunt resultat obtingut: " << endl;
			cout << "Comment :=>> ";  mostraConjunt(c); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		bool iguals = comparaConjuntArray(c, resultatEsperat[i], nElementsEsperats[i]);
		cout << "Comment :=>> Comprovant si contingut correcte ... " << endl;
		if (iguals)
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}

	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}


float testUnio()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test operador + (unio conjunts)" << endl;
	cout << "Comment :=>> ========================================" << endl;

	const int N_PROVES = 5;
	const int N_ELEMENTS = 6;

	Estudiant conjunt1[N_ELEMENTS] =
	{
			{ "NOM_1", "NIU_1"},
			{ "NOM_2", "NIU_2"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"}
	};
	int nElementsConjunt1 = 4;

	Estudiant conjunt2[N_PROVES][N_ELEMENTS] =
	{
		{
			{ "NOM_5", "NIU_5"},
			{ "NOM_6", "NIU_6"}
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_5", "NIU_5"},
			{ "NOM_6", "NIU_6"}
		},
		{
		},
		{
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"}
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_5", "NIU_5"},
			{ "NOM_6", "NIU_6"},
			{ "NOM_2", "NIU_2"},
			{ "NOM_4", "NIU_4"}
		}
	};
	int nElementsConjunt2[N_PROVES] = { 2, 4, 0, 2, 6 };

	Estudiant resultatTest[N_PROVES][N_ELEMENTS] =
	{
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_2", "NIU_2"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"},
			{ "NOM_5", "NIU_5"},
			{ "NOM_6", "NIU_6"}
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_2", "NIU_2"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"},
			{ "NOM_5", "NIU_5"},
			{ "NOM_6", "NIU_6"}
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_2", "NIU_2"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"}
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_2", "NIU_2"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"}
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_2", "NIU_2"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"},
			{ "NOM_5", "NIU_5"},
			{ "NOM_6", "NIU_6"}
		}
	};
	int nElementsEsperats[N_PROVES] = { 6, 6, 4, 4, 6 };
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Conjunt 1: " << endl;
		cout << "Comment :=>> "; mostraVector(conjunt1, nElementsConjunt1); cout << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Conjunt 2: " << endl;
		cout << "Comment :=>> "; mostraVector(conjunt2[i], nElementsConjunt2[i]); cout << endl;
		Conjunt c1(conjunt1, nElementsConjunt1);
		Conjunt c2(conjunt2[i], nElementsConjunt2[i]);
		Conjunt c3 = c1 + c2;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Conjunt resultat esperat: " << endl;
		cout << "Comment :=>> "; mostraVector(resultatTest[i], nElementsEsperats[i]); cout << endl;
		cout << "Comment :=>> --------------------" << endl;
		cout << "Comment :=>> Conjunt resultat obtingut: " << endl;
		cout << "Comment :=>> ";  mostraConjunt(c3); cout << endl;
		cout << "Comment :=>> --------------------" << endl;
		bool iguals = comparaConjuntArray(c3, resultatTest[i], nElementsEsperats[i]);
		cout << "Comment :=>> Comprovant si contingut correcte ... " << endl;
		if (iguals)
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> ------------------------------------------------------------" << endl;
	}
	return reduccio;
}

float testInterseccio()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test operador * (interseccio conjunts)" << endl;
	cout << "Comment :=>> ===============================================" << endl;

	const int N_PROVES = 5;
	const int N_ELEMENTS = 6;

	Estudiant conjunt1[N_ELEMENTS] =
	{
			{ "NOM_1", "NIU_1"},
			{ "NOM_2", "NIU_2"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"}
	};
	int nElementsConjunt1 = 4;

	Estudiant conjunt2[N_PROVES][N_ELEMENTS] =
	{
		{
			{ "NOM_5", "NIU_5"},
			{ "NOM_6", "NIU_6"}
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_5", "NIU_5"},
			{ "NOM_6", "NIU_6"}
		},
		{
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"},
			{ "NOM_2", "NIU_2"}
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_5", "NIU_5"},
			{ "NOM_6", "NIU_6"},
			{ "NOM_2", "NIU_2"},
			{ "NOM_4", "NIU_4"}
		}
	};
	int nElementsConjunt2[N_PROVES] = { 2, 4, 0, 4, 6 };

	Estudiant resultatTest[N_PROVES][N_ELEMENTS] =
	{
		{
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_3", "NIU_3"},
		},
		{
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_2", "NIU_2"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"}
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_2", "NIU_2"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_4", "NIU_4"}
		}
	};
	int nElementsEsperats[N_PROVES] = { 0, 2, 0, 4, 4 };
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Conjunt 1: " << endl;
		cout << "Comment :=>> "; mostraVector(conjunt1, nElementsConjunt1); cout << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Conjunt 2: " << endl;
		cout << "Comment :=>> "; mostraVector(conjunt2[i], nElementsConjunt2[i]); cout << endl;
		Conjunt c1(conjunt1, nElementsConjunt1);
		Conjunt c2(conjunt2[i], nElementsConjunt2[i]);
		Conjunt c3 = c1 * c2;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Conjunt resultat esperat: " << endl;
		cout << "Comment :=>> "; mostraVector(resultatTest[i], nElementsEsperats[i]); cout << endl;
		cout << "Comment :=>> --------------------" << endl;
		cout << "Comment :=>> Conjunt resultat obtingut: " << endl;
		cout << "Comment :=>> ";  mostraConjunt(c3); cout << endl;
		cout << "Comment :=>> ---------------------" << endl;
		bool iguals = comparaConjuntArray(c3, resultatTest[i], nElementsEsperats[i]);
		cout << "Comment :=>> Comprovant si contingut correcte ... " << endl;
		if (iguals)
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> ---------------------------------------------------------------" << endl;
	}
	return reduccio;
}

float testSortidaPantalla()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test operador << de sortida a pantalla" << endl;
	cout << "Comment :=>> ===============================================" << endl;

	const int N_ELEMENTS = 4;
	Estudiant estudiantTest[N_ELEMENTS] =
	{
		{ "NOM_1", "NIU_1"},
		{ "NOM_2", "NIU_2"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_4", "NIU_4"}
	};
	float notesTest[N_ELEMENTS] = { 5, 6, 7, 8};
	for (int i = 0; i < N_ELEMENTS; i++)
		estudiantTest[i].afegeixNota(notesTest[i]);

	string resultatEsperat[N_ELEMENTS] = { "NOM_1 NIU_1 5", "NOM_2 NIU_2 6", "NOM_3 NIU_3 7", "NOM_4 NIU_4 8"};

	cout << "Comment :=>> Inicialitzant el conjunt amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(estudiantTest, N_ELEMENTS); cout << endl;
	Conjunt c(estudiantTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;

	cout << "Comment :=>> Escrivint el conjunt a la sortida estàndard amb cout ...." << endl;
	ofstream fitxerTestOut;
	string nomFitxerOut = "test_conjunt_cout.txt";
	fitxerTestOut.open(nomFitxerOut);
	streambuf* buffer_cout = cout.rdbuf(fitxerTestOut.rdbuf());
	cout << c;
	cout.rdbuf(buffer_cout);
	fitxerTestOut.close();

	cout << "Comment :=>> -----" << endl;
	cout << "Comment :=>> Resultat esperat: " << endl;
	for (int i = 0; i < N_ELEMENTS; i++)
		cout << "Comment :=>> " << resultatEsperat[i] << endl;

	ifstream fitxerTestResultat;
	fitxerTestResultat.open(nomFitxerOut);
	string resultat;
	cout << "Comment :=>> -----" << endl;
	cout << "Comment :=>> Resultat obtingut: " << endl;
	bool error = false;
	for (int i = 0; i < N_ELEMENTS; i++)
	{
		getline(fitxerTestResultat, resultat);
		cout << "Comment :=>> " << resultat << endl;
		if (resultat != resultatEsperat[i])
			error = true;
	}
	fitxerTestResultat.close();

	if (!error)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 3;
	}

	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}


float testSortidaFitxer()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test operador << de escriptura a fitxer" << endl;
	cout << "Comment :=>> ================================================" << endl;

	const int N_ELEMENTS = 4;
	Estudiant estudiantTest[N_ELEMENTS] =
	{
		{ "NOM_1", "NIU_1"},
		{ "NOM_2", "NIU_2"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_4", "NIU_4"}
	};
	float notesTest[N_ELEMENTS] = { 5, 6, 7, 8 };
	for (int i = 0; i < N_ELEMENTS; i++)
		estudiantTest[i].afegeixNota(notesTest[i]);

	string resultatEsperat[N_ELEMENTS] = { "NOM_1 NIU_1 5", "NOM_2 NIU_2 6", "NOM_3 NIU_3 7", "NOM_4 NIU_4 8" };

	cout << "Comment :=>> Inicialitzant el conjunt amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(estudiantTest, N_ELEMENTS); cout << endl;
	Conjunt c(estudiantTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;

	cout << "Comment :=>> Escrivint el conjunt al fitxer amb l'operador << ...." << endl;
	ofstream fitxerTestOut;
	string nomFitxerOut = "test_conjunt_fitxer.txt";
	fitxerTestOut.open(nomFitxerOut);
	if (fitxerTestOut.is_open())
	{
		fitxerTestOut << c;
		fitxerTestOut.close();

		cout << "Comment :=>> -----" << endl;
		cout << "Comment :=>> Resultat esperat: " << endl;
		for (int i = 0; i < N_ELEMENTS; i++)
			cout << "Comment :=>> " << resultatEsperat[i] << endl;

		ifstream fitxerTestResultat;
		fitxerTestResultat.open(nomFitxerOut);
		string resultat;
		cout << "Comment :=>> -----" << endl;
		cout << "Comment :=>> Resultat obtingut: " << endl;
		bool error = false;
		for (int i = 0; i < N_ELEMENTS; i++)
		{
			getline(fitxerTestResultat, resultat);
			cout << "Comment :=>> " << resultat << endl;
			if (resultat != resultatEsperat[i])
				error = true;
		}
		fitxerTestResultat.close();
		if (!error)
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 3;
		}
	}
	else
	{
		cout << "Comment :=>> ERROR OBRINT EL FITXER" << endl;
		reduccio += 3;
	}


	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}

float testLecturaFitxer()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test operador >> de lectura de fitxer" << endl;
	cout << "Comment :=>> ==============================================" << endl;

	const int N_ELEMENTS = 4;
	Estudiant estudiantTest[N_ELEMENTS] =
	{
		{ "NOM_1", "NIU_1"},
		{ "NOM_2", "NIU_2"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_4", "NIU_4"}
	};
	int nNotesTest[N_ELEMENTS] = { 1, 0, 2, 3 };
	float notesTest[N_ELEMENTS][MAX_NOTES] = 
	{
		{ 5 },
		{ },
		{6, 8 },
		{5, 7, 9}
	};
	for (int i = 0; i < N_ELEMENTS; i++)
		for (int j = 0; j < nNotesTest[i]; j++)
			estudiantTest[i].afegeixNota(notesTest[i][j]);

	cout << "Comment :=>> Llegint el conjunt del fitxer amb l'operador >> .... " << endl;
	Conjunt c;

	ifstream fitxerTestIn;
	string nomFitxerIn = "test_conjunt_fitxer_in.txt";
	fitxerTestIn.open(nomFitxerIn);
	if (fitxerTestIn.is_open())
	{
		fitxerTestIn >> c;
		fitxerTestIn.close();

		cout << "Comment :=>> " << endl;
		cout << "Comment :=>> Contingut esperat del conjunt: " << endl;
		cout << "Comment :=>> "; mostraVector(estudiantTest, N_ELEMENTS); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Contingut del conjunt despres llegir del fitxer: " << endl;
			cout << "Comment :=>> ";  mostraConjunt(c); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		bool iguals = comparaConjuntArray(c, estudiantTest, N_ELEMENTS);
		cout << "Comment :=>> Comprovant si contingut correcte ... " << endl;
		if (!iguals)
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 3.0;
		}
		else
			cout << "Comment :=>> CORRECTE" << endl;

	}
	else
	{
		cout << "Comment :=>> ERROR OBRINT EL FITXER" << endl;
		reduccio += 3;
	}


	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}




int main()
{
	float grade = 0.0;
	float reduccio;

	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;

	reduccio = testInicialitzacioConjunt();
	grade = grade + (1.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testPertany();
	grade = grade + (1.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testRecuperaElement();
	grade = grade + (1.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testOperadorSumaIgual();
	grade = grade + (1.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testOperadorRestaIgual();
	grade = grade + (1.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testUnio();
	grade = grade + (1.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testInterseccio();
	grade = grade + (1.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testSortidaPantalla();
	grade = grade + (1.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testSortidaFitxer();
	grade = grade + (1.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testLecturaFitxer();
	grade = grade + (1.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	if (grade < 0)
		grade = 0.0;
	cout << "Grade :=>> " << grade << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	return 0;

}