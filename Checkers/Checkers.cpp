// Checkers.cpp : This file contains the 'main' function. Program execution begins and ends there.//

#include "GameBoard.h"
#include <iostream>

using namespace std;
int main()
{
    int boardHeight = 8, boardWidith = 8;
    char rowSelect = 0, rowMove = 0;          //User Input Decleration
    int columnSelect = 0, columnMove = 0;
    int  teamWhite;
    int  teamBlack;
    GameBoard game(boardWidith,boardHeight);  //Initial Setup for the Board
    bool gameFlag = true;
    cout << "\n\n";
    while (gameFlag == true) {
        game.gbRender();
        cout << "\nSelect Piece:";
        cin >> rowSelect >> columnSelect;
        cout << "Move Piece:";
        cin >> rowMove >> columnMove;
        game.gbPieceMove(columnSelect, rowSelect, columnMove, rowMove);
        if (game.winCondition(&teamBlack, &teamWhite))
            gameFlag = false;
    }
    if (teamBlack == 0)
        cout << "White Wins!";
    else if (teamWhite == 0)
        cout << "Black Wins!";
    return 0;
}