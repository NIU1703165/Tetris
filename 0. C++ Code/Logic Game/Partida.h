#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>

#include "InfoJoc.h"
#include "Joc.h"

using namespace std;

class Partida 
{
public:
    Partida();
    ~Partida();
    void actualitza(double deltaTime);
    void nivell();
    void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
    void menu();
    void puntuacio();
    void actualitzapunts();    //la fas tu titu
    int getpunts() { return m_puntuacio; }
    Joc GetJoc() { return m_joc; }
private:
    double m_temps;
    float m_velocitat;
    Joc m_joc;
    int puntuacio_files;
    int m_puntuacio;
    int m_nivell;
};


#endif 
