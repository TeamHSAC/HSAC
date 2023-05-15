#include "map.h"
#include "game.h"
#include "attack.h"
#include "monster.h"

int selectWeapon = 0;
int reloadFrameSync = 100;
int isReload = FALSE;
int barrelCount = 0;

int isDamage(int xData, int yData, char type, int isBarrel) {
	switch (type) {
	case 'm':
		for (int i = 0; i < stageMaxMonster; i++) {
			if (mon[i].x == xData && mon[i].y == yData) {
				if (isBarrel == TRUE) {
					mon[i].hp -= BRDAMAGE;
				}
				else {
					mon[i].hp -= weapon[selectWeapon].damage;
				}
				//몬스터 사망
				if (mon[i].hp <= 0) {
					tempMap[yData][xData] = '0';
					mon[i].exist = FALSE;
					remainMonsterCount--;
					return TRUE;
				}
				return FALSE;
			}
		}
		break;
	case 'w':
		for (int i = 0; i < MAXWALL; i++) {
			if (wall[i].x == xData && wall[i].y == yData) {
				if (isBarrel == TRUE) {
					wall[i].hp -= BRDAMAGE;
				}
				else {
					wall[i].hp -= weapon[selectWeapon].damage;
				}
				if (wall[i].hp <= 0) {
					tempMap[yData][xData] = '0';
					return TRUE;
				}
				return FALSE;
			}
		}
		break;
	case 'b':
		for (int i = 0; i < MAXBARREL; i++) {
			if (bar[i].x == xData && bar[i].y == yData) {
				if (isBarrel == TRUE) {
					bar[i].hp -= BRDAMAGE;
				}
				else {
					bar[i].hp -= weapon[selectWeapon].damage;
				}
				break;
			}
		}
		break;
	}
}

void isBarrelExplode() {
	int i = 0;
	while (i < barrelCount) {
		if (bar[i].exist == TRUE && bar[i].hp <= 0) {
			PlaySound(TEXT("BR.wav"), 0, SND_FILENAME | SND_ASYNC);
			bar[i].exist = REMOVING;
			tempMap[bar[i].y][bar[i].x] = '0';
			for (int j = -2; j <= 2; j++) {
				for (int k = -2; k <= 2; k++) {
					switch (tempMap[bar[i].y + j][bar[i].x + k]) {
					case '0':
						tempMap[bar[i].y + j][bar[i].x + k] = 'K';
						break;
					case 'p': case 'P':
						userHP -= 1;
						//if (userHP <= 0)
						//	gameLoop = FALSE;
						break;
					case '!':
						isDamage(bar[i].x + k, bar[i].y + j, 'w', TRUE);
						break;
					case 'q':case 't':case 'e':case 'r':case 'Q':
						isDamage(bar[i].x + k, bar[i].y + j, 'm', TRUE);
						break;
					case 'k':
						isDamage(bar[i].x + k, bar[i].y + j, 'b', TRUE);
						isBarrelExplode();
						break;
					}
				}
			}
		}
		i++;
	}
}

void removeBarrelExplode() {
	int i = 0;
	while (i < barrelCount) {
		if (bar[i].exist == REMOVING && bar[i].hp <= 0) {
			bar[i].exist = FALSE;
			tempMap[bar[i].y][bar[i].x] = '0';
			for (int j = -2; j <= 2; j++) {
				for (int k = -2; k <= 2; k++) {
					if (tempMap[bar[i].y + j][bar[i].x + k] == 'K')
						tempMap[bar[i].y + j][bar[i].x + k] = '0';
				}
			}
		}
		i++;
	}
}

