#ifndef PIECE_H
#define PIECE_H
class Piece
{
	bool validMove(int currentPositionX, int currentPositionY, int movePositionX, int movePositionY);
};
class TeamWhite :public Piece
{
	bool kingFlag;
	bool isWhite;
	void render(bool kingFlag, bool isWhite);
};

class TeamBlack : public Piece
{
	bool kingFlag;
	bool isBlack;
	void render(bool kingFlag,bool isBlack);
};
#endif