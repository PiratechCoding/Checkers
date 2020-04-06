// Checkers.cpp : This file contains the 'main' function. Program execution begins and ends there.//

#include "GameBoard.h"
#include <iostream>


using namespace std;
int main()
{
    GameBoard game;
    int inputHeight = 8,inputWidith = 8;
    game.gbSetSize(inputWidith, inputHeight);
    cout << "Widith of Board: " <<inputWidith <<"\n";
    cout << "Height of Board: " << inputHeight << "\n";  //Set up the size of the board
    game.gbPrint(game.gbWidith,game.gbHeight);
    return 0;
}
