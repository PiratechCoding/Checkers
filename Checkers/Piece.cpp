#include "Piece.h"
#include <iostream>
using namespace std;
bool kingFlag = false;
bool isWhite = false;
bool isBlack = false;
bool isEmpty = true;

Piece::Piece(){
	isEmpty = true;
	isWhite = false;
	isBlack = false;
	kingFlag = false;
}
//Pieces in General
void Piece::render() {
	if (this->isWhite) {
		if (this->kingFlag) {
			cout << "[W] ";
		}
		else
			cout << "[w] ";
	}
	else if (this->isBlack) {
		if (this->kingFlag) {
			cout << "[B] ";
		}
		else
			cout << "[b] ";
	}
	else
		cout << "[_] ";

}
/*
//Team White Construction
 TeamWhite::TeamWhite() {
	kingFlag = false;
	isWhite = true;
	isBlack = false;
	isEmpty = false;
}

 //TeamBlack Construction
 TeamBlack::TeamBlack() {
	 isBlack = true;
	 isWhite = false;
	 kingFlag = false;
	 isEmpty = false;
	 
 }
 */