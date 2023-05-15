#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "displayControl.h"


// **** 화면에 출력할 아스키 코드를 저장하는 공간


// *** 메인 메뉴 아스키 코드 생성 소스코드

void mainMenu_Version()
{
	gotoxy(0, 0);
	printscr("HSU ParkJongBeom - Version 0.0");
}

void mainMenu_Title(int x, int y) {
	//** Quick Draw 가로 92 세로 9
	//화면 사이즈 120 * 6

	//** Quick
	
	ascii mario 

	textcolor(RED1, BLACK);
	//가로 44, 세로 9
	gotoxy(x, y + 0); printscr("  /$$$$$$            /$$           /$$      \n");
	gotoxy(x, y + 1); printscr(" /$$__  $$          |__/          | $$      \n");
	gotoxy(x, y + 2); printscr("| $$  \\ $$ /$$   /$$ /$$  /$$$$$$$| $$   /$$\n");
	gotoxy(x, y + 3); printscr("| $$  | $$| $$  | $$| $$ /$$_____/| $$  /$$/\n");
	gotoxy(x, y + 4); printscr("| $$  | $$| $$  | $$| $$| $$      | $$$$$$/ \n");
	gotoxy(x, y + 5); printscr("| $$/$$ $$| $$  | $$| $$| $$      | $$_  $$ \n");
	gotoxy(x, y + 6); printscr("|  $$$$$$/|  $$$$$$/| $$|  $$$$$$$| $$ \\  $$\n");
	gotoxy(x, y + 7); printscr(" \\____ $$$ \\______/ |__/ \\_______/|__/  \\__/\n");
	gotoxy(x, y + 8); printscr("     \\__/\n");


	//** Draw
	

	//가로 43 세로 8
	textcolor(BLUE1, BLACK);
	gotoxy(x + 49, y + 0); printscr("/$$$$$$$                                   \n");
	gotoxy(x + 49, y + 1); printscr("| $$__  $$                                 \n");
	gotoxy(x + 49, y + 2); printscr("| $$  \\ $$  /$$$$$$  /$$$$$$  /$$  /$$  /$$\n");
	gotoxy(x + 49, y + 3); printscr("| $$  | $$ /$$__  $$|____  $$| $$ | $$ | $$\n");
	gotoxy(x + 49, y + 4); printscr("| $$  | $$| $$  \\__/ /$$$$$$$| $$ | $$ | $$\n");
	gotoxy(x + 49, y + 5); printscr("| $$  | $$| $$      /$$__  $$| $$ | $$ | $$\n");
	gotoxy(x + 49, y + 6); printscr("| $$$$$$$/| $$     |  $$$$$$$|  $$$$$/$$$$/\n");
	gotoxy(x + 49, y + 7); printscr("|_______/ |__/      \\_______/ \\_____/\\___/ \n");

	gotoxy(x + 40, y + 8); 

	// 색상 초기화
	textcolor(WHITE, BLACK);
}

void mainMenu_Select(int x, int y, int width, int height, int selectType, int userSelected)
{
	// ** 함수 설명
	// ----------------------------------------------------------------
	// x, y는 선택 상자의 시작 좌표
	// width, height는 선택 상자의 크기를 결정
	
	// selectType는 해당 선택 상자의 종류가 무엇인지 판단
	// <1. 게임 시작하기 2. 2인 게임 시작하기 3. 종료 >
	
	// isSelected는 해당 선택 상자가 유저에 의해 선택되어 있는지를 확인
	// ----------------------------------------------------------------

	// * 상자 색상 결정 프로세스
	if (selectType == userSelected)
	{
		textcolor(RED1, BLACK);
		x = x - 4;
	}
	else if (selectType != userSelected)
	{
		textcolor(WHITE, BLACK);
	}
		

	// * 상자 생성 프로세스
	int x1 = x;
	int y1 = y;

	int x2 = x + width;
	int y2 = y + height;

	for (int p = x1; p <= x2; p += 2) {
		gotoxy(p, y1);
		printscr("─"); 
		gotoxy(p, y2);
		printscr("─");
	}
	for (int q = y1; q <= y2; q++) {
		gotoxy(x1, q);
		printscr("│");
		gotoxy(x2, q);
		printscr("│");
	}
	gotoxy(x1, y1); printscr("┌");
	gotoxy(x1, y2); printscr("└");
	gotoxy(x2, y1); printscr("┐");
	gotoxy(x2, y2); printscr("┘");


	// * 선택 상자 글 작성
	gotoxy(x + 4, y + 2);

	switch (selectType)
	{
	case 1:
		// 게임 시작하기
		gotoxy(x + 9, y + 2);
		printscr("게임 시작하기!!");
		break;
	case 2:
		gotoxy(x + 9, y + 2);
		printscr("두명이서 놀기!!");
		break;
	case 3:
		gotoxy(x + 9, y + 2);
		printscr("게임 종료하기!!");
		break;
	default:
		printscr("empty");
		break;
	}

	textcolor(WHITE, BLACK);

}

void mainMenu_img_cowboy(int x, int y)
{
	gotoxy(x, y++);	printscr("(                                 _\n");
	gotoxy(x, y++);	printscr(" )                               /=>\n");
	gotoxy(x, y++);	printscr("(  +____________________/\\/\\___ / /|\n");
	gotoxy(x, y++);	printscr(" .''._____________'._____      / /|/\\\n");
	gotoxy(x, y++);	printscr(": () :              :\\ ----\\|    \\ )\n");
	gotoxy(x, y++);	printscr(" '..'______________.'0|----|      \\\n");
	gotoxy(x, y++);	printscr("                  0_0/____/        \\\n");
	gotoxy(x, y++);	printscr("                      |----    /----\\\n");
	gotoxy(x, y++);	printscr("                     || -\\\\ --|      \\\n");
	gotoxy(x, y++);	printscr("                     ||   || ||\\      \\\n");
	gotoxy(x, y++);	printscr("                        \\\\____// '|      \\\n");
	gotoxy(x, y++);	printscr("                                .'/       |\n");
	gotoxy(x, y++);	printscr("                               .:/        |\n");
	gotoxy(x, y++);	printscr("                               :/_________|\n");

	textcolor(WHITE, BLACK);
}


// *** 게임 아스키 코드 생성 소스코드

void gameEngine_Frame(int x1, int y1, int x2, int y2) {

	int x, y;
	//int len = strlen(ch);
	for (x = x1; x <= x2; x += 2) { // 한글은 2칸씩 차지한다.
		gotoxy(x, y1);
		printscr("─"); // ㅂ 누르고 한자키 누르고 선택
		gotoxy(x, y2);
		printscr("─");
	}
	for (y = y1; y <= y2; y++) {
		gotoxy(x1, y);
		printscr("│");
		gotoxy(x2, y);
		printscr("│");
	}
	gotoxy(x1, y1); printscr("┌");
	gotoxy(x1, y2); printscr("└");
	gotoxy(x2, y1); printscr("┐");
	gotoxy(x2, y2); printscr("┘");
}