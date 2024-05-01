#ifndef FIGURA_H
#define FIGURA_H

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
    Inicialitza_Figura(TipusFigura t);
    Inicialitza_Figura_Tipus(TipusFigura t, int col, const int& fil);
    getPosicioActual(const int& n) const { return = m_Posicio_actual[n] };
    getTamanyFigura(const int& n) { return = m_TamanyFigura[n] };
    void GirarFigura(DireccioGir DirGir);
    void mouFigura(int Direccio); // -1 = esquerra, +1 Dreta;
    void BaixaFigura();
    void FormaZero();

private:
    TipusFigura m_TpusFigura;
    ColorFigura m_ColorFigura;
    int m_HitBoxFigura[MAX_ALCADA][MAX_AMPLADA];
    int m_Posicio_actual[2]; // [0] = posicio_fila, [1] = posicio_columne;
    int m_TamanyFigura[2]; // [0] = tamany x, [1] = tamany y;

};


#endif