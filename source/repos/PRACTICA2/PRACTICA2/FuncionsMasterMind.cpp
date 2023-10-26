#include "FuncionsMasterMind.h"

using namespace std;

void Menu()
{
	cout << "MASTER MIND" << endl;
	cout << endl;
	cout << "Escull una opcio: " << endl;
	cout << endl;
	cout << "Opcio 1 Ajuda" << endl;
	cout << "Opcio 2 Jugar" << endl;
	cout << "Opcio 3 Sortir" << endl;

}

void Ajuda()
{
	cout << "L'objectiu del joc es trobar el codi ocoult" << endl;
	cout << "El codi es de longitud " << LONG_CODI << " nombres del 0 al 9" << endl;
	cout << "Despres de cada intent et dona la seguent informacio:" << endl;
	cout << "Nombre de nombres encertats (en la posicio correcte)" << endl;
	cout << "Nommbre de nombres aproximats (correctes pero mal col.locats)" << endl;
	cout << "El nombre de intents son " << MAX_INTENTS << endl;
}
void GenerarCodiOcult(int CodiMaster[], int DIM)
{
	for (int i = 0; i < DIM; i++)
	{
		CodiMaster[i] = Aleatori(0, 9);
	}
}
int LlegirNombre(int min, int max)
{
	int xx;

	cout << "Entra valor entre " << min << " i " << max << endl;
	cin >> xx;

	while (xx < min || xx > max)
	{
		cout << "Error valor fora del interval" << endl;
		cout << "Entra valor entre " << min << " i " << max << endl;
		cin >> xx;
	}
	return xx;
}

void IntToArray(int NOMBRE, int codi[], int DIM)
{
	for (int i = DIM - 1; i >= 0; i--)
	{
		codi[i] = NOMBRE % 10;
		NOMBRE = NOMBRE/10;
	}
}

void InicialitzarArray(int Array[], int Dim, int& Valor)
{
	for (int i = 0; i < Dim; i++)
	{
		Array[i] = Valor;
	}
}

int Minim(int Valor1, int Valor2)
{
	if (Valor1 == Valor2) 
	{
		return Valor1;
	}

	if (Valor1 < Valor2) 
	{
		return Valor1;
	}
	else 
	{
		return Valor2;
	}

}

void ImprimirComparacions(int Encerts, int Aproximacions)
{
	cout << "Aquest codi te " << Encerts << " Encerts i " << Aproximacions << " Aproximacions" << endl;
}

void FrequenciaDigit(int Codi[], int DIM, int Frequencia[])
{
	for (int i = 0; i < DIGITS; i++)
	{
		for (int x = 0; x < DIM; x++)
		{
			if (Codi[x] == i)
			{
				Frequencia[i]++;
			}
		}
	}
}
