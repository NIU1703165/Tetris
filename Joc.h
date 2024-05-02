#ifndef JOC_H
#define JOC_H

#include "Tauler.h"
#include "Figura.h"
#include <string>
using namespace std;

class Joc
{
public:
    void inicialitza(const string& nomFitxer);
    bool giraFigura(DireccioGir direccio);
    bool mouFigura(int direccio);
    int baixaFigura();
    void escriuTauler(const string& nomFitxer);

private:
    Tauler m_Tauler;
    Figura m_Figura_a;
};

#endif
