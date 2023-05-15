#ifndef _MONSTER_H

#define _MONSTER_H

int monsterFrameSync;
int monsterMoveFrameSync;
int remainMonsterCount;
int monsterCount;

int isMonsterRemain();
void monsterMove(int* x, int* y);
void checkMonsterBug();

#endif