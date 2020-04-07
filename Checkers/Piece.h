#ifndef PIECE_H
#define PIECE_H
class Piece
{
public:
	bool isEmpty;
	bool validMove(int currentPositionX, int currentPositionY, int movePositionX, int movePositionY);
	virtual void render();
	Piece();
protected:
	bool isWhite;
	bool isBlack;
	bool kingFlag;
};
class TeamWhite :public Piece
{
public:
	bool kingFlag;
	bool isWhite;
	using Piece::render;
	void render();

	TeamWhite();
};

class TeamBlack : public Piece
{
public:
	bool kingFlag;
	bool isBlack;
	using Piece::render;
	void render();
	TeamBlack();
};
#endif