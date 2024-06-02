#include <string>
#include "Tetris.h"
#include <stdio.h>
#include <string>
#include "Partida.h"
#include <iostream>
#include <conio.h>      

#include "./Partida.h"
#include "./InfoJoc.h"

using namespace std;

Tetris::Tetris()
{

}

Tetris::~Tetris()
{
    guardarPuntuacions();
}



void Tetris::cargarPuntuacions()
{

    ifstream archiu(m_archiuPuntuacions);

    if (archiu.is_open())
    {
        vector < pair < string, int >> puntuacionsTemp;
        string nom;
        int puntuacio;

        while (archiu >> nom >> puntuacio)
        {
            puntuacionsTemp.emplace_back(nom, puntuacio);
        }
        archiu.close();

        // Ordenar por puntuación en orden descendente
        sort(puntuacionsTemp.begin(), puntuacionsTemp.end(), [](const pair < string, int >& a, const pair < string, int>& b)
            {
                return a.second > b.second;
            });

        // Limpiar las listas antes de agregar las puntuaciones ordenadas
        m_puntuacions.clear();
        m_noms.clear();

        // Separar los nombres y puntuaciones ordenados
        for (const auto& p : puntuacionsTemp) {
            m_noms.push_back(p.first);
            m_puntuacions.push_back(p.second);
        }
    }
}

void Tetris::guardarPuntuacions()
{
    ofstream archiu(m_archiuPuntuacions);
    if (archiu.is_open())
    {
        auto itNoms = m_noms.begin();
        auto itPunts = m_puntuacions.begin();
        while (itNoms != m_noms.end() && itPunts != m_puntuacions.end())
        {
            archiu << *itNoms << " " << *itPunts << endl;
            ++itNoms;
            ++itPunts;
        }
        archiu.close();
    }
}
void Tetris::actualizarPuntuacions(int novaPuntuacio, string nom)
{
    m_puntuacions.push_back(novaPuntuacio);
    m_puntuacions.sort(std::greater<int>());

    auto itPunts = m_puntuacions.begin();
    auto itNoms = m_noms.begin();
    for (; itPunts != m_puntuacions.end(); ++itPunts, ++itNoms)
    {
        if (*itPunts == novaPuntuacio)
        {
            m_noms.insert(itNoms, nom);
            break;
        }
    }

    if (m_puntuacions.size() > 10)
    {
        m_puntuacions.pop_back();
        m_noms.pop_back();
    }
}

void Tetris::jugar()
{                            //no acabada la fucnio

}

void Tetris::mostrarPuntuacions()
{
    cout << "Millors Puntuacions" << endl;
    auto itNoms = m_noms.begin();
    auto  itPunts = m_puntuacions.begin();
    for (int i = 1; itNoms != m_noms.end() && itPunts != m_puntuacions.end(); ++itNoms, ++itPunts, ++i)
    {
        cout << i << "-" << *itNoms << " " << *itPunts << endl;
    }
}

