#include "NodeFigura.h"

class LlistaFigura
{
public:
	LlistaFigura() { m_primer = nullptr; }
	~LlistaFigura();
	LlistaFigura(const LlistaFigura& l);
	LlistaFigura& operator=(const LlistaFigura& l);
	NodeFigura* insereix(const InfoFigura& pt);
	void elimina();
	int getNElements() const;
	InfoFigura getPrimer() const { return m_primer->getValor(); }
	bool esBuida() const { return m_primer == nullptr; }
		
 private:
	NodeFigura* m_primer;
	NodeFigura* m_ultim;
};
