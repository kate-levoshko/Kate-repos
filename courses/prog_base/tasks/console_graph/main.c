#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <conio.h>

void fillBackground(void);
void drawAxis(COORD pos_c);
void writeGraph(int num);
void print(COORD pos_c,int x,int y);
void GRAPH(COORD pos_c,int,int);
void link (COORD pos_c,int, int, int, int);



int main()
{
	int num = 1;
	int deformation=20;
	fillBackground();
	COORD pos_c;//pos_centre
	pos_c.X = 40;
	pos_c.Y = 12;
	drawAxis(pos_c);
	writeGraph(num);
	GRAPH(pos_c,deformation,num);
	int c = 0;
	while (c != 27){
		c = _getch();
		switch (c){
		case 'w':
				pos_c.Y--;
				fillBackground();
				drawAxis(pos_c);
				writeGraph(num);
				GRAPH(pos_c, deformation, num);
				break;
		case 's':
			pos_c.Y++;
			fillBackground();
			drawAxis(pos_c);
			writeGraph(num);
			GRAPH(pos_c, deformation, num);
			break;
		case 'a':
			pos_c.X--;
			fillBackground();
			drawAxis(pos_c);
			writeGraph(num);
			GRAPH(pos_c, deformation, num);
			break;
		case 'd':
			pos_c.X++;
			fillBackground();
			drawAxis(pos_c);
			writeGraph(num);
			GRAPH(pos_c, deformation, num);
			break;
		case '+':
			deformation--;
			if (deformation == 0) deformation = 1;
			fillBackground();
			drawAxis(pos_c);
			writeGraph(num);
			GRAPH(pos_c, deformation, num);
			break;
		case '-':
			deformation++;
			fillBackground();
			drawAxis(pos_c);
			writeGraph(num);
			GRAPH(pos_c, deformation, num);
			break;

		case 32:
			num = (num == 1) ? 2 : 1;
			fillBackground();
			drawAxis(pos_c);
			writeGraph(num);
			GRAPH(pos_c, deformation, num);
			break;
		}
	}
	return 0;
}

void fillBackground(void){
	int fmt;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 0;
	pos.Y = 0;
	SetConsoleCursorPosition(hConsole, pos);
	fmt = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
	SetConsoleTextAttribute(hConsole, fmt);
	for (pos.Y = 0; pos.Y < 25; pos.Y++){
		for (pos.X = 0; pos.X < 80; pos.X++){
		printf(" ");
		}
	}
}

void drawAxis (COORD pos_c){
	int fmt;
	COORD draw;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	fmt = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
	SetConsoleTextAttribute(hConsole, fmt);

	draw.Y = pos_c.Y;

	for (draw.X = 0; draw.X < 80; draw.X++){
		SetConsoleCursorPosition(hConsole, draw);
		if (draw.X % 2 == 0){
			printf("+");
		}
		else printf("-");
}
	draw.X = pos_c.X;
	for (draw.Y = 0; draw.Y < 25; draw.Y++){
		SetConsoleCursorPosition(hConsole, draw);
		if (draw.Y % 2 == 0){
			printf("+");
		}
		else printf("|");
	}
}

void print(COORD pos_c,int x,int y){
	int fmt;
	COORD pos;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	fmt = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
	SetConsoleTextAttribute(hConsole, fmt);
	pos.X =pos_c.X+x ;
	pos.Y = pos_c.Y-y;
	if ((pos.X >= 0) && (pos.X <= 79) && (pos.Y>=0)&&(pos.Y<=24)){
		SetConsoleCursorPosition(hConsole, pos);
		printf(" ");
	}
}

void GRAPH(COORD pos_c,int deformation,int num){
	int x, y,x1,y1,x2,y2;
	x1 = -40;
	if (num == 1) y1 = (0.3*tan(x1*deformation/20 ) + 2)*deformation/20;
	else y1 = (sqrt(x1*deformation/20 + 5) - 7)*deformation/20;
	for (x = -39; x < 40; x++){
		if (num == 1) y = (0.3*tan(x*deformation/20) + 2)*deformation/20;
		else y = (sqrt(x*deformation/20 + 5) - 7)*deformation/20;

		x2 = x;
		y2 = y;
		if (abs(y) <= 50){
			print(pos_c, x, y);
			link(pos_c, x1, y1, x2, y2);
		}
		x1 = x2;
		y1 = y2;
	}
}

void writeGraph(int num){
	int fmt;
	COORD pos;
	pos.X = 0;
	pos.Y = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, pos);
	fmt = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
	SetConsoleTextAttribute(hConsole, fmt);
	if (num == 1) printf("F(x) = 0.3*tg(x) + 2");
	else printf("F(x) = sqrt(x +5)+ 2");

}

void link (COORD pos_c,int x1,int y1,int x2,int y2){
	if (y1 < y2){
		while (y1 < y2){
			print(pos_c, x1, y1);
			y1++;
		}
	}
	if (y1>y2){
		while (y2 < y1){
			print(pos_c, x2, y2);
			y2++;
		}
	}
}
