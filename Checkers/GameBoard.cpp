#include "GameBoard.h"
#include "Piece.h"
#include <iostream>
using namespace std;

GameBoard::GameBoard(int x, int y){	
	gbWidith = x;
	gbHeight = y;
	LETTEROFFSET = 65;
	gbStart();
}
 int LETTEROFFSET;
 int teamTurn;								//1 = Team White //0 = Team Black
 int gbWidith;
 int gbHeight;
 Piece pieceLocationData[8][8];				//Please Refactor me to One Dimensional Array

 
 bool GameBoard::isValidSelection(int indexSelectionX, int indexSelectionY) {
	 if (indexSelectionX >= gbWidith || indexSelectionY >= gbHeight)
		 return false;
	 if (indexSelectionX < 0 || indexSelectionY < 0)
		 return false;
	 //Ensure Selection is safe to pass
	 if (pieceLocation[indexSelectionY][indexSelectionX].getTeam() != teamTurn)
		 return false;
	 //Ensure Selection is correct team and not Empty
	 return true;
 }
 void GameBoard::gbPieceMove(int selectPieceX, int selectPieceY, int newPositionX, int newPositionY) {
	 selectPieceX = selectPieceX - 1;
	 newPositionX = newPositionX - 1;
	 selectPieceY = selectPieceY - LETTEROFFSET;
	 newPositionY = newPositionY - LETTEROFFSET;
	 //User input Adjust
	 if (isValidSelection(selectPieceX, selectPieceY)) {
		 if (pieceLocation[selectPieceY][selectPieceX].validMove(selectPieceX, selectPieceY, newPositionX, newPositionY, teamTurn)) {
			 pieceLocation[selectPieceY][selectPieceX].setEmpty(true);			//Empty current grid when valid
			 pieceLocation[newPositionY][newPositionX].setEmpty(false);			//Fill new current grid
			 if (teamTurn == 0) {												//Black Turn
				 pieceLocation[selectPieceY][selectPieceX].clearTeams();
				 pieceLocation[newPositionY][newPositionX].setTeamBlack();
				 setTeamTurn();
			 }
			 else if (teamTurn == 1) {											// White Turn
				 pieceLocation[selectPieceY][selectPieceX].clearTeams();
				 pieceLocation[newPositionY][newPositionX].setTeamWhite();
				 setTeamTurn();
			 }
		 }
		 else 
			 cout << "Invalid Move Please Redo\n";
	 }
	 else
		 cout << "Invalid Move Please Redo\n";
 }
	  void GameBoard::gbRender() {								//Print Current Game Board  //Please Refactor me
		 cout << " ";
		 char gbDisplayLetters = 64;							//Letter A through H
		for (int i = 0; i < gbHeight; i++)
		{
			gbDisplayLetters++;
			cout << gbDisplayLetters << "  ";					//Print Siding Letters
			for (int j = 0; j < gbWidith; j++)
			{
					pieceLocation[i][j].render();				//Render Each game square with a Piece or Empty
			}
			cout << "\n ";
		}
		cout << "\n    ";
		for (int k = 1; k <= gbWidith; k++)
		{
			cout <<" " << k << "  ";							//Attach Column numbering to the bottom of board
		}
		cout << "\n";
		turnReadOut();
	}


	 void GameBoard::fillWithEmpty() {							//Generate Empty Board with no piece positions //refactor me
		 for (int i = 0; i < gbHeight; i++) {
			 for (int j = 0; j < gbWidith; j++){
				 pieceLocation[i][j] = Piece(&gbWidith,&gbHeight);
			 }
		 }
		 {

		 }
	 }
	 void GameBoard::intialPiecePlacement() {					//Generate starting piece position for standard game, Called after empty board is set //refactor me
			 for (int i = 0; i < gbHeight/2 -1; i++)
			 {
				 for (int j =(gbHeight-i) % 2; j < gbWidith;j += 2 )
				 {
					 pieceLocation[i][j].setTeamWhite();
				 }

			 }
			 for (int i = gbHeight - 1; i >= gbHeight/2 + 1; i--) {
				 for (int j = (gbHeight -i) % 2; j < gbWidith; j += 2)
				 {
					 pieceLocation[i][j].setTeamBlack();
				 }
			 }
	 }
	
	 void  GameBoard::gbStart() {						 //Gameboard Object Init
		fillWithEmpty();
		intialPiecePlacement();
		teamTurn = 0;
	 }
	 void GameBoard::setTeamTurn() {
		 if (teamTurn == 1)
			 teamTurn = 0;
		 else if (teamTurn == 0)
			 teamTurn = 1;
	 }
	 void GameBoard::turnReadOut() {
		 if (teamTurn == 0) {
			 cout << "\nBlack's Turn";
		 }
		 else if (teamTurn == 1)
			 cout << "\nWhite's Turn";
		 else {
			 cout << "\nError";
		 }
	 }