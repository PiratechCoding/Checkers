#include "Piece.h"
#include <iostream>
using namespace std;



Piece::Piece(int* gameBoardWidith,int* gameBoardHeight){
	setEmpty(true);
	clearTeams();
	setKingStatus(false);
	int gameWidith = *gameBoardWidith;
	int gameHeight = *gameBoardHeight;
}
void Piece::setEmpty(bool emptyStatus) {
	this->isEmpty = emptyStatus;
}

void Piece::setKingStatus(bool kingStatus) {
	this->isKing = kingStatus;
}

void Piece::setTeamBlack() {
	this->team = 0;
}

void Piece::setTeamWhite() {		
	this->team = 1;
}

void Piece::clearTeams() {  // 0 Black 1 White
	this->team = -1;   //Will throw error if evalued as expected
}
int Piece::getTeam() {
	return this->team;
}
void Piece::render() {  //Identify Team Color and King Status and render correctly
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
	//Basic Sanity Checks for Outof Bounds
	
	return true;
}
