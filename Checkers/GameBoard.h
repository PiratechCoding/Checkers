
#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "Piece.h"

class GameBoard
{
protected:
	char rowSelect, rowMove;          
	int columnSelect, columnMove;
	int gbWidith;
	int gbHeight;
	Piece pieceLocation[8][8];
public:
	void gbRender();
	void fillWithEmpty();
	void intialPiecePlacement();
	void gbStart();
	void gbPieceMove(int, int, int, int);
	void turnReadOut();
	GameBoard(int, int);
private:
	void gbUserInputAfterCapture();
	void gbBoardUpdate(int selectPieceX, int selectPieceY, int newPositionX, int newPositionY, bool captureFlag);
	void setTeamTurn();
	bool isCaptureble(int, int,int,int);
	bool isValidSelection(int indexSelectionX, int indexSelectionY);
	int LETTEROFFSET;
	int teamTurn;
};

#endif // !1