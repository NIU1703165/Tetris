#include "Figura.h"

void Figura::FormaZero()
{
	for (int i = 0; i < m_TamanyFigura[0]; i++)
	{
		for (int j = 0; j < m_TamanyFigura[1]; j++)
		{
			m_HitBoxFigura[i][j] = 0;
		}
	}
}

Figura::Inicialitza_Figura_Tipus(TipusFigura t, int col, const int& fil)
{
	m_TpusFigura = t;
	DireccioGir = 0;
	m_Posicio_actual[0] = fil; // [0] = posicio_fila, [1] = posicio_columne;
	m_Posicio_actual[1] = col; // [0] = posicio_fila, [1] = posicio_columne;
	Figura::Inicialitza_Figura(t);
}

Figura::Inicialitza_Figura(TipusFigura t)
{
	switch (t)
	{
	case FIGURA_O:
	{
		m_TamanyFigura[0] = 2;
		m_TamanyFigura[1] = 2;
		FormaZero();
		m_HitBoxFigura[0][0] = 1;
		m_HitBoxFigura[0][1] = 1;
		m_HitBoxFigura[1][0] = 1;
		m_HitBoxFigura[1][1] = 1;
		m_ColorFigura = COLOR_GROC;
		break;
	}
	case FIGURA_I:
	{
		m_TamanyFigura[0] = 4;
		m_TamanyFigura[1] = 4;
		FormaZero();
		m_HitBoxFigura[1][0] = 1;
		m_HitBoxFigura[1][1] = 1;
		m_HitBoxFigura[1][2] = 1;
		m_HitBoxFigura[1][3] = 1;
		m_ColorFigura = COLOR_BLAUCEL;
		break;
	}
	case FIGURA_T:
	{
		m_TamanyFigura[0] = 3;
		m_TamanyFigura[1] = 3;
		FormaZero();
		m_HitBoxFigura[0][1] = 1;
		m_HitBoxFigura[1][0] = 1;
		m_HitBoxFigura[1][1] = 1;
		m_HitBoxFigura[1][2] = 1;
		m_ColorFigura = COLOR_MAGENTA;
		break;
	}
	case FIGURA_J:
	{
		m_TamanyFigura[0] = 3;
		m_TamanyFigura[1] = 3;
		FormaZero();
		m_HitBoxFigura[0][0] = 1;
		m_HitBoxFigura[1][0] = 1;
		m_HitBoxFigura[1][1] = 1;
		m_HitBoxFigura[1][2] = 1;
		m_ColorFigura = COLOR_BLAUFOSC;
		break;
	}
	case FIGURA_L;
	{
		m_TamanyFigura[0] = 3;
		m_TamanyFigura[1] = 3;
		FormaZero();
		m_HitBoxFigura[0][2] = 1;
		m_HitBoxFigura[1][0] = 1;
		m_HitBoxFigura[1][1] = 1;
		m_HitBoxFigura[1][2] = 1;
		m_ColorFigura = COLOR_TARONJA;
		break;
	}
	case FIGURA_Z:
	{
		m_TamanyFigura[0] = 3;
		m_TamanyFigura[1] = 3;
		FormaZero();
		m_HitBoxFigura[0][1] = 1;
		m_HitBoxFigura[1][0] = 1;
		m_HitBoxFigura[1][1] = 1;
		m_HitBoxFigura[1][2] = 1;
		m_ColorFigura = COLOR_VERMELL;
		break;
	}
	case FIGURA_S:
	{
		m_TamanyFigura[0] = 3;
		m_TamanyFigura[1] = 3;
		FormaZero();
		m_HitBoxFigura[0][1] = 1;
		m_HitBoxFigura[0][2] = 1;
		m_HitBoxFigura[1][0] = 1;
		m_HitBoxFigura[1][1] = 1;
		m_ColorFigura = COLOR_VERD;
		break;
	}
	default:
		cout << "�ERROR - Aquesta figura no existeix!" << endl;
		break;
	}
}

void Figura::GirarFigura(DireccioGir DirGir)
{
	if (m_TamanyFigura[0] == 4)
	{
		if (DirGir == 0) //Gir Horari
		{
			int c_matriu[m_TamanyFigura[0]][m_TamanyFigura[0];

			for (int i = 0; i < m_TamanyFigura[0]; i++)
			{
				for (int j = 0; j < m_TamanyFigura[0]; j++)
				{
					c_matriu[i][j] = m_HitBoxFigura[i][j];
				}
			}

			for (int i = 0; i < m_TamanyFigura[0]; i++)
			{
				for (int j = 0; j < m_TamanyFigura[0]; j++)
				{
					m_HitBoxFigura[i][j] = c_matriu[(m_TamanyFigura[0] - 1) - j][i];
				}
			}
		}
		else //Gir AntiHorari
		{
			int c_matriu[m_TamanyFigura[0]][m_TamanyFigura[0]];

			for (int i = 0; i < m_TamanyFigura[0]; i++)
			{
				for (int j = 0; j < m_TamanyFigura[0]; j++)
				{
					c_matriu[i][j] = m_HitBoxFigura[i][j];
				}
			}

			for (int i = 0; i < m_TamanyFigura[0]; i++)
			{
				for (int j = 0; j < m_TamanyFigura[0]; j++)
				{
					m_HitBoxFigura[i][j] = c_matriu[j][(m_TamanyFigura[0] - 1) - i];
				}
			}
		}
	}
	else
	{
		int c_matriu[m_TamanyFigura[0]][m_TamanyFigura[0]];

		for (int i = 0; i < m_TamanyFigura[0]; i++)
		{
			for (int j = 0; j < m_TamanyFigura[0]; j++)
			{
				c_matriu[i][j] = m_HitBoxFigura[i][j];
			}
		}

		for (int i = 0; i < m_TamanyFigura[0]; i++)
		{
			for (int j = 0; j < m_TamanyFigura[0]; j++)
			{
				m_HitBoxFigura[i][j] = c_matriu[Tamany - 1 - j][i];
			}
		}
	}
	
}


void Figura::PujaFigura()
{
	m_Posicio_actual[0] -= 1;
}

void Figura::BaixaFigura()
{
	m_Posicio_actual[0] += 1;
}

void Figura::mouFigura(int Direccio)
{
	int m_Posicio_actual[1] += Direccio;
}