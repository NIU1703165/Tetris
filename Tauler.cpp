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
    for (int i = fila; i > 0; --i)
    {
        for (int j = 0; j < MAX_COL ++j)
        {
            m_tauler[i][j + 2] = m_tauler[i - 1][j + 2];
        }
    }

    for (int j = 0; j < MAX_COL; j++)
    {
        tauler[0][j] = 0;
    }
}

bool Tauler::colocaFigura(const Figura& figura)
{
    int color = figura.getColor();
    int posiciofigura[2];
    int hitbox[MAX_AMPLADA][MAX_ALCADA];
    figura.getHitboxFigura(hitbox);

    posiciofigura[0] = figura.getPosicioActual(0);
    posiciofigura[1] = figura.getPosicioActual(1);

    for (int i = 0; i < MAX_AMPLADA; i++)
    {
        for (int j = 0; j < MAX_ALCADA; j++)
        {
            if (hitbox[i][j] == 1)
            {
                if (m_tauler[posiciofigura[0] + i][posiciofigura[1] + j] != 0)
                {
                    return false;
                }
                 else
                 {
                    m_tauler[posiciofigura[0] + i][posiciofigura[1] + j] = color;
                 }
            }
        }
    }

    return true;
}


bool Tauler::Xoca(const Figura& figura)
{
    bool xoca = false;
    int pos[2] = figura.getPosicioActual();
    int hitbox[MAX_AMPLADA][MAX_ALCADA];
    figura.getHitboxFigura(hitbox);

    for (int i = 0; i < MAX_AMPLADA; i++)
    {
        for (int j = 0; j < MAX_ALCADA; j++)
        {
            if (hitbox[i][j] == 1)
            {
                if (m_tauler[pos[0] + i][pos[1] + j] != 0)
                {
                    bool xoca = true;
                }
            }
        }
    }
    return xoca;
}

void Tauler::eliminarFilesCompletes()
{
    int fila = filaCompleta();

    while ((fila != -1)
    {
        eliminarFila(fila);
        fila = filaCompleta();
    }
}

int Tauler::filaCompleta() const
{
    for (int i = 0; i < MAX_FILES; i++)
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
