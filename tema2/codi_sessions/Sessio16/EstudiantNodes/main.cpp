#include "Titulacio.h"
#include <iostream>
#include <string>
using namespace std;

void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}

void mostraLlista(NodeEstudiant* primer)
{
	NodeEstudiant* aux = primer;
	cout << "Comment :=>> [";
	while (aux != nullptr)
	{
		Estudiant e = aux->getValor();
		cout << e.getNiu() << " ";
		aux = aux->getNext();
	}
	cout << "]" << endl;
}

void mostraArray(Estudiant *array, int nElements)
{
	cout << "Comment :=>> [";
	for (int i = 0; i < nElements; i++)
	{
		cout << array[i].getNiu() << " ";
	}
	cout << "]" << endl;
}

bool igualsArrayLlista(NodeEstudiant* primer, Estudiant* array, int nElements)
{
	bool iguals = true;
	int i = 0;
	NodeEstudiant* aux = primer;
	while (iguals && (i < nElements) && (aux != nullptr))
	{
		if (aux->getValor().getNiu() != array[i].getNiu())
			iguals = false;
		else
		{
			i++;
			aux = aux->getNext();
		}
	}
	iguals = iguals && (i == nElements) && (aux == nullptr);
	return iguals;
}

float testConsulta()
{
	float reduccio = 0.0;

	Titulacio t;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode consultaEstudiant" << endl;
	cout << "Comment :=>> =========================================" << endl;
	const int N_PROVES = 4;
	const int N_ESTUDIANTS = 4;
	Estudiant valorsAfegits[N_ESTUDIANTS] =
	{
		{ "niu_1", "nom_1" },
		{ "niu_2", "nom_2" },
		{ "niu_3", "nom_3" },
		{ "niu_4", "nom_4" }
	};
	string valorsConsultats[N_PROVES] = { "niu_2", "niu_4", "niu_1", "niu_5"};

	Estudiant valorEsperat[N_PROVES] =
	{
		{ "niu_2", "nom_2" },
		{ "niu_4", "nom_4" },
		{ "niu_1", "nom_1" },
		{ "", "" }
	};
	bool valorRetornEsperat[N_PROVES] = { true, true, true, false };
	int nElementsEsperat[N_PROVES] = { 3, 2, 1, 1};
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Afegint els seguents estudiants amb el metode insereix" << endl;
	for (int i = 0; i < N_ESTUDIANTS; i++)
	{
		cout << "Comment :=>> " << valorsAfegits[i].getNiu() << ", " << valorsAfegits[i].getNom() << endl;
		t.insereixEstudiant(valorsAfegits[i].getNiu(), valorsAfegits[i].getNom());
	}
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> -----------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> -----------------------------------------" << endl;
		cout << "Comment :=>> Consultem l'estudiant: " << valorsConsultats[i] << endl;
		Estudiant e;
		bool trobat = t.consultaEstudiant(valorsConsultats[i], e);
		cout << "Comment :=>> --------" << endl;
		cout << "Comment :=>> Valor de retorn esperat: "; mostraBool(valorRetornEsperat[i]); cout << endl;
		if (valorRetornEsperat[i])
			cout << "Comment :=>> Valor esperat de l'estudiant: " << valorEsperat[i].getNiu() << ", " << valorEsperat[i].getNom() << endl;
		cout << "Comment :=>> ---------" << endl;
		cout << "Comment :=>> Valor de retorn obtingut: "; mostraBool(trobat); cout << endl;
		if (trobat)
			cout << "Comment :=>> Valor obtingut de l'estudiant: " << e.getNiu() << ", " << e.getNom() << endl;
		if (trobat == valorRetornEsperat[i])
			if (trobat)
				if ((e.getNiu() != valorEsperat[i].getNiu()) || (e.getNom() != valorEsperat[i].getNom()))
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 1.0;
				}
				else
					cout << "Comment :=>> CORRECTE" << endl;
			else
				cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	if (reduccio > 2.0)
		reduccio = 2.0;
	return reduccio;
}


