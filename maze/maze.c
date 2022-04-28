#include "maze.h"

int	checkMovable(int mazeArray[HEIGHT][WIDTH], MapPosition pos)
{
	int direction;

	direction = -1;
	// 0북 1동 2남 3서
	if (pos.y - 1 > -1)
	{
		if (mazeArray[pos.y - 1][pos.x] == 0)
			direction = 0;
	}
	if (pos.x + 1 < WIDTH)
	{
		if (mazeArray[pos.y][pos.x + 1] == 0)
			direction = 1;
	}
	if (pos.y + 1 < HEIGHT)
	{
		if (mazeArray[pos.y + 1][pos.x] == 0)
			direction = 2;
	}
	if (pos.x - 1 > -1)
	{
		if (mazeArray[pos.y][pos.x - 1] == 0)
			direction = 3;
	}
	//갈 수 있는 곳이 없는 경우
	printf("current (%d, %d) direction : %d\n", pos.x, pos.y, direction);
	return (direction);
}		

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
	MapPosition	currPos;
	int x, y, direction;

	currPos.x = startPos.x;
	currPos.y = startPos.y;
	while (mazeArray[endPos.y][endPos.x] != 2)
	{
		pushLSMapPosition(pStack, currPos);
		x = currPos.x;
		y = currPos.y;
		mazeArray[y][x] = VISIT;
		if (mazeArray[endPos.y][endPos.x] == 2)
			break ;
		direction = checkMovable(mazeArray, currPos);
		printf("mazeArray[%d][%d] = %d, direction : %d\n", y, x, mazeArray[y][x], direction);
		if (direction != -1)
		{
			currPos.x = x + DIRECTION_OFFSETS[direction][0];
			currPos.y = y + DIRECTION_OFFSETS[direction][1];
		}
		else //갈 곳이 없는 경우
		{
			while (checkMovable(mazeArray, currPos) < 0)
			{
				popLS(pStack);
				if (isLinkedStackEmpty(pStack))
				{
					printf("탈출 실패\n");
					return ;
				}
				currPos.x = pStack->pTopElement->data.x;
				currPos.y = pStack->pTopElement->data.y;
			}
		}
	}
	printf("탈출 성공\n");
}

int pushLSMapPosition(LinkedStack* pStack, MapPosition data)
{
	StackNode	pNode;

	pNode.data = data;
	return (pushLS(pStack, pNode));
}

// void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH])
// {

// }

void printMaze(int mazeArray[HEIGHT][WIDTH])
{
	printf("-------------------\n");
	for (int i = 0; i < HEIGHT; i++)
	{
		printf("| ");
		for (int j = 0; j < WIDTH; j++)
		{
			printf("%d ", mazeArray[i][j]);
		}
		printf("|\n");
	}
	printf("-------------------\n");
}
