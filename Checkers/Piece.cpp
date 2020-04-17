#include "Piece.h"
#include <math.h>
#include <iostream>
using namespace std;



Piece::Piece(int* gameBoardWidith,int* gameBoardHeight){
	setEmpty(true);
	clearPiece();
	setKingStatus(false);
	gameWidith = *gameBoardWidith;
	gameHeight = *gameBoardHeight;
}
void Piece::setEmpty(bool emptyStatus) {
	this->isEmpty = emptyStatus;
}
bool Piece::getEmptyStatus() {
	return this->isEmpty;
}
void Piece::setKingStatus(bool kingStatus) {
	this->isKing = kingStatus;
}
bool Piece::getKingStatus() {
	return this->isKing;
}
void Piece::setTeamBlack() {
	this->isEmpty = false;
	this->team = 0;
}
void Piece::setTeamWhite() {		
	this->isEmpty = false;
	this->team = 1;
}
void Piece::clearPiece() {  
	this->team = -1;
	this->setKingStatus(0);
	this->setEmpty(1);
}
int Piece::getTeam() {			// 0 Black 1 White
	return this->team;
}

void Piece::render() {			//Identify Team Color and King Status and render correctly
	if (this->team == 1) {
		if (this->isKing) {
			cout << "[W] ";
		}
		else
			cout << "[w] ";
	}
	else if (this->team == 0) {
		if (this->isKing) {
			cout << "[B] ";
		}
		else
			cout << "[b] ";
	}
	else
		cout << "[_] ";
}

bool Piece::validMove(int currentPositionX, int currentPositionY, int newPositionX, int newPositionY, int teamTurn) {  //Take user input and sanitize	
	if (newPositionX >= gameWidith || newPositionY >= gameHeight)
		return false;
	if (newPositionX < 0 || newPositionY < 0)
		return false;
	//Check if new Movement is out of bounds
	if (isCorrectDirection(currentPositionY, newPositionY, teamTurn	) && isDiagMove(currentPositionX,currentPositionY,newPositionX,newPositionY))
		return true;
	else
		return false;
}
bool Piece::isCorrectDirection(int currentPositionY, int newPositionY, int teamTurn) {
	if (!isKing) {
		if (teamTurn == 1 && currentPositionY - newPositionY == -1)
			return true;
		else if (teamTurn == 0 && currentPositionY - newPositionY == 1)
			return true;
		else
			return false;
	}
	return true;
}
bool Piece::isDiagMove(int currentPositionX, int currentPositionY, int newPositionX, int newPositionY) {
	if (currentPositionX == newPositionX)
		return false;
	if (abs(currentPositionX - newPositionX) != 1)
		return false;
	if (abs(currentPositionY - newPositionY) != 1)
		return false;
	return true;
}