float testElimina()
{
	float reduccio = 0.0;

	Titulacio t;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode eliminaEstudiant" << endl;
	cout << "Comment :=>> =========================================" << endl;
	const int N_PROVES = 5;
	const int N_ESTUDIANTS = 4;
	Estudiant valorsAfegits[N_ESTUDIANTS] =
	{
		{ "niu_1", "nom_1" },
		{ "niu_2", "nom_2" },
		{ "niu_3", "nom_3" },
		{ "niu_4", "nom_4" }
	};
	string valorsEliminats[N_PROVES] = { "niu_2", "niu_4", "niu_1", "niu_1", "niu_3" };

	Estudiant valorEsperat[N_PROVES][N_ESTUDIANTS] =
	{
		{
			{ "niu_1", "nom_1" },
			{ "niu_3", "nom_3" },
			{ "niu_4", "nom_4" }
		},
		{
			{ "niu_1", "nom_1" },
			{ "niu_3", "nom_3" }
		},
		{
			{ "niu_3", "nom_3" }
		},
		{
			{ "niu_3", "nom_3" }
		},
		{
			{}
		}
	};
	
	int nElementsEsperat[N_PROVES] = { 3, 2, 1, 1, 0 };
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Afegint els seguents estudiants amb el metode insereix" << endl;
	for (int i = 0; i < N_ESTUDIANTS; i++)
	{
		cout << "Comment :=>> " << valorsAfegits[i].getNiu() << ", " << valorsAfegits[i].getNom() << endl;
		t.insereixEstudiant(valorsAfegits[i].getNiu(), valorsAfegits[i].getNom());
	}
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> -----------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> -----------------------------------------" << endl;
		cout << "Comment :=>> Eliminem l'estudiant: " << valorsEliminats[i] << endl;
		t.eliminaEstudiant(valorsEliminats[i]);
		cout << "Comment :=>> --------" << endl;
		cout << "Comment :=>> Valor esperat de la llista d'estudiants: " << endl;
		mostraArray(valorEsperat[i], nElementsEsperat[i]);
		cout << "Comment :=>> ---------" << endl;
		cout << "Comment :=>> Valor obtingut de la llista d'estudiants: " << endl;
		mostraLlista(t.getPrimerEstudiant());
		if (!igualsArrayLlista(t.getPrimerEstudiant(), valorEsperat[i], nElementsEsperat[i]))
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		else
			cout << "Comment :=>> CORRECTE" << endl;
	}
	if (reduccio > 2.0)
		reduccio = 2.0;
	return reduccio;
}


float testInsereix()
{
	float reduccio = 0.0;

	Titulacio t;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode insereixEstudiant" << endl;
	cout << "Comment :=>> =========================================" << endl;
	const int N_ESTUDIANTS = 4;
	Estudiant valorsAfegits[N_ESTUDIANTS] =
	{
		{ "niu_3", "nom_3" },
		{ "niu_1", "nom_1" },
		{ "niu_2", "nom_2" },
		{ "niu_4", "nom_4" }
	};
	Estudiant valorsEsperats[N_ESTUDIANTS] =
	{
		{ "niu_1", "nom_1" },
		{ "niu_2", "nom_2" },
		{ "niu_3", "nom_3" },
		{ "niu_4", "nom_4" }
	};
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Afegint els seguents estudiants ordenats amb el metode insereix" << endl;
	for (int i = 0; i < N_ESTUDIANTS; i++)
	{
		cout << "Comment :=>> " << valorsAfegits[i].getNiu() << ", " << valorsAfegits[i].getNom() << endl;
		t.insereixEstudiant(valorsAfegits[i].getNiu(), valorsAfegits[i].getNom());
	}
	cout << "Comment :=>> ---------" << endl;
	cout << "Comment :=>> Valor esperat de la llista d'estudiants: " << endl;
	mostraArray(valorsEsperats, N_ESTUDIANTS);
	cout << "Comment :=>> ---------" << endl;
	cout << "Comment :=>> Valor obtingut de la llista d'estudiants: " << endl;;
	mostraLlista(t.getPrimerEstudiant());
	if (!igualsArrayLlista(t.getPrimerEstudiant(), valorsEsperats, N_ESTUDIANTS))
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 2.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;

	if (reduccio > 2.0)
		reduccio = 2.0;
	return reduccio;
}



