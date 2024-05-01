#include "Joc.h"

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		int fil, col, gir, tip;
		fitxer >> tip >> fil >> col >> gir;
		m_Figura_a.Inicialitza_Figura_Tipus(tip, col, fil);

		for (int i = 0; i < length; i++)
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
		m_tauler.inicialitza(taulerInicial);
		fitxer.close();
	}
}

bool Joc::giraFigura(DireccioGir direccio)
{
	m_Figura_a.GirarFigura(direccio);

	bool girValid = m_tauler.girValid(m_Figura_a);
	if (girValid)
	{
		if (direccio == GIR_HORARI)
			direccio = GIR_ANTI_HORARI;
		else
			direccio = GIR_HORARI;
		m_Figura_a.GirarFigura(direccio);
	}
	return !girValid;
}

bool Joc::mouFigura(int direccio)
{
	m_Figura_a.mou(direccio);
	bool girValid = m_tauler.girValid(m_Figura_a);
	if (girValid)
		m_Figura_a.mouFigura(-dirX);
	return !girValid;
}

int Joc::baixaFigura()
{
	int nFiles = 0;
	m_Figura_a.mou.BaixaFigura();
	if (m_tauler.girValid(m_Figura_a))
	{
		m_Figura_a.PujaFigura();
		nFiles = m_tauler.colocaFigura(m_Figura_a);
		m_Figura_a.inicialitza(NO_FIGURA, -1, -1);
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
			m_tauler.colocarFigura(m_Figura_a);

		int tauler[MAX_FILA][MAX_COL];

		m_tauler.getValorsTauler(tauler);
		for (int i = 0; i < MAX_FILA; i++)
		{
			for (int j = 0; j < MAX_COL; j++)
			{
				fitxer << int(tauler[i][j]) << " ";
			}
			fitxer << endl;
		}

		fitxer.close();
	}
}
