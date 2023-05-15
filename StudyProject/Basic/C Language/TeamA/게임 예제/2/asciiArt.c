#include "asciiArt.h"
#include "displayControl.h"
#include "map.h"
#include "attack.h"

void stage(int x, int y) {
	textcolor(GREEN1, BLACK);
	gotoxy(x, y);   printscr(" ######  ########    ###     ######   ######## ");
	gotoxy(x, y+1); printscr("##    ##    ##      ## ##   ##    ##  ##       ");
	gotoxy(x, y+2); printscr("##          ##     ##   ##  ##        ##       ");
	gotoxy(x, y+3); printscr(" ######     ##    ##     ## ##   #### ######   ");
	gotoxy(x, y+4); printscr("      ##    ##    ######### ##    ##  ##       ");
	gotoxy(x, y+5); printscr("##    ##    ##    ##     ## ##    ##  ##       ");
	gotoxy(x, y+6); printscr(" ######     ##    ##     ##  ######   ######## ");
	textcolor(WHITE, BLACK);
	//x+50
}

void first(int x, int y) {
	textcolor(BLUE1, BLACK);
	gotoxy(x, y);     printscr("   ##   ");
	gotoxy(x, y + 1); printscr(" ####   ");
	gotoxy(x, y + 2); printscr("   ##   ");
	gotoxy(x, y + 3); printscr("   ##   ");
	gotoxy(x, y + 4); printscr("   ##   ");
	gotoxy(x, y + 5); printscr("   ##   ");
	gotoxy(x, y + 6); printscr(" ###### ");
	textcolor(WHITE, BLACK);
}

void second(int x, int y) {
	textcolor(YELLOW1, BLACK);
	gotoxy(x, y);     printscr(" #######  ");
	gotoxy(x, y + 1); printscr("##     ## ");
	gotoxy(x, y + 2); printscr("       ## ");
	gotoxy(x, y + 3); printscr(" #######  ");
	gotoxy(x, y + 4); printscr("##        ");
	gotoxy(x, y + 5); printscr("##        ");
	gotoxy(x, y + 6); printscr("######### ");
	textcolor(WHITE, BLACK);
}
void third(int x, int y) {
	textcolor(RED1, BLACK);
	gotoxy(x, y);     printscr(" #######  ");
	gotoxy(x, y + 1); printscr("##     ## ");
	gotoxy(x, y + 2); printscr("       ## ");
	gotoxy(x, y + 3); printscr(" #######  ");
	gotoxy(x, y + 4); printscr("       ## ");
	gotoxy(x, y + 5); printscr("##     ## ");
	gotoxy(x, y + 6); printscr(" ###### ");
	textcolor(WHITE, BLACK);
}

void you(int x, int y) {
	textcolor(BLUE1, BLACK);
	gotoxy(x, y);     printscr("##    ##  #######  ##     ## ");
	gotoxy(x, y + 1); printscr(" ##  ##  ##     ## ##     ## ");
	gotoxy(x, y + 2); printscr("  ####   ##     ## ##     ## ");
	gotoxy(x, y + 3); printscr("   ##    ##     ## ##     ## ");
	gotoxy(x, y + 4); printscr("   ##    ##     ## ##     ## ");
	gotoxy(x, y + 5); printscr("   ##    ##     ## ##     ## ");
	gotoxy(x, y + 6); printscr("   ##     #######   #######  ");
	textcolor(WHITE, BLACK);
}

void win(int x, int y) {
	textcolor(YELLOW1, BLACK);
	gotoxy(x, y);     printscr("##      ## #### ##    ## ");
	gotoxy(x, y + 1); printscr("##  ##  ##  ##  ###   ## ");
	gotoxy(x, y + 2); printscr("##  ##  ##  ##  ####  ## ");
	gotoxy(x, y + 3); printscr("##  ##  ##  ##  ## ## ## ");
	gotoxy(x, y + 4); printscr("##  ##  ##  ##  ##  #### ");
	gotoxy(x, y + 5); printscr("##  ##  ##  ##  ##   ### ");
	gotoxy(x, y + 6); printscr(" ###  ###  #### ##    ## ");
	textcolor(WHITE, BLACK);
}

