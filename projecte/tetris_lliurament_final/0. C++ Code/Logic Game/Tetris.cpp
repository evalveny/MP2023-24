#include "Tetris.h"
#include <fstream>
#include <iostream>
using namespace std;

//Definicio necesaria per poder incloure la llibreria i que trobi el main
//#define SDL_MAIN_HANDLED
#include <windows.h>
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"

Tetris::Tetris(const string& fitxerPuntuacions)
{
    ifstream fitxer;
    fitxer.open(fitxerPuntuacions);
    if (fitxer.is_open())
    {
        Puntuacio p;
        fitxer >> p.nom >> p.punts;
        while (!fitxer.eof())
        {
            m_puntuacions.push_back(p);
            fitxer >> p.nom >> p.punts;
        }
        fitxer.close();
    }
}

void Tetris::visualitzaPuntuacions()
{
    list<Puntuacio>::iterator it = m_puntuacions.begin();
    int ordre = 1;
    cout << endl;
    cout << "LLISTAT DE PUNTUACIONS" << endl;
    cout << "======================" << endl;
    while (it != m_puntuacions.end())
    {
        cout << ordre << ". " << it->nom << " " << it->punts << endl;
        ordre++;
        it++;
    }
    cout << endl;
}

void Tetris::guardaPuntuacions(const string& nomFitxer)
{
    ofstream fitxer;
    fitxer.open(nomFitxer);
    list<Puntuacio>::iterator it = m_puntuacions.begin();
    while (it != m_puntuacions.end())
    {
        fitxer << it->nom << " " << it->punts << endl;
        it++;
    }
    fitxer.close();
}


void Tetris::actualitzaPuntuacio(const string& nom, int punts)
{
    list<Puntuacio>::iterator it = m_puntuacions.begin();
    bool trobat = false;
    while (!trobat && (it != m_puntuacions.end()))
    {
        if (it->punts > punts)
            trobat = true;
        else
            it++;
    }
    Puntuacio p;
    p.nom = nom;
    p.punts = punts;
    m_puntuacions.insert(it, p);
}

int Tetris::juga(Screen& pantalla, ModeJoc mode, const string& nomFitxerInicial, const string& nomFitxerFigures, const string& nomFitxerMoviments)
{

    //Mostrem la finestra grafica
    pantalla.show();

    Partida game(mode);
    game.inicialitza(nomFitxerInicial, nomFitxerFigures, nomFitxerMoviments);

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;

    do
    {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

        // Captura tots els events de ratolí i teclat de l'ultim cicle
        pantalla.processEvents();

        game.actualitza(deltaTime);

        // Actualitza la pantalla
        pantalla.update();

    } while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));
    // Sortim del bucle si pressionem ESC
    int punts = game.getPuntuacio();

    return punts;
}