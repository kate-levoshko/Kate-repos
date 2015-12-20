#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct INGREDIENTS{
	char components[100];
	double icost;
};

struct DISH{          //меню - это массив блюд
	char dishes[100];
	struct INGREDIENTS * ing[10];
};


void ChangeSize(void){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    BOOL ok;
    coord.X = 120;
    coord.Y = 50;
    ok = SetConsoleScreenBufferSize(hStdout, coord);
    SMALL_RECT test = { 0, 0, coord.X - 1, coord.Y - 1 };
    SetConsoleWindowInfo(hStdout, ok, &test);
}

void Colour(int k){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int i;
    for (i = 0; i < 250; i++){
        SetConsoleTextAttribute(hConsole, k);
    }
 }

void jump(int x, int y){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}

void printSt2(int dsize, struct DISH * dlist){
	int i = 0;
	double cost = 0;
	jump(10, dsize*12+i+2);
    printf("%s", dlist->dishes);
    while(dlist->ing[i] != NULL)
    {
        jump(30, 2+dsize*12+i+2);
        printf("%s", dlist->ing[i]->components);
        cost += dlist->ing[i]->icost;
        i++;
    }
	jump(40, 2+dsize*12);
    printf("\t%.2f", cost);

}

void printMenu(char* commands[], int x, int y, int selected, int size){
    int i;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	system("cls");
	jump(x, y);
	Colour(250); //green
	for (i = 0; i < size; i++){
        if (i == selected){
            Colour(230);
            printf("%s", commands[i]);
            Colour(250);
        }
        else printf("%s", commands[i]);
        jump(x, y+i+1);
	}

}
int Menu(char* commands, int size, int x, int y){
    int selected = 0;
    while(TRUE){
        printMenu(commands, x, y , selected, size);
        int button = getch();
        if (button == 13) return selected;
        else if (button == 'w') selected--;
        else if (button == 's') selected++;
        if (selected == -1) selected = size -1;
        else if (selected == size) selected = 0;
    }
}
void minAndMaxCostDish(int dsize, struct DISH  dlist[], double cost){
    int j;
    for (j = 0; j <dsize; j++){
    int i = 0;
    double minval = dlist[i].ing[0]->icost;
    double maxval = dlist[i].ing[0]->icost;
    while (dlist[j].ing[i]->components != NULL){
         if (dlist[j].ing[i]->icost > maxval)
            maxval = dlist[j].ing[i]->icost;
        if(dlist[j].ing[i]->icost < minval)
            minval = dlist[j].ing[i]->icost;
            i++;
        }
    printf("%.2lf\n ", maxval);
    printf("%.2lf\n", minval);
    }
}

void addDish(struct INGREDIENTS * ing, struct DISH * d1, char * ingred[16]){
	int n = 0;
	char temp[30];
	n++;
	int j = 0;
    jump(35,15);
	printf("Please rename the dish:\n");
	jump(35,16);
	scanf("%s",d1->dishes);
	jump(35,18);
	printf("Choose your ingredients :\n");
	jump(35, 20);
	printf("Ingredients : \n");

	do{
		for (j = 0; j < 7; j++){
                Colour(225);
			printf("%d. %s\tCost %.2lf\t\n", j + 1, ing[j].components, ing[j].icost);
		}
		break;
	} while (1);
}
int write (struct DISH * d1, struct INGREDIENTS * ing, int dsize, struct DISH dlist[dsize]){
    FILE *file;
    file = fopen ("dishes.txt", "w");
   	int i = 0, j;
	double cost = 0;
	jump(10, dsize*12+i+2);
    fprintf(file, "%s\n", dlist->dishes);
            while(dlist->ing[i] != NULL)
    {
        jump(30, 2+dsize*12+i+2);
        fprintf(file, "%s\n", dlist->ing[i]->components);
        cost += dlist->ing[i]->icost;
        i++;
    }
	jump(40, 2+dsize*12);
    fprintf(file,"\t%.2f", cost);
    fclose(file);
}

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ChangeSize();
    int icost;
	struct INGREDIENTS ilist[] = { { "potato", 1.23 },  //0
									{ "carrot", 0.72 },  //1
									{ "green", 1.7 }, //2
									{ "onion", 1.2 }, //3
                                    { "meat ", 5.57 }, //4
									{ "fish ", 4.8 },//5
									{ "lemon", 1.72 },//6
									{ "tomato", 0.83 },//7
									{ "mushroom", 4.9 },//8
									{ "butter", 2.29 },//9
									{ "cheese", 3.2 },//10
									{ "macaroni", 2.7 },//11
									{ "flour", 1.2 },//12
									{ "salt ", 0.05 },//13
									{ "pepper", 0.05 },//14
									{ "water", 1.0 } };//15

    int i;
    char * ingred[16];
    for (i = 0; i<16; i++){
        ingred[i]=(char*)malloc(100*sizeof(char));
        sprintf(ingred[i],"%s %.2f$", ilist[i].components, ilist[i].icost);
    }
    struct DISH dlist[] = {{"Mushroom cream soup: ", &ilist[1], &ilist[3], &ilist[8], &ilist[9], &ilist[10], &ilist[13], &ilist[15], &ilist[2]},
                            {"Baked fish:", &ilist[1],&ilist[9],&ilist[5],&ilist[6],&ilist[13],&ilist[14]},
                            {"Pizza", &ilist[12],&ilist[15],&ilist[9],&ilist[9],&ilist[4],&ilist[3],&ilist[7],&ilist[8],&ilist[10]}};

    int dsize = sizeof(dlist)/sizeof(struct DISH);
    int isize = sizeof(ilist)/sizeof(struct INGREDIENTS);
	struct INGREDIENTS * ing = &ilist;
	struct DISH * d1 = &dlist;
    struct DISH * d2 = &dlist[2];
    char * commands[] = {"Ingredients", "Menu", "Rename the first dish", "Categories", "Exit"};
    int sizeC = sizeof(commands)/sizeof(int*);
    double cost;
    while(TRUE){
            int num = Menu(commands, sizeC, 43, 5);
            jump(5, 5);
            SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            system("cls");

        switch(num){
            case 0: SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
                    int ingr = Menu(ingred, 16, 1, 1);
                    getch();
                    break;
            case 1: Colour(252);
                    jump(10, 1);
                    puts("Dishes:\t\t\t\tPrice($):");
                    Colour(249);
                    for (i = 0; i < dsize; i++)
                    printSt2(i, &dlist[i]);
                    getch();
                    break;
            case 2: addDish(ing, d1, ingred);
                    getch();
                    break;
            case 3: minAndMaxCostDish(dsize, dlist, cost);
                    getch();
                    Colour(255);
                    break;
            case 4: free(ingred[16]);
                    write (d1, ing, dsize, dlist);
                    exit(EXIT_SUCCESS);
                    break;
            }
}
	getchar();
	return 0;
}