void g(int x, int y) {
	textcolor(RED1, BLACK);
	gotoxy(x, y);     printscr(" ######   ");
	gotoxy(x, y + 1); printscr("##    ##  ");
	gotoxy(x, y + 2); printscr("##        ");
	gotoxy(x, y + 3); printscr("##   #### ");
	gotoxy(x, y + 4); printscr("##    ##  ");
	gotoxy(x, y + 5); printscr("##    ##  ");
	gotoxy(x, y + 6); printscr(" ######   ");
	textcolor(WHITE, BLACK);
}
void a(int x, int y) {
	textcolor(RED1, BLACK);
	gotoxy(x, y);     printscr("   ###    ");
	gotoxy(x, y + 1); printscr("  ## ##   ");
	gotoxy(x, y + 2); printscr(" ##   ##  ");
	gotoxy(x, y + 3); printscr("##     ## ");
	gotoxy(x, y + 4); printscr("######### ");
	gotoxy(x, y + 5); printscr("##     ## ");
	gotoxy(x, y + 6); printscr("##     ## ");
	textcolor(WHITE, BLACK);
}
void m(int x, int y) {
	textcolor(RED1, BLACK);
	gotoxy(x, y);     printscr("##     ## ");
	gotoxy(x, y + 1); printscr("###   ### ");
	gotoxy(x, y + 2); printscr("#### #### ");
	gotoxy(x, y + 3); printscr("## ### ## ");
	gotoxy(x, y + 4); printscr("##     ## ");
	gotoxy(x, y + 5); printscr("##     ## ");
	gotoxy(x, y + 6); printscr("##     ## ");
	textcolor(WHITE, BLACK);
}
void e(int x, int y) {
	textcolor(RED1, BLACK);
	gotoxy(x, y);     printscr("######## ");
	gotoxy(x, y + 1); printscr("##       ");
	gotoxy(x, y + 2); printscr("##       ");
	gotoxy(x, y + 3); printscr("######   ");
	gotoxy(x, y + 4); printscr("##       ");
	gotoxy(x, y + 5); printscr("##       ");
	gotoxy(x, y + 6); printscr("######## ");
	textcolor(WHITE, BLACK);
}
void o(int x, int y) {
	textcolor(RED1, BLACK);
	gotoxy(x, y);     printscr(" #######  ");
	gotoxy(x, y + 1); printscr("##     ## ");
	gotoxy(x, y + 2); printscr("##     ## ");
	gotoxy(x, y + 3); printscr("##     ## ");
	gotoxy(x, y + 4); printscr("##     ## ");
	gotoxy(x, y + 5); printscr("##     ## ");
	gotoxy(x, y + 6); printscr(" #######  ");
	textcolor(WHITE, BLACK);
}
void v(int x, int y) {
	textcolor(RED1, BLACK);
	gotoxy(x, y);     printscr("##     ## ");
	gotoxy(x, y + 1); printscr("##     ## ");
	gotoxy(x, y + 2); printscr("##     ## ");
	gotoxy(x, y + 3); printscr("##     ## ");
	gotoxy(x, y + 4); printscr(" ##   ##  ");
	gotoxy(x, y + 5); printscr("  ## ##   ");
	gotoxy(x, y + 6); printscr("   ###    ");
	textcolor(WHITE, BLACK);
}
void r(int x, int y) {
	textcolor(RED1, BLACK);
	gotoxy(x, y);     printscr("########  ");
	gotoxy(x, y + 1); printscr("##     ## ");
	gotoxy(x, y + 2); printscr("##     ## ");
	gotoxy(x, y + 3); printscr("########  ");
	gotoxy(x, y + 4); printscr("##   ##   ");
	gotoxy(x, y + 5); printscr("##    ##  ");
	gotoxy(x, y + 6); printscr("##     ## ");
	textcolor(WHITE, BLACK);
}

void start(int x, int y) {
	textcolor(CYAN1, BLACK);
	gotoxy(x, y);     printscr(" ######  ########    ###    ########  ######## ");
	gotoxy(x, y + 1); printscr("##    ##    ##      ## ##   ##     ##    ##    ");
	gotoxy(x, y + 2); printscr("##          ##     ##   ##  ##     ##    ##    ");
	gotoxy(x, y + 3); printscr(" ######     ##    ##     ## ########     ##    ");
	gotoxy(x, y + 4); printscr("      ##    ##    ######### ##   ##      ##    ");
	gotoxy(x, y + 5); printscr("##    ##    ##    ##     ## ##    ##     ##    ");
	gotoxy(x, y + 6); printscr(" ######     ##    ##     ## ##     ##    ##    ");
	textcolor(WHITE, BLACK);
}

