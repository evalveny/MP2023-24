//
//  main.cpp
//
//  Copyright � 2018 Compiled Creations Limited. All rights reserved.
//


#include <iostream>
#include <conio.h>      /* getch */ 
#include "./Tetris.h"


int main(int argc, const char* argv[])
{
    Tetris tetris;

    do
    {
        mostraOpcions();
        char opcio = getch();
        switch (opcio)
        {
            case '1': 
                tetris.juga(MODE_NORMAL, "", "", "");
                break;
            case '2':
                tetris.juga(MODE_NORMAL, "", "", "");
                break;
            default:
                cout << "OPCIO INCORRECTA" << endl;
        }
    }
    return 0;
}

