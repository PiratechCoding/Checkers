#include "GameBoard.h"
#include "Piece.h"
#include <iostream>
using namespace std;

GameBoard::GameBoard(int x, int y){
	teamTurn = 1;
	gbWidith = x;
	gbHeight = y;
	LETTEROFFSET = 65;
	gbStart();
}
 int LETTEROFFSET;
 int teamTurn;								//False = Team White //True = Team Black
 int gbWidith;
 int gbHeight;
 Piece pieceLocationData[8][8];				//Please Refactor me to One Dimensional Array

 void GameBoard::turnReadOut() {
	 if (teamTurn) {
		 cout << "\nBlack's Turn";
	 }
	 else if(!teamTurn)
		 cout << "\nWhite's Turn";
	 else {
		 cout << "\nError";
	 }
 }
 bool isValidSelection(int indexSelectionX, int indexSelectionY) {
	 if (indexSelectionX >= gbWidith || indexSelectionY >= gbHeight)
		 return false;
	 if (indexSelectionX < 0 || indexSelectionY < 0)
		 return false;
	 if (pieceLocationData[indexSelectionX][indexSelectionY].getTeam != teamTurn)
		 return false;
	 return true;
 }
 void GameBoard::gbPieceMove(int selectPieceX, int selectPieceY, int newPositionX, int newPositionY) {
	 //User input Adjust
	 selectPieceX = selectPieceX - LETTEROFFSET;
	 newPositionX = newPositionX - LETTEROFFSET;
	 selectPieceY = selectPieceY - 1;
	 newPositionY = newPositionY - 1;
	 if (isValidSelection(selectPieceX, selectPieceY)) {
		 if (pieceLocationData[selectPieceX][selectPieceY].validMove(selectPieceX, selectPieceY, newPositionX, newPositionY, teamTurn)) {
			 pieceLocationData[selectPieceX][selectPieceY].setEmpty(true);			//Empty current grid when valid
			 pieceLocationData[newPositionX][newPositionY].setEmpty(false);			//Fill new current grid
			 if (teamTurn) {						//Black Turn
				 pieceLocationData[selectPieceX][selectPieceY].clearTeams();
				 pieceLocationData[newPositionX][newPositionY].setTeamBlack();
			 }
			 else if (!teamTurn) {					// White Turn
				 pieceLocationData[selectPieceX][selectPieceY].clearTeams();
				 pieceLocationData[newPositionX][newPositionY].setTeamWhite();
			 }
		 }
		 else 
			 cout << "Invalid Move Please Redo\n";
		 if (teamTurn)
			 teamTurn--;
		 if (!teamTurn)
			 teamTurn++;
	 }
	 else
		 cout << "Invalid Move Please Redo\n";
 }
	  void GameBoard::gbRender() {  //Print Current Game Board  //Please Refactor me
		 cout << " ";
		 char gbDisplayLetters = 64; //Letter A through H
		for (int i = 0; i < gbHeight; i++)
		{
			gbDisplayLetters++;
			cout << gbDisplayLetters << "  ";  //Print Siding Letters
			for (int j = 0; j < gbWidith; j++)
			{
					pieceLocationData[i][j].render();   //Render Each game square with a Piece or Empty
			}
			cout << "\n ";
		}
		cout << "\n    ";
		for (int k = 1; k < 9; k++)
		{
			cout <<" " << k << "  ";    //Attach Column numbering to the bottom of board
		}
		cout << "\n";
		turnReadOut();
	}


	 void GameBoard::fillWithEmpty() { //Generate Empty Board with no piece positions //refactor me
		 for (int i = 0; i < gbHeight; i++) {
			 for (int j = 0; j < gbWidith; j++){
				 pieceLocationData[i][j] = Piece(&gbWidith,&gbHeight);
			 }
		 }
		 {

		 }
	 }
	 void GameBoard::intialPiecePlacement() {	//Generate starting piece position for standard game, Called after empty board is set //refactor me
			 for (int i = 0; i < gbHeight/2 -1; i++)
			 {
				 for (int j =(gbHeight-i) % 2; j < gbWidith;j += 2 )
				 {
					 pieceLocationData[i][j].setTeamWhite();
				 }

			 }
			 for (int i = gbHeight - 1; i >= gbHeight/2 + 1; i--) {
				 for (int j = (gbHeight -i) % 2; j < gbWidith; j += 2)
				 {
					 pieceLocationData[i][j].setTeamBlack();
				 }
			 }
	 }
	
	 void  GameBoard::gbStart() {  //Game Start
		fillWithEmpty();
		intialPiecePlacement();
	 }