void clear(int x, int y) {
	textcolor(MAGENTA1, BLACK);
	gotoxy(x, y);     printscr(" ######  ##       ########    ###    ########    #### ");
	gotoxy(x, y + 1); printscr("##    ## ##       ##         ## ##   ##     ##   #### ");
	gotoxy(x, y + 2); printscr("##       ##       ##        ##   ##  ##     ##   #### ");
	gotoxy(x, y + 3); printscr("##       ##       ######   ##     ## ########     ##  ");
	gotoxy(x, y + 4); printscr("##       ##       ##       ######### ##   ##          ");
	gotoxy(x, y + 5); printscr("##    ## ##       ##       ##     ## ##    ##     ###  ");
	gotoxy(x, y + 6); printscr(" ######  ######## ######## ##     ## ##     ##    ###  ");
	textcolor(WHITE, BLACK);
}

void printGameOver() {
	scr_clear();
	g(XMIN, YMIN);
	scr_switch();
	Sleep(100);

	scr_clear();
	g(XMIN, YMIN);
	a(XMIN+11, YMIN);
	scr_switch();
	Sleep(100);

	scr_clear();
	g(XMIN, YMIN);
	a(XMIN + 11, YMIN);
	m(XMIN + 22, YMIN);
	scr_switch();
	Sleep(100);

	scr_clear();
	g(XMIN, YMIN);
	a(XMIN + 11, YMIN);
	m(XMIN + 22, YMIN);
	e(XMIN + 33, YMIN);
	scr_switch();
	Sleep(100);

	scr_clear();
	g(XMIN, YMIN);
	a(XMIN + 11, YMIN);
	m(XMIN + 22, YMIN);
	e(XMIN + 33, YMIN);
	o(XMIN + 50, YMIN);
	scr_switch();
	Sleep(100);

	scr_clear();
	g(XMIN, YMIN);
	a(XMIN + 11, YMIN);
	m(XMIN + 22, YMIN);
	e(XMIN + 33, YMIN);
	o(XMIN + 50, YMIN);
	v(XMIN + 61, YMIN);
	scr_switch();
	Sleep(100);

	scr_clear();
	g(XMIN, YMIN);
	a(XMIN + 11, YMIN);
	m(XMIN + 22, YMIN);
	e(XMIN + 33, YMIN);
	o(XMIN + 50, YMIN);
	v(XMIN + 61, YMIN);
	e(XMIN + 72, YMIN);
	scr_switch();
	Sleep(100);

	scr_clear();
	g(XMIN, YMIN);
	a(XMIN + 11, YMIN);
	m(XMIN + 22, YMIN);
	e(XMIN + 33, YMIN);
	o(XMIN + 50, YMIN);
	v(XMIN + 61, YMIN);
	e(XMIN + 72, YMIN);
	r(XMIN + 83, YMIN);
	scr_switch();
	Sleep(1500);
}

void printWin() {
	scr_clear();
	you(XMIN+5, YMIN);
	scr_switch();
	Sleep(1000);
	scr_clear();
	you(XMIN+5, YMIN);
	win(XMIN+40, YMIN);
	scr_switch();
	Sleep(2500);
}

void printStart(int type) {
	for (int i = 0; i < 10; i++) {
		scr_clear();
		border();
		stage(XMIN + i, YMIN);
		scr_switch();
		Sleep(100);
	}
	switch (type) {
	case 1:
		scr_clear();
		border();
		stage(XMIN+10, YMIN);
		first(XMIN+60, YMIN);
		scr_switch();
		break;
	case 2:
		scr_clear();
		border();
		stage(XMIN + 10, YMIN);
		second(XMIN + 60, YMIN);
		scr_switch();
		break;
	case 3:
		scr_clear();
		border();
		stage(XMIN + 10, YMIN);
		third(XMIN + 60, YMIN);
		scr_switch();
		break;
	}
	Sleep(1000);
	scr_clear();
	border();
	start(XMIN + 17, YMIN);
	scr_switch();
	Sleep(1500);
}

void printClear(int type) {
	scr_clear();
	border();
	stage(XMIN + 10, YMIN-3);
	scr_switch();
	Sleep(1500);
	
	switch (type) {
	case 1:
		scr_clear();
		border();
		stage(XMIN + 10, YMIN-3);
		first(XMIN + 60, YMIN-3);
		scr_switch();
		Sleep(1500);
		scr_clear();
		border();
		stage(XMIN + 10, YMIN - 3);
		first(XMIN + 60, YMIN - 3);
		clear(XMIN + 11, YMIN + 6);
		scr_switch();
		Sleep(3500);
		break;
	case 2:
		scr_clear();
		border();
		stage(XMIN + 10, YMIN-3);
		second(XMIN + 60, YMIN-3);
		scr_switch();
		Sleep(1500);
		scr_clear();
		border();
		stage(XMIN + 10, YMIN - 3);
		second(XMIN + 60, YMIN - 3);
		clear(XMIN + 11, YMIN + 6);
		scr_switch();
		Sleep(3500);
		break;
	case 3:
		scr_clear();
		border();
		stage(XMIN + 10, YMIN-3);
		third(XMIN + 60, YMIN-3);
		scr_switch();
		Sleep(1500);
		scr_clear();
		border();
		stage(XMIN + 10, YMIN - 3);
		third(XMIN + 60, YMIN - 3);
		clear(XMIN + 11, YMIN + 6);
		scr_switch();
		Sleep(3500);
		break;
	}
	
}

