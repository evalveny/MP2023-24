#include "llista.h"
#include "assignatura.h"
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

bool comparaLlistes(Llista& l, Estudiant* resultat, int longitud)
{
	bool iguals = (longitud == l.getNumElements());
	if (iguals)
	{
		int i = 0;
		while ((i < longitud) && iguals)
		{
			Estudiant estudiant = l.getElement(i);
			if (!((resultat[i].getNom() == estudiant.getNom()) && 
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

void mostraLlista(Llista& l)
{
	cout << "[";
	for (int i = 0; i < l.getNumElements() - 1; i++)
	{
		Estudiant e = l.getElement(i);
		cout << "[" << e.getNom() << "," << e.getNiu() << "," << e.calculaNotaMitjana() << "]" << ", ";
	}
	if (l.getNumElements() > 0)
	{
		Estudiant e = l.getElement(l.getNumElements() - 1);
		cout << "[" << e.getNom() << "," << e.getNiu() << "," << e.calculaNotaMitjana() << "]";

	}
	cout << "]";
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

float testInicialitzacioLlista()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de la inicialitzacio de la classe Llista" << endl;
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

	cout << "Comment :=>> Inicialitzant la llista amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(estudiantTest, N_ELEMENTS); cout << endl;
	Llista l(estudiantTest, N_ELEMENTS);
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Contingut de la llista despres d'inicialitzar (fa servir metodes getElement i getNumElements): " << endl;

	cout << "Comment :=>> ";  mostraLlista(l); cout << endl;

	cout << "Comment :=>> ----------" << endl;
	bool iguals = comparaLlistes(l, estudiantTest, N_ELEMENTS);
	cout << "Comment :=>> Comprovant si contingut correcte (fa servir metodes getElement i getNumElements)... " << endl;
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

	cout << "Comment :=>> Inicialitzant la llista amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(estudiantTest, N_ELEMENTS); cout << endl;
	Llista l(estudiantTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Estudiant a buscar dins la llista: " << estudiantTestPertany[i].getNom() << ", " << estudiantTestPertany[i].getNiu() << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valor retorn esperat: " ; mostraBool(resultatEsperat[i]); cout <<  endl;
		cout << "Comment :=>> ---" << endl;
		bool resultat = l.pertany(estudiantTestPertany[i]);
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

float testCerca()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode cerca" << endl;
	cout << "Comment :=>> ==============================" << endl;
	const int N_ELEMENTS = 5;
	Estudiant estudiantTest[N_ELEMENTS] =
	{
		{ "NOM_1", "NIU_1"},
		{ "NOM_2", "NIU_2"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_4", "NIU_4"},
		{ "NOM_5", "NIU_5"}
	};

	const int N_PROVES = 4;
	string estudiantTestPertany[N_PROVES] = { "NIU_1", "NIU_3", "NIU_5", "NIU_6"};
	int resultatEsperat[N_PROVES] = { 0, 2, 4, -1};

	cout << "Comment :=>> Inicialitzant la llista amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(estudiantTest, N_ELEMENTS); cout << endl;
	Llista l(estudiantTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Cerca de l'estudiant amb niu: " << estudiantTestPertany[i] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valor retorn esperat: " << resultatEsperat[i] << endl;
		cout << "Comment :=>> ---" << endl;
		int resultat = l.cerca(estudiantTestPertany[i]);
		cout << "Comment :=>> Valor retorn obtingut: " << resultat << endl;
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

float testGetElement()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode getElement" << endl;
	cout << "Comment :=>> ===================================" << endl;
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
	int posicio[N_PROVES] = { 0, 2, 4, -1, 5 };
	Estudiant resultatEsperat[N_PROVES] = 
	{
		{ "NOM_1", "NIU_1"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_5", "NIU_5"},
		{ "", ""},
		{ "", ""}
	};
	float notaEsperada[N_PROVES] = { 5, 7, 9, -1, -1 };
	cout << "Comment :=>> Inicialitzant la llista amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(estudiantTest, N_ELEMENTS); cout << endl;
	Llista l(estudiantTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Posicio de la llista a retornar: " << posicio[i] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valor retorn esperat: " << resultatEsperat[i].getNom() << ", " << resultatEsperat[i].getNiu() << ", " << notaEsperada[i] << endl;
		cout << "Comment :=>> ---" << endl;
		Estudiant resultat = l.getElement(posicio[i]);
		cout << "Comment :=>> Valor retorn obtingut: " << resultat.getNom() << ", " << resultat.getNiu() << ", " << resultat.calculaNotaMitjana() << endl;
		if (((resultat.getNom() == resultatEsperat[i].getNom()) &&
			(resultat.getNiu() == resultatEsperat[i].getNiu()) &&
			(resultat.calculaNotaMitjana() == notaEsperada[i])))
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


float testOperadorSuma()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test operador +" << endl;
	cout << "Comment :=>> ========================" << endl;
	cout << "Comment :=>> Inicialitzant la llista buida (amb el constructor per defecte): " << endl;
	Llista l;

	const int N_PROVES = 4;
	const int N_ELEMENTS = 4;
	Estudiant estudiantTest[N_PROVES] =
	{
		{ "NOM_1", "NIU_1"},
		{ "NOM_2", "NIU_2"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_4", "NIU_4"}
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
		}
	};
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Estudiant a afegir: " << estudiantTest[i].getNom() << ", " << estudiantTest[i].getNiu() << endl;
		cout << "Comment :=>> ---" << endl;
		bool resultat = l + estudiantTest[i];
		cout << "Comment :=>> Llista resultat esperada: " << endl;
		cout << "Comment :=>> "; mostraVector(resultatEsperat[i], i + 1); cout << endl;
		cout << "Comment :=>> Valor retorn esperat: "; mostraBool(true); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Llista resultat obtinguda: " << endl;
			cout << "Comment :=>> ";  mostraLlista(l); cout << endl;
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		bool iguals = comparaLlistes(l, resultatEsperat[i], i + 1);
		cout << "Comment :=>> Comprovant si contingut correcte ... " << endl;
		if (iguals && resultat)
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	cout << "Comment :=>> ------------------------------------------" << endl;
	cout << "Comment :=>> Afegint elements fins a omplir la llista ..." << endl;
	for (int i = N_PROVES; i < 100; i++)
		bool resultat = l + estudiantTest[0];
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Afegint un element a la llista plena ..." << endl;
	bool resultat = l + estudiantTest[0];
	cout << "Comment :=>> Valor retorn esperat: "; mostraBool(false); cout << endl;
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
	cout << "Comment :=>> ----------" << endl;
	if (!resultat)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 1.0;
	}

	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}

float testOperadorResta()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test operador -" << endl;
	cout << "Comment :=>> ========================" << endl;

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
	Estudiant llistaEsperada[N_PROVES][N_ELEMENTS] =
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
	bool resultatEsperat[N_PROVES] = { false, true, true, false, true, true, false };
	int nElementsEsperats[N_PROVES] = { 4, 3, 2, 2, 1, 0, 0 };
	cout << "Comment :=>> Inicialitzant la llista amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(estudiantTest, N_ELEMENTS); cout << endl;
	Llista l(estudiantTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Estudiant a eliminar: " << estudiantEliminar[i].getNom() << ", " << estudiantEliminar[i].getNiu() << endl;
		cout << "Comment :=>> ----------" << endl;
		bool resultat = l - estudiantEliminar[i];
		cout << "Comment :=>> Llista resultat esperada: " << endl;
		cout << "Comment :=>> "; mostraVector(llistaEsperada[i], nElementsEsperats[i]); cout << endl;
		cout << "Comment :=>> Valor retorn esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Llista resultat obtinguda: " << endl;
			cout << "Comment :=>> ";  mostraLlista(l); cout << endl;
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		bool iguals = comparaLlistes(l, llistaEsperada[i], nElementsEsperats[i]);
		cout << "Comment :=>> Comprovant si contingut correcte ... " << endl;
		if (iguals && (resultat == resultatEsperat[i]))
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


float testInsereix()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test metode insereix" << endl;
	cout << "Comment :=>> =============================" << endl;
	cout << "Comment :=>> Inicialitzant la llista buida (amb el constructor per defecte): " << endl;
	Llista l;

	const int N_PROVES = 7;
	const int N_ELEMENTS = 5;
	Estudiant estudiantTest[N_PROVES] =
	{
		{ "NOM_1", "NIU_1"},
		{ "NOM_2", "NIU_2"},
		{ "NOM_2", "NIU_2"},
		{ "NOM_2", "NIU_2"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_4", "NIU_4"},
		{ "NOM_5", "NIU_5"}
	};
	int posicioTest[N_PROVES] = { 0, 1, 3, -1, 1, 1, 0 };
	Estudiant llistaEsperada[N_PROVES][N_ELEMENTS] =
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
			{ "NOM_2", "NIU_2"}
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_2", "NIU_2"}
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_2", "NIU_2"}
		},
		{
			{ "NOM_1", "NIU_1"},
			{ "NOM_4", "NIU_4"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_2", "NIU_2"}
		},
		{
			{ "NOM_5", "NIU_5"},
			{ "NOM_1", "NIU_1"},
			{ "NOM_4", "NIU_4"},
			{ "NOM_3", "NIU_3"},
			{ "NOM_2", "NIU_2"}
		}
	};
	bool resultatEsperat[N_PROVES] = { true, true, false, false, true, true, true };
	int nElementsEsperats[N_PROVES] = { 1, 2, 2, 2, 3, 4, 5 };
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Estudiant a afegir: " << estudiantTest[i] << endl;
		cout << "Comment :=>> Posicio: " << posicioTest[i] << endl;
		cout << "Comment :=>> ---" << endl;
		bool resultat = l.insereix(estudiantTest[i], posicioTest[i]);
		cout << "Comment :=>> Llista resultat esperada: " << endl;
		cout << "Comment :=>> "; mostraVector(llistaEsperada[i], nElementsEsperats[i]); cout << endl;
		cout << "Comment :=>> Valor retorn esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Llista resultat obtinguda: " << endl;
			cout << "Comment :=>> ";  mostraLlista(l); cout << endl;
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		bool iguals = comparaLlistes(l, llistaEsperada[i], nElementsEsperats[i]);
		cout << "Comment :=>> Comprovant si contingut correcte ... " << endl;
		if (iguals && (resultat == resultatEsperat[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	cout << "Comment :=>> ------------------------------------------" << endl;
	cout << "Comment :=>> Afegint elements fins a omplir la llista ..." << endl;
	for (int i = 5; i < 100; i++)
		bool resultat = l.insereix(estudiantTest[0], 0);
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Afegint un element a la llista plena ..." << endl;
	bool resultat = l.insereix(estudiantTest[0], 0);
	cout << "Comment :=>> Valor retorn esperat: "; mostraBool(false); cout << endl;
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
	cout << "Comment :=>> ----------" << endl;
	if (!resultat)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 1.0;
	}

	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}

float testElimina()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test metode elimina" << endl;
	cout << "Comment :=>> ============================" << endl;

	const int N_PROVES = 7;
	const int N_ELEMENTS = 4;
	Estudiant estudiantTest[N_ELEMENTS] =
	{
		{ "NOM_1", "NIU_1"},
		{ "NOM_2", "NIU_2"},
		{ "NOM_3", "NIU_3"},
		{ "NOM_4", "NIU_4"}
	};
	int posicioEliminar[N_PROVES] = { -1, 1, 3, 0, 1, 0, 1 };
	Estudiant llistaEsperada[N_PROVES][N_ELEMENTS] =
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
		},
		{
		},
		{
		}
	};
	bool resultatEsperat[N_PROVES] = { false, true, false, true, true, true, false };
	int nElementsEsperats[N_PROVES] = { 4, 3, 3, 2, 1, 0, 0 };
	cout << "Comment :=>> Inicialitzant la llista amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(estudiantTest, N_ELEMENTS); cout << endl;
	Llista l(estudiantTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Posicio a eliminar: " << posicioEliminar[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		bool resultat = l.elimina(posicioEliminar[i]);
		cout << "Comment :=>> Llista resultat esperada: " << endl;
		cout << "Comment :=>> "; mostraVector(llistaEsperada[i], nElementsEsperats[i]); cout << endl;
		cout << "Comment :=>> Valor retorn esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Llista resultat obtinguda: " << endl;
			cout << "Comment :=>> ";  mostraLlista(l); cout << endl;
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		bool iguals = comparaLlistes(l, llistaEsperada[i], nElementsEsperats[i]);
		cout << "Comment :=>> Comprovant si contingut correcte ... " << endl;
		if (iguals && (resultat == resultatEsperat[i]))
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

	cout << "Comment :=>> Inicialitzant la llista amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(estudiantTest, N_ELEMENTS); cout << endl;
	Llista l(estudiantTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;

	cout << "Comment :=>> Escrivint la llista a la sortida estàndard amb cout ...." << endl;
	ofstream fitxerTestOut;
	string nomFitxerOut = "test_llista_cout.txt";
	fitxerTestOut.open(nomFitxerOut);
	streambuf* buffer_cout = cout.rdbuf(fitxerTestOut.rdbuf());
	cout << l;
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

	cout << "Comment :=>> Inicialitzant la llista amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(estudiantTest, N_ELEMENTS); cout << endl;
	Llista l(estudiantTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;

	cout << "Comment :=>> Escrivint la llista al fitxer amb l'operador << ...." << endl;
	ofstream fitxerTestOut;
	string nomFitxerOut = "test_llista_fitxer.txt";
	fitxerTestOut.open(nomFitxerOut);
	if (fitxerTestOut.is_open())
	{
		fitxerTestOut << l;
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

	cout << "Comment :=>> Llegint la llista del fitxer amb l'operador >> .... " << endl;
	Llista l;

	ifstream fitxerTestIn;
	string nomFitxerIn = "test_llista_fitxer_in.txt";
	fitxerTestIn.open(nomFitxerIn);
	if (fitxerTestIn.is_open())
	{
		fitxerTestIn >> l;
		fitxerTestIn.close();

		cout << "Comment :=>> " << endl;
		cout << "Comment :=>> Contingut esperat de la llista: " << endl;
		cout << "Comment :=>> "; mostraVector(estudiantTest, N_ELEMENTS); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Contingut de la llista despres llegir del fitxer: " << endl;
			cout << "Comment :=>> ";  mostraLlista(l); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		bool iguals = comparaLlistes(l, estudiantTest, N_ELEMENTS);
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


float testAfegeixNota(Assignatura& assignatura)
{
	float reduccio = 0.0;
	const int N_PROVES = 9;
	string niu[N_PROVES] = { "NIU_1", "NIU_2", "NIU_3", "NIU_5", "NIU_2", "NIU_2", "NIU_2", "NIU_2", "NIU_2" };
	float nota[N_PROVES] = { 5.0, 4.5, 6.5, 7.5, 5, 5.5, 7.0, 8.0, 6.0 };
	bool resultatEsperat[N_PROVES] = { true, true, true, false, true, true, true, true, false };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << "Comment :=>> Test del metode afegeixNota " << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		bool resultat;

		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Niu estudiant: " << niu[i] << endl;
		cout << "Comment :=>> Nota introduida: " << nota[i] << endl;
		cout << "Comment :=>> ----------" << endl;

		resultat = assignatura.afegeixNota(niu[i], nota[i]);
		cout << "Comment :=>> Resultat esperat: ";
		mostraBool(resultatEsperat[i]);
		cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: ";
		mostraBool(resultat);
		cout << endl;
		cout << "Comment :=>> ----------" << endl;
		if (resultatEsperat[i] == resultat)
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	if (reduccio > 3.0)
		reduccio = 3.0;

	return reduccio;
}


float testCalculaNotaMitjana(Assignatura& assignatura)
{
	float reduccio = 0.0;
	const int N_PROVES = 4;
	string niu[N_PROVES] = { "NIU_1", "NIU_2", "NIU_4", "NIU_5" };
	float mitjanaEsperada[N_PROVES] = { 5.0, 6.0, -1.0, -1.0 };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << "Comment :=>> Test del metode calculaNotaMitjana " << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		float resultat;

		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Niu estudiant: " << niu[i] << endl;
		cout << "Comment :=>> ----------" << endl;

		resultat = assignatura.calculaNotaMitjana(niu[i]);
		cout << "Comment :=>> Resultat esperat: " << mitjanaEsperada[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: " << resultat << endl;
		cout << "Comment :=>> ----------" << endl;
		if (fabs(mitjanaEsperada[i] - resultat) < 0.001)
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}



float testAssignatura()
{
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> Iniciant test de la classe Assignatura" << endl;
	cout << "Comment :=>> ======================================" << endl;
	cout << "Comment :=>> " << endl;

	cout << "Comment :=>> Inicialitzem l'assignatura amb els estudiants següents...." << endl;
	cout << "Comment :=>> NIU_1, NOM_1" << endl;
	cout << "Comment :=>> NIU_2, NOM_2" << endl;
	cout << "Comment :=>> NIU_3, NOM_3" << endl;
	cout << "Comment :=>> NIU_4, NOM_4" << endl;
	cout << "Comment :=>> ----------------------------------" << endl;

	const int nEstudiants = 4;
	string estudiants[MAX_ESTUDIANTS][2] =
	{
		{"NIU_1", "NOM_1"},
		{"NIU_2", "NOM_2"},
		{"NIU_3", "NOM_3"},
		{"NIU_4", "NOM_4"}
	};
	Assignatura assignatura("ASSIG_1", nEstudiants, estudiants);

	float reduccio = testAfegeixNota(assignatura);
	reduccio += testCalculaNotaMitjana(assignatura);

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

	reduccio = testInicialitzacioLlista();
	grade = grade + (0.5 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testPertany();
	grade = grade + (0.5 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testCerca();
	grade = grade + (0.5 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testGetElement();
	grade = grade + (0.5 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testOperadorSuma();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testOperadorResta();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testInsereix();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testElimina();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testSortidaPantalla();
	grade = grade + (0.5 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testSortidaFitxer();
	grade = grade + (0.5 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testLecturaFitxer();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testAssignatura();
	grade = grade + (2 - reduccio);

	if (grade < 0)
		grade = 0.0;
	cout << "Grade :=>> " << grade << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	return 0;

}