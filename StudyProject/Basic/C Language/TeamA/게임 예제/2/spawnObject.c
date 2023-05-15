#include "spawnObject.h"
#include "map.h"
#include "attack.h"
#include "game.h"
#include "monster.h"

int magazineFrameSync = 500;
int healthFrameSync = 1000;
int magazineCount = 0;
int healthCount = 0;

void spawnMonster() {
	while (TRUE) {
		if (monsterCount == stageMaxMonster)
			break;
		if (userStage == 1) {
			mon[monsterCount].x = (rand(time(NULL)) % 8) + 47;
			mon[monsterCount].y = rand(time(NULL)) % 2;
			if (mon[monsterCount].y == 0)
				mon[monsterCount].y = 1;
			else
				mon[monsterCount].y = tempMapY - 1;
		}
		else if (userStage == 2) {
			mon[monsterCount].x = (rand(time(NULL)) % 8) + 31;
			mon[monsterCount].y = rand(time(NULL)) % 2;
			if (mon[monsterCount].y == 0)
				mon[monsterCount].y = 5;
			else
				mon[monsterCount].y = tempMapY - 5;
		}
		else if (userStage == 3) {
			mon[monsterCount].x = (rand(time(NULL)) % 8) + 200;
			mon[monsterCount].y = rand(time(NULL)) % 2;
			if (mon[monsterCount].y == 0)
				mon[monsterCount].y = 1;
			else
				mon[monsterCount].y = tempMapY;
		}
		if (tempMap[mon[monsterCount].y][mon[monsterCount].x] == '0') {
			if (monsterCount % 50 == 49) {
				tempMap[mon[monsterCount].y][mon[monsterCount].x] = 'Q';
				mon[monsterCount].hp = 1000;
				mon[monsterCount].typeFrame = DOUBLEDIAMOND;
			}
			else if (monsterCount % 4 == 0) {
				tempMap[mon[monsterCount].y][mon[monsterCount].x] = 'q';
				mon[monsterCount].hp = 30;
				mon[monsterCount].typeFrame = DIAMOND;
			}
			else if (monsterCount % 4 == 1) {
				tempMap[mon[monsterCount].y][mon[monsterCount].x] = 't';
				mon[monsterCount].hp = 200;
				mon[monsterCount].typeFrame = EMPTYDIAMOND;
			}
			else if (monsterCount % 4 == 2) {
				tempMap[mon[monsterCount].y][mon[monsterCount].x] = 'e';
				mon[monsterCount].hp = 40;
				mon[monsterCount].typeFrame = TRIANGLE;
			}
			else if (monsterCount % 4 == 3) {
				tempMap[mon[monsterCount].y][mon[monsterCount].x] = 'r';
				mon[monsterCount].hp = 60;
				mon[monsterCount].typeFrame = EMPTYTRIANGLE;
			}

			mon[monsterCount].exist = TRUE;
			monsterCount++;
			remainMonsterCount++;
			break;
		}
	}
}

void spawnMagazine() {
	while (TRUE) {
		int x = rand(time(NULL)) % tempMapX;
		int y = rand(time(NULL)) % tempMapY;

		if (tempMap[y][x] == '0') {
			if (magazineCount % 4 == 0) {
				tempMap[y][x] = 'z';
			}
			else if (magazineCount % 4 == 1) {
				tempMap[y][x] = 'x';
			}
			else if (magazineCount % 4 == 2) {
				tempMap[y][x] = 'c';
			}
			else if (magazineCount % 4 == 3) {
				tempMap[y][x] = 'v';
			}
			magazineCount++;
			break;
		}
	}
}

void spawnHealth() {
	while (TRUE) {
		int x = rand(time(NULL)) % tempMapX;
		int y = rand(time(NULL)) % tempMapY;

		if (tempMap[y][x] == '0') {
			tempMap[y][x] = 'n';
			break;
		}
	}
}