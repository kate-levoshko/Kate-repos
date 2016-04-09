#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

struct memory_s{
	int status;
	int allocMemorySize;
	int amountOfObjects;
	char data[MAX_AMOUNT_OF_BYTES];
};


enum MemoryError memory_getStatus(memory_t * mem){
	return mem->status;
}

void memory_writeBytesInMemory(memory_t * mem, char * bytes){
	if (strlen(bytes) + mem->allocMemorySize > MAX_AMOUNT_OF_BYTES){
		mem->status = MEMORY_FULL;
	}
	else {
		strcat(mem->data, bytes);
		mem->status = MEMORY_OK;
		mem->allocMemorySize += strlen(bytes);
	}
}

char * memory_readBytesfromMemory(memory_t * mem){
	if (mem->data[0] == '\0'){
		mem->status = MEMORY_EMPTY;
		printf("There are no data!\n");
		return NULL;
	}
	else {
		return mem->data;
	}
}

int memory_getSize(memory_t * mem){
	mem->status = MEMORY_OK;
	return mem->allocMemorySize;
}

int memory_getStructSize(){
	return sizeof(struct memory_s);
}

void memory_setNullAllocMemorySize(memory_t * mem){
	mem->allocMemorySize = 0;
}

void memory_setNullAmountOfObjects(memory_t * mem){
	mem->amountOfObjects = 0;
}

void memory_setNullData(memory_t * mem){
	mem->data[0] = '\0';
}