void printGun() {
	int x = 37;
	int y = 28;
	switch (selectWeapon) {
	case HG:
		gotoxy(x, y);	printscr("            ■  ■                            ");
		gotoxy(x, y+1);	printscr("        ■■■■■■■■■■■■■■■■■■■");
		gotoxy(x, y+2);	printscr("      ■            ■■                  ■■");
		gotoxy(x, y+3);	printscr("    ■                                    ■  ");
		gotoxy(x, y+4);	printscr("      ■■■      ■■■■■■■■■■■■■  ");
		gotoxy(x, y+5);	printscr("          ■    ■  ■  ■                    ");
		gotoxy(x, y+6);	printscr("        ■    ■    ■  ■                    ");
		gotoxy(x, y+7);	printscr("      ■    ■■■■■■                      ");
		gotoxy(x, y+8);	printscr("    ■    ■                                  ");
		gotoxy(x, y+9);	printscr("      ■■                                      ");
		gotoxy(x, y+10);	printscr("                                                                                           ");
		//space 랑 ■ 랑 크기가 달라서 그림이 깨져보이는데 콘솔상으론 제대로 보임
		break;
	case AR:
		gotoxy(x, y);	printscr("            ■■■■■■■■■■■■■■■■■■■■■■■            ■  ");
		gotoxy(x, y+1);	printscr("■■■    ■                                              ■■■■■■■■");
		gotoxy(x, y+2);	printscr("■    ■■    ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
		gotoxy(x, y+3);	printscr("■          ■  ■  ■■      ■  ■    ■■■");
		gotoxy(x, y+4);	printscr("■        ■    ■  ■        ■  ■ ");
		gotoxy(x, y+5);	printscr("■      ■      ■  ■        ■  ■");
		gotoxy(x, y+6);	printscr("■■■■        ■■■        ■  ■");
		gotoxy(x, y+7);	printscr("                              ■■  ■");
		gotoxy(x, y+8);	printscr("                                ■  ■■");
		gotoxy(x, y+9);	printscr("                                  ■■");
		break;
	case SG:
		gotoxy(x, y);	printscr("                                                                                            ");
		gotoxy(x, y+1);	printscr("                  ■■■■■■■■■■■■■■■■■■                                      ");
		gotoxy(x, y+2);	printscr("              ■■■■■■■■■■■■■■■■■■■■■■■■                              ");
		gotoxy(x, y+3);	printscr("          ■■■      ■■              ■■■■■■■                                      ");
		gotoxy(x, y+4);	printscr("      ■■■■  ■    ■■■■■■■■■■  ■  ■  ■■■■                                ");
		gotoxy(x, y+5);	printscr("    ■    ■■■■■■■■■■■■■■■■  ■  ■  ■■■■                                ");
		gotoxy(x, y+6);	printscr("  ■    ■    ■  ■  ■                ■■■■■■■                                      ");
		gotoxy(x, y+7);	printscr("■    ■      ■■■■                                                                      ");
		gotoxy(x, y+8);	printscr("■  ■■                                                                                    ");
		gotoxy(x, y+9);	printscr("■■■                                                                                      ");

		gotoxy(10, 24);

		break;
	case SR:
		gotoxy(x, y);	printscr("                                  ■■      ■■■■                                        ");
		gotoxy(x, y+1);	printscr("                      ■■■■■■    ■■■■    ■                                        ");
		gotoxy(x, y+2);	printscr("                      ■■■■■■■■■■■■■■■                                        ");
		gotoxy(x, y+3);	printscr("                            ■■        ■■                                                ");
		gotoxy(x, y+4);	printscr("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
		gotoxy(x, y+5);	printscr("■                ■■■■■■■■■              ■■■■■■■■■  ■■■■■■■■■■■");
		gotoxy(x, y+6);	printscr("■            ■■  ■    ■  ■  ■■■■■■■■                ■■■                    ");
		gotoxy(x, y+7);	printscr("■        ■■      ■  ■    ■  ■                                                        ");
		gotoxy(x, y+8);	printscr("■      ■        ■  ■  ■■■■                                                          ");
		gotoxy(x, y+9);	printscr("■■■■          ■  ■                                                                    ");
		gotoxy(x, y+10);printscr("                ■■■                                                                      ");

		break;
	}
}

void reloadGun() {
	int x = 37;
	int y = 28;
	switch (selectWeapon) {
	case HG:
		gotoxy(x, y);		printscr("                                    ■        ");
		gotoxy(x, y + 1);	printscr("■■■■■■■■■■■■■■■■■■■■      ");
		gotoxy(x, y + 2);	printscr("■                                    ■■■■");
		gotoxy(x, y + 3);	printscr("■                                        ■■");
		gotoxy(x, y + 4);	printscr("  ■            ■■■■■■■■■■■■■■  ");
		gotoxy(x, y + 5);	printscr("    ■        ■  ■■        ■              ");
		gotoxy(x, y + 6);	printscr("  ■        ■■    ■        ■              ");
		gotoxy(x, y + 7);	printscr("  ■      ■  ■■    ■■■■                ");
		gotoxy(x, y + 8);	printscr("■      ■        ■■■                      ");
		gotoxy(x, y + 9);	printscr("■      ■                                    ");
		gotoxy(x, y + 10);	printscr("■■■■■                                    ");
		//space 랑 ■ 랑 크기가 달라서 그림이 깨져보이는데 콘솔상으론 제대로 보임
		break;
	case AR:
		gotoxy(x, y);		printscr("                                                                          ");
		gotoxy(x, y + 1);	printscr("            ■■■■■■■■■■■■■■■■■■■■■■■            ■  ");
		gotoxy(x, y + 2);	printscr("■■■    ■                                              ■■■■■■■■");
		gotoxy(x, y + 3);	printscr("■    ■■    ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
		gotoxy(x, y + 4);	printscr("■          ■  ■  ■■                ■■■                            ");
		gotoxy(x, y + 5);	printscr("■        ■    ■  ■        ■■■                                      ");
		gotoxy(x, y + 6);	printscr("■      ■      ■  ■        ■  ■                                      ");
		gotoxy(x, y + 7);	printscr("■■■■        ■■■        ■  ■                                      ");
		gotoxy(x, y + 8);	printscr("                              ■■  ■                                    ");
		gotoxy(x, y + 9);	printscr("                                ■  ■■                                  ");
		gotoxy(x, y + 10);	printscr("                                  ■■                                    ");
		break;
	case SG:
		gotoxy(x, y);		printscr("                                                              ");
		gotoxy(x, y + 1);	printscr("              ■■■■■■■■■■■■■■■■■■■■■■■■");
		gotoxy(x, y + 2);	printscr("          ■■■      ■■      ■■■■■■■                ");
		gotoxy(x, y + 3);	printscr("      ■■■■  ■    ■■■■■■  ■  ■  ■■■■■■■■  ");
		gotoxy(x, y + 4);	printscr("    ■    ■■■■■■■■■■■■  ■  ■  ■■■■■■■■  ");
		gotoxy(x, y + 5);	printscr("  ■    ■    ■  ■  ■        ■■■■■■■                ");
		gotoxy(x, y + 6);	printscr("■    ■      ■■■■                                        ");
		gotoxy(x, y + 7);	printscr("■  ■■                                                      ");
		gotoxy(x, y + 8);	printscr("■■■                                                        ");

		break;
	case SR:
		gotoxy(x, y);		printscr("                                  ■■      ■■■■                                        ");
		gotoxy(x, y + 1);	printscr("                      ■■■■■■    ■■■■    ■                                        ");
		gotoxy(x, y + 2);	printscr("                      ■■■■■■■■■■■■■■■                                        ");
		gotoxy(x, y + 3);	printscr("                            ■■        ■■                                                ");
		gotoxy(x, y + 4);	printscr("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
		gotoxy(x, y + 5);	printscr("■                ■■■■■■■■■              ■■■■■■■■■  ■■■■■■■■■■■");
		gotoxy(x, y + 6);	printscr("■            ■■  ■    ■  ■  ■■■■■■■■                ■■■                    ");
		gotoxy(x, y + 7);	printscr("■        ■■      ■  ■    ■  ■                                                        ");
		gotoxy(x, y + 8);	printscr("■      ■        ■  ■  ■■■■      ■■■■                                            ");
		gotoxy(x, y + 9);	printscr("■■■■          ■  ■                ■■■■                                            ");
		gotoxy(x, y + 10);	printscr("                ■■■                                                                      ");

		break;
	}
}