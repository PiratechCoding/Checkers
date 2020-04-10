#ifndef PIECE_H
#define PIECE_H
class Piece
{
private:
	bool isDiagMove(int currentPositionX, int currentPositionY, int newPositionX, int newPositionY);
	bool isCorrectDirection(int currentPositionY, int newPositionY, int teamTurn);
protected:
	bool isEmpty;
	int team;
	bool isKing;
	int gameWidith, gameHeight;
public:
	bool validMove(int currentPositionX, int currentPositionY, int movePositionX, int movePositionY, int teamTurn);
	void render();
	void setTeamBlack();
	void setTeamWhite();
	void setKingStatus(bool kingStatus);
	void clearTeams();
	void setEmpty(bool emptyStatus);
	int getTeam();
	bool getEmptyStatus();
	Piece(int* gameWidith, int* gameHeight);
	Piece() = default; //default const to fall back on
};

#endif