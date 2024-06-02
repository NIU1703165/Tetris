#ifndef TETRIS_H
#define TETRIS_H

#endif
#include <iostream>
#include <list>
#include <fstream>
#include "Partida.h"

using namespace std;

class Tetris
{
public:
    Tetris();
    ~Tetris();
    void jugar();
    void mostrarPuntuacions();
    void actualizarPuntuacions(int nuevaPuntuacion, string nom);
    void cargarPuntuacions();
    void guardarPuntuacions();
    void setarchiu(string archiu) { m_archiuPuntuacions = archiu; }
    string getarchiu() { return m_archiuPuntuacions; }

private:
    Partida m_partida;
    list<int> m_puntuacions;
    list<string> m_noms;
    string m_archiuPuntuacions;


};




