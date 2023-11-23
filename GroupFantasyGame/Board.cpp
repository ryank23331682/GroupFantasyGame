#include "Board.h"
#include "Square.h"

Board::Board(int width, int height)
{
}

void Board::initializeBoard(int width, int height)
{
	//Square square = Square();
	//grid = std::vector<std::vector<Square>>(height, std::vector<Square>(width, square));
}

Square Board::getSquare(int x, int y)
{
	if (x >= 0 && x < width && y >= 0 && y < height) {
		return grid[y][x];
	}
}
