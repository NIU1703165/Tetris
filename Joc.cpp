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

	}
}

bool Joc::giraFigura(DireccioGir direccio)
{

}

bool Joc::mouFigura(int direccio)
{

}

int Joc::baixaFigura()
{

}

void Joc::escriuTauler(const string& nomFitxer)
{

}
