#include "Joc.h"
#include <fstream>

void Joc::inicialitza(const string& nomFitxer)
{
    ifstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        int fil, col, gir, tip;
        fitxer >> tip >> fil >> col >> gir;
        m_Figura_a.Inicialitza_Figura_Tipus(static_cast<TipusFigura>(tip), col, fil);

        for (int i = 0; i < gir; i++)
        {
            m_Figura_a.GirarFigura(GIR_HORARI);
        }

        int taulerInicial[MAX_FILA][MAX_COL];
        int n_color;
        for (int i = 0; i < MAX_FILA; i++)
            for (int j = 0; j < MAX_COL; j++)
            {
                fitxer >> n_color;
                taulerInicial[i][j] = n_color;
            }
        m_Tauler.inicialitza(taulerInicial);
        fitxer.close();
    }
}

bool Joc::giraFigura(DireccioGir direccio)
{
    m_Figura_a.GirarFigura(direccio);

    bool girValid = m_Tauler.girValid(m_Figura_a);
    if (!girValid)
    {
        if (direccio == GIR_HORARI)
            direccio = GIR_ANTI_HORARI;
        else
            direccio = GIR_HORARI;
        m_Figura_a.GirarFigura(direccio);
    }
    return girValid;
}

bool Joc::mouFigura(int direccio)
{
    m_Figura_a.mouFigura(direccio);
    bool movimentValid = m_Tauler.movimentValid(m_Figura_a);
    if (!movimentValid)
        m_Figura_a.mouFigura(-direccio);
    return movimentValid;
}

int Joc::baixaFigura()
{
    int nFiles = 0;
    m_Figura_a.BaixaFigura();
    if (!m_Tauler.movimentValid(m_Figura_a))
    {
        m_Figura_a.PujaFigura();
        nFiles = m_Tauler.colocaFigura(m_Figura_a);
        m_Figura_a.Inicialitza_Figura(NO_FIGURA);
    }
    return nFiles;
}

void Joc::escriuTauler(const string& nomFitxer)
{
    ofstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        if (m_Figura_a.getTipus() != NO_FIGURA)
            m_Tauler.colocaFigura(m_Figura_a);

        int tauler[MAX_FILA][MAX_COL];

        m_Tauler.getValorsTauler(tauler);
        for (int i = 0; i < MAX_FILA; i++)
        {
            for (int j = 0; j < MAX_COL; j++)
            {
                fitxer << tauler[i][j] << " ";
            }
            fitxer << endl;
        }

        fitxer.close();
    }
}
