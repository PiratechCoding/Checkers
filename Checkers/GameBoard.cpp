#include "GameBoard.h"
#include "Piece.h"
#include <iostream>
using namespace std;

GameBoard::GameBoard(int x, int y){	
	char rowSelect = 0, rowMove = 0;          //User Input Decleration
	int columnSelect = 0, columnMove = 0;
	gbWidith = x;
	gbHeight = y;
	LETTEROFFSET = 65;
	gbStart();
}
 int LETTEROFFSET;
 int teamTurn;								//1 = Team White //0 = Team Black
 int gbWidith;
 int gbHeight;
 Piece pieceLocation[8][8];				//Please Refactor me to One Dimensional Array
 bool GameBoard::winCondition(int* teamBlackPointer, int* teamWhitePointer) {
	 int teamWhite = 0;
	 int teamBlack = 0;
	 for (int i; i < gbHeight; i++) {
		 for (int j = 0; j < gbWidith; j++) {
			 if (pieceLocation[i][j].getTeam() == 0)
				 teamBlack++;
			 else if (pieceLocation[i][j].getTeam() == 1)
				 teamWhite++;
		 }
	 }
	 if (teamBlack == 0) {
		 *teamBlackPointer = teamBlack;
		 *teamWhitePointer = teamWhite;
		 return true;
	 }
	 else if (teamWhite == 0) {
		 teamBlackPointer = &teamBlack;
		 teamWhitePointer = &teamWhite;
		 return true;
	 }
	 else
		 return false;
 }
 
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
 void GameBoard::gbBoardUpdate(int selectPieceX, int selectPieceY, int newPositionX, int newPositionY,bool captureFlag) {
	 if (teamTurn == 0) {												//Black Turn
		 pieceLocation[selectPieceY][selectPieceX].clearPiece();
		 pieceLocation[newPositionY][newPositionX].setTeamBlack();
		 gbPieceUpgrade(newPositionX, newPositionY);
	 }
	 else if (teamTurn == 1) {											// White Turn
		 pieceLocation[selectPieceY][selectPieceX].clearPiece();
		 pieceLocation[newPositionY][newPositionX].setTeamWhite();
		 gbPieceUpgrade(newPositionX, newPositionY);
	 }
	 else
		 cout << "Error:Team is Empty";
	 if (!captureFlag) {
		 setTeamTurn();
	 }
 }
 void GameBoard::gbPieceUpgrade(int selectPieceX, int selectPieceY) {
	 if (pieceLocation[selectPieceX][selectPieceY].getKingStatus == false) {
		 if (teamTurn == 0) {
			 if (selectPieceY == gbHeight - 1)
				 pieceLocation[selectPieceX][selectPieceY].setKingStatus(1);
		 }
		 if (teamTurn == 1) {
			 if (selectPieceY == 0)
				 pieceLocation[selectPieceX][selectPieceY].setKingStatus(1);
		 }
	 }
 }
 bool GameBoard::isCaptureble(int selectPieceX, int selectPieceY, int newPositionX, int newPositionY) {
	 int emptyStatus = pieceLocation[newPositionY][newPositionX].getEmptyStatus();
	 if (emptyStatus == false) {
		 if (pieceLocation[selectPieceY][selectPieceX].getKingStatus()) {
			 if (upperValidation(newPositionY)) {
				 if (lowerValidation(newPositionX)) {
					 if (pieceLocation[newPositionY + 1][newPositionX - 1].getEmptyStatus() == true && selectPieceX != newPositionX) //Check Left Square
						 return true;
				 }
				 if (rightMostValidation(newPositionX))
					 if (pieceLocation[newPositionY + 1][newPositionX + 1].getEmptyStatus() == true && selectPieceX != newPositionX) //Check Right Square
						 return true;
			 }
			 if (lowerValidation(newPositionY)) {
				 if (lowerValidation(newPositionX)) {
					 if (pieceLocation[newPositionY - 1][newPositionX - 1].getEmptyStatus() == true && selectPieceX != newPositionX)
						 return true;
				 }
				 if (rightMostValidation(newPositionX)) {
					 if (pieceLocation[newPositionY - 1][newPositionX + 1].getEmptyStatus() == true && selectPieceX != newPositionX)
						 return true;
				 }
			 }
		 }
		 else if (pieceLocation[selectPieceY][selectPieceX].getTeam() == 0) {
			 if (upperValidation(newPositionY)) {
				 if (lowerValidation(newPositionX)) {
					 if(pieceLocation[newPositionY + 1][newPositionX - 1].getEmptyStatus() == true && selectPieceX != newPositionX) //Check Left Square
						 return true;
				 }
				 if(rightMostValidation(newPositionX))
					 if(pieceLocation[newPositionY + 1][newPositionX + 1].getEmptyStatus() == true && selectPieceX != newPositionX) //Check Right Square
						 return true;
			 }
		 }
		 else if (pieceLocation[selectPieceY][selectPieceX].getTeam() == 1) {
			 if (lowerValidation(newPositionY)) {
				 if (lowerValidation(newPositionX)) {
					 if (pieceLocation[newPositionY - 1][newPositionX - 1].getEmptyStatus() == true && selectPieceX != newPositionX)
						 return true;
				 }
				 if (rightMostValidation(newPositionX)) {
					 if (pieceLocation[newPositionY - 1][newPositionX + 1].getEmptyStatus() == true && selectPieceX != newPositionX)
						 return true;
				 }
			 }
		 }
		 else {
			 cout << "Piece not Capturable";
			 return false;
		 }
	 }
	 else 
		return false;
 }

 void GameBoard::gbUserInputAfterCapture() {
	 cout << "Move Piece Again:";
	 cin >> rowMove >> columnMove;
 }
 void GameBoard::gbPieceMove(int selectPieceX, int selectPieceY, int newPositionX, int newPositionY) {
	 selectPieceX = selectPieceX - 1;
	 newPositionX = newPositionX - 1;
	 selectPieceY = selectPieceY - LETTEROFFSET;
	 newPositionY = newPositionY - LETTEROFFSET;
	 //User input Adjust
	 if (isValidSelection(selectPieceX, selectPieceY)) {
		 if (isCaptureble(selectPieceX, selectPieceY, newPositionX, newPositionY) && pieceLocation[selectPieceY][selectPieceX].validMove(selectPieceX, selectPieceY, newPositionX, newPositionY, teamTurn)) {
			 gbUserInputAfterCapture();
			 gbBoardUpdate(selectPieceX, selectPieceY, newPositionX, newPositionY,true);
			 gbPieceMove(newPositionX + 1,(newPositionY + LETTEROFFSET),columnMove,rowMove);
		 }
		 else if (pieceLocation[selectPieceY][selectPieceX].validMove(selectPieceX, selectPieceY, newPositionX, newPositionY, teamTurn)) {
			 pieceLocation[selectPieceY][selectPieceX].setEmpty(true);			//Empty current grid when valid
			 pieceLocation[newPositionY][newPositionX].setEmpty(false);			//Fill new current grid
			 gbBoardUpdate(selectPieceX, selectPieceY, newPositionX, newPositionY,false);
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
	 bool GameBoard::upperValidation(int newPosition) {
		 if (newPosition + 1 >= gbHeight) 
			 return false;
		 return true;
	 }
	 bool GameBoard::lowerValidation(int newPostion) {
		 if (newPostion - 1 < 0)
			 return false;
		 return true;
	 }
	 bool GameBoard::rightMostValidation(int newPosition) {
		 if (newPosition + 1 >= gbWidith)
			 return false;
		 return true;
	 }