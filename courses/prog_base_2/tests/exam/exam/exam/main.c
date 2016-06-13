/*Функція, що приймає строку у якій повинні бути записані цілі числа, 
що розділені однією комою(допускається будь - яка кількість пробільних символів між комами і числами).
Функція повертає суму цих чисел.*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int getString(char * str){
	char * end;
	int it = 0;
	int sum = 0;
	for (int i = 0; i < strlen(str); i++){
		if (isdigit(str[i])) it++;
	}
	/*for (int i = 0; i < it; i++){
		sum
	}*/

	while (strtol(str, &end, 10) != 0){
		sum += strtol(str, &end, 10);
		strtol(&end, NULL, 10);
	}
	
	return sum;
}



int main(void){

	int func = getString("    1     ,    2   ,   3  ,   4   ");
	printf("%d", func);
	getchar();
	return 0;
}