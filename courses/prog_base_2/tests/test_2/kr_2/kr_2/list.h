#pragma once
#define _CRT_SECURE_NO_WARNINGS

typedef struct list_s list_t;

list_t * list_new();
void list_free(list_t * self);

void list_add(list_t * self, void * info);
void * list_remove(list_t * self, int index);

void * list_get(list_t * self, int index);
int list_size(list_t * self);
int list_isEmpty(list_t * self);

