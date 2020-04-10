
#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "Piece.h"

class GameBoard
{
protected:
	int gbWidith;
	int gbHeight;
	Piece pieceLocationData[8][8];
public:
	void gbRender();
	void fillWithEmpty();
	void intialPiecePlacement();
	void gbStart();
	void gbPieceMove(int, int, int, int);
	void turnReadOut();
	GameBoard(int, int);
private:
	bool isValidSelection(int indexSelectionX, int indexSelectionY);
	int LETTEROFFSET;
	int teamTurn;
};

#endif // !1