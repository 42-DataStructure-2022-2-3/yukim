#ifndef MAZE_H
# define MAZE_H

#include "linkedstack.h"

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
int pushLSMapPosition(LinkedStack* pStack, MapPosition data);
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]); 
void printMaze(int mazeArray[HEIGHT][WIDTH]);

#endif