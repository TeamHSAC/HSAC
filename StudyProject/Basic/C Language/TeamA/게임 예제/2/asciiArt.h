#ifndef _ASCIIART_H

#define _ASCIIART_H
#define XMIN 27
#define YMIN 8

void stage(int x, int y, int type);
void first(int x, int y);
void second(int x, int y);
void third(int x, int y);
void printStart(int type);
void printClear(int type);
void printGameOver();
void printGun();
void reloadGun();
void printWin();
void g(int x, int y);
void a(int x, int y);
void m(int x, int y);
void e(int x, int y);
void o(int x, int y);
void v(int x, int y);
void r(int x, int y);

#endif
