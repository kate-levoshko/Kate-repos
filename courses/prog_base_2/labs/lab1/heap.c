#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "header.h"

memory_t * memory_new(heap_t * self); // conctructor

struct heap_s{
	int status;
	int amountOfObjects;
	int numberOfProcess;
	struct memory_s * memory[MAX_AMOUNT_OF_OBJECTS];
};

heap_t * heap_new(int numberOfProcess){
	heap_t * h = (heap_t *)malloc(sizeof(struct heap_s));
	h->amountOfObjects = 0;
	if (numberOfProcess < 0){
		h->status = HEAP_INRORRECTNUMBER;
	}
	else{
		h->numberOfProcess = numberOfProcess;
		printf("Heap %d is created!\n", numberOfProcess);
	}
	return h;
}

void heap_free(heap_t * self){
	for (int i = 0; i < self->amountOfObjects; i++){
		free(self->memory[i]);
	}
	free(self);
}

enum HeapError heap_getStatus(heap_t * self){
	return self->status;
}

memory_t * heap_addMemory(heap_t * self){
	if (self->amountOfObjects > MAX_AMOUNT_OF_OBJECTS){
		self->status = HEAP_OVERFLOW;
	}
	else {
		self->memory[self->amountOfObjects] = malloc(memory_getStructSize());
		memory_setNullAllocMemorySize(self->memory[self->amountOfObjects]);
		memory_setNullAmountOfObjects(self->memory[self->amountOfObjects]);
		memory_setNullData(self->memory[self->amountOfObjects]);
		self->amountOfObjects++;
		self->status = HEAP_OK;
		return self->memory[self->amountOfObjects-1];
	}	
}

void heap_freeMemory(heap_t * self, int index){
	if (index < 0 || index > self->amountOfObjects){
		self->status = MEMORY_INCORRECTDATA;
		return;
	}
	if (self->amountOfObjects == 0){
		self->status = MEMORY_EMPTY;
		return;
	}
	self->memory[index] = NULL;
	for (int i = 1; i < self->amountOfObjects; i++){
		self->memory[i - 1] = self->memory[i];
	}
	self->amountOfObjects--;
	self->status = HEAP_EMPTY;
}

int heap_amountOfObjects(heap_t * self){
	self->status = HEAP_OK;
	return self->amountOfObjects;
}