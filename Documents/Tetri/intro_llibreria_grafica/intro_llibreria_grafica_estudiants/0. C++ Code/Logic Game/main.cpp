//
//  main.cpp
//
//  Copyright � 2018 Compiled Creations Limited. All rights reserved.
//

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined  (_WIN64)

#include <iostream>
//Definicio necesaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED
#include <windows.h>
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#include <conio.h>      /* getch */ 

#elif __APPLE__
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

#endif

#include "./Partida.h"
#include "./InfoJoc.h"
#include "Tetris.h"

using namespace std;

int main(int argc, const char* argv[])
{
    //Instruccions necesaries per poder incloure la llibreria i que trobi el main
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO);

    //Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
    Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
    //Mostrem la finestra grafica

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;

    bool comprovant = true;
    int var;
    int punts;
    string nom;
    string archiu;

    while (comprovant)
    {
        Partida game;
        game.menu();
        cin >> var;
        system("cls");

        switch (var)
        {
        case 1:
            do
            {
                pantalla.show();
                LAST = NOW;
                NOW = SDL_GetPerformanceCounter();
                deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

                // Captura tots els events de ratolí i teclat de l'ultim cicle
                pantalla.processEvents();

                game.actualitza(deltaTime);


                // Actualitza la pantalla
                pantalla.update();
            } while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));


            break;

        case 2:
            // Call the function to play a test game
            break;

        case 3:


            break;

        case 4:
            comprovant = false; // Exit the loop
            break;

        default:
            cout << "Introdueix una de les opcions valides" << endl;
            break;
        }
        game.~Partida();
    }

    SDL_Quit();
    return 0;
}
