
#include <iostream>
using namespace std;
class GameBoard {
	int gbWidith, gbHeight;
public:
	void gbSetSize(int x, int y) {
		gbWidith = x;
		gbHeight = y;
	}
	void gbPrint(int x, int y) {
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				cout << "[] ";
			}
			cout << "\n ";
		}
	}
};