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
					pieceLocationData[i][j].render();
			}
			cout << "\n ";
		}
	}
	 void GameBoard::fillWithEmpty(int x, int y) {
		 for (int i = 0; i < y; i++) {
			 for (int j = 0; j < x; j++){
				 pieceLocationData[i][j] = Piece();
			 }
		 }
		 {

		 }
	 }
	 void GameBoard::intialPiecePlacement() {	
			 for (int i = 0; i < gbHeight/2 -1; i++)
			 {
				 for (int j =(gbHeight-i) % 2; j < gbWidith;j += 2 )
				 {
					 pieceLocationData[i][j].isWhite = true;
				 }

			 }
			 for (int i = gbHeight - 1; i >= gbHeight/2 + 1; i--) {
				 for (int j = (gbHeight -i) % 2; j < gbWidith; j += 2)
				 {
					 pieceLocationData[i][j].isBlack = true;
				 }
			 }
	 }
	
