#include <stdlib.h>

class Node
{
    public:
        Node();
        ~Node();
        Node (const int& valor) : m_valor(valor), m_next(nullptr) {}
        Node* getNext() { return m_next; }
        void setNext(Node* next) { m_next = next; }
		int getValor() { return m_valor; }
        void setValor(const int &valor) { m_valor = valor; }
    private:
        int m_valor;
        Node* m_next;
};
