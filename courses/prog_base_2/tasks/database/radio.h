#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct radio_s{
	int id;
	char name[256];
	char surname[256];
	char jobBeginDate[256];
	float jobExperience;
	char style[256];
	int salary;
	int programsAmount;
} radio_t;

void radio_print(radio_t * radio);
void radio_printList(radio_t * arr, int len);
