#include "GameBoard.h"
#include <iostream>
using namespace std;

     
	 void GameBoard::gbSetSize(int x, int y) {
		gbWidith = x;
		gbHeight = y;
	}
	 void GameBoard::gbPrint(int x, int y) {
		 cout << " ";
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				cout << "[] ";
			}
			cout << "\n ";
		}
	}
