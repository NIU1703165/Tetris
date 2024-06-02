#ifndef JOC_H
#define JOC_H

#include "Tauler.h"
#include "Figura.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Joc
{
public:
    void OmplirBolsa();
    int agafarNumero();
    int Columnaaleatoria();
    void inicialitza(const string& nomFitxer);
    void inicialitza();
    bool giraFigura(DireccioGir direccio);
    bool mouFigura(int direccio);
    bool baixaFigura_2();
    bool GetFinal() { return m_Final; }
    void SetFinal(bool x) { m_Final = x; }
    int baixaFigura();
    int getfigures_colocades() { return m_figures_colocades; }
    int getfiles_eliminades() { return m_files_eliminades; }
    void resetFilesEliminades() { m_files_eliminades = 0; }
    Figura getFigura() {return m_Figura_a; }
    void escriuTauler(const string& nomFitxer);
    Tauler getTauler() { return m_Tauler; }
    TipusFigura generafigura();
    TipusFigura convertirANumeroAFigura(int numero);

private:
    int m_figures_colocades;
    int m_files_eliminades;
    Tauler m_Tauler;
    Figura m_Figura_a;
    vector<int> bolsa;
    bool m_Final;
};

#endif
