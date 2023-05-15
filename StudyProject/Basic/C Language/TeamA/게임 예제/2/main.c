#define _CRT_SECURE_NO_WARNINGS

#include "displayControl.h"
#include "main.h"
#include "map.h"
#include "menu.h"
#include "game.h"
#include "asciiArt.h"

#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")


int userStage = 1;

void init()
{
	//창 사이즈 조절
	system("mode con cols=140 lines=43 | title Game Title");
	scr_init();
}



int main(void) {
	init();

	while (TRUE) {
		PlaySound(TEXT("bgm.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
 		int userChoice = menuChoice();
		gameLoop = TRUE;
		isRetry = TRUE;
		userHP = maxHP;
		switch (userChoice) {
		case 0:
			//게임시작
			while (userStage < 4) {
				if (isRetry == FALSE) {
					userStage = 1;
					break;
				}
				gameLoop = TRUE;
				game();
			}
			if (userStage == 4) {
				PlaySound(TEXT("win.wav"), 0, SND_FILENAME | SND_ASYNC);
				printWin();
				userStage = 1;
			}
			break;

		case 2:
			//옵션
			how();
			break;

		case 4:
			exit(1);
			break;
		}
	}
}