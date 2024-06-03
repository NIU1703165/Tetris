#include "Tauler.h"

Tauler::Tauler()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        m_tauler[i][0] = -1;
        m_tauler[i][1] = -1;
        m_tauler[i][MAX_COL + 2] = -1;
        m_tauler[i][MAX_COL + 3] = -1;

        for (int j = 0; j < MAX_COL; j++)
        {
            m_tauler[i][j + 2] = 0;
        }
    }
    
    for (int j = 0; j < MAX_COL + 4; j++)
    {
        m_tauler[MAX_FILA][j] = -1;
        m_tauler[MAX_FILA + 1][j] = -1;
    }
}

void Tauler::inicialitza(int taulerInicial[MAX_FILA][MAX_COL])
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            m_tauler[i][j + 2] = taulerInicial[i][j]; 
        }
    }
}

void Tauler::eliminarFila(int fila)
{
    for (int i = fila; i > 0; i--)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            m_tauler[i][j + 2] = m_tauler[i - 1][j + 2];
        }
    }

    for (int j = 0; j < MAX_COL; j++)
    {
        m_tauler[0][j] = 0;
    }
}

int Tauler::getFilesCompletes() const
{
    int cont = 0;
    for (int i = 0; i < MAX_FILA; i++)
    {
        bool comprovant = true;
        for (int j = 2; j < MAX_COL + 2; j++)
        {
            if (m_tauler[i][j] == 0)
            {
                comprovant = false;
                break;
            }
        }
        if (comprovant)
        {
            cont++;
        }
    }
    return cont;
}

 
void Tauler::colocaFigura(const Figura& figura)
{
    int color = figura.getColor();
    int posiciofigura[2];
    bool comprovant = true;
   
    posiciofigura[0] = figura.getPosicioActual(0);
    posiciofigura[1] = figura.getPosicioActual(1);
    
    for (int i = 0; i < figura.getTamanyFigura(0); i++)
    {
        for (int j = 0; j < figura.getTamanyFigura(1); j++)
        {
            if (figura.getHitboxFigura(i, j) == 1)
            {
                if (m_tauler[posiciofigura[0] + i - 1][posiciofigura[1] + j + 1] != 0)
                {
                    comprovant = false;
                }
            }
        }
    }
    
    if(comprovant)
    {
       for (int i = 0; i < figura.getTamanyFigura(0); i++)
       {
          for (int j = 0; j < figura.getTamanyFigura(1); j++)
          {
            if (figura.getHitboxFigura(i, j) == 1)
            {
               m_tauler[posiciofigura[0] + i - 1][posiciofigura[1] + j + 1] = color;

            }
          }
       }
    }
}


bool Tauler::Xoca(const Figura& figura)
{
    bool xoca = false;
    int pos[2];
    pos[0] = figura.getPosicioActual(0);
    pos[1] = figura.getPosicioActual(1);
    
    for (int i = 0; i < figura.getTamanyFigura(0); i++)
    {
        for (int j = 0; j < figura.getTamanyFigura(1); j++)
        {
            if (figura.getHitboxFigura(i, j) == 1)
            {
                if (m_tauler[pos[0] + i -1][pos[1] + j + 1] != 0)
                {
                    xoca = true;
                }
            }
        }
    }
    return xoca;
}


int Tauler::filaCompleta() const
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        bool comprovant = true;
        for (int j = 2; j < MAX_COL + 2; j++)
        {
            if (m_tauler[i][j] == 0)
            {
                comprovant = false;
                break;
            }
        }
        if (comprovant)
        {
            return i;
        }
    }
    return -1;
}

void Tauler::getTauler(int tauler[MAX_FILA][MAX_COL])
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            tauler[i][j] = m_tauler[i][j + 2];
        }
    }
}

void Tauler::ElimiarFilesComplertes()
{
    if(getFilesCompletes() > 0)
    {
        int fila = filaCompleta();
        
        while(fila != -1)
        {
            eliminarFila(fila);
            fila = filaCompleta();
        }
    }
}

void Tauler::actualitzatauler(Figura figura)
{
    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);

    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j <= MAX_COL+1; j++)
        {
            if (m_tauler[i][j] != 0 && m_tauler[i][j] != -1)
            {
                switch (m_tauler[i][j])
                {
                case 1:
                    GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_GROC, POS_X_TAULER + ((j - 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false);
                    break;
                case 2:
                    GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_BLAUCEL, POS_X_TAULER + ((j - 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false);
                    break;
                case 3:
                    GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_MAGENTA, POS_X_TAULER + ((j - 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false);
                    break;
                case 4:
                    GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_TARONJA, POS_X_TAULER + ((j - 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false);
                    break;
                case 5:
                    GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_BLAUFOSC, POS_X_TAULER + ((j - 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false);
                    break;
                case 6:
                    GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_VERMELL, POS_X_TAULER + ((j - 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false);
                    break;
                case 7:
                    GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_VERD, POS_X_TAULER + ((j - 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false);
                    break;
                }
            }
        }
    }
}