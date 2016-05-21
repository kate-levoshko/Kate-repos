#include "listener.h"

struct listener_s{
	int amount;
};
/*
listener_t * listener_new(int capacity){
	listener_t * listener = malloc(sizeof(struct listener_s));
	listener->arr = malloc(capacity*sizeof(list_t));
	list->length = 0;
}

void list_free(list_t * self){
	free(self->arr);
	free(self);
}

void list_add(list_t * self, track_t data){
	self->arr[self->length++] = data;
}

track_t list_get(list_t * self, int index){
	return self->arr[index];
}

track_t list_delete(list_t * self, int index){
	if (index >= self->length || index < 0) exit(EXIT_SUCCESS);
	track_t res = self->arr[index];
	for (int i = index; i < self->length - 1; i++){
		self->arr[i] = self->arr[i + 1];
	}
	self->length--;
	return res;
}
*/