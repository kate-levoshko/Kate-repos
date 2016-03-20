#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_AMOUNT_OF_SYMBOLS 100

typedef void(*callback_t)(char *, int);

void server(char * connectedClients[], char* newName, int number, callback_t onClientConnectedCB, callback_t onClientDisconnected){
	if (strcmp(connectedClients[number], "") == 0){
		puts("\n");
		strcpy(connectedClients[number], newName);
		onClientConnectedCB(connectedClients, number);
	}
	else {
		puts("\n");
		onClientDisconnected(connectedClients, number);
		strcpy(connectedClients[number],"");
	}
}

void onClientConnectedCB1(char * connectedClients[], int number){
	printf("new %d: %s\n", number, connectedClients[number]);
}

void onClientDisconnectedCB1(char * connectedClients[], int number){
	printf("deleting %d: %s\n", number, connectedClients[number]);
}

void onClientConnectedCB2(char * connectedClients[], int number){
	for (int j = 0; j < 10; j++){
		if (strcmp(connectedClients[j], "") != 0){
			printf("%d: %s\n", j, connectedClients[j]);
		}
	}
}

void onClientDisconnectedCB2(char * connectedClients[], int number){
	for (int j = 0; j < 10; j++){
		if (strcmp(connectedClients[j], "") != 0 && j != number){
			printf("%d: %s\n", j, connectedClients[j]);
		}
	}
}

int main(void)
{
	srand(time(NULL));
	int number = rand() % 10;
	printf("%d\n", number);
	char newName[MAX_AMOUNT_OF_SYMBOLS] = "Ivan Ivanov";

	char * connectedClients[10];

	for (int i = 0; i < 10; i++){
		connectedClients[i] = (char *)malloc(MAX_AMOUNT_OF_SYMBOLS*sizeof(char));
	}
	strcpy(connectedClients[0], "Lina Dovhaniuk");
	strcpy(connectedClients[1], "Katya Levoshko");
	strcpy(connectedClients[2], "");
	strcpy(connectedClients[3], "Olga Yashan");
	strcpy(connectedClients[4], "");
	strcpy(connectedClients[5], "Dima Urukov");
	strcpy(connectedClients[6], "Ruslan Hadyniak");
	strcpy(connectedClients[7], "");
	strcpy(connectedClients[8], "");
	strcpy(connectedClients[9], "Karina Chumak");

	for (int j = 0; j < 10; j++){
		if (strcmp(connectedClients[j],"") != 0){
			printf("%d: %s\n", j, connectedClients[j]);
		}
	}
	//server(connectedClients, newName, number, onClientConnectedCB1, onClientDisconnectedCB1);
	server(connectedClients, newName, number, onClientConnectedCB2, onClientDisconnectedCB2);
	getchar();
	return 0;
}

