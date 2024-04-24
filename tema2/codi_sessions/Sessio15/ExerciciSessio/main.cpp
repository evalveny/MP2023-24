#include "Titulacio.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	float grade = 0;
	cout << "Grade :=>> " << grade << endl;
	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;

	cout << "Comment :=>> TEST DEL CONSTRUCTOR DE COPIA" << endl;
	cout << "Comment :=>> -----------------------------" << endl;


	Titulacio titulacio("nom_titulacio", 10, 10);
	titulacio.afegeixEstudiant("NIU_1", "NOM_1");
	titulacio.afegeixEstudiant("NIU_2", "NOM_2");
	Estudiant* e = titulacio.consultaEstudiant("NIU_1");
	e->afegeixAssignatura("ASSIG_1");
	e->afegeixAssignatura("ASSIG_2");

	cout << "Comment :=>> Inicialitzant dades d'una titulacio ..." << endl;
	cout << "Comment :=>> ----" << endl;
	cout << "Comment :=>> Fent copia de la titulacio amb constructor de copia ..." << endl;
	Titulacio titulacioCopia(titulacio);
	cout << "Comment :=>> ----" << endl;
	cout << "Comment :=>> Comprovant copia ..." << endl;
	bool correcte = true;
	correcte = correcte && (titulacioCopia.getNom() == "nom_titulacio")
		&& (titulacioCopia.getMaxAssignatures() == 10) && (titulacioCopia.getMaxEstudiants() == 10)
		&& (titulacioCopia.getNEstudiants() == 2);
	e = titulacioCopia.consultaEstudiant("NIU_1");
	correcte = correcte && (e != nullptr) && (e->getNAssignatures() == 2)
		&& (e->getAssignatura(0) == "ASSIG_1") && (e->getAssignatura(1) == "ASSIG_2");
	e = titulacioCopia.consultaEstudiant("NIU_2");
	correcte = correcte && (e != nullptr) && (e->getNAssignatures() == 0);
	if (correcte)
	{
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 2.5;
	}
	else
		cout << "Comment :=>> ERROR" << endl;
	cout << "Comment :=>> ---------------------------" << endl;
	cout << "Comment :=>> " << endl;
	cout << "Grade :=>> " << grade << endl;
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> TEST DE L'OPERADOR D'ASSIGNACIO" << endl;
	cout << "Comment :=>> -------------------------------" << endl;
	cout << "Comment :=>> Fent copia de la titulacio amb operador d'assignacio ..." << endl;
	Titulacio titulacioAssignacio;
	titulacioAssignacio = titulacio;
	cout << "Comment :=>> ----" << endl;
	cout << "Comment :=>> Comprovant copia ..." << endl;

	correcte = true;
	correcte = correcte && (titulacioAssignacio.getNom() == "nom_titulacio")
		&& (titulacioAssignacio.getMaxAssignatures() == 10) && (titulacioAssignacio.getMaxEstudiants() == 10)
		&& (titulacioAssignacio.getNEstudiants() == 2);
	e = titulacioAssignacio.consultaEstudiant("NIU_1");
	correcte = correcte && (e != nullptr) && (e->getNAssignatures() == 2)
		&& (e->getAssignatura(0) == "ASSIG_1") && (e->getAssignatura(1) == "ASSIG_2");
	e = titulacioAssignacio.consultaEstudiant("NIU_2");
	correcte = correcte && (e != nullptr) && (e->getNAssignatures() == 0);
	if (correcte)
	{
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 2.5;
	}
	else
		cout << "Comment :=>> ERROR" << endl;
	cout << "Comment :=>> ---------------------------" << endl;
	cout << "Comment :=>> " << endl;
	cout << "Grade :=>> " << grade << endl;
	cout << "Comment :=>> " << endl;

	string assignatura;
	Estudiant estudiant;
	cout << "Comment :=>> TEST afegir assignatura alfabeticament a estudiant" << endl;
	cout << "Comment :=>> ------------------------------------------" << endl;
	cout << "Comment :=>> Afegint assignatures..." << endl;
	cout << "Comment :=>> Metodologia de la Programacio" << endl;
	estudiant.insereixAssignatura("Metodologia de la Programacio");
	cout << "Comment :=>> Fonaments d'informatica" << endl;
	estudiant.insereixAssignatura("Fonaments d'informatica");
	cout << "Comment :=>> Xarxes" << endl;
	estudiant.insereixAssignatura("Xarxes");
	cout << "Comment :=>> Grafics" << endl;
	estudiant.insereixAssignatura("Grafics");
	cout << "Comment :=>> ---------" << endl;
	cout << "Comment :=>> Comprovant assignatura a la posicio 2 del vector..." << endl;
	assignatura = estudiant.getAssignatura(2);
	cout << "Comment :=>> ---" << endl;
	cout << "Comment :=>> Valor esperat: Metodologia de la Programacio " << endl;
	cout << "Comment :=>> ---" << endl;
	cout << "Comment :=>> Valor obtingut: " << assignatura << endl;
	cout << "Comment :=>> ---" << endl;
	if (assignatura == "Metodologia de la Programacio")
	{
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 2.5;
	}
	else 
	{
		cout << "Comment :=>> ERROR a l'afegir assignatura" << endl;
	}

	cout << "Comment :=>> " << endl;
	cout << "Grade :=>> " << grade << endl;
	cout << "Comment :=>> " << endl;

	cout << "Comment :=>> TEST eliminar assignatura a estudiant" << endl;
	cout << "Comment :=>> ------------------------------------------" << endl;
	cout << "Comment :=>> Eliminant assignatures..." << endl;
	cout << "Comment :=>> Grafics" << endl;
	estudiant.eliminaAssignatura("Grafics");
	cout << "Comment :=>> Fonaments d'informatica" << endl;
	estudiant.eliminaAssignatura("Fonaments d'informatica");
	cout << "Comment :=>> Xarxes" << endl;
	estudiant.eliminaAssignatura("Xarxes");
	assignatura = estudiant.getAssignatura(0);
	cout << "Comment :=>> ---------" << endl;
	cout << "Comment :=>> Comprovant assignatura a la posicio 0 del vector..." << endl;
	cout << "Comment :=>> ---" << endl;
	cout << "Comment :=>> Valor esperat: Metodologia de la Programacio " << endl;
	cout << "Comment :=>> ---" << endl;
	cout << "Comment :=>> Valor obtingut: " << assignatura << endl;
	cout << "Comment :=>> ---" << endl;
	if (assignatura != "Metodologia de la Programacio")
	{
		cout << "Comment :=>> ERROR a l'eliminar assignatura" << endl;
	}
	else 
	{
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 2.5;
	}
		
	cout << "Comment :=>> " << endl;
	cout << "Grade :=>> " << grade << endl;
	cout << "Comment :=>> " << endl;

	cout << "Comment :=>> TEST mostrar assignatures estudiant" << endl;
	cout << "Comment :=>> ------------------------------------------" << endl;
	estudiant.mostraAssignatures();
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> " << grade << endl;;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
 	return 0;
}