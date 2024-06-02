#include "Joc.h"
#include <fstream>

void Joc::OmplirBolsa()
{
    bolsa.clear();
    for (int i = 1; i <= 7; ++i)
    {
        bolsa.push_back(i);
    }
}

int Joc::agafarNumero()
{
    if (bolsa.empty())
    {
        OmplirBolsa();
    }

    int indice = rand() % bolsa.size();
    int numero = bolsa[indice];
    bolsa.erase(bolsa.begin() + indice);

    return numero;
}

TipusFigura Joc::convertirANumeroAFigura(int numero) {
    if (numero >= NO_FIGURA && numero <= FIGURA_S) {
        return static_cast<TipusFigura>(numero);
    }
    else 
    {
        return NO_FIGURA;
    }
}

TipusFigura Joc::generafigura()
{
    return convertirANumeroAFigura(agafarNumero());
}

void Joc::inicialitza()
{
    int taulerInicial[MAX_FILA][MAX_COL];
    m_files_eliminades = 0;
    m_figures_colocades = 0;
    srand(time(0));
    OmplirBolsa();
    m_Final = false;

    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            taulerInicial[i][j] = 0;
        }
    }
    m_Tauler.inicialitza(taulerInicial);
    
    m_Figura_a.Inicialitza_Figura_Tipus(generafigura(), Columnaaleatoria(), 1);
}

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

    bool girValid = m_Tauler.Xoca(m_Figura_a);
    if (girValid)
    {
        if (direccio == GIR_HORARI)
        {
            direccio = GIR_ANTI_HORARI;
        }
         else
         {
            direccio = GIR_HORARI;
         }
       
        m_Figura_a.GirarFigura(direccio);
    }
    return !girValid;
}

bool Joc::mouFigura(int direccio)
{
    m_Figura_a.mouFigura(direccio);
   
    bool movimentValid = m_Tauler.Xoca(m_Figura_a);
    
    if (movimentValid)
    {
        m_Figura_a.mouFigura(-direccio);
    }
    
    return !movimentValid;
}

int Joc::baixaFigura()
{
    int FilesComplertes = 0;
    m_Figura_a.BaixaFigura();
    
    if (m_Tauler.Xoca(m_Figura_a))
    {
        m_Figura_a.PujaFigura();
        m_Tauler.colocaFigura(m_Figura_a);
        FilesComplertes = m_Tauler.getFilesCompletes();
        m_Figura_a.Inicialitza_Figura_Tipus(generafigura(), Columnaaleatoria(), 1);
        Figura F_temp = m_Figura_a;

        if (m_Tauler.Xoca(F_temp))
        {
            m_Final = true;
        }
        else
        {
            m_figures_colocades++;
        }
    }

    m_Tauler.ElimiarFilesComplertes();
    m_files_eliminades = FilesComplertes;

    return FilesComplertes;
}

bool Joc::baixaFigura_2()
{
    m_Figura_a.BaixaFigura();

    if (m_Tauler.Xoca(m_Figura_a))
    {
        m_Figura_a.PujaFigura();
        baixaFigura();
        return true;
    }
}

void Joc::escriuTauler(const string& nomFitxer)
{
    ofstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        if (m_Figura_a.getTipusFigura() != NO_FIGURA)
            m_Tauler.colocaFigura(m_Figura_a);

        int tauler[MAX_FILA][MAX_COL];

        m_Tauler.getTauler(tauler);
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

int Joc::Columnaaleatoria()
{
    int random_num = rand() % 12;

    while(random_num > 8 || random_num < 1)
    {
        random_num = rand() % 12;
    }
    return random_num;
}