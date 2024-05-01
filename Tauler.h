#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
    Tauler(int files, int columnes);
    void inicialitza(int taulerInicial[MAX_FILA][MAX_COL]);
    bool colocaFigura(Figura figura);
    bool girValid(const Figura& figura) const;
    bool movimentValid(const Figura& figura) const;
    void eliminarFilesCompletes();

private:
    int nFiles, nColumnes;
    int tauler[MAX_FILA][MAX_COL];
    void eliminarFila(int fila);
    int filaCompleta() const;
};

#endif