void attack(int* x, int* y, int _x, int _y, char wh) {
	weapon[selectWeapon].bullet--;
	int xData = *x + _x;
	int yData = *y + _y;
	char mapObject = tempMap[yData][xData];
	//장애물을 만날때까지 총알이 날아감
	if (selectWeapon == HG || selectWeapon == AR || selectWeapon == SR) {
		while (TRUE) {
			//몬스터 피격시 체력 감소 및 총알 관통 금지
			if (tempMap[yData][xData] == 'q'|| tempMap[yData][xData] == 't' || tempMap[yData][xData] == 'e' || tempMap[yData][xData] == 'r' || tempMap[yData][xData] == 'Q') {
				//스나이퍼 총알관통
				if (selectWeapon == SR) {
					isDamage(xData, yData, 'm', FALSE);
					xData += _x;
					yData += _y;
					continue;
				}
				else {
					isDamage(xData, yData, 'm', FALSE);
					break;
				}
			}
			//부서지는 벽
			else if (tempMap[yData][xData] == '!') {
				if (selectWeapon == SR) {
					isDamage(xData, yData, 'w', FALSE);
					xData += _x;
					yData += _y;
					continue;
				}
				else {
					isDamage(xData, yData, 'w', FALSE);
					break;
				}
			}

			else if (tempMap[yData][xData] == 'k') {
				isDamage(xData, yData, 'b', FALSE);
				isBarrelExplode();
				break;
			}

			else if (tempMap[yData][xData] == 'z' || tempMap[yData][xData] == 'x' || tempMap[yData][xData] == 'c' || tempMap[yData][xData] == 'v' || tempMap[yData][xData] == 'P' || tempMap[yData][xData] == 'n') {
				yData += _y;
				xData += _x;
				mapObject = tempMap[yData][xData];
			}
			else if (tempMap[yData][xData] == '0') {
				tempMap[yData][xData] = wh;
				yData += _y;
				xData += _x;
				mapObject = tempMap[yData][xData];
			}
			else
				break;
		}
	}
	//샷건 탄퍼짐 구현
	else if (selectWeapon == SG) {
		int isEmptyPlace = TRUE;

		for (int i = 0; i < 16; i++) {

			if (tempMap[yData][xData] == 'q' || tempMap[yData][xData] == 't' || tempMap[yData][xData] == 'e' || tempMap[yData][xData] == 'r' || tempMap[yData][xData] == 'Q') {
				isDamage(xData, yData, 'm', FALSE);
			}
			//부서지는 벽
			else if (tempMap[yData][xData] == '!') {
				isDamage(xData, yData, 'w', FALSE);
			}

			else if (tempMap[yData][xData] == 'k') {
				isDamage(xData, yData, 'b', FALSE);
				isBarrelExplode();
			}

			if (isEmptyPlace == FALSE)
				break;

			switch (i) {
			case 0:
				if (tempMap[yData][xData] == '0') {
					tempMap[yData][xData] = 's';
				}
				else if (tempMap[yData][xData] == 'z' || tempMap[yData][xData] == 'x' || tempMap[yData][xData] == 'c' || tempMap[yData][xData] == 'v' || tempMap[yData][xData] == 'P' || tempMap[yData][xData] == 'n');
				else
					isEmptyPlace = FALSE;
				if (_x != 0) {
					xData += _x;
					yData--;
				}
				else {
					yData += _y;
					xData--;
				}
				break;
			case 1:
				if (tempMap[yData][xData] == '0')
					tempMap[yData][xData] = 's';
				if (_x != 0)
					yData++;
				else
					xData++;

				break;

			case 2:
				if (tempMap[yData][xData] == '0')
					tempMap[yData][xData] = 's';
				else if (tempMap[yData][xData] == 'z' || tempMap[yData][xData] == 'x' || tempMap[yData][xData] == 'c' || tempMap[yData][xData] == 'v' || tempMap[yData][xData] == 'P' || tempMap[yData][xData] == 'n');
				else
					isEmptyPlace = FALSE;
				if (_x != 0)
					yData++;
				else
					xData++;
				break;

			case 3:
				if (tempMap[yData][xData] == '0')
					tempMap[yData][xData] = 's';
				if (_x != 0) {
					yData -= 3;
					xData += _x;
				}
				else {
					xData -= 3;
					yData += _y;
				}
				break;

			case 4: case 5: case 6: case 7:
				if (tempMap[yData][xData] == '0')
					tempMap[yData][xData] = 's';

				if (_x != 0)
					yData++;
				else
					xData++;
				break;

			case 8:
				if (tempMap[yData][xData] == '0')
					tempMap[yData][xData] = 's';
				if (_x != 0) {
					yData -= 5;
					xData += _x;
				}
				else {
					xData -= 5;
					yData += _y;
				}
				break;
			case 9:case 10:case 11:case 12:case 13:case 14:case 15:
				if (tempMap[yData][xData] == '0')
					tempMap[yData][xData] = 's';

				if (_x != 0)
					yData++;
				else
					xData++;
				break;
			}
		}
	}
	else if (selectWeapon == BR) {
		if (tempMap[yData][xData] == '0') {
			tempMap[yData][xData] = 'k';
		}
		else if (tempMap[yData][xData] == 'P') {
			yData--;
			tempMap[yData][xData] = 'k';
		}
		bar[barrelCount].x = xData;
		bar[barrelCount].y = yData;
		bar[barrelCount].exist = TRUE;
		bar[barrelCount].hp = 1;
		barrelCount++;
	}
}

