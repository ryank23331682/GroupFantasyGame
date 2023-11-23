#include <vector>
#include "Square.h"
using namespace std;

class Board
{
	Board(int width, int height);
	void initializeBoard(int width, int height);
	Square getSquare(int x, int y);
	int width;
	int height;
	vector<vector<Square>> grid;
};
