#ifndef _MAP_DATA

#define _MAP_DATA

#include "main.h"

#define MAPXSTART 17

#define MAP1XMAX 99
#define MAP1YMAX 39
#define MAPXHALF 25
#define MAPYHALF 12
#define MAP2XMAX 68
#define MAP2YMAY 120
#define MAP2XMAX 68
#define MAP2YMAX 120
#define MAP3XMAX 450
#define MAP3YMAX 115

int tempMapX;
int tempMapY;

char map1[MAP1YMAX + 1][MAP1XMAX + 1];
char map2[MAP2YMAX + 1][MAP2XMAX + 1];
char map3[MAP3YMAX + 1][MAP3XMAX + 1];
char tempMap[600][600];

void border();
void drawMap(int* x, int* y);
void drawInfo();

#endif