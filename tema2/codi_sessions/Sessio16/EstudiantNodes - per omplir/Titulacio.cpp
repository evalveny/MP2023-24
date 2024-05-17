#include "Titulacio.h"

void Titulacio::eliminaPrimerEstudiant()
{
	// Guardar apuntador al primer element en un auxiliar

	// Modificar apuntador al primer element (al seg�ent element)

	// Alliberar el primer element(utilitzant l�apuntador auxiliar)



}

void Titulacio::afegeixEstudiant(const string& niu, const string& nom)
{
	// Crear nou node

	// Inicialitzar estudiant i posar-lo al node

	// Enlla�ar nou node amb la resta de la llista

	// Modificar apuntador al nou element	


}

bool Titulacio::eliminaEstudiant(const string& niu)
{
	bool trobat = false;
	NodeEstudiant* aux = m_estudiants;
	NodeEstudiant* anterior = nullptr;

	// Recuperar apuntador a l'estudiant que volem eliminar i a l'element anterior.
	// Aplicar esquema de cerca per recuperar l�apuntador a l�estudiant, per� 	
	// recuperar tamb� a la vegada l�apuntador a l'element anterior.







	if (trobat)
	{
		// Si element a eliminar diferent de primer element
			// Enlla�ar element anterior amb el seg�ent element.

		// Si element a eliminar �s el primer 
			// Modificar apuntador a primer element.

		// En els dos casos, alliberar mem�ria de l'element eliminat



		m_nEstudiants--;
	}
	return trobat;
}

void Titulacio::insereixEstudiant(const string& niu, const string& nom)
{
	bool trobat = false;
	NodeEstudiant* seguent = m_estudiants;
	NodeEstudiant* anterior = nullptr;

	// Recuperar apuntador als estudiants seg�ent i anterior a la posici� on volem 
    // inserir	
	// Aplicar esquema de cerca per recuperar els apuntadors seg�ent i anterior

	// En qualsevol cas, crear el nou node, inicialitzar-lo i enlla�ar-lo amb 
    // l�element seg�ent 

    // Si element anterior �s diferent nullptr, enlla�ar-lo amb el nou element

	// Si element anterior �s nullptr, modificar m_estudiants al nou element
}


bool Titulacio::consultaEstudiant(const string& niu, Estudiant& e)
{
	bool trobat = false;
	<inicialitzar_seq��ncia>
		while (!(<final_seq��ncia>) && (!trobat))
		{
			<recuperar_estudiant_actual>
				if (< condicio_trobat)
					trobat = true;
				else
					<avan�ar_seq��ncia>
		}
	return trobat;

}