void endAttack(int* x, int* y, int _x, int _y, char wh) {
	int xData = *x + _x;
	int yData = *y + _y;
	char mapObject = tempMap[yData][xData];
	//HG, AR, SR 지우기
	if (selectWeapon == HG || selectWeapon == AR || selectWeapon == SR) {
		while (TRUE) {
			if (tempMap[yData][xData] == wh) {
				tempMap[yData][xData] = '0';
				yData += _y;
				xData += _x;
				mapObject = tempMap[yData][xData];
			}
			else if (tempMap[yData][xData] == 'z' || tempMap[yData][xData] == 'x' || tempMap[yData][xData] == 'c' || tempMap[yData][xData] == 'v' || tempMap[yData][xData] == 'P' || tempMap[yData][xData] == 'n') {
				yData += _y;
				xData += _x;
				mapObject = tempMap[yData][xData];
			}
			else if (tempMap[yData][xData] == '!' && selectWeapon == SR) {
				yData += _y;
				xData += _x;
				mapObject = tempMap[yData][xData];
			}
			else if (tempMap[yData][xData] == 'k'|| tempMap[yData][xData] == 'K') {
				removeBarrelExplode();
			}
			else if (selectWeapon == SR && (mapObject == 'q' || mapObject == 'e' || mapObject == 'r' || mapObject == 't' || mapObject == '0' || mapObject == 'Q')) {
				yData += _y;
				xData += _x;
				mapObject = tempMap[yData][xData];
			}
			else
				break;
		}
	}
	//샷건 지우기
	else if (selectWeapon == SG) {
		for (int i = 0; i < 16; i++) {
			if (tempMap[yData][xData] == 'k' || tempMap[yData][xData] == 'K') {
				removeBarrelExplode();
			}
			switch (i) {
			case 0:
				if (tempMap[yData][xData] == 's') {
					tempMap[yData][xData] = '0';
				}
				if (_x != 0) {
					xData += _x;
					yData--;
				}
				else {
					yData += _y;
					xData--;
				}
				break;
			case 1: case 2:
				if (tempMap[yData][xData] == 's')
					tempMap[yData][xData] = '0';
				if (_x != 0)
					yData++;
				else
					xData++;

				break;

			case 3:
				if (tempMap[yData][xData] == 's')
					tempMap[yData][xData] = '0';

				if (_x != 0) {
					yData -= 3;
					xData += _x;
				}
				else {
					xData -= 3;
					yData += _y;
				}
				break;

			case 4: case 5: case 6: case 7:
				if (tempMap[yData][xData] == 's')
					tempMap[yData][xData] = '0';

				if (_x != 0)
					yData++;
				else
					xData++;
				break;
			case 8:
				if (tempMap[yData][xData] == 's')
					tempMap[yData][xData] = '0';
				if (_x != 0) {
					yData -= 5;
					xData += _x;
				}
				else {
					xData -= 5;
					yData += _y;
				}
				break;
			case 9:case 10:case 11:case 12:case 13:case 14:case 15:
				if (tempMap[yData][xData] == 's')
					tempMap[yData][xData] = '0';

				if (_x != 0)
					yData++;
				else
					xData++;
				break;
			}
		}
	}
}