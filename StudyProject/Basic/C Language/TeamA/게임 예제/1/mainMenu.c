#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include "displayControl.h"
#include "AsciiArt.h"

// **** 메인메뉴를 구성하는 함수 라이브러리

// *** 키보드 제어 상수

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

// 선택지 열거형 정의
typedef enum _menu_choice {
	PLAYER1 = 1, PLAYER2, EXIT
}MENU_NUM;


// **** 메인메뉴 ****

int mainMenu()
{
	int select = 1;
	// 유저가 현재 선택한 선택창을 나타낸다.
	// <1. 게임하기, 2. 2인 플레이 3. 게임 종료>
	int roop = true;
	scr_init(); 
	
	while (roop)
	{
		
		scr_clear();

		mainMenu_Version();
		mainMenu_Title(13,6);
		mainMenu_Select(19, 19, 30, 4, 1, select);
		mainMenu_Select(19, 24, 32, 4, 2, select);
		mainMenu_Select(19, 29, 32, 4, 3, select);
		mainMenu_img_cowboy(62, 18);

		scr_switch();
		 
		unsigned char keyboardInput;
		keyboardInput = _getch();

		// ENTER, SPACE BAR, ESC를 눌렀을 경우 해당 메뉴를 선택하게 된다.
		if (keyboardInput == 'r' || keyboardInput == BLANK || keyboardInput == ESC)
		{
			switch (select)
			{
			case PLAYER1:
			case PLAYER2:
				//루프를 탈출하고 게임을 실행한다.
				roop = false;
				break;
			case EXIT:
				// 바로 프로그램을 종료한다.
				exit(0);
			default:
				break;
			}
		}
		else if (keyboardInput == SPECIAL1 || keyboardInput == SPECIAL2)
		{
			keyboardInput = _getch();

			switch (keyboardInput)
			{
			case UP:
				if (select > 1)
					select--;
				break;
			case DOWN:
				if (select < 3)
					select++;
				break;
			default:
				break;
			}	
		}
		
	}

	return select;
}