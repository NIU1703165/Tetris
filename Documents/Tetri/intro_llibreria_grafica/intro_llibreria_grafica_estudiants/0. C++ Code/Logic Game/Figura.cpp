#include "Figura.h"

void Figura::FormaZero()
{
    for (int i = 0; i < m_TamanyFigura[0]; i++)
    {
        for (int j = 0; j < m_TamanyFigura[1]; j++)
        {
            m_HitBoxFigura[i][j] = 0;
        }
    }
}

void Figura::Inicialitza_Figura_Tipus(TipusFigura t, int col, const int& fil)
{
    m_TipusFigura = t;
    m_Posicio_actual[0] = fil; // [0] = posicio_fila, [1] = posicio_columne;
    m_Posicio_actual[1] = col; // [0] = posicio_fila, [1] = posicio_columne;
    Inicialitza_Figura(t);
}

void Figura::Inicialitza_Figura(TipusFigura t)
{
    switch (t)
    {
    case FIGURA_O:
        m_TamanyFigura[0] = 2;
        m_TamanyFigura[1] = 2;
        FormaZero();
        m_HitBoxFigura[0][0] = 1;
        m_HitBoxFigura[0][1] = 1;
        m_HitBoxFigura[1][0] = 1;
        m_HitBoxFigura[1][1] = 1;
        m_ColorFigura = COLOR_GROC;
        break;
    case FIGURA_I:
        m_TamanyFigura[0] = 4;
        m_TamanyFigura[1] = 4;
        FormaZero();
        m_HitBoxFigura[1][0] = 1;
        m_HitBoxFigura[1][1] = 1;
        m_HitBoxFigura[1][2] = 1;
        m_HitBoxFigura[1][3] = 1;
        m_ColorFigura = COLOR_BLAUCEL;
        break;
    case FIGURA_T:
        m_TamanyFigura[0] = 3;
        m_TamanyFigura[1] = 3;
        FormaZero();
        m_HitBoxFigura[0][1] = 1;
        m_HitBoxFigura[1][0] = 1;
        m_HitBoxFigura[1][1] = 1;
        m_HitBoxFigura[1][2] = 1;
        m_ColorFigura = COLOR_MAGENTA;
        break;
    case FIGURA_J:
        m_TamanyFigura[0] = 3;
        m_TamanyFigura[1] = 3;
        FormaZero();
        m_HitBoxFigura[0][0] = 1;
        m_HitBoxFigura[1][0] = 1;
        m_HitBoxFigura[1][1] = 1;
        m_HitBoxFigura[1][2] = 1;
        m_ColorFigura = COLOR_BLAUFOSC;
        break;
    case FIGURA_L:
        m_TamanyFigura[0] = 3;
        m_TamanyFigura[1] = 3;
        FormaZero();
        m_HitBoxFigura[0][2] = 1;
        m_HitBoxFigura[1][0] = 1;
        m_HitBoxFigura[1][1] = 1;
        m_HitBoxFigura[1][2] = 1;
        m_ColorFigura = COLOR_TARONJA;
        break;
    case FIGURA_Z:
        m_TamanyFigura[0] = 3;
        m_TamanyFigura[1] = 3;
        FormaZero();
        m_HitBoxFigura[0][0] = 1;
        m_HitBoxFigura[0][1] = 1;
        m_HitBoxFigura[1][1] = 1;
        m_HitBoxFigura[1][2] = 1;
        m_ColorFigura = COLOR_VERMELL;
        break;
    case FIGURA_S:
        m_TamanyFigura[0] = 3;
        m_TamanyFigura[1] = 3;
        FormaZero();
        m_HitBoxFigura[0][1] = 1;
        m_HitBoxFigura[0][2] = 1;
        m_HitBoxFigura[1][0] = 1;
        m_HitBoxFigura[1][1] = 1;
        m_ColorFigura = COLOR_VERD;
        break;
    default:
        cout << "ERROR - Aquesta figura no existeix!" << endl;
        break;
    }
}

