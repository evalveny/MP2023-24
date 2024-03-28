class Node
{
public:
    Node(int valor) : m_valor(valor), m_next(nullptr) {}

    int m_valor;
    Node* m_next;
};


int main()
{
    Node* p1, *p2, *p3;

    p1 = new Node(5);
    p2 = new Node(10);
    p1->m_next = p2;
    p2->m_next = new Node(0);
    p3 = p2->m_next;
    p3->m_valor = p1->m_valor + p2->m_valor;
    p1->m_next = p3;
    delete p2;

    return 0;
}