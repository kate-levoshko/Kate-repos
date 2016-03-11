#include <stdio.h>
#include <stdlib.h>

#include "post.h"
/*  Масив структур даних типу Пост у соцмережі.
	Можна вставляти елементи на будь-яку позицію у списку і
	видаляти елементи,
	отримувати розмір списку.
	Додати функції отримання вказівника на пост із найбільшою кількістю репостів та
	отримання масиву постів, у яких кількість репостів більша за задане число.
*/

struct list_s{
	int amount;
	enum ListError status;
	struct post_s * p[MAX_AMOUNT_OF_POSTS];
};

struct post_s{
	int reposts;
	char text[MAX_AMOUNT_OF_SYMBOLS];
};

// constructor
list_t * list_new(){
	list_t * l = (list_t * )malloc(sizeof(struct list_s));
	l->amount = 0;
	return l;
}
 // destructor
void list_free(list_t * self){
	for (int i = 0; i < self->amount; i++){
		free(self->p[i]);
	}
	free(self);
}

enum ListError list_getStatus(list_t * self){
	return self->status;
}

void list_setPostAt(list_t * self, int index, char * text){
	if (index < 0 || index > MAX_AMOUNT_OF_POSTS){
		self->status = WRONG_INDEX;
		return 0;
	}
	self->p[self->amount] = (struct post_s *)malloc(sizeof(struct post_s));
	for (int i = self->amount; i > index; i--){
		self->p[i] = self->p[i - 1];
	}
	strcpy(self->p[index]->text, text);
	self->amount++;
	self->status = LIST_OK;
}

void list_postRemove(list_t * self, int index){
	if (index < 0 || index > MAX_AMOUNT_OF_POSTS){
		self->status = WRONG_INDEX;
		return 0;
	}
	else if (self->amount == 0){
		self->status = LIST_EMPTY;
		return 0;
	}

	for (int i = self->p[index]; i < self->amount; i++){
		self->p[i - 1] = self->p[i];
	}
	self->amount--;
}

int list_getSize(list_t * self){
	return self->amount;
	self->status = LIST_OK;
}

int list_getIndex(list_t * self){
	int max = self->p[0];
	int index = -1;
	for (int i = 0; i < self->amount; i++){
		if (self->p[i] > max){
			max = self->p[i];
			index = i;
		}
	}
	return index;
}

list_t * list_listOfPosts(list_t * self, int amountOfReposts){
	if (amountOfReposts < 0){
		self->status = INCORRECT_AMOUNT;
		return 0;
	}
	list_t * newList = list_new();
	int k = 0;
	for (int i = 0; i < self->amount + 1; i++){
		if (self->p[i]->reposts > amountOfReposts){
			list_setPostAt(newList, k, self->p[i]->text);
			k++;
		}
	}
	return list_new();
}