#include <stdlib.h>
#include "InfoJoc.h"

typedef struct
{
    TipusFigura figura;
    int fila;
    int columna;
    int gir;
} InfoFigura;

class NodeFigura
{
public:
    NodeFigura() {m_next = nullptr;};
	~NodeFigura() {};
    NodeFigura(const InfoFigura& valor) {m_valor = valor; m_next = nullptr;}
    NodeFigura* getNext() { return m_next; }
    void setNext(NodeFigura* next) { m_next = next; }
    InfoFigura getValor() { return m_valor; }
    void setValor(const InfoFigura& valor) { m_valor = valor; }
private:
    InfoFigura m_valor;
    NodeFigura* m_next;
};

