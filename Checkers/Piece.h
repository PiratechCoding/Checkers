#ifndef PIECE_H
#define PIECE_H
class Piece
{
private:
	bool isDiagMove(int currentPositionX, int currentPositionY, int newPositionX, int newPositionY);
	bool isCorrectDirection(int currentPositionY, int newPositionY, int teamTurn);
protected:
	
	int team;
	bool isKing;
	int gameWidith, gameHeight;
	bool isEmpty;
public:
	
	bool validMove(int currentPositionX, int currentPositionY, int movePositionX, int movePositionY, int teamTurn);
	void render();
	void setTeamBlack();
	void setTeamWhite();
	bool getKingStatus();
	void setKingStatus(bool kingStatus);
	void clearPiece();
	bool getEmptyStatus();
	void setEmpty(bool emptyStatus);
	int getTeam();
	Piece(int* gameWidith, int* gameHeight);
	Piece() = default; //default const to fall back on
};

#endif