float testEliminaPrimer()
{
	float reduccio = 0.0;

	Titulacio t;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode eliminaPrimerEstudiant" << endl;
	cout << "Comment :=>> ===============================================" << endl;
	const int N_PROVES = 3;
	const int N_ESTUDIANTS = 2;
	Estudiant valorsAfegits[N_ESTUDIANTS] =
	{
		{ "niu_1", "nom_1" },
		{ "niu_2", "nom_2" },
	};
	Estudiant valorEsperat[N_PROVES][N_ESTUDIANTS] =
	{
		{
			{ "niu_1", "nom_1" }
		},
		{
		},
		{
		},
	};
	int nElementsEsperat[N_PROVES] = { 1, 0, 0 };
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Afegint els seguents estudiants pel principi de la llista" << endl;
	for (int i = 0; i < N_ESTUDIANTS; i++)
	{
		cout << "Comment :=>> " << valorsAfegits[i].getNiu() << ", " << valorsAfegits[i].getNom() << endl;
		t.afegeixEstudiant(valorsAfegits[i].getNiu(), valorsAfegits[i].getNom());
	}
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> -----------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> -----------------------------------------" << endl;
		cout << "Comment :=>> Eliminem el primer estudiant a la llista anterior" << endl;
		t.eliminaPrimerEstudiant();
		cout << "Comment :=>> --------" << endl;
		cout << "Comment :=>> Valor esperat de la llista d'estudiants: " << endl;
		mostraArray(valorEsperat[i], nElementsEsperat[i]);
		cout << "Comment :=>> ---------" << endl;
		cout << "Comment :=>> Valor obtingut de la llista d'estudiants: " << endl;
		mostraLlista(t.getPrimerEstudiant());
		if (!igualsArrayLlista(t.getPrimerEstudiant(), valorEsperat[i], nElementsEsperat[i]))
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		else
			cout << "Comment :=>> CORRECTE" << endl;
	}
	if (reduccio > 2.0)
		reduccio = 2.0;
	return reduccio;
}



float testAfegeix()
{
	float reduccio = 0.0;

	Titulacio t;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode afegeixEstudiant" << endl;
	cout << "Comment :=>> =========================================" << endl;
	const int N_PROVES = 2;
	Estudiant valorEsperat[N_PROVES] =
	{
		{ "niu_2", "nom_2" },
		{ "niu_1", "nom_1" },
	};
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Afegint els seguents estudiants pel principi de la llista" << endl;
	for (int i = N_PROVES - 1; i >= 0; i--)
	{
		cout << "Comment :=>> " << valorEsperat[i].getNiu() << ", " << valorEsperat[i].getNom() << endl;
		t.afegeixEstudiant(valorEsperat[i].getNiu(), valorEsperat[i].getNom());
	}
	cout << "Comment :=>> ---------" << endl;
	cout << "Comment :=>> Valor esperat de la llista d'estudiants: " << endl;
	mostraArray(valorEsperat, N_PROVES);
	cout << "Comment :=>> ---------" << endl;
	cout << "Comment :=>> Valor obtingut de la llista d'estudiants: " << endl;;
	mostraLlista(t.getPrimerEstudiant());
	if (!igualsArrayLlista(t.getPrimerEstudiant(), valorEsperat, N_PROVES))
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 2.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;

	if (reduccio > 2.0)
		reduccio = 2.0;
	return reduccio;
}



int main()
{
	float grade = 0;

	cout << "Grade :=>> " << grade << endl;
	grade += (2 - testAfegeix());
	cout << "Grade :=>> " << grade << endl;
	grade += (2 - testEliminaPrimer());
	cout << "Grade :=>> " << grade << endl;
	grade += (2 - testInsereix());
	cout << "Grade :=>> " << grade << endl;
	grade += (2 - testElimina());
	cout << "Grade :=>> " << grade << endl;
	grade += (2 - testConsulta());

	if (grade < 0)
		grade = 0.0;
	if (grade >= 10.0)
	{
		grade = 10;
		cout << "Comment :=>> Final del test sense errors" << endl;
	}
	cout << "Grade :=>> " << grade << endl;

	return 0;

}