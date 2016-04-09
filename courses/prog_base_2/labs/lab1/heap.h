#pragma once

#define MAX_AMOUNT_OF_OBJECTS 100

#include "header.h"

enum HeapError {
	HEAP_OK,
	HEAP_OVERFLOW,
	HEAP_EMPTY,
	HEAP_INRORRECTNUMBER
};

heap_t * heap_new(int numberOfProcess);		// conctructor
void heap_free(heap_t * self);				// destructor

memory_t * heap_addMemory(heap_t * self); // создавать новые экземпл€ры выделенной пам€ти
void heap_freeMemory(heap_t * self, int index); // очищать выделенную пам€ть экземпл€ров
int heap_amountOfObjects(heap_t * self);
