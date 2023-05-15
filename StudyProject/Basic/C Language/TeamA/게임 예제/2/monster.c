#include "game.h"
#include "main.h"
#include "map.h"

int monsterFrameSync = 30;
int monsterMoveFrameSync = 10;
int remainMonsterCount = 0;
int monsterCount = 0;

void monsterMove(int* x, int* y) {
	int count = 0;
	int xDifferenceValue, yDifferenceValue;
	while (count < monsterCount) {
		if (frameCount % mon[count].typeFrame == 0) {
			if (mon[count].exist == TRUE) {

				xDifferenceValue = *x - mon[count].x;
				yDifferenceValue = *y - mon[count].y;

				if (abs(xDifferenceValue) > abs(yDifferenceValue)) {

					if (tempMap[mon[count].y][mon[count].x + 1] == 'P' || tempMap[mon[count].y][mon[count].x - 1] == 'P') {
						if (isBarrier == FALSE) {
							userHP -= 2;
							isBarrier = TRUE;
							barrierStartTime = runTime;
						}
						if (runTime - barrierStartTime >= 1)
							isBarrier = FALSE;
						//if (userHP <= 0)
						//	gameLoop = FALSE;
					}
					else if (tempMap[mon[count].y][mon[count].x + 1] == 'p' || tempMap[mon[count].y][mon[count].x - 1] == 'p') {
						if (isBarrier == FALSE) {
							userHP--;
							isBarrier = TRUE;
							barrierStartTime = runTime;
						}
						if (runTime - barrierStartTime >= 1)
							isBarrier = FALSE;
						//if (userHP <= 0)
						//	gameLoop = FALSE;
					}
					else if (xDifferenceValue > 0 && tempMap[mon[count].y][mon[count].x + 1] == '0') {
						tempMap[mon[count].y][mon[count].x + 1] = tempMap[mon[count].y][mon[count].x];
						tempMap[mon[count].y][mon[count].x] = '0';
						mon[count].x++;
					}
					else if (xDifferenceValue <= 0 && tempMap[mon[count].y][mon[count].x - 1] == '0') {
						tempMap[mon[count].y][mon[count].x - 1] = tempMap[mon[count].y][mon[count].x];
						tempMap[mon[count].y][mon[count].x] = '0';
						mon[count].x--;
					}
					else if (yDifferenceValue > 0 && tempMap[mon[count].y + 1][mon[count].x] == '0') {
						tempMap[mon[count].y + 1][mon[count].x] = tempMap[mon[count].y][mon[count].x];
						tempMap[mon[count].y][mon[count].x] = '0';
						mon[count].y++;
					}
					else if (yDifferenceValue <= 0 && tempMap[mon[count].y - 1][mon[count].x] == '0') {
						tempMap[mon[count].y - 1][mon[count].x] = tempMap[mon[count].y][mon[count].x];
						tempMap[mon[count].y][mon[count].x] = '0';
						mon[count].y--;
					}
				}

				else {
					if (tempMap[mon[count].y + 1][mon[count].x] == 'P' || tempMap[mon[count].y - 1][mon[count].x] == 'P') {
						if (isBarrier == FALSE) {
							userHP -= 2;
							isBarrier = TRUE;
							barrierStartTime = runTime;
						}
						if (runTime - barrierStartTime >= 1)
							isBarrier = FALSE;
						//if (userHP <= 0)
						//	gameLoop = FALSE;
					}
					else if (tempMap[mon[count].y + 1][mon[count].x] == 'p' || tempMap[mon[count].y - 1][mon[count].x] == 'p') {
						if (isBarrier == FALSE) {
							userHP--;
							isBarrier = TRUE;
							barrierStartTime = runTime;
						}
						if (runTime - barrierStartTime >= 1)
							isBarrier = FALSE;
						//if (userHP <= 0)
						//	gameLoop = FALSE;
					}
					else if (yDifferenceValue > 0 && tempMap[mon[count].y + 1][mon[count].x] == '0') {
						tempMap[mon[count].y + 1][mon[count].x] = tempMap[mon[count].y][mon[count].x];
						tempMap[mon[count].y][mon[count].x] = '0';
						mon[count].y++;
					}
					else if (yDifferenceValue <= 0 && tempMap[mon[count].y - 1][mon[count].x] == '0') {
						tempMap[mon[count].y - 1][mon[count].x] = tempMap[mon[count].y][mon[count].x];
						tempMap[mon[count].y][mon[count].x] = '0';
						mon[count].y--;
					}
					else if (xDifferenceValue > 0 && tempMap[mon[count].y][mon[count].x + 1] == '0') {
						tempMap[mon[count].y][mon[count].x + 1] = tempMap[mon[count].y][mon[count].x];
						tempMap[mon[count].y][mon[count].x] = '0';
						mon[count].x++;
					}
					else if (xDifferenceValue <= 0 && tempMap[mon[count].y][mon[count].x - 1] == '0') {
						tempMap[mon[count].y][mon[count].x - 1] = tempMap[mon[count].y][mon[count].x];
						tempMap[mon[count].y][mon[count].x] = '0';
						mon[count].x--;
					}
				}
			}
		}
		count++;
	}
}

int isMonsterRemain() {
	for (int i = 0; i < stageMaxMonster; i++) {
		if (mon[i].exist == TRUE)
			return TRUE;
	}
	return FALSE;
}

void checkMonsterBug() {
	for (int i = 0; i < monsterCount; i++) {
		if (mon[i].exist == TRUE && tempMap[mon[i].y][mon[i].x] == '0')
			mon[i].exist = FALSE;
	}
}