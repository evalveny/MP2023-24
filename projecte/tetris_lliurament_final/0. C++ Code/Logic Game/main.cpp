//
//  main.cpp
//
//  Copyright � 2018 Compiled Creations Limited. All rights reserved.
//


#include <iostream>
#include <string>
#include <conio.h>      /* getch */ 
#include "./Tetris.h"

//Definicio necesaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED
#include <windows.h>
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
using namespace std;


void mostraOpcions()
{
    cout << endl;
    cout << "MENU PRINCIPAL" << endl;
    cout << "==============" << endl;
    cout << "1. Joc en mode normal" << endl;
    cout << "2. Joc en mode test" << endl;
    cout << "3. Mostrar puntuacions" << endl;
    cout << "4. Sortir" << endl;
}


void llegeixNomFitxers(string& nomInicial, string& nomFigures, string& nomMoviments)
{
    cout << "Nom del fitxer amb l'estat inicial del tauler: ";
    getline(cin, nomInicial);
    nomInicial = "./data/Games/" + nomInicial;
    cout << "Nom del fitxer amb la sequencia de figures: ";
    getline(cin, nomFigures);
    nomFigures = "./data/Games/" + nomFigures; 
    cout << "Nom del fitxer amb la sequencia de moviments: ";
    getline(cin, nomMoviments);
    nomMoviments = "./data/Games/" + nomMoviments;
}


int main(int argc, const char* argv[])
{
    //Instruccions necesaries per poder incloure la llibreria i que trobi el main
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO);

    //Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
    Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);

    Tetris tetris("./data/Games/puntuacions.txt");
    bool sortir = false;
    string nomInicial, nomFigures, nomMoviments, nomJugador;
    int punts;
    do
    {
        mostraOpcions();
        char opcio = _getch();
        switch (opcio)
        {
            case '1': 
                punts = tetris.juga(pantalla, MODE_NORMAL, "", "", "");
                cout << "Nom del jugador: ";
                cin >> nomJugador;
                tetris.actualitzaPuntuacio(nomJugador, punts);
                break;
            case '2':
                Sleep(500);
                llegeixNomFitxers(nomInicial, nomFigures, nomMoviments);
                punts = tetris.juga(pantalla, MODE_TEST, nomInicial, nomFigures, nomMoviments);
                break;
            case '3':
                tetris.visualitzaPuntuacions();
                break;
            case '4':
                sortir = true;
                break;
            default:
                cout << "OPCIO INCORRECTA" << endl;
        }
    } while (!sortir);
    tetris.guardaPuntuacions("./data/Games/puntuacions.txt");

    //Instruccio necesaria per alliberar els recursos de la llibreria 
    SDL_Quit();

    return 0;
}

