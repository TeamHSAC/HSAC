#ifndef ASCIIART_H
#define ASCIIART_H

// **** 화면에 출력할 아스키 코드를 출력하는 라이브러리


// *** 메인메뉴 아스키 코드 생성 함수
void mainMenu_Version();
void mainMenu_Title(int x, int y);
void mainMenu_Select(int x, int y, int width, int height, int selectType, int isSelected);
void mainMenu_img_cowboy(int x, int y);

// *** 게임엔진 아스키 코드 생성 함수
void gameEngine_Frame(int x1, int y1, int x2, int y2);


#endif

