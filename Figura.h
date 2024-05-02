#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>
using namespace std;

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;

typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
} TipusFigura;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;
const int TIPUS_FIGURES = 7;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
    void Inicialitza_Figura(TipusFigura t);
    void Inicialitza_Figura_Tipus(TipusFigura t, int col, const int& fil);
    int getPosicioActual(const int& n) const { return m_Posicio_actual[n]; }
    int getTamanyFigura(const int& n) const { return m_TamanyFigura[n]; }
    void getHitboxFigura(int& hitbox);
    void GirarFigura(int DirGir);
    void mouFigura(int Direccio); // -1 = esquerra, +1 Dreta;
    void BaixaFigura();
    void PujaFigura();
    void FormaZero();

private:
    TipusFigura m_TpusFigura;
    ColorFigura m_ColorFigura;
    int m_HitBoxFigura[MAX_ALCADA][MAX_AMPLADA];
    int m_Posicio_actual[2]; // [0] = posicio_fila, [1] = posicio_columne;
    int m_TamanyFigura[2];   // [0] = tamany x, [1] = tamany y;
};

#endif
