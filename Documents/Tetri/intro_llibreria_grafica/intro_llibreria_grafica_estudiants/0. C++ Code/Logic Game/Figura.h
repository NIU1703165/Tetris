#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>

#include "GraphicManager.h"
#include "InfoJoc.h"

using namespace std;

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
    int getHitboxFigura(int x, int y) const { return m_HitBoxFigura[x][y]; }
    int getColor() const { return m_ColorFigura; }
    int getTipusFigura() const {return m_TipusFigura; }
    void GirarFigura(int DirGir);
    void mouFigura(int Direccio); // -1 = esquerra, +1 Dreta;
    void BaixaFigura();
    void PujaFigura();
    void FormaZero();
    void DibuixaFigura();

private:
    TipusFigura m_TipusFigura;
    ColorFigura m_ColorFigura;
    int m_HitBoxFigura[MAX_ALCADA][MAX_AMPLADA];
    int m_Posicio_actual[2]; // [0] = posicio_fila, [1] = posicio_columne;
    int m_TamanyFigura[2];   // [0] = tamany x, [1] = tamany y;
};

#endif
