#ifndef PIECE_H
#define PIECE_H
class Piece
{
public:
	bool validMove(int currentPositionX, int currentPositionY, int movePositionX, int movePositionY);
	void render();
	Piece();
	bool isEmpty;
	bool isWhite;
	bool isBlack;
	bool kingFlag;
};

/*
class TeamWhite :public Piece
{
public:
	bool kingFlag;
	bool isWhite;
	TeamWhite();
};

class TeamBlack : public Piece
{
public:
	bool kingFlag;
	bool isBlack;
	TeamBlack();
};*/
#endif