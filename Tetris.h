#ifndef TETRIS_H
#define TETRIS_H

#include <stdio.h>
#include <string>
#include "Partida.h"

using namespace std;

class Tetris
{
public:
	Tetris();
	~Tetris();
	void menu();
	void juganormal();
	void jugatest();
	void mostraresultats();

private:
	Partida m_partida;
};

#endif
