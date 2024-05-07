#include "Partida.h"
#include "GraphicManager.h"

void Partida::inicialitza(const string& nomFitxer, const string& nomFitxerFigures, const string& nomFitxerMoviments)
{
    if (m_mode == MODE_NORMAL)
        m_joc.novaFigura();
    else
	    m_joc.inicialitza(nomFitxer);
}

void Partida::actualitza(float deltaTime)
{
    if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
        m_joc.mouFigura(1);
    else
        if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
            m_joc.mouFigura(-1);
    if (Keyboard_GetKeyTrg(KEYBOARD_UP))
        m_joc.giraFigura(GIR_HORARI);
    else
        if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
            m_joc.giraFigura(GIR_ANTI_HORARI);
    int nFilesEliminades;
    if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
    {
        nFilesEliminades = m_joc.colocaFigura();
        actualitzaPunts(nFilesEliminades);
        m_joc.novaFigura();
        m_temps = 0.0;
    }
    else 
    {
        m_temps += deltaTime;
        if (m_temps > 0.5)
        {
            nFilesEliminades = m_joc.baixaFigura();
            if (nFilesEliminades != -1)
            {
                m_joc.novaFigura();
                actualitzaPunts(nFilesEliminades);
            }
            m_temps = 0.0;
        }
    }

	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	m_joc.dibuixa();
    string msgPunts = "Puntuacio: " + to_string(m_punts);
    string msgNivell = "Nivell: " + to_string(m_nivell);
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_PUNTUACIO, POS_Y_PUNTUACIO, 0.8, msgPunts);
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_NIVELL, POS_Y_NIVELL, 0.8, msgNivell);

}

void Partida::actualitzaPunts(int nFilesEliminades)
{
    if (nFilesEliminades == 0)
        m_punts += PUNTS_FIGURA;
    else
    {
        m_punts += PUNTS_FILA;
        switch (nFilesEliminades)
        {
        case 2:
            m_punts += DOBLE_FILA;
            break;
        case 3:
            m_punts += TRIPLE_FILA;
            break;
        case 4:
            m_punts += QUADRUPLE_FILA;
            break;
        }
    }
    if (m_punts > (m_nivell * CANVI_NIVELL))
    {
        m_nivell += 1;
        m_velocitat *= CANVI_VELOCITAT;
    }
}
