#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define SLEEP_MILLISECONDS 4

int changeColour (COORD pos){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int colour = 0;
    switch (pos.X + pos.Y) {
        case 70 ... 79:
        case 24 ... 33:colour = BACKGROUND_RED | BACKGROUND_BLUE;
        SetConsoleTextAttribute(hConsole, colour);
            break;
        case 34 ... 69: colour = BACKGROUND_RED;
        SetConsoleTextAttribute(hConsole, colour);
            break;
        default: colour = BACKGROUND_RED | BACKGROUND_GREEN;
        SetConsoleTextAttribute(hConsole, colour);
            break;
               }
    return colour;
}
COORD leftBord(COORD pos, int lBorder){
    int colour = 0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (pos.X>lBorder){
        SetConsoleCursorPosition(hConsole, pos);
        changeColour (pos);
		Sleep(SLEEP_MILLISECONDS);
		printf("*");
		pos.X--;
	}
	return pos;
}

COORD downBord(COORD pos, int dBorder){
    int colour = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (pos.Y<dBorder){
		SetConsoleCursorPosition(hConsole, pos);
        changeColour (pos);
		Sleep(SLEEP_MILLISECONDS);
		printf("*");
		pos.Y++;
	}
	return pos;
}

COORD rightBord(COORD pos, int rBorder){
    int colour = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (pos.X < rBorder){
		SetConsoleCursorPosition(hConsole, pos);
        changeColour (pos);
		Sleep(SLEEP_MILLISECONDS);
		printf("*");
		pos.X++;
	}
	return pos;
}
COORD upBord(COORD pos, int uBorder){
    int colour = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (pos.Y > uBorder){
		SetConsoleCursorPosition(hConsole, pos);
		changeColour (pos);
		Sleep(SLEEP_MILLISECONDS);
		printf("*");
		pos.Y--;
	}
	return pos;
}

int main(void){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	int i;
	int lBorder = 0, dBorder = 24, rBorder = 79, uBorder = 1;
	pos.X = 79;
	pos.Y = 0;
	for (i = 1; i < 14; i++){
       	pos=leftBord(pos, lBorder);
        lBorder++;
        pos = downBord(pos, dBorder);
        dBorder--;
        pos = rightBord(pos, rBorder);
        rBorder--;
        pos = upBord(pos, uBorder);
        uBorder++;
        changeColour (pos);
	}
	return EXIT_SUCCESS;
}
