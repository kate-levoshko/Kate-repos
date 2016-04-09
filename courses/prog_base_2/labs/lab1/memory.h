#pragma once

#define MAX_AMOUNT_OF_BYTES 256

#include "header.h"

enum MemoryError{
	MEMORY_FULL,
	MEMORY_EMPTY,
	MEMORY_OK,
	MEMORY_INCORRECTDATA
};

int memory_getSize(memory_t * mem); // получить размер выделенной памяти
void memory_writeBytesInMemory(memory_t * mem, char * bytes); // записать последовательность байт в память
char * memory_readBytesfromMemory(memory_t * mem); // считать последовательность байтов из памяти

int memory_getStructSize();

void memory_setNullAllocMemorySize(memory_t * mem);
void memory_setNullAmountOfObjects(memory_t * mem);
void memory_setNullData(memory_t * mem);