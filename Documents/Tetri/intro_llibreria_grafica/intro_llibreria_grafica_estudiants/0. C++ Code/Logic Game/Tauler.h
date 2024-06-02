#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 21;
const int MAX_COL = 11;

class Tauler
{
public:
    Tauler();
    void inicialitza(int taulerInicial[MAX_FILA][MAX_COL]);
    void actualitzatauler(Figura figura);
    void colocaFigura(const Figura& figura);
    bool Xoca(const Figura& figura);
    void ElimiarFilesComplertes();
    void getTauler(int tauler[MAX_FILA][MAX_COL]);
    int getFilesCompletes() const;
    void DibuixaFiguraTauler(const Figura& figura);

private:
    int m_tauler[MAX_FILA + 2][MAX_COL + 4];
    void eliminarFila(int fila);
    int filaCompleta() const;
    
};

#endif
