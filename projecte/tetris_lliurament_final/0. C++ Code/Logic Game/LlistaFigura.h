#include "NodeFigura.h"

class LlistaFigura
{
public:
	LlistaFigura() { m_primer = nullptr; }
	~LlistaFigura();
	LlistaFigura(const LlistaFigura& l);
	LlistaFigura& operator=(const LlistaFigura& l);
	NodeFigura* insereix(const InfoFigura& pt);
	NodeFigura* elimina();
	int getNElements() const;
	NodeFigura* getInici() { return m_primer; }
	bool esBuida() const { return m_primer == nullptr; }
		
 private:
	NodeFigura* m_primer;
	NodeFigura* m_ultim;
};
