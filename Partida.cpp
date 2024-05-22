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
    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
    m_temps += deltaTime;
    if (m_temps > 0.5)
    {
        if (m_fila < N_FILES_TAULER)
            m_fila++;
        m_temps = 0.0;
    }
    GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_GROC,
        POS_X_TAULER + (m_columna * MIDA_QUADRAT),
        POS_Y_TAULER + ((m_fila - 1) * MIDA_QUADRAT), false);
    string msg = "Fila: " + to_string(m_fila) + ", Columna: " + to_string(m_columna);
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, msg);
}