void Figura::GirarFigura(int DirGir)
{
    if (DirGir == 0) //Gir Horari
    {
        int** c_matriu =new int*[m_TamanyFigura[0]];

        for (int i = 0; i < m_TamanyFigura[0]; i++)
        {
            c_matriu[i] = new int[m_TamanyFigura[1]];
        }

        for (int i = 0; i < m_TamanyFigura[0]; i++)
        {
            for (int j = 0; j < m_TamanyFigura[0]; j++)
            {
                c_matriu[i][j] = m_HitBoxFigura[i][j];
            }
        }

        for (int i = 0; i < m_TamanyFigura[0]; i++)
        {
            for (int j = 0; j < m_TamanyFigura[0]; j++)
            {
                m_HitBoxFigura[i][j] = c_matriu[(m_TamanyFigura[0] - 1) - j][i];
            }
        }

        for (int i = 0; i < m_TamanyFigura[0]; i++)
        {
            delete[] c_matriu[i];
        }
    }
    else //Gir AntiHorari
    {
        int** c_matriu = new int* [m_TamanyFigura[0]];

        for (int i = 0; i < m_TamanyFigura[0]; i++) 
        {
            c_matriu[i] = new int[m_TamanyFigura[1]];
        }

        for (int i = 0; i < m_TamanyFigura[0]; i++)
        {
            for (int j = 0; j < m_TamanyFigura[0]; j++)
            {
                c_matriu[i][j] = m_HitBoxFigura[i][j];
            }
        }

        for (int i = 0; i < m_TamanyFigura[0]; i++)
        {
            for (int j = 0; j < m_TamanyFigura[0]; j++)
            {
                m_HitBoxFigura[i][j] = c_matriu[j][(m_TamanyFigura[0] - 1) - i];
            }

        }

        for (int i = 0; i < m_TamanyFigura[0]; i++) 
        {
            delete[] c_matriu[i];
        }

        delete[] c_matriu;
    }
}

void Figura::PujaFigura()
{
    m_Posicio_actual[0] -= 1;
}

void Figura::BaixaFigura()
{
    m_Posicio_actual[0] += 1;
}

void Figura::mouFigura(int Direccio)
{
    m_Posicio_actual[1] += Direccio;
} 

void Figura::DibuixaFigura()
{
    for (int i = 0; i < m_TamanyFigura[0]; i++)
    {
        for (int j = 0; j < m_TamanyFigura[1]; j++)
        {
            if (m_HitBoxFigura[i][j] != 0)
            {
                switch (m_TipusFigura) 
                {
                case FIGURA_O:
                    GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_GROC, POS_X_TAULER + ((m_Posicio_actual[1] + j) * MIDA_QUADRAT), POS_Y_TAULER + ((m_Posicio_actual[0] + i - 1) * MIDA_QUADRAT), false);
                    break;
                case FIGURA_I:
                    GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_BLAUCEL, POS_X_TAULER + ((m_Posicio_actual[1] + j) * MIDA_QUADRAT), POS_Y_TAULER + ((m_Posicio_actual[0] + i - 1) * MIDA_QUADRAT), false);
                    break;
                case FIGURA_T:
                    GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_MAGENTA, POS_X_TAULER + ((m_Posicio_actual[1] + j) * MIDA_QUADRAT), POS_Y_TAULER + ((m_Posicio_actual[0] + i - 1) * MIDA_QUADRAT), false);
                    break;
                case FIGURA_J:
                    GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_BLAUFOSC, POS_X_TAULER + ((m_Posicio_actual[1] + j) * MIDA_QUADRAT), POS_Y_TAULER + ((m_Posicio_actual[0] + i - 1) * MIDA_QUADRAT), false);
                    break;
                case FIGURA_L:
                    GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_TARONJA, POS_X_TAULER + ((m_Posicio_actual[1] + j) * MIDA_QUADRAT), POS_Y_TAULER + ((m_Posicio_actual[0] + i - 1) * MIDA_QUADRAT), false);
                    break;
                case FIGURA_Z:
                    GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_VERMELL, POS_X_TAULER + ((m_Posicio_actual[1] + j) * MIDA_QUADRAT), POS_Y_TAULER + ((m_Posicio_actual[0] + i - 1) * MIDA_QUADRAT), false);
                    break;
                case FIGURA_S:
                    GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_VERD, POS_X_TAULER + ((m_Posicio_actual[1] + j) * MIDA_QUADRAT), POS_Y_TAULER + ((m_Posicio_actual[0] + i - 1) * MIDA_QUADRAT), false);
                    break;
                }
            }
        }
    }
}