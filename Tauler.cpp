#include "Tauler.h"

Tauler::Tauler(int files, int columnes)
{
    nFiles = files;
    nColumnes = columnes;

    for (int i = 0; i < nFiles; i++)
    {
        for (int j = 0; j < nColumnes; j++)
        {
            tauler[i][j] = 0;
        }
    }
}

void Tauler::eliminarFila(int fila)
{
    for (int i = fila; i > 0; --i)
    {
        for (int j = 0; j < nColumnes; ++j)
        {
            tauler[i][j] = tauler[i - 1][j];
        }
    }

    for (int j = 0; j < nColumnes; j++)
    {
        tauler[0][j] = 0;
    }
}

bool Tauler::colocaFigura(Figura figura)
{
    int color = figura.getColor();
    int posiciofigura[2];
    int tamanyfigura[2];

    posiciofigura[0] = figura.getPosicioActual(0);  //fila
    posiciofigura[1] = figura.getPosicioActual(1);  //columna

    tamanyfigura[0] = figura.getTamanyFigura(0);   //x
    tamanyfigura[1] = figura.getTamanyFigura(1);   //y

    for (int i = 0; i < tamanyfigura[0]; i++)
    {
        for (int j = 0; j < tamanyfigura[1]; j++)
        {
            int fila = posiciofigura[0] + i;
            int columna = posiciofigura[1] + j;

            if (fila >= 0 && fila < nFiles && columna >= 0 && columna < nColumnes)
            {
                if (tauler[fila][columna] == 0)
                {
                    tauler[fila][columna] = color;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

bool Tauler::girValid(const Figura& figura) const
{
    Figura figuraGirada = figura;
    figuraGirada.GirarFigura();

    int posiciofigura[2];
    int tamanyfigura[2];

    posiciofigura[0] = figuraGirada.getPosicioActual(0);  // fila
    posiciofigura[1] = figuraGirada.getPosicioActual(1);  // columna
    tamanyfigura[0] = figuraGirada.getTamanyFigura(0);    // x
    tamanyfigura[1] = figuraGirada.getTamanyFigura(1);    // y

    for (int i = 0; i < tamanyfigura[0]; i++)
    {
        for (int j = 0; j < tamanyfigura[1]; j++)
        {
            int fila = posiciofigura[0] + i;
            int columna = posiciofigura[1] + j;

            if (fila < 0 || fila >= nFiles || columna < 0 || columna >= nColumnes)
            {
                return false;
            }
        }
    }

    return true;
}

bool Tauler::movimentValid(const Figura& figura) const
{
    int posiciofigura[2];
    int tamanyfigura[2];
    posiciofigura[0] = figura.getPosicioActual(0);     // Nueva fila
    posiciofigura[1] = figura.getPosicioActual(1);     // Nueva columna
    tamanyfigura[0] = figura.getTamanyFigura(0);       // x
    tamanyfigura[1] = figura.getTamanyFigura(1);       // y

    for (int i = 0; i < tamanyfigura[0]; i++)
    {
        for (int j = 0; j < tamanyfigura[1]; j++)
        {
            int fila = posiciofigura[0] + i;
            int columna = posiciofigura[1] + j;

            if (fila < 0 || fila >= nFiles || columna < 0 || columna >= nColumnes)
            {
                return false;
            }
        }
    }

    return true;
}

void Tauler::eliminarFilesCompletes()
{
    int fila;
    while ((fila = filaCompleta()) != -1)
    {
        eliminarFila(fila);
    }
}

int Tauler::filaCompleta() const
{
    for (int i = 0; i < nFiles; i++)
    {
        bool comprovant = true;
        for (int j = 0; j < nColumnes; j++)
        {
            if (tauler[i][j] == 0)
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
