#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

// 화면 제어를 위한 명령어 라이브러리 구현 소스코드

// **** 화면 크기 상수 ****
#define WIDTH 140
#define HEIGHT 60

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

// **** 더블 버퍼링 변수 ****
int hidden_index; // Hidden 화면 번호 0 or 1
HANDLE scr_handle[2]; // 화면 버퍼 변수


// **** 제어 함수 ****

void gotoxy(int x, int y) //내가 원하는 위치로 커서 이동
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	// hidden screen에 gotoxy
	SetConsoleCursorPosition(scr_handle[hidden_index], CursorPosition);
}

void textcolor(int fg_color, int bg_color)
{
	SetConsoleTextAttribute(scr_handle[hidden_index], fg_color | bg_color << 4);
}

void removeCursor(void) { // 커서를 안보이게 한다
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void showCursor(void) { // 커서를 보이게 한다
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(scr_handle[hidden_index], &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(scr_handle[hidden_index], &curInfo);
}

void cls(int text_color, int bg_color) // 화면 지우기
{
	char cmd[100];
	system("cls");
	sprintf(cmd, "COLOR %x%x", bg_color, text_color);
	system(cmd);
}

void ChangeScreenSize(HANDLE hnd, COORD NewSize)
{
	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT DisplayArea = { 0, 0, 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
	GetConsoleScreenBufferInfo(hnd, &SBInfo);
	DisplayArea.Bottom = NewSize.Y;
	DisplayArea.Right = NewSize.X;
	SetConsoleWindowInfo(hnd, 1, &DisplayArea);
}

void ChangeBuffSize(HANDLE hnd, COORD NewSize)
{
	SetConsoleScreenBufferSize(hnd, NewSize);
}

// **** 더블 버퍼링 제어 함수 ****

void scr_init()
{
	CONSOLE_CURSOR_INFO cci;

	// 화면 버퍼 2개를 만든다.
	scr_handle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	scr_handle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// 커서를 숨긴다.
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(scr_handle[0], &cci);
	SetConsoleCursorInfo(scr_handle[1], &cci);
	// 0번 화면이 default
	SetConsoleActiveScreenBuffer(scr_handle[0]);
	hidden_index = 1; // 1번 화면이 Hidden Screen
}

void scr_switch()
{
	// hidden 을 active 로 변경한다.
	SetConsoleActiveScreenBuffer(scr_handle[hidden_index]);
	// active를 hidden으로 변경한다.
	hidden_index = !hidden_index; // 0 <-> 1 toggle
}

void scr_clear()
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	// hidden screen를 clear한다.
	// WIDTH*2 * HEIGHT 값은 [속성]에서 설정한 값과 정확히 같아야 한다.
	// 즉, 화면 속성에서 너비(W)=80, 높이(H)=25라면 특수 문자는 2칸씩 이므로 WIDTH=40, HEIGHT=25이다.
	FillConsoleOutputCharacter(scr_handle[hidden_index], ' ', WIDTH * 2 * HEIGHT, Coor, &dw);
}

void scr_release()
{
	CloseHandle(scr_handle[0]);
	CloseHandle(scr_handle[1]);
}

void printscr(const char* str)
{
	// const char*형으로 매개변수를 전달함.
	DWORD dw;
	// hidden screen에 gotoxy 되었다고 가정하고 print
	WriteFile(scr_handle[hidden_index], str, strlen(str), &dw, NULL);
}

void printintscr(int str)
{
	// const char*형으로 매개변수를 전달함.
	DWORD dw;
	// hidden screen에 gotoxy 되었다고 가정하고 print
	WriteFile(scr_handle[hidden_index], str, strlen(str), &dw, NULL);
}

void printxy(int x, int y, char* str)
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	// hidden screen에 gotoxy + print
	SetConsoleCursorPosition(scr_handle[hidden_index], CursorPosition);
	WriteFile(scr_handle[hidden_index], str, strlen(str), &dw, NULL);
}