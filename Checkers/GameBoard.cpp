#include "GameBoard.h"
#include "Piece.h"
#include <iostream>
using namespace std;

GameBoard::GameBoard(int x, int y) {
	 gbWidith = x;
	 gbHeight = y;
	 fillWithEmpty(gbWidith, gbHeight);
}
 bool teamTurn = false; //False = Team White //True = Team Black
 int gbWidith;
 int gbHeight;
 Piece pieceLocationData[8][8] = {};

	 void GameBoard::gbSetSize(int x, int y) {
		gbWidith = x;
		gbHeight = y;
	}
	 void GameBoard::gbPrint() {  //Print Current Game Board
		 cout << " ";
		for (int i = 0; i < gbHeight; i++)
		{
			for (int j = 0; j < gbWidith; j++)
			{
				if (pieceLocationData[i][j].isEmpty != 0) {
					pieceLocationData[i][j].render();
				}
				else
					cout << "[ ] ";
			}
			cout << "\n ";
		}
	}
	 void GameBoard::fillWithEmpty(int x, int y) {
		 for (int i = 0; i < y; i++) {
			 for (int j = 0; j < x; j++){
				 pieceLocationData[i][j].isEmpty = 1;
			 }
		 }
		 {

		 }
	 }
	 void GameBoard::intialPiecePlacement() {	
			 for (int i = 0; i < gbHeight/2; i++)
			 {
				 for (int j = 1; j < gbWidith;j += 2 )
				 {
					 pieceLocationData[i][j] = TeamWhite();
				 }
			 }
			 for (int i = gbHeight - 1; i > gbHeight/2 ; i--) {
				 for (int j = gbWidith; j > 0;j -= 2)
				 {
					 pieceLocationData[i][j] = TeamBlack();
				 }
			 }
	 }
	
