#ifndef PIECE_H
#define PIECE_H
class Piece
{
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
	Piece(int* gameWidith, int* gameHeight);
	Piece() = default;
};

#endif