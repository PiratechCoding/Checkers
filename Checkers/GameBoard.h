
#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "Piece.h"

class GameBoard
{
	 int gbWidith;
	 int gbHeight;
	
public:
	Piece pieceLocationData[8][8];
	void gbPrint();
	void gbSetSize(int, int);
	void fillWithEmpty(int, int);
	void intialPiecePlacement();
	void gbPieceMove(int, int, int, int);

	GameBoard(int, int);
};

#endif // !1