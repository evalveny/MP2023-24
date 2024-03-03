#ifndef _AULA_H
#define _AULA_H
#include <string>
using namespace std;

const int MAX_DIES = 5;
const int MAX_HORES = 13;
const int HORA_INICIAL = 8;
const int HORA_FINAL = HORA_INICIAL + MAX_HORES - 1;
const int MAX_CAPACITAT_AULA = 1000;

typedef enum
{
	DILLUNS = 0,
	DIMARTS,
	DIMECRES,
	DIJOUS,
	DIVENDRES
} DiaSetmana;


class Aula
{
public:
	Aula() : m_codi(""), m_capacitat(0) { inicialitzaOcupacio(); }
	Aula(const string& codi, int capacitat): m_codi(codi), m_capacitat(capacitat) { inicialitzaOcupacio(); }
	void setCodi(const string& codi) { m_codi = codi; }
	void setCapacitat(int capacitat) { m_capacitat = capacitat; }
	string getCodi() const { return m_codi; } 
	int getCapacitat() const { return m_capacitat; }

	bool estaDisponible(DiaSetmana dia, int hora, int durada) const;
	bool reserva(DiaSetmana dia, int hora, int durada);
	bool anulaReserva(DiaSetmana dia, int hora, int durada);
private:
	string m_codi;
	int m_capacitat;
	bool m_ocupacio[MAX_DIES][MAX_HORES];

	void inicialitzaOcupacio();
};

#endif
