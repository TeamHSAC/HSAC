#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include "displayControl.h"
#include "AsciiArt.h"

// **** 실제 게임이 구현되어 있는 소스코드
// **** 게임 엔진 라이브러리



int quickDraw_player1()
{
	  
}


int gameEngine(int select)
{
	int roop = true;

	while (roop)
	{
		scr_clear();
		gameEngine_Frame(0, 0, 118, 38);
		scr_switch();
	}

	return 0;
}