#include "Partida.h"
#include "InfoJoc.h"
#include "GraphicManager.h"

Partida::Partida()
{
    m_temps = 0;
    for (int i = 0; i < MIDA; i++)
        for (int j = 0; j < MIDA; j++)
            m_forma[i][j] = NO_COLOR;
    m_forma[0][0] = COLOR_BLAUFOSC;
    m_forma[1][0] = COLOR_BLAUFOSC;
    m_forma[1][1] = COLOR_BLAUFOSC;
    m_forma[1][2] = COLOR_BLAUFOSC;
    m_fila = 1;
    m_columna = 5;
}

void Partida::actualitza(double deltaTime)
{
    //TODO 1: Interactuar amb la crida per dibuixar gràfics (sprites).
    // 	      Dibuixar a pantalla el fons i el gràfic amb el tauler buit.
    //------------------------------------------------------------------

    //TODO 1.1 Afegir l'include de GraphicManager --> #include "GraphicManager.h"
    //TODO 1.2 Fer la crida de dibuixar un sprite --> GraphicManager::getInstance()->drawSprite(image, posX, posY, centered);
    //	    Per començar podem cridar el drawSprite amb els params --> 
    //          (GRAFIC_FONS,0,0, false) i 
    //          (GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false)

 /*   GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);*/

    

    //TODO 1.3: Dibuixar a pantalla el gràfic amb el tauler i un quadrat groc a la posició (2,3) del tauler

    //int fila = 2;
    //int columna = 3;
    //GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    //GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
    //GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_GROC, POS_X_TAULER + (columna * MIDA_QUADRAT), 
    //    POS_Y_TAULER + ((fila - 1) * MIDA_QUADRAT), false);

    //TODO 1.3: Dibuixar a pantalla el gràfic amb el tauler i la figura representada a la matriu m_forma 
    // a la posició del tauler indicada per m_fila i m_columna

    //GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    //GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
    //for (int i = 0; i < MIDA; i++)
    //    for (int j = 0; j < MIDA; j++)
    //        if (m_forma[i][j] != NO_COLOR)
    //            GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_BLAUFOSC, POS_X_TAULER + ((m_columna + j) * MIDA_QUADRAT), 
    //                POS_Y_TAULER + ((m_fila + i - 1) * MIDA_QUADRAT), false);

    
    //TODO 2: Interacció amb el teclat
    //------------------------------------------
    // TODO 2.1: Dibuixar dibuixar per pantalla un quadrat groc a la posicio indicada per m_fila i 
    // m_columna i que es vagi movent cap a la dreta cada cop que es prem la tecla de la fletxa dreta. 

    //GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    //GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
    //if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
    //    if (m_columna < N_COL_TAULER)
    //        m_columna++;
    //GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_GROC, POS_X_TAULER + (m_columna * MIDA_QUADRAT),
    //    POS_Y_TAULER + ((m_fila - 1) * MIDA_QUADRAT), false);

    // TODO 2.2 Dibuixar a pantalla el gràfic amb el tauler i la figura representada a l’atribut m_forma
    // a la posició del tauler indicada per m_fila i m_columna. 
    // Moure la figura cap a la dreta o l’esquerra si es pressionen les tecles de les fletxes corresponents, 
    // comprovant que no ens passem dels limits del tauler. 

    //GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    //GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
    //if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
    //{
    //    if ((m_columna + 2) < N_COL_TAULER)
    //        m_columna++;
    //}
    //else
    //    if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
    //    {
    //        if (m_columna > 1)
    //            m_columna--;
    //    }
    //for (int i = 0; i < MIDA; i++)
    //    for (int j = 0; j < MIDA; j++)
    //        if (m_forma[i][j] != NO_COLOR)
    //            GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_BLAUFOSC, POS_X_TAULER + ((m_columna + j) * MIDA_QUADRAT),
    //                POS_Y_TAULER + ((m_fila + i - 1) * MIDA_QUADRAT), false);

    //TODO 3: Introduir un temps d'espera
    //-----------------------------------
    // TODO 3.1: Dibuixar dibuixar per pantalla un quadrat groc a la posicio indicada per m_fila i 
    // m_columna. Fer que cada mig segon baixi una fila

    //GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    //GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
    //m_temps += deltaTime;
    //if (m_temps > 0.5)
    //{
    //    if (m_fila < N_FILES_TAULER)
    //        m_fila++;
    //    m_temps = 0.0;
    //}
    //GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_GROC, POS_X_TAULER + (m_columna * MIDA_QUADRAT),
    //        POS_Y_TAULER + ((m_fila - 1) * MIDA_QUADRAT), false);
    

    // TODO 3.2: Dibuixar per pantalla un quadrat groc a la posicio indicada per m_fila i  m_columna.
    // Moure el quadrat cap a la dreta o l’esquerra si es pressionen les tecles de les fletxes corresponents, 
    // comprovant que no ens passem dels limits del tauler.
    // Fer que cada segon baixi una fila, comprovant que no ens passem del limit inferior del tauler.

    //GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    //GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
    //m_temps += deltaTime;
    //if (m_temps > 1)
    //{
    //    if (m_fila < N_FILES_TAULER)
    //        m_fila++;
    //    m_temps = 0.0;
    //}
    //if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
    //{
    //    if (m_columna < N_COL_TAULER)
    //        m_columna++;
    //}
    //else
    //    if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
    //        if (m_columna > 1)
    //            m_columna--;
    //GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_GROC, POS_X_TAULER + (m_columna * MIDA_QUADRAT),
    //    POS_Y_TAULER + ((m_fila - 1) * MIDA_QUADRAT), false);

    // TODO 4: Imprimir text per pantalla
    //------------------------------------------
    // TODO 4.1: Mostrar la posició actual del quadrat a dalt del tauler

    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
    m_temps += deltaTime;
    if (m_temps > 0.5)
    {
        if (m_fila < N_FILES_TAULER)
            m_fila++;
        m_temps = 0.0;
    }
    GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_GROC, POS_X_TAULER + (m_columna * MIDA_QUADRAT),
            POS_Y_TAULER + ((m_fila - 1) * MIDA_QUADRAT), false);
    string msg = "Fila: " + to_string(m_fila) + ", Columna: " + to_string(m_columna);
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, msg);



    //TODO 5: Mostrar l’estat inicial del joc amb tots els caramels col·locats a la seva posició inicial
    //-----------------------------------------
 



}

