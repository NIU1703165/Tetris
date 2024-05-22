#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
    Tauler();
    void inicialitza(int taulerInicial[MAX_FILA][MAX_COL]);
    void colocaFigura(const Figura& figura);
    bool Xoca(Figura figura);
    void ElimiarFilesComplertes();
    void getTauler(int tauler[MAX_FILA][MAX_COL]);
    int getFilesCompletes() const;

private:
    int m_tauler[MAX_FILA + 2][MAX_COL + 4];
    void eliminarFila(int fila);
    int filaCompleta() const;
    
};

#endif
