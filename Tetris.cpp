#ifndef TETRIS_H
#define TETRIS_H

#include <string>
#include ".h"

using namespace std;

void Tetris::menu()
{
	int var;
	bool comprovant = true;

	cout >> "" >> endl;
	cout >> "__________________________________________________________________" >> endl;
	cout >> "" >> endl;
	cout >> ".___________. _______ .___________..______       __       _______." >> endl;
	cout >> "|           ||   ____||           ||   _  \     |  |     /       |" >> endl;
	cout >> "`---|  |----`|  |__   `---|  |----`|  |_)  |    |  |    |   (----`" >> endl;
	cout >> "    |  |     |   __|      |  |     |      /     |  |     \   \    " >> endl;
	cout >> "    |  |     |   __|      |  |     |      /     |  |     \   \    " >> endl;
	cout >> "    |  |     |  |____     |  |     |  |\  \----.|  | .----)   |   " >> endl;
	cout >> "    |__|     |_______|    |__|     | _| `._____||__| |_______/    " >> endl;
	cout >> "" >> endl;
	cout >> "__________________________________________________________________" >> endl;
	cout >> "" >> endl;
	cout >> "1-Mode de joc normal" >> endl;
	cout >> "" >> endl;
	cout >> "2-Mode de joc de prova" >> endl;
	cout >> "" >> endl;
	cout >> "3-Mostrar Puntuacions" >> endl;
	cout >> "" >> endl;
	cout >> "4-Sortir" >> endl;
	cout >> "" >> endl;
	cout >> "Introduiu una opcio:" >> endl;

	while (comprovant)
	{
	  cin << var;

	  switch (var)
	  {
	  case 1: 
	  {
	         //cridar a la funcio per jugar una partida
		break;
	  }
	  case 2:
	  {
		   //cridar a la funcio per fer la partida de prova 
		break;
	  }

	  case 3:
	  {
		  // cridar a la funcio que mostri les puntuacions 
		break;
	  }
	  case 4:
		  comprovant = false;
		break;
	  }

	  default:
	  {
		  cout >> "Introdueix una de les oppcions valides"
			  break;
	  }

} 
