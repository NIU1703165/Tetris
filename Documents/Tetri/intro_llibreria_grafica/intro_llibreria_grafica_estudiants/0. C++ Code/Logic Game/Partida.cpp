#include "Partida.h"
#include "InfoJoc.h"
#include "GraphicManager.h"
#include <iostream>

using namespace std;

Partida::Partida()
{
    m_joc.inicialitza();
    puntuacio_files = 0;
    m_nivell = 0;
    m_puntuacio = 0;
    m_temps = 0;
    m_velocitat = 0.500;
}

Partida::~Partida()
{

}

void Partida::actualitza(double deltaTime)
{
    nivell();

    if (!m_joc.GetFinal())
    {
        m_joc.getTauler().actualitzatauler(m_joc.getFigura());
        m_temps += deltaTime;

        if (m_temps > m_velocitat)
        {
            if (!m_joc.baixaFigura_2())
                m_temps = 0.0;
        }
        m_joc.getFigura().DibuixaFigura();

        if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
        {
            m_joc.mouFigura(1);
        }

        if (Keyboard_GetKeyTrg(KEYBOARD_UP))
        {
            m_joc.giraFigura(GIR_HORARI);
        }

        if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
        {
            m_joc.giraFigura(GIR_ANTI_HORARI);
        }

        if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
        {
            m_joc.mouFigura(-1);
        }

        if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
        {
            while (!m_joc.baixaFigura_2());
        }

        puntuacio();

        string msg = "Fila: " + to_string(m_joc.getFigura().getPosicioActual(0)) + ", Columna: " + to_string(m_joc.getFigura().getPosicioActual(1));
        GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 90, 1.0, msg);

        string msg2 = "Puntuacio: " + to_string(m_puntuacio) + ", Nivell: " + to_string(m_nivell);
        GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 57, 1.0, msg2);
    }
    else
    {
        m_joc.getTauler().actualitzatauler(m_joc.getFigura());
        string msg2 = "Puntuacio: " + to_string(m_puntuacio);
        GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 57, 1.0, msg2);
    }

}

void Partida::nivell()
{
    int nivell;
    nivell = m_nivell;

    m_nivell = m_puntuacio / 1000;

    if (nivell != m_nivell)
    {
        m_velocitat *= 0.75;
    }
}

void Partida::puntuacio()
{
    int puntuacio = m_puntuacio;

    puntuacio = m_joc.getfigures_colocades() * 10;

    if (m_joc.getfiles_eliminades() != 0)
    {
        switch (m_joc.getfiles_eliminades())
        {
        case (1):
            puntuacio_files += 100;
            break;
        case (2):
            puntuacio_files += 150;
            break;

        case (3):
            puntuacio_files += 175;
            break;
        default:
            puntuacio_files += 200;
            break;
        }
        m_joc.resetFilesEliminades();
    }
    m_puntuacio = puntuacio + puntuacio_files;
}

void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments)
{

}

void Partida::menu()
{
    int var;
    bool comprovant = true;

    cout << "" << endl;
    cout << "__________________________________________________________________" << endl;
    cout << "" << endl;
    cout << ".___________. _______ .___________..______       __       _______." << endl;
    cout << "|           ||   ____||           ||   _  \\     |  |     /       |" << endl;
    cout << "`---|  |----`|  |__   `---|  |----`|  |_)  |    |  |    |   (----`" << endl;
    cout << "    |  |     |   __|      |  |     |      /     |  |     \\   \\    " << endl;
    cout << "    |  |     |  |____     |  |     |  |\\  \\----.|  | .----)   |   " << endl;
    cout << "    |__|     |_______|    |__|     | _| `._____||__| |_______/    " << endl;
    cout << "" << endl;
    cout << "__________________________________________________________________" << endl;
    cout << "" << endl;
    cout << "1-Mode de joc normal" << endl;
    cout << "" << endl;
    cout << "2-Mode de joc de prova" << endl;
    cout << "" << endl;
    cout << "3-Mostrar Puntuacions" << endl;
    cout << "" << endl;
    cout << "4-Sortir" << endl;
    cout << "" << endl;
    cout << "Introduiu una opcio:" << endl;
}

void Partida::actualitzapunts()
{
    m_puntuacio = 0;
}