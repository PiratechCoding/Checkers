// Checkers.cpp : This file contains the 'main' function. Program execution begins and ends there.//

#include "GameBoard.h"
#include <iostream>


using namespace std;
int main()
{
    int boardHeight = 8, boardWidith = 8;
    GameBoard game(boardWidith,boardHeight);
    game.gbPrint();
    game.intialPiecePlacement();
    cout << "\n";
    game.gbPrint();
    
                                                   //Initial Setup for the Board
    cout << "\nWould you like to play a game: (Y/N)\n";


    return 0;
}
