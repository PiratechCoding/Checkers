#include "Piece.h"
#include <iostream>
using namespace std;
bool kingFlag = false;
bool isWhite;
bool isBlack;
bool isEmpty;
void Piece::render() {
	cout << "[_] ";
}
Piece::Piece(){
	//cout << "Created Piece Const";
}
 TeamWhite::TeamWhite() {
	kingFlag = false;
	isWhite = true;
	isEmpty = false;
}
 void TeamWhite::render() {
	 if (!this->kingFlag) {
		 cout << "[w] ";
	 }
	 else
		 cout << "[W] ";
}

 TeamBlack::TeamBlack() {
	 isBlack = true;
	 kingFlag = false;
	 isEmpty = false;
 }
 void TeamBlack::render() {
	 if (!this->kingFlag) {
		 cout << "[b] ";
	 }
	 else
		 cout << "[B] ";
 }