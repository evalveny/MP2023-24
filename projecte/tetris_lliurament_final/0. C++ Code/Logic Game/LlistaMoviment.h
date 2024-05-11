#include "NodeMoviment.h"

class LlistaMoviment
{
public:
	LlistaMoviment() { m_primer = nullptr; }
	~LlistaMoviment();
	LlistaMoviment(const LlistaMoviment& l);
	LlistaMoviment& operator=(const LlistaMoviment& l);
	NodeMoviment* insereix(const TipusMoviment& pt);
	void elimina();
	int getNElements() const;
	TipusMoviment getPrimer() const { return m_primer->getValor(); }
	bool esBuida() const { return m_primer == nullptr; }
		
 private:
	NodeMoviment* m_primer;
	NodeMoviment* m_ultim;
};
