#ifndef DISPLAYCONTROL_H
#define DISPLAYCONTROL_H

#include <stdio.h>
#include <Windows.h>

// 화면 제어를 위한 명령어 라이브러리

//SetConsoleTitle(TEXT("Quick Draw"));
//system("mode con cols=120 lines=40");

// **** 색상 상수 ****
#define BLACK	0
#define BLUE1	1
#define GREEN1	2
#define CYAN1	3
#define RED1	4
#define MAGENTA1 5
#define YELLOW1	6
#define GRAY1	7
#define GRAY2	8
#define BLUE2	9
#define GREEN2	10
#define CYAN2	11
#define RED2	12
#define MAGENTA2 13
#define YELLOW2	14
#define WHITE	15

//키보드 제어 상수
#define ESC 0x1b
#define SPECIAL1 0xe0 // 특수키는 0xe0 + key 값으로 구성된다.
#define SPECIAL2 0x00 // keypad 경우 0x00 + key 로 구성된다.
#define UP  0x48 // Up key는 0xe0 + 0x48 두개의 값이 들어온다.
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d
#define UP2		'w'
#define DOWN2	's'
#define LEFT2	'a'
#define RIGHT2	'd'
#define F1	0x3b//엔터를 대신하여 사용
#define F2	0x3c
#define BLANK ' '

// **** 제어 함수 ****
void gotoxy(int x, int y);

void textcolor(int fg_color, int bg_color);

void removeCursor(void);

void showCursor(void);

void cls(int text_color, int bg_color);

void ChangeScreenSize(HANDLE hnd, COORD NewSize);

void ChangeBuffSize(HANDLE hnd, COORD NewSize);

// **** 더블 버퍼링 제어 함수 ****

void scr_init();

void scr_switch();

void scr_clear();

void scr_release();

void printscr(const char* str);

void printintscr(int str);

void printxy(int x, int y, char* str);

#endif