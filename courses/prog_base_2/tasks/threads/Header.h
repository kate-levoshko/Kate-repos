#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#define MAX_AMOUNT_OF_LETTERS 100
#define AMOUNT_OF_STRINGS 10

#include "thread.h"
#include "mutex.h"

typedef struct text_s{
	char * strings[AMOUNT_OF_STRINGS];
	char * str;
	int number;
	mutex_t * mu;
} text_t;