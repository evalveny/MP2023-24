#include "Node.h"

class Cua
{
    public:
		Cua();
        ~Cua();

		bool esBuida() const;
		int getPrimer() const;
		int getUltim() const;
		void afegeix(const int& valor);
		void treu();
    private:
        Node* m_primer;
		Node* m_ultim;
};