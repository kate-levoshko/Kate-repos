#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#define MAX_AMOUNT_OF_LETTERS 100
#define AMOUNT_OF_STRINGS 10

#include "thread.h"
#include "mutex.h"

/*
	Модуль Writer приймає вказівник на строку і масив строк, 
	кожна з яких слово і створює потік, 
	у якому по черзі присвоює вказівнику на строку значення із масиву строк(циклічно).
	Модуль Reader приймає вказівник на ту ж строку, і створює потік, 
	у якому перевіряє вказівник на строку 
	і, якщо довжина строки менша 5, виводить її у консоль.
	В main() створити 1 Writer та 2 Reader модулі і передати їм вказівники на спільну строку.
	Синхронізувати доступ до строки.
*/

typedef struct text_s{
	char * strings[MAX_AMOUNT_OF_LETTERS];
	char * str;
	int number;
	mutex_t * mu;
} text_t;

void * Writer(void * args) {
	text_t * text = (text_t *)args;
	while (1) {
		mutex_lock(text->mu);
		text->str =	text->strings[text->number++];
		if (text->number == AMOUNT_OF_STRINGS){
			text->number = 0;
		}
		mutex_unlock(text->mu);
	}
	return NULL;
}

void * Reader(void * args) {
	text_t * text = (text_t *)args;
	while (1) {
		mutex_lock(text->mu);
		if (strlen(text->str) < 5){
			puts(text->str);
		}
		mutex_unlock(text->mu);
		Sleep(1);
	}
	return NULL;
}

int main(){
	text_t data;

	for (int i = 0; i < AMOUNT_OF_STRINGS; i++){
		data.strings[i] = (char *)malloc(MAX_AMOUNT_OF_LETTERS*sizeof(char));
	}
	data.mu = mutex_new();
	data.number = 0;

	strcpy(data.strings[0], "word1");
	strcpy(data.strings[1], "word2");
	strcpy(data.strings[2], "word3");
	strcpy(data.strings[3], "kpi");
	strcpy(data.strings[4], "hell");
	strcpy(data.strings[5], "word6");
	strcpy(data.strings[6], "word7");
	strcpy(data.strings[7], "word8");
	strcpy(data.strings[8], "word9");
	strcpy(data.strings[9], "Ruslan");

	thread_t * setter= thread_create_args(Writer, &data);
	thread_t * getter1 = thread_create_args(Reader, &data);
	thread_t * getter2 = thread_create_args(Reader, &data);
	thread_join(getter2); 
	thread_free(setter);
	thread_free(getter1);
	thread_free(getter2);
	mutex_free(data.mu);
	return 0;
}