#include "maze.h"

int main()
{
	LinkedStack	*pStack = createLinkedStack();
	MapPosition startPos;
	MapPosition endPos;
	int map[HEIGHT][WIDTH] = {
		{0, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 0}
	};
	startPos.x = 0;
	startPos.y = 0;
	startPos.direction = 0;
	endPos.x = 7;
	endPos.y = 7;
	endPos.direction = 0;
	printMaze(map);
	findPath(map, startPos, endPos, pStack);
	return 0;
}