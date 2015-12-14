#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int amount(char * str, int number, int index){

	if (strlen(str) == 0)  return 0;
	else if (isalnum(str[index])){
		number++;
		amount(str, number, index + 1);
	}
	else if (strlen(str)>index){
		amount(str, number, index + 1);
	}
	else return number;
}

int main(void) {
	char str[100];
	int index = 0;
	int number = 0;
	puts("Please, enter your string");
	gets(str);
	int res = amount(str, number, index);
	printf("%i", res);
	return 0;
}
