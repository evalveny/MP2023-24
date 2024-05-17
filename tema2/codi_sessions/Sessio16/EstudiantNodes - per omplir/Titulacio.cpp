#include "Titulacio.h"

void Titulacio::eliminaPrimerEstudiant()
{
	// Guardar apuntador al primer element en un auxiliar

	// Modificar apuntador al primer element (al següent element)

	// Alliberar el primer element(utilitzant l’apuntador auxiliar)



}

void Titulacio::afegeixEstudiant(const string& niu, const string& nom)
{
	// Crear nou node

	// Inicialitzar estudiant i posar-lo al node

	// Enllaçar nou node amb la resta de la llista

	// Modificar apuntador al nou element	


}

bool Titulacio::eliminaEstudiant(const string& niu)
{
	bool trobat = false;
	NodeEstudiant* aux = m_estudiants;
	NodeEstudiant* anterior = nullptr;

	// Recuperar apuntador a l'estudiant que volem eliminar i a l'element anterior.
	// Aplicar esquema de cerca per recuperar l’apuntador a l’estudiant, però 	
	// recuperar també a la vegada l’apuntador a l'element anterior.







	if (trobat)
	{
		// Si element a eliminar diferent de primer element
			// Enllaçar element anterior amb el següent element.

		// Si element a eliminar és el primer 
			// Modificar apuntador a primer element.

		// En els dos casos, alliberar memòria de l'element eliminat



		m_nEstudiants--;
	}
	return trobat;
}

void Titulacio::insereixEstudiant(const string& niu, const string& nom)
{
	bool trobat = false;
	NodeEstudiant* seguent = m_estudiants;
	NodeEstudiant* anterior = nullptr;

	// Recuperar apuntador als estudiants següent i anterior a la posició on volem 
    // inserir	
	// Aplicar esquema de cerca per recuperar els apuntadors següent i anterior

	// En qualsevol cas, crear el nou node, inicialitzar-lo i enllaçar-lo amb 
    // l’element següent 

    // Si element anterior és diferent nullptr, enllaçar-lo amb el nou element

	// Si element anterior és nullptr, modificar m_estudiants al nou element
}


bool Titulacio::consultaEstudiant(const string& niu, Estudiant& e)
{
	bool trobat = false;
	<inicialitzar_seqüència>
		while (!(<final_seqüència>) && (!trobat))
		{
			<recuperar_estudiant_actual>
				if (< condicio_trobat)
					trobat = true;
				else
					<avançar_seqüència>
		}
	return trobat;

}