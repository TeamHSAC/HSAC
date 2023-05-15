#ifndef MAINMENU_H
#define MAINMENU_H

#include <stdio.h>
#include <Windows.h>
#include "displayControl.h"
#include "AsciiArt.h"

typedef enum _menu_choice {
	PLAYER1 = 1, PLAYER2, EXIT
}MENU_NUM;

// **** 메인메뉴 ****
int mainMenu();

#endif