#include "Data.h"
#include <fstream>
using namespace std;

void Data::llegeixFitxer(const string& nomFitxer)
{
    ifstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        fitxer >> m_dia >> m_mes >> m_any;
        fitxer.close();
    }
}

void Data::escriuFitxer(const string& nomFitxer)
{
    ofstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        fitxer << m_dia << endl;
        fitxer << m_mes << endl;
        fitxer << m_any << endl;
        fitxer.close();
    }
}
