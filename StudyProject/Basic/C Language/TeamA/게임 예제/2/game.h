#ifndef _GAME_H

#define _GAME_H

#define ATTACK 4
#define MAXMONSTER 150
#define MAXWALL 800
#define MAXBARREL 800
#define HGINTERVAL 1
#define SGINTERVAL 2
#define SRINTERVAL 3


typedef struct {
	int x, y;
	int hp;
	int exist;
	int typeFrame;
} MONSTER;

typedef struct {
	int x, y;
	int hp;
} WALL;

typedef struct {
	int x, y;
	int hp;
	int exist;
} BARREL;


int dwID;

//게임시작
int gameLoop;
int isRetry;
//속도 관련 변수
int frameCount;
int delay;
int startTime;
int runTime, startTime;
//플레이어 체력 변수
int maxHP;
int userHP;
//피격시 무적시간 변수
int isBarrier;
int barrierStartTime;
//스테이지 최대 몬스터 수
int stageMaxMonster;

int keyControl();
int move(int* x, int* y, int _x, int _y);
void userData(int* x, int* y);
void wallSearch();
void gameInit();
void game();

MONSTER mon[MAXMONSTER];
WALL wall[MAXWALL];
BARREL bar[MAXBARREL];

#endif