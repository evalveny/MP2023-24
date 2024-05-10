#include "Partida.h"
#include "GraphicManager.h"
#include <fstream>

void Partida::inicialitza(const string& nomFitxer, const string& nomFitxerFigures, const string& nomFitxerMoviments)
{
    if (m_mode == MODE_NORMAL)
        m_finalJoc = m_joc.novaFigura();
    else
    {
        m_joc.inicialitza(nomFitxer);
        inicialitzaFigures(nomFitxerFigures);
        inicialitzaMoviments(nomFitxerMoviments);
    }
	    
}

void Partida::inicialitzaFigures(const string& nomFitxer)
{
    ifstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        InfoFigura figura;
        int tipus;
        fitxer >> tipus >> figura.fila >> figura.columna >> figura.gir;
        figura.tipus = TipusFigura(tipus);
        while (!fitxer.eof())
        {
            m_figures.insereix(figura);
            fitxer >> tipus >> figura.fila >> figura.columna >> figura.gir;
            figura.tipus = TipusFigura(tipus);
        }
        fitxer.close();
    }
}

void Partida::inicialitzaMoviments(const string& nomFitxer)
{
    ifstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        int tipus;
        fitxer >> tipus;
        while (!fitxer.eof())
        {
            m_moviments.insereix(TipusMoviment(tipus));
            fitxer >> tipus;
        }
        fitxer.close();
    }
}


void Partida::actualitzaNormal(float deltaTime)
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
        m_finalJoc = m_joc.novaFigura();
        m_temps = 0.0;
    }
    else
    {
        m_temps += deltaTime;
        if (m_temps > m_velocitat)
        {
            nFilesEliminades = m_joc.baixaFigura();
            if (nFilesEliminades != -1)
            {
                m_finalJoc = m_joc.novaFigura();
                actualitzaPunts(nFilesEliminades);
            }
            m_temps = 0.0;
        }
    }
}

void Partida::actualitzaTest(float deltaTime)
{
    m_temps += deltaTime;
    if (m_temps > m_velocitat)
    {
        m_temps = 0.0;
        TipusMoviment moviment;
        if (m_moviments.esBuida())
        {
            m_finalJoc = true;
        }
        else
        {
            moviment = m_moviments.getPrimer();
            m_moviments.elimina();
            int nFilesEliminades;
            switch (moviment)
            {
            case MOVIMENT_DRETA:
                m_joc.mouFigura(1);
                break;
            case MOVIMENT_ESQUERRA:
                m_joc.mouFigura(-1);
                break;
            case MOVIMENT_GIR_HORARI:
                m_joc.giraFigura(GIR_HORARI);
                break;
            case MOVIMENT_GIR_ANTI_HORARI:
                m_joc.giraFigura(GIR_ANTI_HORARI);
                break;
            case MOVIMENT_BAIXA_FINAL:
                nFilesEliminades = m_joc.colocaFigura();
                actualitzaPunts(nFilesEliminades);
                if (!m_figures.esBuida())
                {
                    InfoFigura figura = m_figures.getPrimer();
                    m_figures.elimina();
                    m_joc.novaFigura(figura);
                }
                else
                    m_finalJoc = true;
                break;
            case MOVIMENT_BAIXA:
                nFilesEliminades = m_joc.baixaFigura();
                if (nFilesEliminades != -1)
                {
                    actualitzaPunts(nFilesEliminades);
                    if (!m_figures.esBuida())
                    {
                        InfoFigura figura = m_figures.getPrimer();
                        m_figures.elimina();
                        m_joc.novaFigura(figura);
                    }
                    else
                        m_finalJoc = true;
                }
            }
        }
                    
    }
}

void Partida::actualitza(float deltaTime)
{
    if (!m_finalJoc)
    {
        if (m_mode == MODE_NORMAL)
            actualitzaNormal(deltaTime);
        else
            actualitzaTest(deltaTime);
    }

	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	m_joc.dibuixa();
    string msgPunts = "Puntuacio: " + to_string(m_punts);
    string msgNivell = "Nivell: " + to_string(m_nivell);
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_PUNTUACIO, POS_Y_PUNTUACIO, 0.8, msgPunts);
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_NIVELL, POS_Y_NIVELL, 0.8, msgNivell);
    if (m_finalJoc)
    {
        string msgFinal = "GAME OVER";
        GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_FINAL_JOC, POS_Y_FINAL_JOC, 1.8, msgFinal);

    }
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
